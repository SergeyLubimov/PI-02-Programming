#include "Date.h"

bool setDay(Date *date, int day)
{
	if (day > 0 && day <= 31)
	{
		date->day = day;
		return true;
	}
	return false;
}
bool setMonht(Date *date, int month)
{
	if (month > 0 && month <= 12)
	{
		date->month = month;
		return true;
	}
	return false;
}
bool setYear(Date *date, int year)
{
	if (year > 0 && year < 10000)
	{
		date->year = year;
		return true;
	}
	return false;
}
bool setDate(Date *date, int day, int month, int year)
{
	return setDay(date, day) && setMonht(date, month) && setYear(date, year);
}

bool setDateAsCharArray(Date *date, char* str)
{
	if (str != 0 && ((strlen(str) == 11 && str[10] == 0) || 
		(strlen(str) == 10 && str[9] != 0)))
	{
		int i = 0;
		char c;
		while (i < 10 && i > -1)
		{
			c = str[i];
			i++;
			if ((c < '0' || c > '9') && c != '.') i = -1;
		}
		if (i > -1)
		{
			int day = (str[0] - '0') * 10 + (str[1] - '0');

			int month = (str[3] - '0') * 10 + (str[4] - '0');

			int year = (str[6] - '0') * 1000 + (str[7] - '0') * 100 +
				        (str[8] - '0') * 10 + (str[9] - '0');

			return setDate(date, day, month, year);
		}		
	}
	return false;
}

bool setDateAsCharArray(Date *date, const char str[])
{
	if (str != 0 &&	((strlen(str) == 10 && str[10] == 0) ||
		(strlen(str) == 9 && str[9] != 0)))
	{
		int i = 0;
		char c;
		while (i < 10 && i > -1)
		{
			c = str[i];
			i++;
			if ((c < '0' || c > '9') && c != '.') i = -1;
		}
		if (i > -1)
		{
			int day = (str[0] - '0') * 10 + (str[1] - '0');

			int month = (str[3] - '0') * 10 + (str[4] - '0');

			int year = (str[6] - '0') * 1000 + (str[7] - '0') * 100 +
				        (str[8] - '0') * 10 + (str[9] - '0');

			return setDate(date, day, month, year);
		}
	}
	return false;
}

char* getDateAsCharArray(Date *date)
{
	char *str = (char*)malloc(11);

	str[0] = int(date->day / 10) + '0';
	str[1] = date->day % 10 + '0';
	str[2] = '.';
	str[3] = int(date->month / 10) + '0';
	str[4] = date->month % 10 + '0';
	str[5] = '.';
	str[6] = int(date->year / 1000) + '0';
	str[7] = int(date->year % 1000 / 100) + '0';
	str[8] = int(date->year % 100 / 10) + '0';
	str[9] = date->year % 10 + '0';
	str[10] = '\0';

	return str;
}