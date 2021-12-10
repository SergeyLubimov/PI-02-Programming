#include "Convert .h"

char* convertIntToCharArray_OnlyPositive(int integer)
{
	char* str;
	if (integer == 0) 
	{
		str = new char[2];
		str[0] = '0';
		str[1] = '\0';
	}
	else
	{
		int degree = log(integer) / log(10);

		str = new char[degree + 2];

		str[degree + 1] = '\0';

		degree++;
		int buff = 10;

		while (degree > 0)
		{
			str[degree - 1] = int((integer % buff) / (buff / 10)) + '0';
			buff *= 10;
			degree--;
		}
	}
	return str;
}

char* convertIntToCharArray(int integer)
{
	char* str;
	if (integer < 0)
	{
		char* s = convertIntToCharArray_OnlyPositive(abs(integer*1.0));
		int size = strlen(s) + 2;

		str = new char[size];
		str[size - 1] = 0;
		
		strcpy_s(str, size, "-");
		strcat_s(str, size, s);
	}
	else str = convertIntToCharArray_OnlyPositive(integer);
	return str;
}

int convertDateToDays(Date date)
{
	return date.getYear() * 365 + date.getMonht() * (365 / 12) + date.getDay();
}

int convertCharArrayToInt(char* str)
{
	int n = strlen(str);
	int n1 = n - 1;
	int ret = 0;
	int multiplier = 1;

	for (int i = 0; i < n; i++)
	{
		ret += multiplier * (str[n - i - 1] - '0');
		multiplier *= 10;
	}
	return ret;
}

bool checkWhetherInt(char* str)
{
	int n = strlen(str);
	char c;
	for (int i = 0; i < n; i++)
	{
		c = str[i];
		if (!(c >= '0' && c <= '9' || c == '-'))
			return false;
	}
	return true;
}