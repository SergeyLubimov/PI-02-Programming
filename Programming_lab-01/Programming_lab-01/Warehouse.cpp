
#include "Warehouse.h"

Warehouse::Warehouse()
{
	head_ = NULL;
	warehouse_size_ = 0;
	displayed_warehouse_ = 0;
}

void Warehouse::init()
{
	head_ = NULL;
	warehouse_size_ = 0;
	displayed_warehouse_ = 0;
}

NodeWithPachage* Warehouse::getHead()
{
	return head_;
}

int Warehouse::getSize()
{
	return warehouse_size_;
}

int Warehouse::getDisplayedWarehouse()
{
	return displayed_warehouse_;
}

void Warehouse::addBatch(BatchOfGoods* batch)
{
	char* name = batch->getName();
	NodeWithPachage* node = head_;

	while (node != NULL && strcmp(name, node->package->getName()) != 0)
		node = node->next;

	if (node == NULL)
	{
		node = (NodeWithPachage*)malloc(sizeof(NodeWithBatch));//////////////////////////
		node->next = head_;
		head_ = node;

		node->package = new PackageOfBatchesOfGoods();

		node->package->addBatch(batch);

		node->package->setNameOfPackage(name);

		/*int size = strlen(name) + 1;
		node->package->name = (char*)malloc(size);
		strcpy_s(node->package->name, size, name);*/

		warehouse_size_++;
		displayed_warehouse_++;
	}
	else node->package->addBatch(batch);

	node->is_empty = false;
}

float Warehouse::sellGoods(char* name, int* quantity)
{
	NodeWithPachage* node = head_;

	float sum = -1;

	while (node != NULL && strcmp(name, node->package->getName()) != 0)
		node = node->next;

	if (node != NULL && node->is_empty == false)
	{
		sum = node->package->sellGoods(quantity);

		if (node->package->getSize() == 0)
		{
			node->is_empty = true;
			displayed_warehouse_--;
		}
	}
	return sum;
}

float Warehouse::sellGoods(const char name[], int* quantity)
{
	NodeWithPachage* node = head_;

	float sum = -1;

	while (node != NULL && strcmp(name, node->package->getName()) != 0)
		node = node->next;

	if (node != NULL && node->is_empty == false)
	{
		sum = node->package->sellGoods(quantity);

		if (node->package->getSize() == 0)
		{
			node->is_empty = true;
			displayed_warehouse_--;
		}
	}
	return sum;
}