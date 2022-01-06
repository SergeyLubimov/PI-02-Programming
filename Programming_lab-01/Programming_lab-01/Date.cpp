#include "Date.h"

Date::Date()
{
	day_ = 0;
	month_ = 0;
	year_ = 0;
}

//Date::Date(int day, int month)
//{
//	setDay(day);
//	setMonht(month);
//}
//
//Date::Date(int day, int month, int year)
//{
//	this(day, month);
//}

int Date::getDay()
{
	return day_;
}

int Date::getMonht()
{
	return month_;
}

int Date::getYear()
{
	return year_;
}

bool Date::setDay(int day)
{
	if (day > 0 && day <= 31)
	{
		day_ = day;
		return true;
	}
	return false;
}
bool Date::setMonht(int month)
{
	if (month > 0 && month <= 12)
	{
		month_ = month;
		return true;
	}
	return false;
}
bool Date::setYear(int year)
{
	if (year > 0 && year < 10000)
	{
		year_ = year;
		return true;
	}
	return false;
}
bool Date::setDate(int day, int month, int year)
{
	return setDay(day) && setMonht(month) && setYear(year);
}

bool Date::setDateAsCharArray(std::string str)
{
	if (str != "" && (str.size() == 10))
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

			return setDate(day, month, year);
		}		
	}
	return false;
}

bool Date::setDateAsCharArray(const char str[])
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

			return setDate(day, month, year);
		}
	}
	return false;
}

char* Date::getDateAsCharArray()
{
	char* str = new char[11];

	str[0] = int(day_ / 10) + '0';
	str[1] = day_ % 10 + '0';
	str[2] = '.';
	str[3] = int(month_ / 10) + '0';
	str[4] = month_ % 10 + '0';
	str[5] = '.';
	str[6] = int(year_ / 1000) + '0';
	str[7] = int(year_ % 1000 / 100) + '0';
	str[8] = int(year_ % 100 / 10) + '0';
	str[9] = year_ % 10 + '0';
	str[10] = '\0';

	return str;
}

const Date& operator++(Date& date)
{
	if (date.day_ < 31) date.day_++;
	else
	{
		date.day_ = 1;
		if (date.month_ < 12) date.month_++;
		else
		{
			date.month_ = 1;
			date.year_++;
		}
	}
	return date;
}

const Date& operator++(Date& date, int)
{
	Date* old = new Date();

	old->setDate(date.day_, date.month_, date.year_);
	if (date.day_ < 31) date.day_++;
	else
	{
		date.day_ = 1;
		if (date.month_ < 12) date.month_++;
		else
		{
			date.month_ = 1;
			date.year_++;
		}
	}
	return *old;
}