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







  //  /*list<BatchOfGoods*> asd;*/

  // /* string s = "112235";

  //  cout << convertStringToCharArray(s);*/

  //  
  //  /*time_t rawtime;
  //  struct tm timeinfo;
  //  time(&rawtime);
  //  localtime_s(&timeinfo, &rawtime);

  //  char data[80];

  //  strftime(data, 80, "%d.%m.%Y", &timeinfo);*/

  //  //time_t rawtime;
  //  //struct tm* timeinfo;
  //  //char data[80];                                // строка, в которой будет храниться текущее время

  //  //time(&rawtime);                               // текущая дата в секундах
  //  //timeinfo = localtime_s(timeinfo, &rawtime);               // текущее локальное время, представленное в структуре

  //  //strftime(data, 80, "%d.%m.%Y", timeinfo);

  //  //cout << data;


  // /* SupplierOfGoods sup;

  //  Shop shopC;

  //  shopC.setNameOfShop("C");

  //  shopC.signContract(&sup);
  //  shopC.investMoney(10000);

  //  sup.setMargin(60);
  //  shopC.setMargin(20);

  //  shopC.displayAssortment();

  //  shopC.makeOrder("A", 100);

  //  sup.fulfillOrders();

  //  shopC.redeemOrders();

  //  shopC.displayAssortment();*/

  //  SupplierOfGoods sup;

  //  Shop shopC, shopD;
  //  shopC.setNameOfShop("C");
  //  shopD.setNameOfShop("D");

  //  shopC.investMoney(1000);
  //  shopD.investMoney(1000);

  //  Customer cus;

  //  BatchOfGoods z, x;

  //  z.setNameOfGoods("A");
  //  z.setIdOfGood(5556454);
  //  z.setPriceOfGoods(10);
  //  z.setQuantityOfGoods(150);
  //  z.setDateOfBatch("10.10.2010");

  //  x.setNameOfGoods("A");
  //  x.setIdOfGood(5556454);
  //  x.setPriceOfGoods(10);
  //  x.setQuantityOfGoods(150);
  //  x.setDateOfBatch("10.10.2010");

  //  shopC.addBatch(&z);
  //  shopD.addBatch(&x);

  //  shopC.displayAssortment();
  //  shopD.displayAssortment();

  //  cus.rememberShop(&shopC);
  //  cus.rememberShop(&shopD);

  //  cout << cus.buyGoods("A", 160) << endl;

  //  shopC.displayAssortment();
  //  shopD.displayAssortment();



  //  Shop shopA;
  //  Shop* shopB;

  //  shopB = new Shop();

  //  shopA.setNameOfShop("Shop A");
  //  shopB->setNameOfShop("Shop B");

  //  BatchOfGoods* a = new BatchOfGoods[3];

  //  BatchOfGoods* b[3];

  //  for (int i = 0; i < 3; i++) 
  //      b[i] = new BatchOfGoods();

  //  a[0].setNameOfGoods("A");
  //  a[0].setIdOfGood(2256);
  //  a[0].setPriceOfGoods(150);
  //  a[0].setQuantityOfGoods(16);
  //  a[0].setDateOfBatch("11.01.1996");

  //  a[1].setNameOfGoods("A");
  //  a[1].setIdOfGood(1200564);
  //  a[1].setPriceOfGoods(178);
  //  a[1].setQuantityOfGoods(70);
  //  a[1].setDateOfBatch("11.01.2008");

  //  a[2].setNameOfGoods("A");
  //  a[2].setIdOfGood(420751);
  //  a[2].setPriceOfGoods(73);
  //  a[2].setQuantityOfGoods(16);
  //  a[2].setDateOfBatch("01.11.2008");

  //  b[0]->setNameOfGoods("B");
  //  b[0]->setIdOfGood(398755);
  //  b[0]->setPriceOfGoods(15);
  //  b[0]->setQuantityOfGoods(8);
  //  b[0]->setDateOfBatch("07.02.2019");

  //  ////////////////////////

  ///*  asd.push_back(&a[0]);

  //  BatchOfGoods *c = asd.back();*/

  //  
  //  int q3 = 10;

  //  shopA.sellGoods("C", &q3);

  //  shopA.displayAssortment();


  // //<summary>
  //  /// ////////////////
  // 

  //  bool is_fullB[3];

  //  is_fullB[0] = false;

  //  for (int i = 1; i < 3; i++)
  //  {
  //      is_fullB[i] = false;
  //      is_fullB[i] = b[i]->launchNewBatchForm();
  //  }

  //  for (int i = 0; i < 3; i++)
  //  {
  //      shopA.addBatch(&a[i]);
  //      shopB->addBatch(a[i].cloneBarch());

  //      if (is_fullB[i])
  //      {
  //          shopA.addBatch(b[i]);
  //          shopB->addBatch(b[i]->cloneBarch());
  //      }
  //  }

  //  shopA.displayAssortment();
  //  shopB->displayAssortment(); 

  //  int q1 = 110;
  //  int q2 = 9;

  //  shopA.sellGoods("A", &q1);
  //  shopA.sellGoods("B", &q2);

  //  shopA.displayAssortment();

  //  if (q1 > 0) 
  //      cout << "\n\nThe product A is over. Missing " << q1 << '\n';

  //  if (q2 > 0) 
  //      cout << "\n\nThe product B is over. Missing " << q2 << '\n';

  //  q1 = 110;
  //  q2 = 9;

  //  shopB->sellGoods("A", &q1);
  //  shopB->sellGoods("B", &q2);

  //  shopB->displayAssortment();

  //  if (q1 > 0)
  //      cout << "\n\nThe product A is over. Missing " << q1 << '\n';

  //  if (q2 > 0)
  //      cout << "\n\nThe product B is over. Missing " << q2 << '\n';    
}
