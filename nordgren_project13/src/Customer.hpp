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


class Customer {
public:
	Customer(void);
	virtual ~Customer(void);
	std::string getCustomerNumber(void); //Getters
	std::string getCustomerName(void);
	std::string getEmail(void);
	Date getDateJoined(void);
	void setCustomerNumber(std::string); //Setters
	void setCustomerName(std::string);
	void setEmail(std::string);
	void setDateJoined(Date);
private:
	std::string customerNumber;
	std::string customerName;
	std::string email;
	Date dateJoined;
};

#endif /* CUSTOMER_HPP_ */
