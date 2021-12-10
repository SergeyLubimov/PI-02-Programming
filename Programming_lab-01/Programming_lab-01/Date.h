#pragma once

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>

class Date
{
private: 
	int day_, month_, year_;

public:
	Date();

	int getDay();

	int getMonht();

	int getYear();

	bool setDay(int day);

	bool setMonht(int month);

	bool setYear(int year);

	bool setDate(int day, int month, int year);

	bool setDateAsCharArray(char* str);

	bool setDateAsCharArray(const char str[]);

	char* getDateAsCharArray();
};

//struct Date
//{
//	int day, month, year;
//};
//
//bool setDay(Date *date, int day);
//
//bool setMonht(Date *date, int month);
//
//bool setYear(Date *date, int year);
//
//bool setDate(Date *date, int day, int month, int year);
//
//bool setDateAsCharArray(Date *date, char *str);
//
//bool setDateAsCharArray(Date *date, const char str[]);
//
//char* getDateAsCharArray(Date *date);
