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

void init(Warehouse* w)
{
	w->head = NULL;
	w->warehouse_size = 0;
	w->displayed_warehouse = 0;
}

//void init(NodeWithPachage *package)
//{
//	package->is_empty = true;
//	package->next = NULL;
//	package->package = NULL;
//}
//
//void init(Warehouse *w)
//{
//	w->head = NULL;
//	w->warehouse_size = 0;
//	w->displayed_warehouse = 0;
//}

void addBatch(Warehouse* warehouse, BatchOfGoods* batch)
{
	char* name = batch->name;
	NodeWithPachage* node = warehouse->head;

	while (node != NULL && strcmp(name, node->package->name) != 0)
		node = node->next;

	if (node == NULL)
	{
		node = (NodeWithPachage*)malloc(sizeof(NodeWithBatch));
		node->next = warehouse->head;
		warehouse->head = node;

		node->package = (PackageOfBatchesOfGoods*)malloc(sizeof(PackageOfBatchesOfGoods));

		//init(node->package);

		//node->package->package_size = 0;

		init(node->package);

		addBatch(node->package, batch);

		int size = strlen(name) + 1;
		node->package->name = (char*)malloc(size);
		strcpy_s(node->package->name, size, name);

		warehouse->warehouse_size++;
		warehouse->displayed_warehouse++;
	}
	else
	{
		addBatch(node->package, batch);
	}

	//node->is_empty == false;

	node->is_empty = false;
}

float sellGoods(Warehouse *warehouse, char* name, int *quantity)
{
	NodeWithPachage* node = warehouse->head;

	float sum = -1;

	while (node != NULL && strcmp(name, node->package->name) != 0)
		node = node->next;

	if (node != NULL && node->is_empty == false)
	{
		sum = sellGoods(node->package, quantity);

		if (node->package->package_size == 0)
		{
			node->is_empty = true;
			warehouse->displayed_warehouse--;
		}
	}
	return sum;
}