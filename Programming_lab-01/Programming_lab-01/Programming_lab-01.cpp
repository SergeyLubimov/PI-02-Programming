// Programming_lab-01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

    setNameOfShop(&shopA, "A");
    setNameOfShop(shopB, "B");

    BatchOfGoods a1, a2, a3;

    BatchOfGoods *b1, *b2, *b3;

    setNameOfGoods(&a1, "A");
    setIdOfGood(&a1, 2256);
    setPriceOfGoods(&a1, 150);
    setQuantityOfGoods(&a1, 16);
    setDateOfBatch(&a1, "11.01.1996");

    setNameOfGoods(&a2, "A");
    setIdOfGood(&a2, 1200564);
    setPriceOfGoods(&a2, 178);
    setQuantityOfGoods(&a2, 70);
    setDateOfBatch(&a2, "11.01.2008");

    setNameOfGoods(&a3, "A");
    setIdOfGood(&a3, 420751);
    setPriceOfGoods(&a3, 73);
    setQuantityOfGoods(&a3, 16);
    setDateOfBatch(&a3, "01.11.2008");

    b1 = (BatchOfGoods*)malloc(sizeof(BatchOfGoods));
    setNameOfGoods(b1, "B");
    setIdOfGood(b1, 398755);
    setPriceOfGoods(b1, 15);
    setQuantityOfGoods(b1, 8);
    setDateOfBatch(b1, "07.02.2019");

    b2 = launchNewBatchForm();

    b3 = launchNewBatchForm();

    addBatch(&shopA, &a1);
    addBatch(&shopA, &a2);
    addBatch(&shopA, &a3);

    addBatch(shopB, cloneBarch(&a1));
    addBatch(shopB, cloneBarch(&a2));
    addBatch(shopB, cloneBarch(&a3));

    addBatch(&shopA, b1);
    addBatch(&shopA, b2);
    addBatch(&shopA, b3);

    addBatch(shopB, cloneBarch(b1));
    addBatch(shopB, cloneBarch(b2));
    addBatch(shopB, cloneBarch(b3));

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
