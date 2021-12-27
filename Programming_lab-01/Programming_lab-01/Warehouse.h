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