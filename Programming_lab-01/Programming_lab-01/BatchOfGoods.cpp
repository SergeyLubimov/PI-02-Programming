#include "BatchOfGoods.h"

BatchOfGoods::BatchOfGoods()
{
	name_ = NULL;
	int ID_ = 0;
	float price_ = 0;
	int quantity_ = 0;
}

bool BatchOfGoods::setNameOfGoods(char* s)
{
	int size_str = strlen(s) + 1;
	if (s != 0)
	{
		if (name_ == 0) delete name_;

		name_ = new char[size_str];
		strcpy_s(name_, size_str, s);

		return true;
	}
	else false;
}

bool BatchOfGoods::setNameOfGoods(const char s[])
{
	int size_str = strlen(s) + 1;
	if (s != 0)
	{
		if (name_ == 0) free(name_);
		
		name_ = new char[size_str];
		strcpy_s(name_, size_str, s);
		return true;
	}
	return false;
}

bool BatchOfGoods::setIdOfGood(int id)
{
	if (id >= 0 && id < 100000000)
	{
		ID_ = id;
		return true;
	}
	else false;
}

bool BatchOfGoods::setPriceOfGoods(int price)
{
	if (price >= 0)
	{
		price_ = price;
		return true;
	}
	else false;
}

bool BatchOfGoods::setQuantityOfGoods(int quantity)
{
	if (quantity >= 0)
	{
		quantity_ = quantity;
		return true;
	}
	else false;
}

bool BatchOfGoods::setDateOfBatch(char* str)
{
	return date_.setDateAsCharArray(str);
}

bool BatchOfGoods::setDateOfBatch(const char str[])
{
	return date_.setDateAsCharArray(str);
}

char* BatchOfGoods::getName()
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

char* BatchOfGoods::getIdOfGoodsAsCharArray()
{
	char* str = new char[9];
	str[8] = '\0';
	char* str0;
	char* str_id;

	str_id = convertIntToCharArray(ID_);

	int n = 8 - strlen(str_id);
	
	str0 = new char[n + 1];
	str0[n] = '\0';

	int i = 0;
	for (; i < n; i++) str0[i] = '0';

	strcpy_s(str, 9, str0);
	strcat_s(str, 9, str_id);

	delete str0;
	delete str_id;

	return str;
}

char* BatchOfGoods::getBatchAsCharArray(int n)
{
	char* indent = new char[n + 2];

	indent[0] = '\n';
	for (int i = 1; i <= n; i++) indent[i] = ' ';
	indent[n + 1] = '\0';

	char* name, * ID, * price, * quantity, * date;

	name = name_;
	ID = getIdOfGoodsAsCharArray();
	price = convertIntToCharArray(price_);
	quantity = convertIntToCharArray(quantity_);
	date = date_.getDateAsCharArray();

	int str_size = 5 * (n + 2);

	str_size += strlen("Name: ") + strlen(name);
	str_size += strlen("ID: ") + strlen(ID);
	str_size += strlen("Price: ") + strlen(price);
	str_size += strlen("Quantity: ") + strlen(quantity);
	str_size += strlen("Date: ") + strlen(date) + 10;

	char* str = new char[str_size];

	strcpy_s(str, str_size, indent);
	strcat_s(str, str_size, "Name: ");
	strcat_s(str, str_size, name);

	strcat_s(str, str_size, indent);
	strcat_s(str, str_size, "ID: ");
	strcat_s(str, str_size, ID);

	strcat_s(str, str_size, indent);
	strcat_s(str, str_size, "Price: ");
	strcat_s(str, str_size, price);

	strcat_s(str, str_size, indent);
	strcat_s(str, str_size, "Quantity: ");
	strcat_s(str, str_size, quantity);

	strcat_s(str, str_size, indent);
	strcat_s(str, str_size, "Date: ");
	strcat_s(str, str_size, date);

	delete indent;
	delete ID;
	delete price;
	delete quantity;
	delete date;

	return str;
}

