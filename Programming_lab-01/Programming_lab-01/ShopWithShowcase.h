#pragma once
#include "Shop.h"

class ShopWithShowcase : public Shop
{
private:

	int showcase_level_;

public:
	ShopWithShowcase() : Shop()
	{
		showcase_level_ = 0;
	}

	ShopWithShowcase(int showcase_level) : Shop()
	{
		showcase_level_ = showcase_level;
	}

	bool investInShowcase(float investment_amount)
	{
		if (cash_ >= investment_amount && investment_amount > 0)
		{
			cash_ -= investment_amount;
			showcase_level_ = (int)(showcase_level_ / 10 + (investment_amount / 1000) + log10(investment_amount));
			return true;
		}
		return false;
	}

	int getShowcaseLevel()
	{
		return showcase_level_;
	}

	void setMargin(unsigned percent)
	{
		margin_ = 1 + (float(percent) + showcase_level_) / 100;
		std::cout << "It's ShopWithShowcase\n";
	}

	/*void setMargin(unsigned percent)
	{
		Shop::setMargin(percent + showcase_level_);
	}*/

	ShopWithShowcase& operator=(Shop shop)
	{
		this->setNameOfShop(shop.getName());
		this->setMargin(shop.getMargin());
		this->setWarehouse(shop.getWarehouse());
		this->setContractWithSupplier(shop.getContractWithSupplier());		
		return *this;
	}

	std::ostream& operator<<(std::ostream& out)
	{
		NodeWithPachage* node = getWarehouse().getHead();

		std::string str = "\n\n*** " + getName() + " ***\n" + "|cash: " + std::to_string(cash_);

		while (node != NULL)
		{
			if (node->is_empty_ == false)
				str += node->package_->getPackageAsCharArray();
			node = node->next_;
		}
		return out << str;
	}

};

class C : protected ShopWithShowcase
{
	C()
	{
		cash_ = 0;
		setNameOfShop("");
	}
};

