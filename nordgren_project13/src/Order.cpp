/*
 * Order.cpp
 *
 *  Created on: Mar 20, 2018
 *      Author: student
 */

#include "Order.hpp"

Order::Order() {
    orderNumber = "00000000000";
    orderTotal = 0.0;
    orderDate = Date();
    orderCustomer = new Customer();


}

Order::~Order() {

}


void Order::setOrderNumber(string aString){
    orderNumber = aString;
}

void Order::setOrderTotal(double aDouble){
    orderTotal = aDouble;
}

void Order::setOrderDate(Date aDate){
    orderDate = aDate;
}

void Order::setOrderCustomer(Customer *aCustomer){
    delete orderCustomer;
    orderCustomer = aCustomer;
}

string Order::getOrderNumber(){
    return orderNumber;
}

double Order::getOrderTotal(){
    return orderTotal;
}

Date Order::getOrderDate(){
    return orderDate;
}

Customer Order::getOrderCustomer(){
    return *orderCustomer;
}
