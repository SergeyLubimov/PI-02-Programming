#pragma once

#include "Date.h"
#include <cmath>

char* convertIntToCharArray_OnlyPositive(int integer);

char* convertIntToCharArray(int integer);

int convertCharArrayToInt(char* str);

bool checkWhetherInt(char* str);

int convertDateToDays(Date date);
