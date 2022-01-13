#pragma once

#include "Warehouse.h"

class SupplierOfGoods;

class Shop
{
private:
	std::string name_;
	Warehouse warehouse_;		
	SupplierOfGoods* contract_with_supplier_;	

protected:
	float cash_;
	float margin_;

public:

	Shop();

	Shop(std::string name);

	Shop(std::string name, int percent_margin, float cash);

	std::string getName();

	/*virtual */void setMargin(unsigned percent);
	/*{
		margin_ = 1 + float(percent) / 100;
		std::cout << "It's Shop\n";
	}*/

	bool setNameOfShop(std::string name);

	void addBatch(BatchOfGoods* batch);

	bool sellGoods(std::string name, int* q);

	void displayAssortment();

	void signContract(SupplierOfGoods* supplier);
	
	void makeOrder(std::string name, int quantity);	

	void redeemOrders();

	void investMoney(float money);

	float getMargin();

	Warehouse getWarehouse();

	SupplierOfGoods* getContractWithSupplier();

	void setWarehouse(Warehouse warehouse);

	void setContractWithSupplier(SupplierOfGoods* contract);

};