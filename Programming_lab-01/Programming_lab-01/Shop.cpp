
#include "Shop.h"
#include "SupplierOfGoods.h"

Shop::Shop()
{
	cash_ = 0;
	name_ = NULL;
	margin_ = 1;
}

void Shop::setMargin(unsigned percent)
{
	margin_ = 1 + float(percent) / 100;
}

bool Shop::setNameOfShop(char* name)
{
	int size_str = strlen(name) + 1;
	if (name != 0)
	{
		if (name_ == 0) delete name_;

		name_ = new char[size_str];
		strcpy_s(name_, size_str, name);

		return true;
	}
	else false;
}

bool Shop::setNameOfShop(const char s[])
{
	int size_str = strlen(s) + 1;
	if (s != 0)
	{
		if (name_ == 0) delete name_;

		name_ = new char[size_str];
		strcpy_s(name_, size_str, s);
		return true;
	}
	return false;
}

void Shop::addBatch(BatchOfGoods* batch)
{	
	batch->setPriceOfGoods(batch->getPrice() * margin_);
	warehouse_.addBatch(batch);
}

bool Shop::sellGoods(char* name, int* q)
{
	NodeWithPachage* node = warehouse_.getHead();

	bool ret = false;

	while (node != NULL && strcmp(node->package_->getName(), name) != 0)
		node = node->next_;

	if (node != NULL && node->is_empty_ == false)
	{
		cash_ += node->package_->sellGoods(q);
		ret = true;
	}
	return ret;
}

bool Shop::sellGoods(const char name[], int* q)
{
	bool ret = false;

	if (*q > 0)
	{
		cash_ += warehouse_.sellGoods(name, q);
		ret = true;
	}
	return ret;
}

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
	contracts_with_suppliers_ = supplier;
	supplier->addContract(this);
}

void Shop::makeOrder(std::string name, int quantity)
{
	if (cash_ >= 0)
		contracts_with_suppliers_->acceptOrder(this, name, quantity);
	else
	{
		std::cout << "\n\nNEGATIVE BALANCE";
		displayAssortment();
	}
}

void Shop::redeemOrders()
{
	cash_ -= contracts_with_suppliers_->sellOrders(this);
}

void Shop::investMoney(float money)
{
	if(money > 0)
		cash_ += money;
}