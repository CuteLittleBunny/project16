/*
 * Date.hpp
 *
 *  Created on: Mar 20, 2018
 *      Author: student
 */

#ifndef DATE_HPP_
#define DATE_HPP_
#include <iostream>


using namespace std;
class Date {
public:
	Date();
	virtual ~Date();
	void setYear(int); //setters
	void setMonth(int);
	void setDay(int);
	int getYear(void);//getters
	int getMonth(void);
	int getDay(void);
	string getStringDate();
private:
	int year;
	int month;
	int day;
};

#endif /* DATE_HPP_ */
