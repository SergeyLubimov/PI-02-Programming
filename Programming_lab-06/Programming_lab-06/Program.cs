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

			




		//	Console.WriteLine("\x01");


		//	SupplierOfGoods supplier = new SupplierOfGoods();

		//	Shop[] shopsA = new Shop[3];

		//	for (int i = 0; i < 3; i++)
		//	{
		//		shopsA[i] = new Shop($"Shop A{i + 1}", 20, 10000);
		//		shopsA[i].signContract(supplier);
		//		shopsA[i].makeOrder("A", i + 1);
		//		Console.Write(shopsA[i].getName() + ' ');
		//	}
		//	Console.WriteLine("\n");

		//	Shop[,] shopsB = new Shop[3, 3];

		//	for (int i = 0; i < 3; i++)
		//	{
		//		for (int j = 0; j < 3; j++)
		//		{
		//			shopsB[i, j] = new Shop($"Shop B{i * 3 + j + 1}", 20, 10000);
		//			shopsB[i, j].signContract(supplier);
		//			shopsB[i, j].makeOrder("B", i * 3 + j + 1);
		//			Console.Write(shopsB[i, j].getName() + ' ');

		//		}
		//		Console.WriteLine("");
		//	}
		//	supplier.fulfillOrders();

		//	for (int i = 0; i < 3; i++)
		//	{
		//		shopsA[i].redeemOrders();
		//		shopsA[i].displayAssortment();
		//		for (int j = 0; j < 3; j++)
		//		{
		//			shopsB[i, j].redeemOrders();
		//			shopsB[i, j].displayAssortment();
		//		}
		//	}
		//}
	}
}
