
#include "Warehouse.h"

Warehouse::Warehouse()
{
	head_ = NULL;
	warehouse_size_ = 0;
}

Warehouse::~Warehouse()
{
	NodeWithPachage* buff, * node = head_;
	while (node != NULL)
	{
		buff = node;
		node = node->next_;
		delete buff;
	}
}

NodeWithPachage* Warehouse::getHead()
{
	return head_;
}

int Warehouse::getSize()
{
	return warehouse_size_;
}

void Warehouse::addBatch(BatchOfGoods* batch)
{
	char* name = batch->getName();
	NodeWithPachage* node = head_;

	while (node != NULL && strcmp(name, node->package_->getName()) != 0)
		node = node->next_;

	if (node == NULL)
	{
		node = new NodeWithPachage();
		node->next_ = head_;
		head_ = node;

		node->package_ = new PackageOfBatchesOfGoods();

		node->package_->addBatch(batch);

		node->package_->setNameOfPackage(name);

		warehouse_size_++;
	}
	else node->package_->addBatch(batch);

	node->is_empty_ = false;
}

float Warehouse::sellGoods(char* name, int* quantity)
{
	NodeWithPachage* node = head_;

	float sum = -1;

	while (node != NULL && strcmp(name, node->package_->getName()) != 0)
		node = node->next_;

	if (node != NULL && node->is_empty_ == false)
	{
		sum = node->package_->sellGoods(quantity);

		if (node->package_->getSize() == 0)
		{
			node->is_empty_ = true;
		}
	}
	return sum;
}

float Warehouse::sellGoods(const char name[], int* quantity)
{
	NodeWithPachage* node = head_;

	float sum = -1;

	while (node != NULL && strcmp(name, node->package_->getName()) != 0)
		node = node->next_;

	if (node != NULL && node->is_empty_ == false)
	{
		sum = node->package_->sellGoods(quantity);

		if (node->package_->getSize() == 0)
		{
			node->is_empty_ = true;
		}
	}
	return sum;
}

NodeWithPachage::NodeWithPachage()
{
	NodeWithPachage* next = NULL;
	bool is_empty = true;
}

NodeWithPachage::~NodeWithPachage()
{
	delete package_;
}

