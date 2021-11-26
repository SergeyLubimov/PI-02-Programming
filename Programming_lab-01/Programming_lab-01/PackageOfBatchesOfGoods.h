#pragma once

#include "BatchOfGoods.h"

//struct  Node
//{
//	BatchOfGoods* batch = NULL;
//	int v;
//	Node* next;
//};
//
//struct  PackageOfBatchesOfGoods
//{
//	Node *head = NULL;
//
//};
//
//void addNode(PackageOfBatchesOfGoods* package, BatchOfGoods *batch)
//{
//	Node* node = (Node*)malloc(sizeof(Node));
//	//node->v = a;
//
//	node->batch = batch;
//
//	node->next = package->head;
//	package->head = node;
// }
//
//void print(PackageOfBatchesOfGoods *pachage)
//{
//	Node* node = pachage->head;
//
//	while (node != NULL)
//	{
//		std::cout << getBatchAsCharArray(*(node->batch), 2) << std::endl;
//		node = node->next;
//	}
//}


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

//void init(NodeWithBatch* node)
//{
//	node->batch = NULL;
//	node->next = NULL;
//	node->prev = NULL;
//	int sumDays = 0;
//}
//
//void init(PackageOfBatchesOfGoods* p)
//{
//	p->name = NULL;
//	p->head = NULL;
//	p->tail = NULL;
//	p->package_size = 0;
//}

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



//PackageOfBatchesOfGoods* packBatch(BatchOfGoods *batch)
//{
//	PackageOfBatchesOfGoods* package = (PackageOfBatchesOfGoods*)malloc(1);
//
//	NodeWithBatch *ptr =  package->head = package->tail = (NodeWithBatch*)malloc(1);
//	
//	ptr->batch = batch;
//	ptr->prev = ptr->next = 0;
//	ptr->sumDays = convertDateToDays(ptr->batch->date);
//
//	package->package_size = 1;
//
//	int size = strlen(batch->name) + 1;
//
//	package->name = (char*)malloc(size);
//	strcpy_s(package->name, size, batch->name);
//
//	return package;
//}
//
////NodeWithBatch** takeStep(int sum, NodeWithBatch** ptr)
////{
////	/*if (*ptr != 0 && (*ptr)->sumDays > sum)
////	{
////		ptr = takeStep(sum, &((*ptr)->next));
////	}
////	return ptr;*/
////}
//
//NodeWithBatch* addNodeAfterCurrent(NodeWithBatch * current_node)
//{
//	NodeWithBatch* new_node = (NodeWithBatch*)malloc(1);
//
//	new_node->next = current_node->next;
//	new_node->prev = current_node;
//	current_node->next = new_node;
//
//	return new_node;
//}
//
//NodeWithBatch* addNodeBeforeCurrent(NodeWithBatch* current_node)
//{
//	NodeWithBatch* new_node = (NodeWithBatch*)malloc(1);
//
//	new_node->prev = current_node->prev;
//	new_node->next = current_node;
//	current_node->prev = new_node;
//
//	return new_node;
//}
//
//void addBatch(PackageOfBatchesOfGoods* package, BatchOfGoods *batch)
//{
//	int sum = convertDateToDays(batch->date);
//
//	NodeWithBatch* node;
//
//	if (package->head != NULL)
//	{
//		if (package->tail->sumDays <= sum) 
//			package->tail = node = addNodeAfterCurrent(package->tail);	
//
//		else
//		{
//			node = package->head;
//			while (node->sumDays < sum) node = node->next;
//
//			if (node == package->head)		
//				package->head = node = addNodeBeforeCurrent(node);
//
//			else node = addNodeBeforeCurrent(node);
//		}
//	}
//	else
//	{
//		node = package->head = package->tail = (NodeWithBatch*)malloc(1);
//		node->next = NULL;
//		node->prev = NULL;
//	}
//	node->batch = batch;
//	node->sumDays = sum;
//
//	package->package_size++;
//}
//
//NodeWithBatch* findNodeByBatchId(NodeWithBatch *start_node, int id)
//{
//	while (start_node > NULL && start_node->batch->ID != id) start_node = start_node->next;
//	return start_node;
//}
//
//NodeWithBatch* findNodeBySumDaysOfBatch(NodeWithBatch* start_node, int sum)
//{
//	while (start_node > NULL && start_node->sumDays != sum) start_node = start_node->next;
//	return start_node;
//}
//
//void deleteNode(NodeWithBatch *node)
//{
//	NodeWithBatch* next, * prev;
//	next = node->next;
//	prev = node->prev;
//
//	if (next != prev)
//	{
//		if (next != NULL) next->prev = prev;
//		if (prev != NULL) prev->next = next;
//	}
//	deleteBatch(node->batch);
//	free(node);
//}
//
//char* getPackageAsCharArray(PackageOfBatchesOfGoods* package, int n)
//{
//	char* str;
//
//	int str_size = strlen(package->name) + 1;
//
//	return 0;
//}
//
////char* getPackageAsCharArray(PackageOfBatchesOfGoods package, int n)
////{
////	char* indent = (char*)malloc(n + 2);
////
////	char frame[] = "===================";
////
////	indent[0] = '\n';
////	for (int i = 1; i <= n; i++) indent[i] = ' ';
////	indent[n + 1] = '\0';
////
////	int str_size = 3 * (n + 2) + 2 * strlen(frame) + strlen(package.name) + 2;
////
////	NodeWithBatch* node = package.head;
////
////	int size = package.package_size;
////
////	char** lines = (char**)malloc(size);
////
////	for(int i = 0; i < size; i++)
////	{
////		lines[i] = getBatchAsCharArray_WithoutName(*(node->batch), n);
////		str_size += strlen(lines[i]);
////	}
////
////	char* str = (char*)malloc(str_size);
////
////	strcpy_s(str, str_size, indent);
////	strcat_s(str, str_size, frame);
////	strcat_s(str, str_size, indent);
////	strcat_s(str, str_size, "| ");
////	strcat_s(str, str_size, package.name);
////	strcat_s(str, str_size, indent);
////	strcat_s(str, str_size, frame);
////
////	for (int i = 0; i < size; i++) 
////		strcat_s(str, str_size, lines[i]);
////
////	return str;
////}


