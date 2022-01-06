#include "Customer.h"

void Customer::rememberShop(Shop* shop)
{
	shop_in_mind_.push_back(shop);
}

int Customer::buyGoods(std::string name, const int q)
{
	int Q = q;

	std::list<Shop*>::iterator it = shop_in_mind_.begin();
	//it++;

	while (Q > 0 && it != shop_in_mind_.end())
	{
		(*it)->sellGoods(name, &Q);
		it++;
	}
	return Q;
}

//int Customer::buyGoods(const char name[], const int q)
//{
//	int Q = q;
//
//	std::list<Shop*>::iterator it = shop_in_mind_.begin();
//
//	while (Q > 0 && it != shop_in_mind_.end())
//	{
//		(*it)->sellGoods(name, &Q);
//		it++;
//	}
//	return Q;
//}