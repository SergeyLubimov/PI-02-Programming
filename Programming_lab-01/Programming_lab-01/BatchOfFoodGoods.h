#pragma once

#include "BatchOfGoods.h"

class BatchOfFoodGoods: protected BatchOfGoods
{
private:
	Date expiration_date_;

public:

	BatchOfFoodGoods() : BatchOfGoods() 
	{
		expiration_date_ = getDate();
	}
	
	BatchOfFoodGoods(int period_in_days);

	void checkingFreshness();
	std::string getBatchAsCharArray(int n);

	//void func();

	BatchOfFoodGoods& operator=(BatchOfGoods& source)
	{
		if (this != &source)
		{
			this->setNameOfGoods(source.getName());
			this->setIdOfGood(source.getID());
			price_ = source.getPrice();
			this->setQuantityOfGoods(source.getQuantity());

			
		}

		return *this;
	}
};

class C : protected BatchOfFoodGoods
{
public:
	C() : BatchOfFoodGoods() {};
	/*void func()
	{
		name_;
		expiration_date_;
		setNameOfGoods("Name");
	}*/
};

