//Programming_lab-01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "SupplierOfGoods.h"
#include "BatchOfFoodGoods.h"
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
	/*Date d, d2;

	d.setDate(20, 2, 2003);

	cout << d.getDateAsCharArray();

	d2 = d;

	d2.setDate(1, 1, 1999);

	cout << d.getDateAsCharArray();*/


	SupplierOfGoods supplier;

	Shop shopsA[3];

	for (int i = 0; i < 3; i++)
	{
		shopsA[i] = Shop("Shop A" + to_string(i + 1), 20, 10000);
		shopsA[i].signContract(&supplier);
		shopsA[i].makeOrder("A", i + 1);
		cout << shopsA[i].getName() + ' ';
	}
	cout << "\n\n";

	Shop shopsB[3][3];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			shopsB[i][j] = Shop("Shop B" + to_string(i * 3 + j + 1), 20, 10000);
			shopsB[i][j].signContract(&supplier);
			shopsB[i][j].makeOrder("B", i * 3 + j + 1);
			cout << shopsB[i][j].getName() + ' ';
			
		}
		cout << endl;
	}
	supplier.fulfillOrders();

	for (int i = 0; i < 3; i++)
	{
		shopsA[i].redeemOrders();
		shopsA[i].displayAssortment();
		for (int j = 0; j < 3; j++)
		{
			shopsB[i][j].redeemOrders();
			shopsB[i][j].displayAssortment();
		}
	}




}
