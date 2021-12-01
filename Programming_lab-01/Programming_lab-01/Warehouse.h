#pragma once

#include "PackageOfBatchesOfGoods.h"

struct NodeWithPachage
{
	PackageOfBatchesOfGoods* package;
	NodeWithPachage* next = NULL;
	bool is_empty = true;
};

struct Warehouse
{
private:
	NodeWithPachage* head_;
	int warehouse_size_;
	int displayed_warehouse_;

public:

	Warehouse();

	void init();

	NodeWithPachage* getHead();

	int getSize();

	int getDisplayedWarehouse();

	void addBatch(BatchOfGoods* batch);

	float sellGoods(char* name, int* quantity);

	float sellGoods(const char name[], int* quantity);
};


//struct Warehouse
//{
//	NodeWithPachage* head = NULL;
//	int warehouse_size = 0;
//	int displayed_warehouse = 0;
//};
//
//void init(Warehouse* w);
//
//void addBatch(Warehouse* warehouse, BatchOfGoods* batch);
//
//float sellGoods(Warehouse* warehouse, char* name, int* quantity);
//
//float sellGoods(Warehouse* warehouse, const char name[], int* quantity);