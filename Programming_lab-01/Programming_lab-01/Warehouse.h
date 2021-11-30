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
	NodeWithPachage* head = NULL;
	int warehouse_size = 0;
	int displayed_warehouse = 0;
};

void init(Warehouse* w);

void addBatch(Warehouse* warehouse, BatchOfGoods* batch);

float sellGoods(Warehouse* warehouse, char* name, int* quantity);

float sellGoods(Warehouse* warehouse, const char name[], int* quantity);