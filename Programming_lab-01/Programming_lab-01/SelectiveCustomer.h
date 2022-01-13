#pragma once

#include "ShopWithShowcase.h"
#include <list>

class SelectiveCustomer
{
private:
	std::list<ShopWithShowcase*> shop_in_mind_;

	//bool comp(ShopWithShowcase* a, ShopWithShowcase* b);

public:
	void rememberShop(ShopWithShowcase* shop);

	int buyGoods(std::string name, const int q);

	
};

