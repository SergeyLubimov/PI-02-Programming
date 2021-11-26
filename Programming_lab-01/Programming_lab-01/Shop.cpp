
#include "Shop.h"

bool setNameOfShop(Shop* shop, char* name)
{
	int size_str = strlen(name) + 1;
	if (name != 0)
	{
		if (shop->name == 0) free(shop->name);

		shop->name = (char*)malloc(size_str);
		strcpy_s(shop->name, size_str, name);

		return true;
	}
	else false;
}

bool setNameOfShop(Shop* shop, const char s[])
{
	int size_str = strlen(s) + 1;
	if (s != 0)
	{
		if (shop->name == 0) free(shop->name);
		shop->name = (char*)malloc(size_str);
		strcpy_s(shop->name, size_str, s);
		return true;
	}
	return false;
}

void addBatch(Shop* shop, BatchOfGoods* batch)
{
	addBatch(&shop->warehouse, batch);
}


bool sellGoods(Shop* shop, char* name, int* q)
{
	NodeWithPachage* node = shop->warehouse.head;

	bool ret = false;

	while (node != NULL && strcmp(node->package->name, name) != 0)
		node = node->next;

	if (node != NULL && node->is_empty == false)
	{
		shop->cash += sellGoods(node->package, q);
		ret = true;
	}
	return ret;
}

void displayAssortment(Shop shop)
{
	NodeWithPachage* node = shop.warehouse.head;

	std::cout << "\n\n*** " << shop.name << " ***";

	while (node != NULL)
	{
		if (node->is_empty == false)
		{
			std::cout << getPackageAsCharArray(node->package);
			node = node->next;
		}
	}
}