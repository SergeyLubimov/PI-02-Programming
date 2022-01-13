#pragma once
#include "SupplierOfGoods.h"

class SupplierOfBook : private SupplierOfGoods
{
	bool SupplierOfGoods::acceptOrder(Shop* contact, std::string name, int quantity)
	{
		if (name.compare(0, 5, "Book:") == 0)
			return SupplierOfGoods::acceptOrder(contact, name, quantity);
		return false;
	}
};

