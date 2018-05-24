/*
 * Order.hpp
 *
 *  Created on: Mar 20, 2018
 *      Author: student
 */

#ifndef ORDER_HPP_
#define ORDER_HPP_
#include <iostream>
#include "Date.hpp"
#include "Customer.hpp"

using namespace std;

class Order {
public:
	Order();
	virtual ~Order();
	void setOrderNumber(string); //setters
	void setOrderDate(Date);
	void setOrderTotal(double);
	void setOrderCustomer(Customer*);
	string getOrderNumber(void);//getters
	Date getOrderDate(void);
	double getOrderTotal(void);
	Customer getOrderCustomer(void);
private:
	string orderNumber;
	Date orderDate;
	double orderTotal;
	Customer *orderCustomer;
};

#endif /* ORDER_HPP_ */
