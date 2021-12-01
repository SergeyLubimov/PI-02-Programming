#pragma once

#include "Convert .h"
#include <iostream>

struct BatchOfGoods
{ 
private:
	char* name_;
	int ID_;
	float price_;
	int quantity_;
	Date date_;

public:
	BatchOfGoods();

	bool setNameOfGoods(char* s);

	bool setNameOfGoods(const char s[]);

	bool setIdOfGood(int id);

	bool setPriceOfGoods(int price);

	bool setQuantityOfGoods(int quantity);

	bool setDateOfBatch(char* str);

	bool setDateOfBatch(const char str[]);

	char* getIdOfGoodsAsCharArray();

	char* getName();

	int getID();

	float getPrice();

	int getQuantity();
	
	Date getDate();

	char* getBatchAsCharArray(int n);

	char* getBatchAsCharArray_WithoutName(int n);

	int reduceQuantityOfGoods();

	int reduceQuantityOfGoods(int n);

	void resetQuantityOfGoods();

	bool launchNewBatchForm();

	void deleteBatch();

	BatchOfGoods* cloneBarch();
};


/*
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

BatchOfGoods* cloneBarch(BatchOfGoods* batch);
*/