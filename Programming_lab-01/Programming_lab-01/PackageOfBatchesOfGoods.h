#pragma once

#include "Convert .h"
#include "BatchOfGoods.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

class NodeWithBatch;

class PackageOfBatchesOfGoods
{
private:
	std::string name_;
	NodeWithBatch* head_;
	NodeWithBatch* tail_;
	int package_size_;

public:

	PackageOfBatchesOfGoods();

	~PackageOfBatchesOfGoods();

	void addBatch(BatchOfGoods* batch);

	void setNameOfPackage(std::string name);

	std::string getName();

	int getSize();

	std::string getPackageAsCharArray();

	int reducePackageSize(int n);

	void resetPackageSize();

	bool delNode(NodeWithBatch* node);

	NodeWithBatch* findNode(int id);

	float sellProduct(int id);

	float sellGoods(NodeWithBatch* node, int* quantity);

	float sellGoods(int* quantity);

	float sellGoods(NodeWithBatch *node, int& quantity);

	float sellGoods(int& quantity);
	
	int countGoods();

	void printPackageAsCharArray();
};

class NodeWithBatch
{
public:
	BatchOfGoods* batch_ = NULL;
	NodeWithBatch* next_ = NULL;
	NodeWithBatch* prev_ = NULL;
	int sumDays_;
	NodeWithBatch();
	~NodeWithBatch();
};