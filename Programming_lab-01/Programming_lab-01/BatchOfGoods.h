#pragma once

#include "Convert .h"
#include <iostream>

class BatchOfGoods
{ 
private:
	char* name_;
	int ID_;
	float price_;
	int quantity_;
	Date date_;

public:
	BatchOfGoods();

	~BatchOfGoods();

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

	BatchOfGoods* cloneBarch();
};