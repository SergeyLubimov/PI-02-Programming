#pragma once

#include <list>
#include <string>
#include "Shop.h"


class Customer
{
private:
	std::list<Shop*> shop_in_mind_;

public:
	void rememberShop(Shop* shop);

	int buyGoods(char* name, const int q);

	int buyGoods(const char name[], const int q);
};

