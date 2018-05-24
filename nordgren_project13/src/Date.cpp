/*
 * Date.cpp
 *
 *  Created on: Mar 20, 2018
 *      Author: student
 */

#include "Date.hpp"

Date::Date() {
	// TODO Auto-generated constructor stub
    year = 0;
    month = 0;
    day = 0;
}

Date::~Date() {
	// TODO Auto-generated destructor stub
}

//Getters
int Date::getYear() {
    return year;
}

int Date::getMonth() {
    return month;
}
int Date::getDay() {
    return day;
}

void Date::setYear(int aYear){
    year = aYear;
}

void Date::setMonth(int aMonth){
    month = aMonth;
}

void Date::setDay(int aDay){
    day = aDay;
}

string Date::getStringDate(){
    string tempString = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
    return tempString;
}
