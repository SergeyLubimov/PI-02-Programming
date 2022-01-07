using System;

namespace Programming_lab_06
{
    class Program
    {
        static void Func1(ref string a)
        {
            a = "C#";
        }
        static void Func2(out string a)
        {
            a = "C#";
        }
        static void Func3(ref string a)
        {
            ;
        }
        //static void Func4(out string a)
        //{
        //    ;
        //}
        static void Main(string[] args)
        {

            SupplierOfGoods supplier = new SupplierOfGoods();
            supplier.setMatgin(20);

            Shop[] shops = new Shop[5];

            for(int i = 0; i < shops.Length; i++)
            {
                shops[i] = new Shop();
                shops[i].signContract(supplier);
                shops[i].setName(String.Format($"Shop {i + 1}"));
                shops[i].makeOrder(String.Format($"Good {i + 1}"), i + 1);
            }

            supplier.fulfillOrders();

            for (int i = 0; i < shops.Length; i++)
            {
                shops[i].redeemOrders();
                shops[i].displayAssortment();
            }

            string a, b;

            a = "C#";

            Func1(ref a);
            Func2(out a);
                        
            Func2(out b);
            Func1(ref b);

            Shop shopA = new Shop("A");

            shopA++;
            ++shopA;
            shopA.displayAssortment();

            Warehouse w1 = new Warehouse();
            Warehouse w2 = new Warehouse();

            BatchOfGoods b1 = BatchOfGoods.createRandom("A");
            BatchOfGoods b2 = BatchOfGoods.createRandom("B");

            w1.addBatchOfGoods(b1);
            w2.addBatchOfGoods(b2);

            Warehouse sum = w1 + w2;

            w1.getPackagesAsString();
            w2.getPackagesAsString();
            sum.getPackagesAsString();

            Console.WriteLine($"\n\nW1:\n{w1.getPackagesAsString()}\n\n" +
                $"W2:\n{w2.getPackagesAsString()}" + 
                $"\n\nW1 + W2:\n{sum.getPackagesAsString()}");



            //SupplierOfGoods supplier = new SupplierOfGoods();

            //supplier.setMatgin(20);

            //Shop shopA, shopB;

            //shopA = new Shop();
            //shopB = new Shop();

            //shopA.setName("Shop A");
            //shopB.setName("Shop B");

            //shopA.setMargin(10);
            //shopA.setMargin(15);

            //supplier.addContract(shopA);
            //supplier.addContract(shopB);

            //shopA.signContract(supplier);
            //shopB.signContract(supplier);

            //shopA.investMoney(10000);
            //shopB.investMoney(10000);

            //shopA.displayAssortment();
            //shopB.displayAssortment();

            //shopA.makeOrder("A", 150);
            //shopB.makeOrder("A", 150);
            //shopB.makeOrder("B", 30);

            //supplier.fulfillOrders();

            //shopA.redeemOrders();
            //shopB.redeemOrders();

            //shopA.displayAssortment();
            //shopB.displayAssortment();

            //Customer customer = new Customer();

            //customer.rememberShop(shopA);
            //customer.rememberShop(shopB);

            //int q1 = customer.buyGoods("A", 160);
            //int q2 = customer.buyGoods("B", 40);

            //shopA.displayAssortment();
            //shopB.displayAssortment();

            //if (q1 > 0)
            //    Console.WriteLine($"\n\nThe product A is over. Missing {q1}\n");
            //if (q2 > 0)
            //    Console.WriteLine($"\n\nThe product B is over. Missing {q2}\n");
        }
    }
}
