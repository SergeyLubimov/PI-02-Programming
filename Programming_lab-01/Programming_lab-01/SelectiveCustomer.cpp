#include "SelectiveCustomer.h"

void SelectiveCustomer::rememberShop(ShopWithShowcase* shop)
{
	shop_in_mind_.push_back(shop);
}

bool comp(ShopWithShowcase* a, ShopWithShowcase* b)
{
	return a->getShowcaseLevel() > b->getShowcaseLevel();
}

int SelectiveCustomer::buyGoods(std::string name, const int q)
{
	int Q = q;

	shop_in_mind_.sort(&comp);

	std::list<ShopWithShowcase*>::iterator it = shop_in_mind_.begin();

	while (Q > 0 && it != shop_in_mind_.end())
	{
		(*it)->sellGoods(name, &Q);
		it++;
	}
	return Q;
}
