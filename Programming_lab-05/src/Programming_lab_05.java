
import java.util.*;

public class Programming_lab_05 
{
	
	private static void increase(Buff buff)
	{
		buff.setValue(buff.getValue() + 1);
	}
		
	public static void main(String[] args)
	{
		SupplierOfGoods supplier = new SupplierOfGoods();

		Shop[] shopsA = new Shop[3];

		for (int i = 0; i < 3; i++)
		{
			shopsA[i] = new Shop(String.format("Shop A%d", i + 1 ), 20, 10000);
			shopsA[i].signContract(supplier);
			shopsA[i].makeOrder("A", i + 1);
			System.out.print(shopsA[i].getName() + ' ');
		}
		System.out.print("\n\n");

		Shop[][] shopsB = new Shop[3][3];

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				shopsB[i][j] = new Shop(String.format("Shop B%d", i * 3 + j + 1), 20, 10000);
				shopsB[i][j].signContract(supplier);
				shopsB[i][j].makeOrder("B", i * 3 + j + 1);
				System.out.print(shopsB[i][j].getName() + ' ');
				
			}
			System.out.print("\n\n");
		}
		supplier.fulfillOrders();

		for (int i = 0; i < 3; i++)
		{
			shopsA[i].redeemOrders();
			shopsA[i].displayAssortment();
			for (int j = 0; j < 3; j++)
			{
				shopsB[i][j].redeemOrders();
				shopsB[i][j].displayAssortment();
			}
		}

	}
}
