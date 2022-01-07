#pragma once

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>

class Date
{
private: 
	int day_, month_, year_;

	static int number_days_in_year;
	static int number_days_in_month;
	static int number_months_in_year;

public:
	Date();

	int getDay();

	int getMonht();

	int getYear();

	bool setDay(int day);

	bool setMonht(int month);

	bool setYear(int year);

	bool setDate(int day, int month, int year);

	bool setDateAsCharArray(std::string str);

	bool setDateAsCharArray(const char str[]);

	char* getDateAsCharArray();

	friend const Date& operator+(const Date& left, const Date& right);

	friend const Date& operator++(Date& date);

	friend const Date& operator++(Date& date, int);

	static int getNumberDaysInYear() { return number_days_in_year; }
	static int getNumberDaysInMonth() { return number_days_in_month; }
	static int getNumberMonthsInYear() { return number_months_in_year; }
};

int Date::number_days_in_year = 365;
int Date::number_days_in_month = 30;
int Date::number_months_in_year = 12;