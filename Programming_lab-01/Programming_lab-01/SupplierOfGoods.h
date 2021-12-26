#pragma once

#include <string>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Shop.h"




class Order
{
private:
	std::list<Shop*>::iterator shop_iterator_;
	std::string name_;
	int quantity_;

public:
	Order(std::list<Shop*>::iterator it, std::string name, int quantity)
	{
		shop_iterator_ = it;
		name_ = name;
		quantity_ = quantity;
	}

	std::list<Shop*>::iterator getShopIteraror()
	{
		return shop_iterator_;
	}

	std::string getName()
	{
		return name_;
	}

	int getQuantity()
	{
		return quantity_;
	}
};

class ReadyOrder
{
private:
	std::list<Shop*>::iterator shop_iterator_;
	BatchOfGoods* batch_;

public:
	ReadyOrder(std::list<Shop*>::iterator shop_iterator, BatchOfGoods* batch)
	{
		shop_iterator_ = shop_iterator;
		batch_ = batch;
	}

	std::list<Shop*>::iterator getShopIterator()
	{
		return shop_iterator_;
	}

	BatchOfGoods* getBatchOfGoods()
	{
		return batch_;
	}
	
};



class SupplierOfGoods
{
private:
	std::list<Shop*> contracts_with_shops_;

	//std::list<std::string*> list_products_;

	float margin_;

	std::list<Order*> orders_;

	std::list<ReadyOrder*> ready_orders_;	

public:

	SupplierOfGoods()
	{
		margin_ = 0;
		
	}

	void addContract(Shop* shop)
	{
		contracts_with_shops_.push_back(shop);
		contracts_with_shops_.unique();		
	}

	/*void addProduct(std::string product)
	{
		list_products_.push_back(new std::string(product));
		contracts_with_shops_.unique();
	}*/

	void setMargin(unsigned percent)
	{
		margin_ = percent / 100;
	}

	bool acceptOrder(Shop* contact, std::string name, int quantity)
	{
		std::list<Shop*>::iterator it1;
		
		
		it1 = std::find(contracts_with_shops_.begin(), contracts_with_shops_.end(), contact);
		//it2 = std::find(list_products_.begin(), list_products_.end(), name);
		
		if (it1 != contracts_with_shops_.end() /*&&
			it2 != list_products_.end()*/)
		{
			orders_.push_back((new Order(it1, name, quantity)));
			return true;
		}
		return false;
	}

	void fulfillOrders()
	{
		Order *buff;
		BatchOfGoods* batch;
		std::string str;
		srand(unsigned(time(0)));

		//time_t rawtime;
		//struct tm* timeinfo;
		//char data[80];                                // строка, в которой будет храниться текущее время

		//time(&rawtime);                               // текущая дата в секундах
		//timeinfo = localtime(&rawtime);               // текущее локальное время, представленное в структуре

		//strftime(data, 80, "Сейчас %I:%M%p.", timeinfo);

		time_t rawtime;
		struct tm timeinfo;
		time(&rawtime);
		localtime_s(&timeinfo, &rawtime);

		char data[80];

		strftime(data, 80, "%d.%m.%Y", &timeinfo);

		while (orders_.size() > 0)
		{			
			buff = orders_.back();
			str = buff->getName();
			orders_.pop_back();

			batch = new BatchOfGoods();
			//batch->setNameOfGoods()
			batch->setNameOfGoods(convertStringToCharArray(str));
			batch->setIdOfGood((rand() + str.at(0))% 100000000);
			batch->setPriceOfGoods((int)str.at(0) * margin_);
			batch->setQuantityOfGoods(buff->getQuantity());
			batch->setDateOfBatch(data);	

			ready_orders_.push_back(new ReadyOrder(buff->getShopIteraror(), batch));
		}
		
	}

	float sellOrders(Shop* contact)
	{
		float sum = 0;

		std::list<Shop*>::iterator it;	

		it = std::find(contracts_with_shops_.begin(), contracts_with_shops_.end(), contact);

		if (it != contracts_with_shops_.end())
		{
			int n = ready_orders_.size();
			
			ReadyOrder* buff;

			while (n > 0)
			{
				buff = ready_orders_.front();
				ready_orders_.pop_front();

				if (buff->getShopIterator() == it)
				{
					sum += buff->getBatchOfGoods()->getPrice();
					contact->addBatch(buff->getBatchOfGoods());
				}
				else ready_orders_.push_back(buff);
				n--;
			}
		}
		return sum;
	}
};

