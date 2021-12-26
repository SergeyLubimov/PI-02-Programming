#pragma once

#include "Warehouse.h"

class SupplierOfGoods;

class Shop
{
private:
	char* name_;
	Warehouse warehouse_;
	float cash_;
	SupplierOfGoods* contracts_with_suppliers_;
	

public:
	Shop();

	void init();

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

//struct Shop
//{
//	char* name;
//	Warehouse warehouse;
//	float cash = 0;
//};
//
//void init(Shop* sh);
//
//bool setNameOfShop(Shop* shop, char* name);
//
//bool setNameOfShop(Shop* shop, const char s[]);
//
//void addBatch(Shop* shop, BatchOfGoods* batch);
//
//bool sellGoods(Shop* shop, char* name, int* q);
//
//bool sellGoods(Shop* shop, const char name[], int* q);
//
//void displayAssortment(Shop shop);