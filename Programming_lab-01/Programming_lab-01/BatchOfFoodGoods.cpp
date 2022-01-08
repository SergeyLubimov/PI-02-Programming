#include "BatchOfFoodGoods.h"


BatchOfFoodGoods::BatchOfFoodGoods(int period_in_days) : BatchOfGoods()
{
	while (period_in_days > 0)
	{
		expiration_date_++;
		period_in_days--;
	}
}

//void BatchOfFoodGoods::func()
//{
//	//name_;
//	setNameOfGoods("Name");
//}

void BatchOfFoodGoods::checkingFreshness()
{
	Date date = getDate();

	int difference = expiration_date_.getYear() - date.getYear();

	if (difference == 0)
	{
		difference = expiration_date_.getMonht() - date.getMonht();
		if (difference == 0)
			difference = expiration_date_.getDay() - date.getDay();
	}
	if (difference <= 0) price_ = 0;
}

std::string BatchOfFoodGoods::getBatchAsCharArray(int n)
{
	checkingFreshness();
	return getBatchAsCharArray(n);
}

//std::string BatchOfFoodGoods::getBatchAsCharArray(int n)
//{
//	checkingFreshness();
//	
//	std::string indent = "\n";
//
//	for (int i = 1; i <= n; i++) indent += " ";
//
//	std::string name, ID, price, quantity, date;
//
//	name = getName();
//	ID = getIdOfGoodsAsCharArray();
//	price = std::to_string(price_);
//	quantity = std::to_string(getQuantity());
//	date = getDate().getDateAsCharArray();
//
//	std::string str;
//
//	str += indent + "Name: " + name;
//	str += indent + "ID: " + ID;
//	str += indent + "Price: " + price;
//	str += indent + "Quantity: " + quantity;
//	str += indent + "Date: " + date;
//
//	return str;
//}