﻿//Programming_lab-01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Shop.h"
#include <iostream>

using namespace std;

int main()
{
    Shop shopA;
    Shop* shopB;

    shopB = new Shop();

    /*shopA.init();
    shopB->init();*/

    shopA.setNameOfShop("Shop A");
    shopB->setNameOfShop("Shop B");

    //BatchOfGoods a1, a2, a3;

    BatchOfGoods* a = new BatchOfGoods[3];

    BatchOfGoods* b1, * b2, * b3;

    BatchOfGoods* b[3];

    for (int i = 0; i < 3; i++) 
        b[i] = new BatchOfGoods();

    a[0].setNameOfGoods("A");
    a[0].setIdOfGood(2256);
    a[0].setPriceOfGoods(150);
    a[0].setQuantityOfGoods(16);
    a[0].setDateOfBatch("11.01.1996");

    a[1].setNameOfGoods("A");
    a[1].setIdOfGood(1200564);
    a[1].setPriceOfGoods(178);
    a[1].setQuantityOfGoods(70);
    a[1].setDateOfBatch("11.01.2008");

    a[2].setNameOfGoods("A");
    a[2].setIdOfGood(420751);
    a[2].setPriceOfGoods(73);
    a[2].setQuantityOfGoods(16);
    a[2].setDateOfBatch("01.11.2008");

    b[0]->setNameOfGoods("B");
    b[0]->setIdOfGood(398755);
    b[0]->setPriceOfGoods(15);
    b[0]->setQuantityOfGoods(8);
    b[0]->setDateOfBatch("07.02.2019");

    bool is_fullB[3];

    is_fullB[0] = false;

    for (int i = 1; i < 3; i++)
    {
        is_fullB[i] = false;
        is_fullB[i] = b[i]->launchNewBatchForm();
    }

    for (int i = 0; i < 3; i++)
    {
        shopA.addBatch(&a[i]);
        shopB->addBatch(a[i].cloneBarch());

        if (is_fullB[i])
        {
            shopA.addBatch(b[i]);
            shopB->addBatch(b[i]->cloneBarch());
        }
    }

    shopA.displayAssortment();
    shopB->displayAssortment(); 

    int q1 = 110;
    int q2 = 9;

    shopA.sellGoods("A", &q1);
    shopA.sellGoods("B", &q2);

    shopA.displayAssortment();

    if (q1 > 0) 
        cout << "\n\nThe product A is over. Missing " << q1 << '\n';

    if (q2 > 0) 
        cout << "\n\nThe product B is over. Missing " << q2 << '\n';

    q1 = 110;
    q2 = 9;

    shopB->sellGoods("A", &q1);
    shopB->sellGoods("B", &q2);

    shopB->displayAssortment();

    if (q1 > 0)
        cout << "\n\nThe product A is over. Missing " << q1 << '\n';

    if (q2 > 0)
        cout << "\n\nThe product B is over. Missing " << q2 << '\n';    
}