char* BatchOfGoods::getBatchAsCharArray_WithoutName(int n)
{
	char* indent = new char[n + 2];

	indent[0] = '\n';
	for (int i = 1; i <= n; i++) indent[i] = ' ';
	indent[n + 1] = '\0';

	char * ID, * price, * quantity, * date;

	ID = getIdOfGoodsAsCharArray();
	price = convertIntToCharArray(price_);
	quantity = convertIntToCharArray(quantity_);
	date = date_.getDateAsCharArray();

	int str_size = 5 * (n + 2) + 19;

	str_size += strlen("| ID: ") + strlen(ID);
	str_size += strlen("| Price: ") + strlen(price);
	str_size += strlen("| Quantity: ") + strlen(quantity);
	str_size += strlen("| Date: ") + strlen(date) + 10;

	char* str = new char[str_size];

	strcpy_s(str, str_size, indent);
	strcat_s(str, str_size, "| ID: ");
	strcat_s(str, str_size, ID);

	strcat_s(str, str_size, indent);
	strcat_s(str, str_size, "| Price: ");
	strcat_s(str, str_size, price);

	strcat_s(str, str_size, indent);
	strcat_s(str, str_size, "| Quantity: ");
	strcat_s(str, str_size, quantity);

	strcat_s(str, str_size, indent);
	strcat_s(str, str_size, "| Date: ");
	strcat_s(str, str_size, date);

	strcat_s(str, str_size, indent);
	strcat_s(str, str_size, "------------------");

	delete indent;
	delete ID;
	delete price;
	delete quantity;
	delete date;

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

bool BatchOfGoods::launchNewBatchForm()
{
	char command[100];
	bool is_right[5];

	for (int i = 0; i < 5; i++) is_right[i] = false;

	std::cout << "\n\nForm of creating a new batch:\n(enter \"!exit\" to exit the form)\n\n";

	int i = -1;

	while (i < 0 || (strcmp(command, "!exit") != 0 && !(is_right[0] && is_right[1] &&
		is_right[2] && is_right[3] && is_right[4])))
	{
		switch (i)
		{
		case -1:
		{
			i = 0;
		}
		case 0:
		{
			std::cout << "\n  Enter the name: ";
			break;
		}
		case 1:
		{
			std::cout << "\n  Enter the ID: ";
			break;
		}
		case 2:
		{
			std::cout << "\n  Enter the price: ";
			break;
		}
		case 3:
		{
			std::cout << "\n  Enter the quantity: ";
			break;
		}
		case 4:
		{
			std::cout << "\n  Enter the date(dd.mm.yyyy): ";
			break;
		}
		default: break;
		}

		std::cin >> command;

		switch (i)
		{
		case 0:
		{
			is_right[i] = setNameOfGoods(command);
			break;
		}
		case 1:
		{
			is_right[i] = checkWhetherInt(command) &&
				setIdOfGood(convertCharArrayToInt(command));
			break;
		}
		case 2:
		{
			is_right[i] = checkWhetherInt(command) &&
				setPriceOfGoods(convertCharArrayToInt(command));
			break;
		}
		case 3:
		{
			is_right[i] = checkWhetherInt(command) &&
				setQuantityOfGoods(convertCharArrayToInt(command));
			break;
		}
		case 4:
		{
			is_right[i] = setDateOfBatch(command);
			break;
		}
		default: break;
		}

		if (is_right[i] == false) std::cout << "\n\nError\n";
		else i++;
	}

	if (is_right[0] && is_right[1] &&
		is_right[2] && is_right[3] && is_right[4])
	{
		std::cout << "\n\nBatch:\n" <<
			getBatchAsCharArray(2) << "\n\nIs it right?(y/n)\n";
		char c;
		{
			std::cin >> c;
		}
		while (c != 'y' && c != 'n');

		if (c == 'y')
		{
			return true;
		}
	}	
	return false;
}

BatchOfGoods* BatchOfGoods::cloneBarch()
{
	BatchOfGoods* b = new BatchOfGoods();
	*b = *this;
	return b;
}

BatchOfGoods::~BatchOfGoods()
{
	delete name_;
	delete this;
}