#pragma once

#include <list>
#include <string>
#include "Shop.h"



class Customer
{
private:
	std::list<Shop*> shop_in_mind_;

public:
	void rememberShop(Shop* shop)
	{
		shop_in_mind_.push_back(shop);
	}

	int buyGoods(char *name, const int q)
	{
		int Q = q;

		std::list<Shop*>::iterator it = shop_in_mind_.begin();
		it++;
				
		while (Q > 0 && it != shop_in_mind_.end())
		{
			(*it)->sellGoods(name, &Q);
			it++;
		}
		return Q;
	}

	int buyGoods(const char name[], const int q)
	{
		int Q = q;

		std::list<Shop*>::iterator it = shop_in_mind_.begin();

		while (Q > 0 && it != shop_in_mind_.end())
		{
			(*it)->sellGoods(name, &Q);
			it++;
		}
		return Q;
	}




};

