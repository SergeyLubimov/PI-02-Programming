#pragma once

#include "Warehouse.h"

class SupplierOfGoods;

class Shop
{
private:
	char* name_;
	Warehouse warehouse_;
	float cash_;
	float margin_;
	SupplierOfGoods* contract_with_supplier_;	

public:
	Shop();

	void setMargin(unsigned percent);

	bool setNameOfShop(char* name);

	bool setNameOfShop(const char s[]);

	void addBatch(BatchOfGoods* batch);

	bool sellGoods(char* name, int* q);

	bool sellGoods(const char name[], int* q);

	void displayAssortment();

	void signContract(SupplierOfGoods* supplier);
	
	void makeOrder(std::string name, int quantity);	

	void redeemOrders();

	void investMoney(float money);
};