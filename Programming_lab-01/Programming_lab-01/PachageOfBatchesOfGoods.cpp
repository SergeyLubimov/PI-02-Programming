
#include "PackageOfBatchesOfGoods.h"

PackageOfBatchesOfGoods::PackageOfBatchesOfGoods()
{
	name_ = "";
	head_ = NULL;
	tail_ = NULL;
	package_size_ = 0;
}

PackageOfBatchesOfGoods::~PackageOfBatchesOfGoods()
{
	NodeWithBatch *buff, *node = head_;
	while (node != NULL)
	{
		buff = node;
		node = node->next_;
		delete buff;
	}
}

void PackageOfBatchesOfGoods::addBatch(BatchOfGoods* batch)
{
	int sum = convertDateToDays(batch->getDate());

	NodeWithBatch* node = new NodeWithBatch();

	node->batch_ = batch;
	node->sumDays_ = sum;

	if (package_size_ == 0)
	{
		head_ = tail_ = node;
		node->prev_ = node->next_ = NULL;
	}
	else
	{
		if (head_->sumDays_ >= sum)
		{
			node->next_ = head_;
			head_->prev_ = node;
			head_ = node;
			node->prev_ = NULL;
		}
		else
		{
			if (tail_->sumDays_ <= sum)
			{
				tail_->next_ = node;
				node->prev_ = tail_;
				tail_ = node;
				node->next_ = NULL;
			}
			else
			{
				NodeWithBatch* current;
				for (current = head_; current->next_->sumDays_ < sum;
					current = current->next_);

				node->next_ = current->next_;
				current->next_ = node;

				node->prev_ = current;
				node->next_->prev_ = node;
			}
		}
	}
	package_size_++;
}

void PackageOfBatchesOfGoods::setNameOfPackage(std::string name)
{	
	name_ = name;
}

std::string PackageOfBatchesOfGoods::getName()
{
	return name_;
}

int PackageOfBatchesOfGoods::getSize()
{
	return package_size_;
}

std::string PackageOfBatchesOfGoods::getPackageAsCharArray()
{
	int n = package_size_;

	std::string *lines = new std::string[n];
	std::string str;

	NodeWithBatch* node = head_;
	for (int i = 0; i < n; i++)
	{
		lines[i] = node->batch_->getBatchAsCharArray_WithoutName(3);		
		node = node->next_;
	}

	/*str = new char[size_str];*/

	str += "\n=====================\n ";
	//strcat_s(str, size_str, " ");
	str += name_;
	str += "\n=====================";

	for (int i = 0; i < n; i++)
	{
		str += lines[i];
	}
	//delete lines;
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
			head_ = node->next_;
		else node->prev_->next_ = node->next_;
		if (node == tail_)
			tail_ = node->prev_;
		else node->next_->prev_ = node->prev_;

		delete node;

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
		if (current->batch_->getID() == id) node = current;
	return node;
}

float PackageOfBatchesOfGoods::sellProduct(int id)
{
	NodeWithBatch* node = findNode(id);

	float sum = 0;

	if (node != NULL)
	{
		node->batch_->reduceQuantityOfGoods(1);
		sum = node->batch_->getPrice();
		if (node->batch_->getQuantity() == 0) delNode(node);
	}
	return sum;
}

float PackageOfBatchesOfGoods::sellGoods(NodeWithBatch* node, int* quantity)
{
	float sum = 0;

	if (node != NULL)
	{
		int q = *quantity;
		if (q > node->batch_->getQuantity())
		{
			q = node->batch_->getQuantity();
			*quantity -= q;
			node->batch_->resetQuantityOfGoods();
		}
		else
		{
			node->batch_->reduceQuantityOfGoods(q);
			*quantity = 0;
		}
		sum = q * node->batch_->getPrice();
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

		if (node->batch_->getQuantity() == 0)
		{
			buff = node;
			node = node->next_;
			delNode(buff);
		}
		else node = node->next_;
	}
	return sum;
}

float PackageOfBatchesOfGoods::sellGoods(NodeWithBatch *node, int &quantity)
{
	float sum = 0;

	if (node != NULL)
	{
		int q = quantity;
		if (q > node->batch_->getQuantity())
		{
			q = node->batch_->getQuantity();
			quantity -= q;
			node->batch_->resetQuantityOfGoods();
		}
		else
		{
			node->batch_->reduceQuantityOfGoods(q);
			quantity = 0;
		}
		sum = q * node->batch_->getPrice();
	}
	return sum;
}

float PackageOfBatchesOfGoods::sellGoods(int &quantity)
{
	float sum = 0;

	NodeWithBatch* node = head_;
	NodeWithBatch* buff;

	while (node != NULL && quantity > 0)
	{
		sum += sellGoods(node, quantity);

		if (node->batch_->getQuantity() == 0)
		{
			buff = node;
			node = node->next_;
			delNode(buff);
		}
		else node = node->next_;
	}
	return sum;
}

int PackageOfBatchesOfGoods::countGoods()
{
	NodeWithBatch* node = head_;

	int count = 0;
	while (node != NULL)
	{
		count += node->batch_->getQuantity();
		node = node->next_;
	}
	return count;
}

void PackageOfBatchesOfGoods::printPackageAsCharArray()
{
	int n = package_size_;
	NodeWithBatch* current = head_;
	for (int i = 0; i < n; i++)
	{
		std::cout << current->batch_->getBatchAsCharArray(0) << std::endl;
		current = current->next_;
	}
}

NodeWithBatch::NodeWithBatch()
{
	batch_ = NULL;
	next_ = NULL;
	prev_ = NULL;
	sumDays_ = 0;
}

NodeWithBatch::~NodeWithBatch()
{
	batch_ = NULL;
}
