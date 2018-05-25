/*
 * Order.cpp
 *
 *  Created on: Mar 20, 2018
 *      Author: student
 */

#include "Order.hpp"



bryce::Order::Order() {
    orderNumber = "00000000000";
    orderTotal = 0.0;
    orderDate = Date();
    orderCustomer = new Customer();


}

bryce::Order::~Order() {

}


void bryce::Order::setOrderNumber(std::string aString){
    orderNumber = aString;
}

void bryce::Order::setOrderTotal(double aDouble){
    orderTotal = aDouble;
}

void bryce::Order::setOrderDate(Date aDate){
    orderDate = aDate;
}

void bryce::Order::setOrderCustomer(Customer *aCustomer){
    delete orderCustomer;
    orderCustomer = aCustomer;
}

std::string bryce::Order::getOrderNumber(){
    return orderNumber;
}

double bryce::Order::getOrderTotal(){
    return orderTotal;
}

Date bryce::Order::getOrderDate(){
    return orderDate;
}

Customer bryce::Order::getOrderCustomer(){
    return *orderCustomer;
}


