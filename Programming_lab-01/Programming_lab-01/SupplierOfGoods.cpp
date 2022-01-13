#include "SupplierOfGoods.h"

//Функции класса SupplierOfGoods
//
SupplierOfGoods::SupplierOfGoods()
{
	margin_ = 1;
}

SupplierOfGoods::SupplierOfGoods(int percent)
{
	margin_ = 1 + percent / 100;
}

void SupplierOfGoods::addContract(Shop* shop)
{
	contracts_with_shops_.push_back(shop);
	contracts_with_shops_.unique();
}

void SupplierOfGoods::setMargin(unsigned percent)
{
	margin_ = 1 + float(percent) / 100;
}


bool SupplierOfGoods::acceptOrder(Shop* contact, std::string name, int quantity)
{
	std::list<Shop*>::iterator it1;

	it1 = std::find(contracts_with_shops_.begin(), contracts_with_shops_.end(), contact);

	if (it1 != contracts_with_shops_.end())
	{
		orders_.push_back((new Order(it1, name, quantity)));
		return true;
	}
	return false;
}


void SupplierOfGoods::fulfillOrders()
{
	Order* buff;
	BatchOfGoods* batch;
	srand(unsigned(time(0)));

	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	char data[80];

	strftime(data, 80, "%d.%m.%Y", &timeinfo);

	while (orders_.size() > 0)
	{
		buff = orders_.back();		
		orders_.pop_back();

		batch = new BatchOfGoods();
		batch->setNameOfGoods(buff->name_);
		batch->setIdOfGood((rand() + buff->name_.at(0)) % 100000000);
		batch->setPriceOfGoods((int)buff->name_.at(0) * margin_);
		batch->setQuantityOfGoods(buff->quantity_);
		batch->setDateOfBatch(data);

		ready_orders_.push_back(new ReadyOrder(buff->shop_iterator_, batch));
	}
}

float SupplierOfGoods::sellOrders(Shop* contact)
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

			if (buff->shop_iterator_ == it)
			{
				sum += buff->batch_->getPrice();
				contact->addBatch(buff->batch_);
			}
			else ready_orders_.push_back(buff);
			n--;
		}
	}
	return sum;
}

//Функции класса Order
//
Order::Order(std::list<Shop*>::iterator it, std::string name, int quantity)
{
	shop_iterator_ = it;
	name_ = name;
	quantity_ = quantity;
}

//Функции класса ReadyOrder
//
ReadyOrder::ReadyOrder(std::list<Shop*>::iterator shop_iterator, BatchOfGoods* batch)
{
	shop_iterator_ = shop_iterator;
	batch_ = batch;
}



