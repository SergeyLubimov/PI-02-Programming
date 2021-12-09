
#include "PackageOfBatchesOfGoods.h"

PackageOfBatchesOfGoods::PackageOfBatchesOfGoods()
{
	name_ = NULL;
	head_ = NULL;
	tail_ = NULL;
	package_size_ = 0;
}

void PackageOfBatchesOfGoods::addBatch(BatchOfGoods* batch)
{
	int sum = convertDateToDays(batch->getDate());

	NodeWithBatch* node = new NodeWithBatch();

	node->batch = batch;
	node->sumDays = sum;

	if (package_size_ == 0)
	{
		head_ = tail_ = node;
		node->prev = node->next = NULL;
	}
	else
	{
		if (head_->sumDays >= sum)
		{
			node->next = head_;
			head_->prev = node;
			head_ = node;
			node->prev = NULL;
		}
		else
		{
			if (tail_->sumDays <= sum)
			{
				tail_->next = node;
				node->prev = tail_;
				tail_ = node;
				node->next = NULL;
			}
			else
			{
				NodeWithBatch* current;
				for (current = head_; current->next->sumDays < sum;
					current = current->next);

				node->next = current->next;
				current->next = node;

				node->prev = current;
				node->next->prev = node;
			}
		}
	}
	package_size_++;
}

void PackageOfBatchesOfGoods::setNameOfPackage(char* name)
{
	int size = strlen(name) + 1;

	name_ = new char[size];
	strcpy_s(name_, size, name);
}

char* PackageOfBatchesOfGoods::getName()
{
	return name_;
}

int PackageOfBatchesOfGoods::getSize()
{
	return package_size_;
}

char* PackageOfBatchesOfGoods::getPackageAsCharArray()
{
	int n = package_size_;

	char** lines = new char* [n];
	char* str;
	int size_str = 2 * 22 + strlen(name_) + 12;

	NodeWithBatch* node = head_;
	for (int i = 0; i < n; i++)
	{
		lines[i] = node->batch->getBatchAsCharArray_WithoutName(3);
		size_str += strlen(lines[i]);
		node = node->next;
	}

	str = new char[size_str];

	strcpy_s(str, size_str, "\n=====================\n");
	strcat_s(str, size_str, " ");
	strcat_s(str, size_str, name_);
	strcat_s(str, size_str, "\n=====================");

	for (int i = 0; i < n; i++)
	{
		strcat_s(str, size_str, lines[i]);
		delete lines[i];
	}
	delete lines;
	return str;
}

int PackageOfBatchesOfGoods::reducePackageSize(int n)
{
	package_size_ -= n;
	return package_size_;
}

void PackageOfBatchesOfGoods::resetPackageSize()
{
	package_size_ = 0;
}

bool PackageOfBatchesOfGoods::delNode(NodeWithBatch* node)
{
	if (node != NULL)
	{
		if (node == head_)
			head_ = node->next;
		else node->prev->next = node->next;
		if (node == tail_)
			tail_ = node->prev;
		else node->next->prev = node->prev;

		free(node);

		package_size_--;

		return true;
	}
	else return false;
}

NodeWithBatch* PackageOfBatchesOfGoods::findNode(int id)
{
	NodeWithBatch* node = NULL;
	NodeWithBatch* current = head_;

	while (current != NULL && node != NULL)
		if (current->batch->getID() == id) node = current;
	return node;
}

float PackageOfBatchesOfGoods::sellProduct(int id)
{
	NodeWithBatch* node = findNode(id);

	float sum = 0;

	if (node != NULL)
	{
		node->batch->reduceQuantityOfGoods(1);
		sum = node->batch->getPrice();
		if (node->batch->getQuantity() == 0) delNode(node);
	}
	return sum;
}

float PackageOfBatchesOfGoods::sellGoods(NodeWithBatch* node, int* quantity)
{
	float sum = 0;

	if (node != NULL)
	{
		int q = *quantity;
		if (q > node->batch->getQuantity())
		{
			q = node->batch->getQuantity();
			*quantity -= q;
			node->batch->resetQuantityOfGoods();
		}
		else
		{
			node->batch->reduceQuantityOfGoods(q);
			*quantity = 0;
		}
		sum = q * node->batch->getPrice();
	}
	return sum;
}

float PackageOfBatchesOfGoods::sellGoods(int* quantity)
{
	float sum = 0;

	NodeWithBatch* node = head_;
	NodeWithBatch* buff;

	while (node != NULL && *quantity > 0)
	{
		sum += sellGoods(node, quantity);

		if (node->batch->getQuantity() == 0)
		{
			buff = node;
			node = node->next;
			delNode(buff);
		}
		else node = node->next;
	}
	return sum;
}

int PackageOfBatchesOfGoods::countGoods()
{
	NodeWithBatch* node = head_;

	int count = 0;
	while (node != NULL)
	{
		count += node->batch->getQuantity();
		node = node->next;
	}
	return count;
}

void PackageOfBatchesOfGoods::printPackageAsCharArray()
{
	int n = package_size_;
	NodeWithBatch* current = head_;
	for (int i = 0; i < n; i++)
	{
		std::cout << current->batch->getBatchAsCharArray(0) << std::endl;
		current = current->next;
	}
}
