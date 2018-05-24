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
#include "Date.hpp"
#include "Customer.hpp"
#include "Order.hpp"
using namespace std;

int main() {

    vector<Customer*> theCustomers;
    vector<Order*> theOrders;
    string inputString; //CustomerNumber, inputString2//CustomerName, inputString3//email;
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

            theCustomers.push_back(new Customer());
            numCustomers++;
            customerFile >> inputString; //Set the cust Number
            theCustomers[numCustomers - 1]->setCustomerNumber(inputString);

            customerFile >> inputString; //Set the cust Name
            theCustomers[numCustomers - 1]->setCustomerName(inputString);

            customerFile >> inputString; //Set the cust Email
            theCustomers[numCustomers - 1]->setEmail(inputString);

            customerFile >> inputInt1; //year //Set the cust DateJoined
            customerFile >> inputInt2; //month
            customerFile >> inputInt3; //day
            Date tempDate; //Create a temporary date to put into the customer Datejoined variable.
            tempDate.setYear(inputInt1);
            tempDate.setMonth(inputInt2);
            tempDate.setDay(inputInt3);

            theCustomers[numCustomers - 1]->setDateJoined(tempDate);

        } //while
        customerFile.close();

    } //if
    else {
        cout << "Error opening Customer File." << endl;
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
            for (int i = 0; i < numCustomers; i++) {
                if (inputString == theCustomers[i]->getCustomerNumber()) {
                    theOrders[numOrders - 1]->setOrderCustomer(theCustomers[i]);
                } //if
            } //for

        } //while
        orderFile.close();

    } //if
    else {
        cout << "Error opening Order File." << endl;
    } //else
    orderFile.close();
    //-----------------------------END OF FILLING OUT INFORMATION---------------------------------------------------------------------------------

    //-----------------------------Print Report---------------------------------------------------------------------------------------------------

    cout << "Customer/Order Report" << endl;
    cout << "=================================" << endl;

    for (int i = 0; i < numCustomers; i++) { //Main loop goes through each customer
        double totalOrders = 0.0; // To track the sum of the orders for each customer
        cout << setw(15) << "Cust ID" << setw(30) << "Name" << setw(60)
                << "Cust Email" << setw(15) << "Cust Date" << endl;
        cout << setw(15) << "-------" << setw(30) << "----" << setw(60)
                << "----------" << setw(15) << "---------" << endl; // Customer Header

        cout << setw(15) << theCustomers[i]->getCustomerNumber() << setw(30)
                << theCustomers[i]->getCustomerName() << setw(60)
                << theCustomers[i]->getEmail() << setw(15)
                << theCustomers[i]->getDateJoined().getStringDate() << endl
                << endl; //Cust Info

        cout << setw(20) << "Order ID" << setw(30) << "Order Date" << setw(20)
                << "Order-Total" << setw(15) << "Customer" << endl;
        cout << setw(20) << "-------" << setw(30) << "---------" << setw(20)
                << "----------" << setw(15) << "--------" << endl; // Order Header
        for (int j = 0; j < numOrders; j++) { //Inner loop goes through each order
            if (theCustomers[i]->getCustomerNumber()
                    == theOrders[j]->getOrderCustomer().getCustomerNumber()) {

                cout << setw(20) << theOrders[j]->getOrderNumber() << setw(30)
                        << theOrders[j]->getOrderDate().getStringDate()
                        << setw(20) << theOrders[j]->getOrderTotal() << setw(15)
                        << theOrders[j]->getOrderCustomer().getCustomerName()
                        << endl; //Order Info
                totalOrders+= theOrders[j]->getOrderTotal();
            } //if

        } //for
        cout << setw(70) << "----------" << endl;
        cout << setw(45) << "Total Orders:" << setw(25) << setprecision(2) << fixed << totalOrders << endl << endl;
        grandTotal += totalOrders;
    } //for
    cout << setw(45) << "Grand Total Orders:" << setw(25) << setprecision(2) << fixed << grandTotal << endl << endl;
    cout << endl << endl;
    // ------------------END OF REPORT-------------------------------------

    // ------------------DELETION-------------------------------------------
    for (int i = 0; i < numCustomers; i++) {
        delete theCustomers[i];
    } //for
    for (int i = 0; i < numOrders; i++) {
        delete theOrders[i];
    } //for
    cout << "Program Ending, Have a nice day!" << endl; // prints Program Ending, Have a nice day!
    return 0;
}
