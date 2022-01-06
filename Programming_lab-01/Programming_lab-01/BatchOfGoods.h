#pragma once

#include "Convert .h"
#include <iostream>
#include<string>

class BatchOfGoods
{ 
private:
	std::string name_;
	int ID_;
	float price_;
	int quantity_;
	Date date_;

public:
	BatchOfGoods();

	~BatchOfGoods();

	bool setNameOfGoods(std::string s);

	bool setNameOfGoods(const char s[]);

	bool setIdOfGood(int id);

	bool setPriceOfGoods(int price);

	bool setQuantityOfGoods(int quantity);

	bool setDateOfBatch(std::string str);

	//bool setDateOfBatch(const char str[]);

	std::string getIdOfGoodsAsCharArray();

	std::string getName();

	int getID();

	float getPrice();

	int getQuantity();
	
	Date getDate();

	std::string getBatchAsCharArray(int n);

	std::string getBatchAsCharArray_WithoutName(int n);

	int reduceQuantityOfGoods();

	int reduceQuantityOfGoods(int n);

	void resetQuantityOfGoods();

	bool launchNewBatchForm();

	BatchOfGoods* cloneBarch();
};