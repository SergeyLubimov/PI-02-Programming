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
}
