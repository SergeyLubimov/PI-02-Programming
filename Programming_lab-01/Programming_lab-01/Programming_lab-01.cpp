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
	BatchOfGoods batch;

	batch.setPriceOfGoods(-200);	
}
