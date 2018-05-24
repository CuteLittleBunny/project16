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

namespace bryce {

class Order {
public:
    Order();
    virtual ~Order();
    void setOrderNumber(string); //setters
    void setOrderDate(Date);
    void setOrderTotal(double);
    void setOrderCustomer(Customer*);
    string getOrderNumber(void); //getters
    Date getOrderDate(void);
    double getOrderTotal(void);
    Customer getOrderCustomer(void);
private:
    string orderNumber;
    Date orderDate;
    double orderTotal;
    Customer *orderCustomer;
};

}

int main() {

    std::map<string,Customer*> CustomerMap;
    std::map<string,Customer*>:: iterator it;
    //vector<Customer*> theCustomers;
    vector<Order*> theOrders;
    string inputString;//inputString2//CustomerName, inputString3//email;
    string inputCustNum;
    int inputInt1, inputInt2, inputInt3; // Year-1/Month-2/Day-3
    int numCustomers = 0; //Counter to fill the customer vector.
    int numOrders = 0; //Counter to fill the order vector.
    double inputDouble; //ordertotal
    double grandTotal = 0; //Tracks the sum of all order totals.
    ifstream customerFile;
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
        std::cout << "Error opening Customer File." << endl;
    } //else

    customerFile.close();

    ifstream orderFile;
    orderFile.open("OrderFile.txt");
    if (!orderFile.fail()) {
        while (!orderFile.eof()) {
            theOrders.push_back(new Order());
            numOrders++;

            orderFile >> inputString; //Order Number
            theOrders[numOrders - 1]->setOrderNumber(inputString);
            orderFile >> inputDouble; //Order Double
            theOrders[numOrders - 1]->setOrderTotal(inputDouble);
            orderFile >> inputInt1; //year //Set the order Date
            orderFile >> inputInt2; //month
            orderFile >> inputInt3; //day
            Date tempDate; //Create a temporary date to put into the order Date variable.
            tempDate.setYear(inputInt1);
            tempDate.setMonth(inputInt2);
            tempDate.setDay(inputInt3);
            theOrders[numOrders - 1]->setOrderDate(tempDate);

            orderFile >> inputString; //Match the customerId from orderfile to existing customers in theCustomers Vector.


            for (it = CustomerMap.begin(); it != CustomerMap.end(); ++it) {
                if (inputString == it->first) { // theCustomers[i]->getCustomerNumber()
                    theOrders[numOrders - 1]->setOrderCustomer(it->second);
                } //if
            } //for

        } //while
        orderFile.close();

    } //if
    else {
        std::cout << "Error opening Order File." << endl;
    } //else
    orderFile.close();
    //-----------------------------END OF FILLING OUT INFORMATION---------------------------------------------------------------------------------

    //-----------------------------Print Report---------------------------------------------------------------------------------------------------

    std::cout << "Customer/Order Report" << endl;
    std::cout << "=================================" << endl;

    for (int i = 0; i < numCustomers; i++) { //Main loop goes through each customer
        double totalOrders = 0.0; // To track the sum of the orders for each customer
        std::cout << setw(15) << "Cust ID" << setw(30) << "Name" << setw(60)
                << "Cust Email" << setw(15) << "Cust Date" << endl;
        std::cout << setw(15) << "-------" << setw(30) << "----" << setw(60)
                << "----------" << setw(15) << "---------" << endl; // Customer Header

        std::cout << setw(15) << theCustomers[i]->getCustomerNumber() << setw(30)
                << theCustomers[i]->getCustomerName() << setw(60)
                << theCustomers[i]->getEmail() << setw(15)
                << theCustomers[i]->getDateJoined().getStringDate() << endl
                << endl; //Cust Info

        std::cout << setw(20) << "Order ID" << setw(30) << "Order Date" << setw(20)
                << "Order-Total" << setw(15) << "Customer" << endl;
        std::cout << setw(20) << "-------" << setw(30) << "---------" << setw(20)
                << "----------" << setw(15) << "--------" << endl; // Order Header
        for (int j = 0; j < numOrders; j++) { //Inner loop goes through each order
            if (theCustomers[i]->getCustomerNumber()
                    == theOrders[j]->getOrderCustomer().getCustomerNumber()) {

                std::cout << setw(20) << theOrders[j]->getOrderNumber() << setw(30)
                        << theOrders[j]->getOrderDate().getStringDate()
                        << setw(20) << theOrders[j]->getOrderTotal() << setw(15)
                        << theOrders[j]->getOrderCustomer().getCustomerName()
                        << endl; //Order Info
                totalOrders += theOrders[j]->getOrderTotal();
            } //if

        } //for
        std::cout << setw(70) << "----------" << endl;
        std::cout << setw(45) << "Total Orders:" << setw(25) << setprecision(2)
                << fixed << totalOrders << endl << endl;
        grandTotal += totalOrders;
    } //for
    std::cout << setw(45) << "Grand Total Orders:" << setw(25) << setprecision(2)
            << fixed << grandTotal << endl << endl;
    std::cout << endl << endl;
    // ------------------END OF REPORT-------------------------------------

    // ------------------DELETION-------------------------------------------
    for (int i = 0; i < numCustomers; i++) {
        delete theCustomers[i];
    } //for
    for (int i = 0; i < numOrders; i++) {
        delete theOrders[i];
    } //for
    std::cout << "Program Ending, Have a nice day!" << endl; // prints Program Ending, Have a nice day!
    return 0;
}
