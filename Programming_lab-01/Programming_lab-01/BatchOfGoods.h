#pragma once

#include "Convert .h"
#include <iostream>

struct BatchOfGoods
{ 
	char* name;
	int ID;
	float price;
	int quantity;
	Date date;
};

bool setNameOfGoods(BatchOfGoods *batch, char* s);

bool setNameOfGoods(BatchOfGoods *batch, const char s[]);

bool setIdOfGood(BatchOfGoods *batch, int id);

bool setPriceOfGoods(BatchOfGoods *batch, int price);

bool setQuantityOfGoods(BatchOfGoods *batch, int quantity);

bool setDateOfBatch(BatchOfGoods *batch, char* str);

bool setDateOfBatch(BatchOfGoods *batch, const char str[]);

char* getIdOfGoods(BatchOfGoods batch);

char* getBatchAsCharArray(BatchOfGoods batch, int n);

char* getBatchAsCharArray_WithoutName(BatchOfGoods batch, int n);

BatchOfGoods* launchNewBatchForm();

void deleteBatch(BatchOfGoods* batch);