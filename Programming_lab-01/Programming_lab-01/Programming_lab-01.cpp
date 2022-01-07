//Programming_lab-01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "SupplierOfGoods.h"
#include "Customer.h"
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;




int main()
{ 

	//BatchOfGoods *b = new BatchOfGoods();

	//b->setNameOfGoods("A");
	//b->setIdOfGood(5464578);
	//b->setPriceOfGoods(1);
	//b->setQuantityOfGoods(20);
	//b->setDateOfBatch("20.02.2003");

	//PackageOfBatchesOfGoods p;

	//p.addBatch(b); 

	//int q = 10;

	////Через указатель
	//p.sellGoods(&q);

	//cout << q << endl;

	//q = 15;

	////По ссылке
	//p.sellGoods(q);

	//cout << q << endl;

	

	SupplierOfGoods supplier;

	supplier.setMargin(20);
	
	Shop shopA, shopB;

	shopA.setNameOfShop("Shop A");
	shopB.setNameOfShop("Shop B");

	shopA.setMargin(10);
	shopB.setMargin(15);

	supplier.addContract(&shopA);
	supplier.addContract(&shopB);

	shopA.signContract(&supplier);
	shopB.signContract(&supplier);

	shopA.investMoney(10000);
	shopB.investMoney(10000);

	shopA.displayAssortment();
	shopB.displayAssortment();

	shopA.makeOrder("A", 150);
	shopB.makeOrder("A", 150);
	shopB.makeOrder("B", 30);

	supplier.fulfillOrders();

	shopA.redeemOrders();
	shopB.redeemOrders();

	shopA.displayAssortment();
	shopB.displayAssortment();

	Customer customer;

	customer.rememberShop(&shopA);
	customer.rememberShop(&shopB);

	int q1 = customer.buyGoods("A", 160);
	int q2 = customer.buyGoods("B", 40);

	shopA.displayAssortment();
	shopB.displayAssortment();

	if (q1 > 0)
		cout << "\n\nThe product A is over. Missing " << q1 << '\n';

	if (q2 > 0)
		cout << "\n\nThe product B is over. Missing " << q2 << '\n';

	Date date1, date1_, date2, date2_;

	date1.setDateAsCharArray("31.10.2010");
	date2.setDateAsCharArray("31.12.2010");

	cout << "\n\nOriginal: " << date1.getDateAsCharArray() << "  " << date2.getDateAsCharArray();
	

	date1_ = ++date1;
	date2_ = date2++;

	Date date_sum = date1 + date2;

	cout << "\nBefore:   " << date1_.getDateAsCharArray() << "  " << date2_.getDateAsCharArray();
	cout << "\nAfter:    " << date1.getDateAsCharArray() << "  " << date2.getDateAsCharArray();
	cout << "\nSum:            " << date_sum.getDateAsCharArray() << endl;

}
