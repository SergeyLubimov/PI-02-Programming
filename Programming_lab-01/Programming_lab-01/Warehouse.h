#pragma once

#include "PackageOfBatchesOfGoods.h"

class NodeWithPachage;

struct Warehouse
{
private:
	NodeWithPachage* head_;
	int warehouse_size_;

public:

	Warehouse();

	~Warehouse();

	NodeWithPachage* getHead();

	int getSize();

	void addBatch(BatchOfGoods* batch);

	float sellGoods(std::string name, int* quantity);

	//float sellGoods(const char name[], int* quantity);
};

class NodeWithPachage
{
public:
	PackageOfBatchesOfGoods* package_;
	NodeWithPachage* next_;
	bool is_empty_;
	NodeWithPachage();
	~NodeWithPachage();
};