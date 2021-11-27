#include "BatchOfGoods.h"

bool setNameOfGoods(BatchOfGoods *batch, char* s)
{
	int size_str = strlen(s) + 1;
	if (s != 0)
	{
		if (batch->name == 0) free(batch->name);

		batch->name = (char*)malloc(size_str);
		strcpy_s(batch->name, size_str, s);

		return true;
	}
	else false;
}

bool setNameOfGoods(BatchOfGoods *batch, const char s[])
{
	int size_str = strlen(s) + 1;
	if (s != 0)
	{
		if (batch->name == 0) free(batch->name);
		batch->name = (char*)malloc(size_str);
		strcpy_s(batch->name, size_str, s);
		return true;
	}
	return false;
}

bool setIdOfGood(BatchOfGoods *batch, int id)
{
	if (id >= 0 && id < 100000000)
	{
		batch->ID = id;
		return true;
	}
	else false;
}

bool setPriceOfGoods(BatchOfGoods *batch, int price)
{
	if (price >= 0)
	{
		batch->price = price;
		return true;
	}
	else false;
}

bool setQuantityOfGoods(BatchOfGoods *batch, int quantity)
{
	if (quantity >= 0)
	{
		batch->quantity = quantity;
		return true;
	}
	else false;
}

bool setDateOfBatch(BatchOfGoods *batch, char* str)
{
	return batch->date.setDateAsCharArray(str);
}

bool setDateOfBatch(BatchOfGoods *batch, const char str[])
{
	return batch->date.setDateAsCharArray(str);
}

char* getIdOfGoods(BatchOfGoods batch)
{
	char *str = (char*)malloc(9);
	str[8] = '\0';
	char* str0;
	char* str_id;

	str_id = convertIntToCharArray(batch.ID);

	int n = 8 - strlen(str_id);
	str0 = (char*)malloc(n + 1);
	str0[n] = '\0';

	int i = 0;
	for (; i < n; i++) str0[i] = '0';

	strcpy_s(str, 9, str0);
	strcat_s(str, 9, str_id);

	free(str0);
	free(str_id);

	return str;
}

char* getBatchAsCharArray(BatchOfGoods batch, int n)
{
	char* indent = (char*)malloc(n + 2);

	indent[0] = '\n';
	for (int i = 1; i <= n; i++) indent[i] = ' ';
	indent[n + 1] = '\0';

	char* name, * ID, * price, * quantity, * date;

	name = batch.name;
	ID = getIdOfGoods(batch);
	price = convertIntToCharArray(batch.price);
	quantity = convertIntToCharArray(batch.quantity);
	date = batch.date.getDateAsCharArray();

	int str_size = 5 * (n + 2);

	str_size += strlen("Name: ") + strlen(name);
	str_size += strlen("ID: ") + strlen(ID);
	str_size += strlen("Price: ") + strlen(price);
	str_size += strlen("Quantity: ") + strlen(quantity);
	str_size += strlen("Date: ") + strlen(date) + 10;

	char* str = (char*)malloc(str_size);

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

	free(indent);
	free(ID);
	free(price);
	free(quantity);
	free(date);

	return str;
}

char* getBatchAsCharArray_WithoutName(BatchOfGoods batch, int n)
{
	char* indent = (char*)malloc(n + 2);

	indent[0] = '\n';
	for (int i = 1; i <= n; i++) indent[i] = ' ';
	indent[n + 1] = '\0';

	char * ID, * price, * quantity, * date;

	ID = getIdOfGoods(batch);
	price = convertIntToCharArray(batch.price);
	quantity = convertIntToCharArray(batch.quantity);
	date = batch.date.getDateAsCharArray();

	int str_size = 5 * (n + 2) + 19;

	str_size += strlen("| ID: ") + strlen(ID);
	str_size += strlen("| Price: ") + strlen(price);
	str_size += strlen("| Quantity: ") + strlen(quantity);
	str_size += strlen("| Date: ") + strlen(date) + 10;

	char* str = (char*)malloc(str_size);

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

	free(indent);
	free(ID);
	free(price);
	free(quantity);
	free(date);

	return str;
}

BatchOfGoods* launchNewBatchForm()
{
	BatchOfGoods* batch = (BatchOfGoods*)malloc(sizeof(BatchOfGoods));

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
			is_right[i] = setNameOfGoods(batch, command);
			break;
		}
		case 1:
		{
			is_right[i] = checkWhetherInt(command) &&
				setIdOfGood(batch, convertCharArrayToInt(command));
			break;
		}
		case 2:
		{
			is_right[i] = checkWhetherInt(command) &&
				setPriceOfGoods(batch, convertCharArrayToInt(command));
			break;
		}
		case 3:
		{
			is_right[i] = checkWhetherInt(command) &&
				setQuantityOfGoods(batch, convertCharArrayToInt(command));
			break;
		}
		case 4:
		{
			is_right[i] = setDateOfBatch(batch, command);
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
			getBatchAsCharArray(*batch, 2) << "\n\nIs it right?(y/n)\n";
		char c;
		{
			std::cin >> c;
		}
		while (c != 'y' && c != 'n');

		if (c == 'y')
		{
			return batch;
		}
	}
	deleteBatch(batch);
	return NULL;
}

void deleteBatch(BatchOfGoods* batch)
{
	free(batch->name);	
	free(batch);
}