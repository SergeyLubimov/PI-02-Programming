// Programming_lab-01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Shop.h"
//#include "PackageOfBatchesOfGoods.h"
//#include "BatchOfGoods.h"

#include <iostream>


using namespace std;

struct MyStruct
{
    int a;
};

void v(MyStruct a)
{
    a.a++;
}




int main()
{
    //BatchOfGoods *a = (BatchOfGoods*)malloc(sizeof(BatchOfGoods));
    //setNameOfGoods(a, "A");
    //setIdOfGood(a, 2005);
    //setPriceOfGoods(a, 100);
    //setQuantityOfGoods(a, 23);
    //setDateOfBatch(a, "10.10.2010");

    //BatchOfGoods *b = (BatchOfGoods*)malloc(sizeof(BatchOfGoods));
    //setNameOfGoods(b, "B");
    //setIdOfGood(b, 2005);
    //setPriceOfGoods(b, 100);
    //setQuantityOfGoods(b, 23);
    //setDateOfBatch(b, "02.01.2000");

    //BatchOfGoods *c = (BatchOfGoods*)malloc(sizeof(BatchOfGoods));
    //setNameOfGoods(c, "C");
    //setIdOfGood(c, 2011);
    //setPriceOfGoods(c, 100);
    //setQuantityOfGoods(c, 23);
    //setDateOfBatch(c, "09.10.2010");

    //BatchOfGoods *d = (BatchOfGoods*)malloc(sizeof(BatchOfGoods));
    //setNameOfGoods(d, "D");
    //setIdOfGood(d, 2005);
    //setPriceOfGoods(d, 100);
    //setQuantityOfGoods(d, 23);
    //setDateOfBatch(d, "10.10.1887");

    ////cout << getBatchAsCharArray(a, 5);

    //NULL;

    //PackageOfBatchesOfGoods p;

    //setNameOfPackage(&p, a->name);

    //addBatch(&p, a);
    //cout << getPackageAsCharArray(&p);

    //addBatch(&p, b);
    //cout << getPackageAsCharArray(&p);

    //addBatch(&p, c);
    //cout << getPackageAsCharArray(&p);

    //addBatch(&p, d);
    //cout << getPackageAsCharArray(&p);

    //int q = 92;

    //sellGoods(&p, &q);

    //cout << getPackageAsCharArray(&p);

   /* BatchOfGoods* batch;

    batch = launchNewBatchForm();

    cout << getBatchAsCharArray(*batch, 5);*/

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







// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
