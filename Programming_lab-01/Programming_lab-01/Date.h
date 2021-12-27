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
