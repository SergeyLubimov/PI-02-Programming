#include "BatchOfGoods.h"

BatchOfGoods::BatchOfGoods()
{
	name_ = "";
	ID_ = 0;
	price_ = 0;
	quantity_ = 0;
}

BatchOfGoods::BatchOfGoods(std::string name)
{
	BatchOfGoods();
	name_ = name;
}

BatchOfGoods::BatchOfGoods(std::string name, int id, float price, int quantity, Date date)
{
	name_ = name;
	ID_ = id;
	price_ = price;
	quantity_ = quantity;
	date_ = date;
}



void BatchOfGoods::setNameOfGoods(std::string s)
{
	try
	{
		if (s == "") throw "Empty name";
	}
	catch (const char* str)
	{
		std::cout << std::endl << str << std::endl;
	}
	name_ = s;
}

void BatchOfGoods::setIdOfGood(int id)
{
	try
	{
		if (id < 0 && id > 100000000) throw "Error ID";
	}
	catch (const char* str)
	{
		std::cout << std::endl << str << std::endl;
	}	
	ID_ = id;	
}

void BatchOfGoods::setPriceOfGoods(int price)
{
	try
	{
		if (price < 0) throw "Error Price";
	}
	catch(const char* str)
	{
		std::cout << std::endl << str << std::endl;
	}
	price_ = price;	
}

void BatchOfGoods::setQuantityOfGoods(int quantity)
{
	try
	{
		if (quantity < 0) throw "Error Quantity";
	}
	catch (const char* str)
	{
		std::cout << std::endl << str << std::endl;
	}	
	quantity_ = quantity;		
}

bool BatchOfGoods::setDateOfBatch(std::string str)
{
	return date_.setDateAsCharArray(str);
}

//bool BatchOfGoods::setDateOfBatch(const char str[])
//{
//	return date_.setDateAsCharArray(str);
//}

std::string BatchOfGoods::getName()
{
	return name_;
}

int BatchOfGoods::getID()
{
	return ID_;
}

float BatchOfGoods::getPrice()
{
	return price_;
}

int BatchOfGoods::getQuantity()
{
	return quantity_;
}

Date BatchOfGoods::getDate()
{
	return date_;
}

std::string BatchOfGoods::getIdOfGoodsAsCharArray()
{
	std::string str = std::to_string(ID_);

	while (str.size() < 8) str = "0" + str;

	return str;
}

std::string BatchOfGoods::getBatchAsCharArray(int n)
{
	std::string indent = "\n";

	for (int i = 1; i <= n; i++) indent += " ";

	std::string name, ID, price, quantity, date;

	name = name_;
	ID = getIdOfGoodsAsCharArray();
	price = std::to_string(price_);
	quantity = std::to_string(quantity_);
	date = date_.getDateAsCharArray();

	std::string str;

	str += indent + "Name: " + name;
	str += indent + "ID: " + ID;
	str += indent + "Price: " + price;
	str += indent + "Quantity: " + quantity;
	str += indent + "Date: " + date;

	return str;
}

std::string BatchOfGoods::getBatchAsCharArray_WithoutName(int n)
{
	std::string indent = "\n";

	for (int i = 1; i <= n; i++) indent += " ";

	std::string name, ID, price, quantity, date;

	name = name_;
	ID = getIdOfGoodsAsCharArray();
	price = std::to_string(price_);
	quantity = std::to_string(quantity_);
	date = date_.getDateAsCharArray();

	/*int str_size = 5 * (n + 2);

	
	str_size += strlen("| ID: ") + strlen(ID);
	str_size += strlen("| Price: ") + strlen(price);
	str_size += strlen("| Quantity: ") + strlen(quantity);
	str_size += strlen("| Date: ") + strlen(date) + 10;*/

	std::string str;
	str += indent + "| ID: " + ID;
	str += indent + "| Price: " + price;
	str += indent + "| Quantity: " + quantity;
	str += indent + "| Date: " + date;
	str += indent + "------------------";
	
	return str;
}

int BatchOfGoods::reduceQuantityOfGoods()
{
	return quantity_--;
}

int BatchOfGoods::reduceQuantityOfGoods(int n)
{
	quantity_ -= n;
	return quantity_;
}

void BatchOfGoods::resetQuantityOfGoods()
{
	quantity_ = 0;
}

//bool BatchOfGoods::launchNewBatchForm()
//{
//	std::string command;
//	bool is_right[5];
//
//	for (int i = 0; i < 5; i++) is_right[i] = false;
//
//	std::cout << "\n\nForm of creating a new batch:\n(enter \"!exit\" to exit the form)\n\n";
//
//	int i = -1;
//
//	while (i < 0 || ((command == "!exit") && !(is_right[0] && is_right[1] &&
//		is_right[2] && is_right[3] && is_right[4])))
//	{
//		switch (i)
//		{
//		case -1:
//		{
//			i = 0;
//		}
//		case 0:
//		{
//			std::cout << "\n  Enter the name: ";
//			break;
//		}
//		case 1:
//		{
//			std::cout << "\n  Enter the ID: ";
//			break;
//		}
//		case 2:
//		{
//			std::cout << "\n  Enter the price: ";
//			break;
//		}
//		case 3:
//		{
//			std::cout << "\n  Enter the quantity: ";
//			break;
//		}
//		case 4:
//		{
//			std::cout << "\n  Enter the date(dd.mm.yyyy): ";
//			break;
//		}
//		default: break;
//		}
//
//		std::cin >> command;
//
//		switch (i)
//		{
//		case 0:
//		{
//			is_right[i] = setNameOfGoods(command);
//			break;
//		}
//		case 1:
//		{
//			is_right[i] = checkWhetherInt(command) &&
//				setIdOfGood(stoi(command));
//			break;
//		}
//		case 2:
//		{
//			is_right[i] = checkWhetherInt(command) &&
//				setPriceOfGoods(stoi(command));
//			break;
//		}
//		case 3:
//		{
//			is_right[i] = checkWhetherInt(command) &&
//				setQuantityOfGoods(stoi(command));
//			break;
//		}
//		case 4:
//		{
//			is_right[i] = setDateOfBatch(command);
//			break;
//		}
//		default: break;
//		}
//
//		if (is_right[i] == false) std::cout << "\n\nError\n";
//		else i++;
//	}
//
//	if (is_right[0] && is_right[1] &&
//		is_right[2] && is_right[3] && is_right[4])
//	{
//		std::cout << "\n\nBatch:\n" <<
//			getBatchAsCharArray(2) << "\n\nIs it right?(y/n)\n";
//		char c;
//		{
//			std::cin >> c;
//		}
//		while (c != 'y' && c != 'n');
//
//		if (c == 'y')
//		{
//			return true;
//		}
//	}	
//	return false;
//}

BatchOfGoods* BatchOfGoods::cloneBarch()
{
	BatchOfGoods* b = new BatchOfGoods();
	*b = *this;
	return b;
}

//BatchOfGoods::~BatchOfGoods()
//{
//	delete name_;
//	delete this;
//}