//Programming_lab-01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "SupplierOfGoods.h"
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
	Date date1;
	Date date2("10.02.2003");
	Date date3 = Date(10, 2, 2003);
	Date* date4 = new Date();
	Date* date5 = new Date("10.02.2003");;
	Date* date6 = new Date(10, 2, 2003);

	BatchOfGoods batch1;
	BatchOfGoods batch2("Good");
	BatchOfGoods batch3("Good", 8845, 10, 5, date2);
	BatchOfGoods *batch4 = new BatchOfGoods();
	BatchOfGoods *batch5 = new BatchOfGoods("Good");
	BatchOfGoods *batch6 = new BatchOfGoods("Good", 8845, 10, 5, date2);

	PackageOfBatchesOfGoods package1;
	PackageOfBatchesOfGoods package2("Good");
	PackageOfBatchesOfGoods* package3 = new PackageOfBatchesOfGoods();
	PackageOfBatchesOfGoods* package4 = new PackageOfBatchesOfGoods("Good");

	Warehouse warehouse1;
	Warehouse *warehouse2 = new Warehouse();

	Shop shop1;
	Shop shop2("Shop");
	Shop shop3("Good", 20, 10000);
	Shop *shop4 = new Shop();
	Shop *shop5 = new Shop("Shop");
	Shop *shop6 = new Shop("Good", 20, 10000);

	SupplierOfGoods supplier1;
	SupplierOfGoods supplier2(15);
	SupplierOfGoods* supplier3 = new SupplierOfGoods();
	SupplierOfGoods* supplier4 = new SupplierOfGoods(15);

	Date *date[5];

	for (int i = 0; i < 5; i++) 
		date[i] = new Date("10.10.2010");

	A a, copy;

	a.str_ = "Hallo";
	a.date_->setDateAsCharArray("10.10.2002");

	copy = a;

	copy.str_= "Yyyy";
	copy.date_->setDateAsCharArray("01.01.2001");

	cout << a.date_->getDateAsCharArray() << endl << a.str_;

		
}
