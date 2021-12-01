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

class PackageOfBatchesOfGoods
{
private:
	char* name_;
	NodeWithBatch* head_;
	NodeWithBatch* tail_;
	int package_size_;

public:

	PackageOfBatchesOfGoods();

	void addBatch(BatchOfGoods* batch);

	void setNameOfPackage(char* name);

	char* getName();

	int getSize();

	char* getPackageAsCharArray();

	int reducePackageSize(int n);

	void resetPackageSize();

	bool delNode(NodeWithBatch* node);

	NodeWithBatch* findNode(int id);

	float sellProduct(int id);

	float sellGoods(NodeWithBatch* node, int* quantity);

	float sellGoods(int* quantity);

	int countGoods();

	void printPackageAsCharArray();
};

//struct PackageOfBatchesOfGoods
//{
//	char* name = NULL;
//	NodeWithBatch* head = NULL;
//	NodeWithBatch* tail = NULL;
//	int package_size = 0;
//};
//
//void init(PackageOfBatchesOfGoods* p);
//
//void addBatch(PackageOfBatchesOfGoods* package, BatchOfGoods* batch);
//
//void setNameOfPackage(PackageOfBatchesOfGoods* p, char* name);
//
//char* getPackageAsCharArray(PackageOfBatchesOfGoods* package);
//
//bool delNode(PackageOfBatchesOfGoods* package, NodeWithBatch* node);
//
//NodeWithBatch* findNode(PackageOfBatchesOfGoods* package, int id);
//
//float sellProduct(PackageOfBatchesOfGoods* package, int id);
//
//float sellGoods(NodeWithBatch* node, int* quantity);
//
//float sellGoods(PackageOfBatchesOfGoods* package, int* quantity);
//
//int countGoods(PackageOfBatchesOfGoods* p);
//
//void printPackageAsCharArray(PackageOfBatchesOfGoods* package);