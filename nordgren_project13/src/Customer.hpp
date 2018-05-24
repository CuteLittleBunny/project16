/*
 * Customer.hpp
 *
 *  Created on: Mar 20, 2018
 *      Author: student
 */

#ifndef CUSTOMER_HPP_
#define CUSTOMER_HPP_
#include <iostream>
#include "Date.hpp"

using namespace std;
class Customer {
public:
	Customer(void);
	virtual ~Customer(void);
	string getCustomerNumber(void); //Getters
	string getCustomerName(void);
	string getEmail(void);
	Date getDateJoined(void);
	void setCustomerNumber(string); //Setters
	void setCustomerName(string);
	void setEmail(string);
	void setDateJoined(Date);
private:
	string customerNumber;
	string customerName;
	string email;
	Date dateJoined;
};

#endif /* CUSTOMER_HPP_ */
