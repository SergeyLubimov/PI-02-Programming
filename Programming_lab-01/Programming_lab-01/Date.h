#pragma once

#include <string>
#include <cstdlib>

struct Date
{
	int day, month, year;
};

bool setDay(Date *date, int day);
bool setMonht(Date *date, int month);
bool setYear(Date *date, int year);
bool setDate(Date *date, int day, int month, int year);

bool setDateAsCharArray(Date *date, char *str);

bool setDateAsCharArray(Date *date, const char str[]);

char* getDateAsCharArray(Date *date);
