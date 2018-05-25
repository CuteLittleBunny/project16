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

namespace bryce {


class Order {
public:
    Order();
    virtual ~Order();
    void setOrderNumber(std::string); //setters
    void setOrderDate(Date);
    void setOrderTotal(double);
    void setOrderCustomer(Customer*);
    std::string getOrderNumber(void); //getters
    Date getOrderDate(void);
    double getOrderTotal(void);
    Customer getOrderCustomer(void);
private:
    std::string orderNumber;
    Date orderDate;
    double orderTotal;
    Customer *orderCustomer;
};

}
#endif /* ORDER_HPP_ */
