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
            BatchOfGoods batch1 = new BatchOfGoods();
            BatchOfGoods batch2 = new BatchOfGoods("Good");
            BatchOfGoods batch3 = new BatchOfGoods("Good", 8754, 10, 20, new DateTime());

            PackageOfGoods package1 = new PackageOfGoods();
            PackageOfGoods package2 = new PackageOfGoods("Good");

            Warehouse warehouse = new Warehouse();

            Customer customer = new Customer();

            SupplierOfGoods supplier1 = new SupplierOfGoods();
            SupplierOfGoods supplier2 = new SupplierOfGoods(20);

            Shop shop1 = new Shop();
            Shop shop2 = new Shop("Shop");
            Shop shop3 = new Shop("Good", 20, 10000);
        }
    }
}
