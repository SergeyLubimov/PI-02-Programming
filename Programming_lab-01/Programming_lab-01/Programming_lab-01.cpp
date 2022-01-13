//Programming_lab-01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "SupplierOfGoods.h"
#include "ShopWithShowcase.h"
#include "SelectiveCustomer.h"
#include "Customer.h"
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;


class A
{
public: 

	string str_;
	Date* date_;

	A()
	{
		str_ = "";
		date_ = new Date();
	}
	A(A& source)
	{
		delete this->date_;

		this->str_ = source.str_;

		if (source.date_ != NULL)
			this->date_ = new Date(source.date_->getDay(), 
				source.date_->getMonht(), source.date_->getYear());

		else this->date_ = nullptr;
	}

	A& operator=(const A& source)
	{		
		if (this != &source)
		{
			delete this->date_;

			this->str_ = source.str_;

			if (source.date_ != NULL)
				this->date_ = new Date(source.date_->getDay(),
					source.date_->getMonht(), source.date_->getYear());

			else this->date_ = nullptr;
		}

		return *this;
	}
};


int main()
{ 
	Shop* sh1, * sh2;

	sh1 = new Shop();
	ShopWithShowcase* sws = new ShopWithShowcase();

	sh2 = sws;

	sh1->setMargin(10);
	sh2->setMargin(10);





	BatchOfGoods* batch1, *batch2, *batch3;

	batch1 = new BatchOfGoods("A", 54654, 10, 100, *(new Date(20, 1, 2020)));
	batch2 = new BatchOfGoods("A", 5670054, 10, 100, *(new Date(2, 10, 2002)));
	batch3 = new BatchOfGoods("A", 54654, 10, 100, *(new Date(11, 1, 1996)));

	ShopWithShowcase shop1 = ShopWithShowcase();
	ShopWithShowcase shop2 = ShopWithShowcase();
	ShopWithShowcase shop3 = ShopWithShowcase();

	shop1.setNameOfShop("Shop A");
	shop2.setNameOfShop("Shop B");
	shop3.setNameOfShop("Shop C");	

	shop1.investMoney(20000);
	shop2.investMoney(20000);
	shop3.investMoney(20000);

	shop1 << cout;

	shop1.investInShowcase(10000);
	shop2.investInShowcase(20000);
	shop3.investInShowcase(10000);
	shop3.investInShowcase(10000);

	shop1.addBatch(batch1);
	shop2.addBatch(batch2);
	shop3.addBatch(batch3);

	shop1.setMargin(10);

	SelectiveCustomer customer;

	customer.rememberShop(&shop1);
	customer.rememberShop(&shop2);
	customer.rememberShop(&shop3);

	customer.buyGoods("A", 150);

	shop1.displayAssortment();
	shop2.displayAssortment();
	shop3.displayAssortment();
	
}
