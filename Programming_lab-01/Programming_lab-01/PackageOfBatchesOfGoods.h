#pragma once

#include "Convert .h"
#include "BatchOfGoods.h"
#include <cstdlib>
#include <string>
#include <iostream>

struct NodeWithBatch
{
	BatchOfGoods* batch = NULL;
	NodeWithBatch* next = NULL;
	NodeWithBatch* prev = NULL;
	int sumDays;
};

struct PackageOfBatchesOfGoods
{
	char* name = NULL;
	NodeWithBatch* head = NULL;
	NodeWithBatch* tail = NULL;
	int package_size = 0;
};

void init(PackageOfBatchesOfGoods* p);

void addBatch(PackageOfBatchesOfGoods* package, BatchOfGoods* batch);

void setNameOfPackage(PackageOfBatchesOfGoods* p, char* name);

char* getPackageAsCharArray(PackageOfBatchesOfGoods* package);

bool delNode(PackageOfBatchesOfGoods* package, NodeWithBatch* node);

NodeWithBatch* findNode(PackageOfBatchesOfGoods* package, int id);

float sellProduct(PackageOfBatchesOfGoods* package, int id);

float sellGoods(NodeWithBatch* node, int* quantity);

float sellGoods(PackageOfBatchesOfGoods* package, int* quantity);

int countGoods(PackageOfBatchesOfGoods* p);

void printPackageAsCharArray(PackageOfBatchesOfGoods* package);