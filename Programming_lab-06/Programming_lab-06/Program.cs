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
            BatchOfGoods b1 = BatchOfGoods.createRandom("A");
            BatchOfGoods b2 = BatchOfGoods.createRandom("B");

            Console.WriteLine($"A: {b1.getBatchAsStringWithoutName()}\n" +
                $"B: {b2.getBatchAsStringWithoutName()}\n\n{Shop.Str}");



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
