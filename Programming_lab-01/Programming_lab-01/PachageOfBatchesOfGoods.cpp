
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

	NodeWithBatch* node = (NodeWithBatch*)malloc(sizeof(NodeWithBatch));/////////////////////////////

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

void PackageOfBatchesOfGoods::setNameOfPackage(PackageOfBatchesOfGoods* p, char* name)
{
	int size = strlen(name) + 1;
	p->name = (char*)malloc(size);
	strcpy_s(p->name, size, name);
}

char* PackageOfBatchesOfGoods::getPackageAsCharArray(PackageOfBatchesOfGoods* package)
{
	int n = package->package_size;

	char** lines = (char**)malloc(n * sizeof(char*));
	char* str;
	int size_str = 2 * 22 + strlen(package->name) + 12;

	NodeWithBatch* node = package->head;
	for (int i = 0; i < n; i++)
	{
		lines[i] = node->batch->getBatchAsCharArray_WithoutName(3);
		size_str += strlen(lines[i]);
		node = node->next;
	}

	str = (char*)malloc(size_str * sizeof(char));

	strcpy_s(str, size_str, "\n=====================\n");
	strcat_s(str, size_str, " ");
	strcat_s(str, size_str, package->name);
	strcat_s(str, size_str, "\n=====================");

	for (int i = 0; i < n; i++)
	{
		strcat_s(str, size_str, lines[i]);
		free(lines[i]);
	}
	free(lines);
	return str;
}

bool PackageOfBatchesOfGoods::delNode(PackageOfBatchesOfGoods* package, NodeWithBatch* node)
{
	if (node != NULL)
	{
		if (node == package->head)
			package->head = node->next;
		else node->prev->next = node->next;
		if (node == package->tail)
			package->tail = node->prev;
		else node->next->prev = node->prev;

		free(node);

		package->package_size--;

		return true;
	}
	else return false;
}

NodeWithBatch* PackageOfBatchesOfGoods::findNode(PackageOfBatchesOfGoods* package, int id)
{
	NodeWithBatch* node = NULL;
	NodeWithBatch* current = package->head;

	while (current != NULL && node != NULL)
		if (current->batch->getID() == id) node = current;
	return node;
}

float PackageOfBatchesOfGoods::sellProduct(PackageOfBatchesOfGoods* package, int id)
{
	NodeWithBatch* node = findNode(package, id);

	float sum = 0;

	if (node != NULL)
	{
		node->batch->reduceQuantityOfGoods(1);
		sum = node->batch->getPrice();
		if (node->batch->getQuantity() == 0) delNode(package, node);
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

float PackageOfBatchesOfGoods::sellGoods(PackageOfBatchesOfGoods* package, int* quantity)
{
	float sum = 0;

	NodeWithBatch* node = package->head;
	NodeWithBatch* buff;

	while (node != NULL && *quantity > 0)
	{
		sum += sellGoods(node, quantity);

		if (node->batch->getQuantity() == 0)
		{
			buff = node;
			node = node->next;
			delNode(package, buff);
		}
		else node = node->next;
	}
	return sum;
}

int PackageOfBatchesOfGoods::countGoods(PackageOfBatchesOfGoods* p)
{
	NodeWithBatch* node = p->head;

	int count = 0;
	while (node != NULL)
	{
		count += node->batch->getQuantity();
		node = node->next;
	}
	return count;
}

void PackageOfBatchesOfGoods::printPackageAsCharArray(PackageOfBatchesOfGoods* package)
{
	int n = package->package_size;
	NodeWithBatch* current = package->head;
	for (int i = 0; i < n; i++)
	{
		std::cout << current->batch->getBatchAsCharArray(0) << std::endl;
		current = current->next;
	}
}
