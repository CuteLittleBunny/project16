/*
 * Customer.cpp
 *
 *  Created on: Mar 20, 2018
 *      Author: student
 */

#include "Customer.hpp"

Customer::Customer() {
	customerNumber = "unknown";
	customerName = "unknown";
	email = "unknown";
	dateJoined = Date();

}

Customer::~Customer() {
	// TODO Auto-generated destructor stub
}

//Getters
string Customer::getCustomerNumber() {
	return customerNumber;
}

string Customer::getCustomerName(void) {
	return customerName;
}
string Customer::getEmail(void) {
	return email;
}
Date Customer::getDateJoined(void) {
	return dateJoined;
}
//Setters
void Customer::setCustomerNumber(string aString) {
	customerNumber = aString;
}
void Customer::setCustomerName(string aString) {
	customerName = aString;
}
void Customer::setEmail(string aString) {
	email = aString;
}
void Customer::setDateJoined(Date aDate) {
	dateJoined = aDate;
}
