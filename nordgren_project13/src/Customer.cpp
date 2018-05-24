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
std::string Customer::getCustomerNumber() {
	return customerNumber;
}

std::string Customer::getCustomerName(void) {
	return customerName;
}
std::string Customer::getEmail(void) {
	return email;
}
Date Customer::getDateJoined(void) {
	return dateJoined;
}
//Setters
void Customer::setCustomerNumber(std::string aString) {
	customerNumber = aString;
}
void Customer::setCustomerName(std::string aString) {
	customerName = aString;
}
void Customer::setEmail(std::string aString) {
	email = aString;
}
void Customer::setDateJoined(Date aDate) {
	dateJoined = aDate;
}
