#pragma once

#include <string>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Shop.h"

class Order;
class ReadyOrder;

class SupplierOfGoods
{
private:
	std::list<Shop*> contracts_with_shops_;
	float margin_;
	std::list<Order*> orders_;
	std::list<ReadyOrder*> ready_orders_;	

public:
	SupplierOfGoods();

	void addContract(Shop* shop);

	void setMargin(unsigned percent);

	bool acceptOrder(Shop* contact, std::string name, int quantity);

	void fulfillOrders();

	float sellOrders(Shop* contact);
};

class Order
{
	friend void SupplierOfGoods::fulfillOrders();

private:
	std::list<Shop*>::iterator shop_iterator_;
	std::string name_;
	int quantity_;

public:
	Order(std::list<Shop*>::iterator it, std::string name, int quantity);
};

class ReadyOrder
{
	friend float SupplierOfGoods::sellOrders(Shop* contact);

private:
	std::list<Shop*>::iterator shop_iterator_;
	BatchOfGoods* batch_;

public:
	ReadyOrder(std::list<Shop*>::iterator shop_iterator, BatchOfGoods* batch);
};

