using System;

namespace Programming_lab_06
{
    class Program
    {
        static void Main(string[] args)
        {

            BatchOfGoods batch = new BatchOfGoods();
            Customer customer = new Customer();

            batch.Name = "Original value for Batch\n";
            customer.check_string_ = "Original value for Customer\n";

            BatchOfGoods batch1 = batch;
            Customer customer1 = customer;

            batch1.Name = "New value for Batch\n";
            customer1.check_string_ = "New value for Customer\n";

            Console.WriteLine(batch.Name + customer.check_string_);


            SupplierOfGoods supplier = new SupplierOfGoods();
            supplier.setMatgin(20);

            Shop[] shops = new Shop[5];

            for (int i = 0; i < shops.Length; i++)
            {
                shops[i] = new Shop(String.Format($"Shop {i + 1}"));
                shops[i].signContract(supplier);
                shops[i].investMoney(10000);
                shops[i].makeOrder(String.Format($"Good {i + 1}"), i + 1);
            }

            supplier.fulfillOrders();

            Customer[] customers = new Customer[5];

            for (int i = 0; i < shops.Length; i++)
            {
                shops[i].redeemOrders();
                shops[i].displayAssortment();

                for (int j = 0; j < customers.Length; j++)
                {
                    customers[j] = new Customer();
                    customers[j].rememberShop(shops[i]);
                }
            }

            for (int j = 0; j < customers.Length; j++)
            {
                customers[j].buyGoods(String.Format($"Good {j + 1}"), j + 1);
            }

            foreach (Shop shop in shops) shop.displayAssortment();











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
