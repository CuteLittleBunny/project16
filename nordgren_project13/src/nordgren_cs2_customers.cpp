//============================================================================
// Name        : nordgren_cs2_customers.cpp
// Author      : Bryce Nordgren
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//
//I have had trouble with the namespace bryce thing.
//I'm struggling to implement it properly.
//
//

//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
#include "Date.hpp"
#include "Customer.hpp"
#include "Order.hpp"

int main() {

    std::map<std::string, Customer*> CustomerMap;
    std::map<std::string, Customer*>::iterator cit; //cit means customer iterator
    //vector<Customer*> theCustomers;
    //vector<Order*> theOrders;
    std::multimap<std::string, bryce::Order*> OrderMultiMap;
    std::multimap<std::string, bryce::Order*>::iterator oit = OrderMultiMap.begin(); // oit means order iterator

    std::string inputString; //inputString2//CustomerName, inputString3//email;

    std::string inputCustNum;
    int inputInt1, inputInt2, inputInt3; // Year-1/Month-2/Day-3
    int numCustomers = 0; //Counter to fill the customer vector.
    int numOrders = 0; //Counter to fill the order vector.
    double inputDouble; //ordertotal
   // double grandTotal = 0; //Tracks the sum of all order totals.
    std::ifstream customerFile;
    customerFile.open("CustomerFile.txt");
    //Customer Vector processing.

    if (!customerFile.fail()) {
        while (!customerFile.eof()) { //Fill theCustomers vector from the CustomerFile.txt
            Customer *tempCustomer = new Customer();
            // theCustomers.push_back(new Customer());
            numCustomers++;
            customerFile >> inputString; //Set the cust Number
            tempCustomer->setCustomerNumber(inputString);
            // theCustomers[numCustomers - 1]->setCustomerNumber(inputString);

            customerFile >> inputString; //Set the cust Name
            tempCustomer->setCustomerName(inputString);
            //theCustomers[numCustomers - 1]->setCustomerName(inputString);

            customerFile >> inputString; //Set the cust Email
            tempCustomer->setEmail(inputString);
            //theCustomers[numCustomers - 1]->setEmail(inputString);

            customerFile >> inputInt1; //year //Set the cust DateJoined
            customerFile >> inputInt2; //month
            customerFile >> inputInt3; //day
            Date tempDate; //Create a temporary date to put into the customer Datejoined variable.
            tempDate.setYear(inputInt1);
            tempDate.setMonth(inputInt2);
            tempDate.setDay(inputInt3);

            tempCustomer->setDateJoined(tempDate);
            //theCustomers[numCustomers - 1]->setDateJoined(tempDate);
            CustomerMap[tempCustomer->getCustomerNumber()] = tempCustomer;

        } //while
        customerFile.close();

    } //if
    else {
        std::cout << "Error opening Customer File." << std::endl;
    } //else

    customerFile.close();

    std::ifstream orderFile;
    orderFile.open("OrderFile.txt");
    if (!orderFile.fail()) {
        while (!orderFile.eof()) {
            //theOrders.push_back(new Order());
            bryce::Order *tempOrder = new bryce::Order();
            numOrders++;

            orderFile >> inputString; //Order Number
            //theOrders[numOrders - 1]->setOrderNumber(inputString);
            tempOrder->setOrderNumber(inputString);
            orderFile >> inputDouble; //Order Double
            //theOrders[numOrders - 1]->setOrderTotal(inputDouble);
            tempOrder->setOrderTotal(inputDouble);
            orderFile >> inputInt1; //year //Set the order Date
            orderFile >> inputInt2; //month
            orderFile >> inputInt3; //day
            Date tempDate; //Create a temporary date to put into the order Date variable.
            tempDate.setYear(inputInt1);
            tempDate.setMonth(inputInt2);
            tempDate.setDay(inputInt3);
            // theOrders[numOrders - 1]->setOrderDate(tempDate);
            tempOrder->setOrderDate(tempDate);

            orderFile >> inputString; //Match the customerId from orderfile to existing customers in CustomerMap map.

            for (cit = CustomerMap.begin(); cit != CustomerMap.end(); ++cit) {
                if (inputString == cit->first) { // cit->second->getCustomerNumber()
                    tempOrder->setOrderCustomer(cit->second);
                } //if
            } //for

            inputString = tempOrder->getOrderCustomer().getCustomerNumber();
            //OrderMultiMap.insert(inputString, tempOrder);
            OrderMultiMap.insert(std::make_pair(inputString, tempOrder));

        } //while
        orderFile.close();

    } //if
    else {
        std::cout << "Error opening Order File." << std::endl;
    } //else
    orderFile.close();
    //-----------------------------END OF FILLING OUT INFORMATION---------------------------------------------------------------------------------

    //-----------------------------Print Report---------------------------------------------------------------------------------------------------

    bool keepgoing = true;

    while (keepgoing) {
        std::cout
                << "Please enter the customer ID for the customer you would like to find!"
                << "Type END to exit" << std::endl;
        std::getline(std::cin, inputString);

        if (inputString == "END" || inputString == "end") {
            keepgoing = false;
        } //if
        else {
            cit = CustomerMap.find(inputString);
            if (cit != CustomerMap.end()) {
                std::cout << std::setw(15) << "Cust ID" << std::setw(30)
                        //cust info start
                        << "Name" << std::setw(60) << "Cust Email"
                        << std::setw(15) << "Cust Date" << std::endl;
                std::cout << std::setw(15) << "-------" << std::setw(30)
                        << "----" << std::setw(60) << "----------"
                        << std::setw(15) << "---------" << std::endl; // Customer Header

                std::cout << std::setw(15) << cit->second->getCustomerNumber()
                        << std::setw(30) << cit->second->getCustomerName()
                        << std::setw(60) << cit->second->getEmail()
                        << std::setw(15)
                        << cit->second->getDateJoined().getStringDate()
                        << std::endl << std::endl; //Cust Info end

                std::cout << std::setw(20) << "Order ID" << std::setw(30)
                        << "Order Date" << std::setw(20) << "Order-Total"
                        << std::setw(15) << "Customer" << std::endl;
                std::cout << std::setw(20) << "-------" << std::setw(30)
                        << "---------" << std::setw(20) << "----------"
                        << std::setw(15) << "--------" << std::endl; // Order Header

                for (oit = OrderMultiMap.begin(); oit != OrderMultiMap.end();
                        ++oit) { //Inner loop goes through each order
                    if (cit->second->getCustomerNumber()
                            == oit->second->getOrderCustomer().getCustomerNumber()) {

                        std::cout << std::setw(20)
                                << oit->second->getOrderNumber()
                                << std::setw(30)
                                << oit->second->getOrderDate().getStringDate()
                                << std::setw(20) << oit->second->getOrderTotal()
                                << std::setw(15)
                                << oit->second->getOrderCustomer().getCustomerName()
                                << std::endl; //Order Info
                    } //if

                } //for

            } //if
            else {
                std::cout << inputString << " was not found!" << std::endl;

            } //else
        } //else

    } //while


     // ------------------END OF REPORT-------------------------------------
    // ------------------DELETION-------------------------------------------
    for (cit = CustomerMap.begin(); cit != CustomerMap.end(); ++cit) {
        delete cit->second;
    } //for
    for (oit = OrderMultiMap.begin(); oit != OrderMultiMap.end(); ++oit) {
        delete oit->second;
    } //for
    std::cout << "Program Ending, Have a nice day!" << std::endl; // prints Program Ending, Have a nice day!
    return 0;
}
