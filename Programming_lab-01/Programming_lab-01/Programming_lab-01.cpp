//Programming_lab-01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Shop.h"
#include <iostream>

using namespace std;

int main()
{
    Shop shopA;
    Shop *shopB;

    shopB = (Shop*)malloc(sizeof(Shop));

    init(&shopA);
    init(shopB);

    setNameOfShop(&shopA, "Shop A");
    setNameOfShop(shopB, "Shop B");

    BatchOfGoods a1, a2, a3;

    BatchOfGoods *b1, *b2, *b3;

    a1.setNameOfGoods("A");
    a1.setIdOfGood(2256);
    a1.setPriceOfGoods(150);
    a1.setQuantityOfGoods(16);
    a1.setDateOfBatch("11.01.1996");

    a2.setNameOfGoods("A");
    a2.setIdOfGood(1200564);
    a2.setPriceOfGoods(178);
    a2.setQuantityOfGoods(70);
    a2.setDateOfBatch("11.01.2008");

    a3.setNameOfGoods("A");
    a3.setIdOfGood(420751);
    a3.setPriceOfGoods(73);
    a3.setQuantityOfGoods(16);
    a3.setDateOfBatch("01.11.2008");

    b1 = (BatchOfGoods*)malloc(sizeof(BatchOfGoods));/////////////////////////////////
    b1->setNameOfGoods("B");
    b1->setIdOfGood(398755);
    b1->setPriceOfGoods(15);
    b1->setQuantityOfGoods(8);
    b1->setDateOfBatch("07.02.2019");


    b2 = new BatchOfGoods();
    b3 = new BatchOfGoods();

    bool is_fullB2, is_fullB3;

    is_fullB2 = b2->launchNewBatchForm();    
    is_fullB3 = b3->launchNewBatchForm();

    addBatch(&shopA, &a1);
    addBatch(&shopA, &a2);
    addBatch(&shopA, &a3);

    addBatch(shopB, a1.cloneBarch());
    addBatch(shopB, a2.cloneBarch());
    addBatch(shopB, a3.cloneBarch());

    addBatch(&shopA, b1);
    if (is_fullB2) addBatch(&shopA, b2);
    if (is_fullB3) addBatch(&shopA, b3);

    addBatch(shopB, b1->cloneBarch());
    if (is_fullB2) addBatch(shopB, b2->cloneBarch());
    if (is_fullB3) addBatch(shopB, b3->cloneBarch());

    displayAssortment(shopA);
    displayAssortment(*shopB); 

    int q1 = 110;
    int q2 = 9;

    sellGoods(&shopA, "A", &q1);
    sellGoods(&shopA, "B", &q2);

    displayAssortment(shopA);

    if (q1 > 0) 
        cout << "\n\nThe product A is over. Missing " << q1 << '\n';

    if (q2 > 0) 
        cout << "\n\nThe product B is over. Missing " << q2 << '\n';

    q1 = 110;
    q2 = 9;

    sellGoods(shopB, "A", &q1);
    sellGoods(shopB, "B", &q2);

    displayAssortment(*shopB);

    if (q1 > 0)
        cout << "\n\nThe product A is over. Missing " << q1 << '\n';

    if (q2 > 0)
        cout << "\n\nThe product B is over. Missing " << q2 << '\n';    



}
