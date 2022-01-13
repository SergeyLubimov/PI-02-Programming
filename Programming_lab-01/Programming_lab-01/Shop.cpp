
#include "Shop.h"
#include "SupplierOfGoods.h"

Shop::Shop()
{
	cash_ = 0;
	name_ = "";
	margin_ = 1;
}

Shop::Shop(std::string name)
{
	Shop();
	name = name_;
}

Shop::Shop(std::string name, int percent_margin, float cash)
{
	cash_ = cash;
	name_ = name;
	margin_ = 1 + percent_margin / 100;
}

std::string Shop::getName()
{
	return name_;
}

void Shop::setMargin(unsigned percent)
{
	margin_ = 1 + float(percent) / 100;
	std::cout << "It's Shop\n";
}

bool Shop::setNameOfShop(std::string name)
{
	if (name != "")
	{		
		name_ = name;
		return true;
	}
	else false;
}



void Shop::addBatch(BatchOfGoods* batch)
{	
	batch->setPriceOfGoods(batch->getPrice() * margin_);
	warehouse_.addBatch(batch);
}

bool Shop::sellGoods(std::string name, int* q)
{
	NodeWithPachage* node = warehouse_.getHead();

	bool ret = false;

	while (node != NULL && node->package_->getName() != name)
		node = node->next_;

	if (node != NULL && node->is_empty_ == false)
	{
		cash_ += node->package_->sellGoods(q);
		ret = true;
	}
	return ret;
}

//bool Shop::sellGoods(const char name[], int* q)
//{
//	bool ret = false;
//
//	if (*q > 0)
//	{
//		cash_ += warehouse_.sellGoods(name, q);
//		ret = true;
//	}
//	return ret;
//}

void Shop::displayAssortment()
{
	NodeWithPachage* node = warehouse_.getHead();

	std::cout << "\n\n*** " << name_ << " ***\n" << "|cash: " << cash_;

	while (node != NULL)
	{
		if (node->is_empty_ == false)
			std::cout << node->package_->getPackageAsCharArray();
		node = node->next_;
	}
}

void Shop::signContract(SupplierOfGoods* supplier)
{
	contract_with_supplier_ = supplier;
	supplier->addContract(this);
}

void Shop::makeOrder(std::string name, int quantity)
{
	if (cash_ >= 0)
		contract_with_supplier_->acceptOrder(this, name, quantity);
	else
	{
		std::cout << "\n\nNEGATIVE BALANCE";
		displayAssortment();
	}
}

void Shop::redeemOrders()
{
	cash_ -= contract_with_supplier_->sellOrders(this);
}

void Shop::investMoney(float money)
{
	if(money > 0)
		cash_ += money;
}

float Shop::getMargin()
{
	return margin_;
}

Warehouse Shop::getWarehouse()
{
	return warehouse_;
}

SupplierOfGoods* Shop::getContractWithSupplier()
{
	return contract_with_supplier_;
}

void Shop::setWarehouse(Warehouse warehouse)
{
	warehouse_ = warehouse;
}

void Shop::setContractWithSupplier(SupplierOfGoods *contract)
{
	contract_with_supplier_ = contract;
}

