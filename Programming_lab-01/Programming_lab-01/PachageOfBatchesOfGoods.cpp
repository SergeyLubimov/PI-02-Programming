
#include "PackageOfBatchesOfGoods.h"

void init(PackageOfBatchesOfGoods *p)
{
	p->name = NULL;
	p->head = NULL;
	p->tail = NULL;
	p->package_size = 0;
}

void addBatch(PackageOfBatchesOfGoods* package, BatchOfGoods* batch)
{
	int sum = convertDateToDays(batch->date);

	NodeWithBatch* node = (NodeWithBatch*)malloc(sizeof(NodeWithBatch));

	node->batch = batch;
	node->sumDays = sum;

	if (package->package_size == 0)
	{
		package->head = package->tail = node;
		node->prev = node->next = NULL;
	}
	else
	{
		if (package->head->sumDays >= sum)
		{
			node->next = package->head;
			package->head->prev = node;
			package->head = node;
			node->prev = NULL;
		}
		else
		{
			if (package->tail->sumDays <= sum)
			{
				package->tail->next = node;
				node->prev = package->tail;
				package->tail = node;
				node->next = NULL;
			}
			else
			{
				NodeWithBatch* current;
				for (current = package->head; current->next->sumDays < sum;
					current = current->next);

				node->next = current->next;
				current->next = node;

				node->prev = current;
				node->next->prev = node;
			}
		}
	}

	if (node->prev == NULL)
	{
		int a = 2 + 2;
	}

	package->package_size++;
}

void setNameOfPackage(PackageOfBatchesOfGoods* p, char* name)
{
	int size = strlen(name) + 1;
	p->name = (char*)malloc(size);
	strcpy_s(p->name, size, name);
}

char* getPackageAsCharArray(PackageOfBatchesOfGoods* package)
{
	int n = package->package_size;

	char** lines = (char**)malloc(n * sizeof(char*));
	char* str;
	int size_str = 2 * 22 + strlen(package->name) + 12;

	NodeWithBatch* node = package->head;
	for (int i = 0; i < n; i++)
	{
		lines[i] = getBatchAsCharArray_WithoutName(*(node->batch), 3);
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

bool delNode(PackageOfBatchesOfGoods* package, NodeWithBatch* node)
{
	if (node != NULL)
	{
		if (node == package->head)
			package->head = node->next;
		else node->prev->next = node->next;
		if (node == package->tail)
			package->tail = node->prev;
		else node->next->prev = node->prev;;

		deleteBatch(node->batch);
		free(node);

		package->package_size--;

		return true;
	}
	else return false;
}

NodeWithBatch* findNode(PackageOfBatchesOfGoods* package, int id)
{
	NodeWithBatch* node = NULL;
	NodeWithBatch* current = package->head;

	while (current != NULL && node != NULL)
		if (current->batch->ID == id) node = current;
	return node;
}

float sellProduct(PackageOfBatchesOfGoods* package, int id)
{
	NodeWithBatch* node = findNode(package, id);

	float sum = 0;

	if (node != NULL)
	{
		node->batch->quantity--;
		sum = node->batch->price;
		if (node->batch->quantity == 0) delNode(package, node);
	}
	return sum;
}

float sellGoods(NodeWithBatch* node, int* quantity)
{
	float sum = 0;

	if (node != NULL)
	{
		int q = *quantity;
		if (q > node->batch->quantity)
		{
			q = node->batch->quantity;
			*quantity -= q;
			node->batch->quantity = 0;
		}
		else
		{
			node->batch->quantity -= q;
			*quantity = 0;
		}
		sum = q * node->batch->price;
	}
	return sum;
}

float sellGoods(PackageOfBatchesOfGoods* package, int* quantity)
{
	float sum = 0;

	NodeWithBatch* node = package->head;
	NodeWithBatch* buff;

	while (node != NULL && *quantity > 0)
	{
		sum += sellGoods(node, quantity);

		if (node->batch->quantity == 0)
		{
			buff = node;
			node = node->next;
			delNode(package, buff);
		}
		else node = node->next;
	}
	return sum;
}

int countGoods(PackageOfBatchesOfGoods* p)
{
	NodeWithBatch* node = p->head;

	int count = 0;
	while (node != NULL)
	{
		count += node->batch->quantity;
		node = node->next;
	}
	return count;
}

void printPackageAsCharArray(PackageOfBatchesOfGoods* package)
{
	int n = package->package_size;
	NodeWithBatch* current = package->head;
	for (int i = 0; i < n; i++)
	{
		std::cout << getBatchAsCharArray(*(current->batch), 0) << std::endl;
		current = current->next;
	}
}
