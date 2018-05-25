//============================================================================
// Name        : nordgren_cs2_customers.cpp
// Author      : Bryce Nordgren
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
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

    std::map<std::string,Customer*> CustomerMap;
    std::map<std::string,Customer*>:: iterator it; //it means iterator
    //vector<Customer*> theCustomers;
    //vector<Order*> theOrders;
    std::multimap<std::string,Order*> OrderMultiMap;
    std::multimap<std::string,Order*>:: iterator oit; // oit means order iterator
    std::string inputString; //inputString2//CustomerName, inputString3//email;

    std::string inputCustNum;
    int inputInt1, inputInt2, inputInt3; // Year-1/Month-2/Day-3
    int numCustomers = 0; //Counter to fill the customer vector.
    int numOrders = 0; //Counter to fill the order vector.
    double inputDouble; //ordertotal
    double grandTotal = 0; //Tracks the sum of all order totals.
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
            Order *tempOrder = new Order();
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


            for (it = CustomerMap.begin(); it != CustomerMap.end(); ++it) {
                if (inputString == it->first) { // it->second->getCustomerNumber()
                    tempOrder->setOrderCustomer(it->second);
                } //if
            } //for

            OrderMultiMap[tempOrder->getOrderCustomer().getCustomerNumber()] = tempOrder;

        } //while
        orderFile.close();

    } //if
    else {
        std::cout << "Error opening Order File." << std::endl;
    } //else
    orderFile.close();
    //-----------------------------END OF FILLING OUT INFORMATION---------------------------------------------------------------------------------

    //-----------------------------Print Report---------------------------------------------------------------------------------------------------

    std::cout << "Customer/Order Report" << std::endl;
    std::cout << "=================================" << std::endl;


    for (it = CustomerMap.begin(); it != CustomerMap.end(); ++it) { //Main loop goes through each customer
        double totalOrders = 0.0; // To track the sum of the orders for each customer int i = 0; i < numCustomers; i++
        std::cout << std::setw(15) << "Cust ID" << std::setw(30) << "Name" << std::setw(60)
                << "Cust Email" << std::setw(15) << "Cust Date" << std::endl;
        std::cout << std::setw(15) << "-------" << std::setw(30) << "----" << std::setw(60)
                << "----------" << std::setw(15) << "---------" << std::endl; // Customer Header

        std::cout << std::setw(15) << it->second->getCustomerNumber() << std::setw(30)
                << it->second->getCustomerName() << std::setw(60)
                << it->second->getEmail() << std::setw(15)
                << it->second->getDateJoined().getStringDate() << std::endl
                << std::endl; //Cust Info

        std::cout << std::setw(20) << "Order ID" << std::setw(30) << "Order Date" << std::setw(20)
                << "Order-Total" << std::setw(15) << "Customer" << std::endl;
        std::cout << std::setw(20) << "-------" << std::setw(30) << "---------" << std::setw(20)
                << "----------" << std::setw(15) << "--------" << std::endl; // Order Header
        for (int j = 0; j < numOrders; j++) { //Inner loop goes through each order
            if (it->second->getCustomerNumber()
                    == theOrders[j]->getOrderCustomer().getCustomerNumber()) {

                std::cout << std::setw(20) << theOrders[j]->getOrderNumber() << std::setw(30)
                        << theOrders[j]->getOrderDate().getStringDate()
                        << std::setw(20) << theOrders[j]->getOrderTotal() << std::setw(15)
                        << theOrders[j]->getOrderCustomer().getCustomerName()
                        << std::endl; //Order Info
                totalOrders += theOrders[j]->getOrderTotal();
            } //if

        } //for
        std::cout << std::setw(70) << "----------" << std::endl;
        std::cout << std::setw(45) << "Total Orders:" << std::setw(25) << std::setprecision(2)
                << std::fixed << totalOrders << std::endl << std::endl;
        grandTotal += totalOrders;
    } //for
    std::cout << std::setw(45) << "Grand Total Orders:" << std::setw(25) << std::setprecision(2)
            << std::fixed << grandTotal << std::endl << std::endl;
    std::cout << std::endl << std::endl;
    // ------------------END OF REPORT-------------------------------------

    // ------------------DELETION-------------------------------------------
    for (it = CustomerMap.begin(); it != CustomerMap.end(); ++it) {
        delete it->second;
    } //for
    for (int i = 0; i < numOrders; i++) {
        delete theOrders[i];
    } //for
    std::cout << "Program Ending, Have a nice day!" << std::endl; // prints Program Ending, Have a nice day!
    return 0;
}
