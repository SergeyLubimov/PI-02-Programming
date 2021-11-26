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

    addBatch(shopB, &a1);
    addBatch(shopB, &a2);
    addBatch(shopB, &a3);

    addBatch(&shopA, b1);
    addBatch(&shopA, b2);
    addBatch(&shopA, b3);

    addBatch(shopB, b1);
    addBatch(shopB, b2);
    addBatch(shopB, b3);

    displayAssortment(shopA);
    displayAssortment(*shopB); 
}
