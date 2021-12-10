//Programming_lab-01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Shop.h"
#include <iostream>

using namespace std;

int main()
{
    Shop shopA;
    Shop *shopB;

    shopB = new Shop();

    /*shopA.init();
    shopB->init();*/

    shopA.setNameOfShop("Shop A");
    shopB->setNameOfShop("Shop B");

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

    b1 = new BatchOfGoods();
    b1->setNameOfGoods("B");
    b1->setIdOfGood(398755);
    b1->setPriceOfGoods(15);
    b1->setQuantityOfGoods(8);
    b1->setDateOfBatch("07.02.2019");


    b2 = new BatchOfGoods();
    b3 = new BatchOfGoods();

    bool is_fullB2 = false;
    bool is_fullB3 = false;

    is_fullB2 = b2->launchNewBatchForm();    
    is_fullB3 = b3->launchNewBatchForm();

    shopA.addBatch(&a1);
    shopA.addBatch(&a2);
    shopA.addBatch(&a3);

    shopB->addBatch(a1.cloneBarch());
    shopB->addBatch(a2.cloneBarch());
    shopB->addBatch(a3.cloneBarch());

    shopA.addBatch(b1);
    if (is_fullB2) shopA.addBatch(b2);
    if (is_fullB3) shopA.addBatch(b3);

    shopB->addBatch(b1->cloneBarch());
    if (is_fullB2) shopB->addBatch(b2->cloneBarch());
    if (is_fullB3) shopB->addBatch(b3->cloneBarch());

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
