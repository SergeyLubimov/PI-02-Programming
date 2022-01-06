


public class Programming_lab_05 
{
	
	private static void increase(Buff buff)
	{
		buff.setValue(buff.getValue() + 1);
	}
	
	public static void main(String[] args)
	{
		SupplierOfGoods supplier = new SupplierOfGoods();
		
		Shop[] shops = new Shop[5];
		
		for(int i = 0; i < shops.length; i++)
		{
			shops[i] = new Shop(String.format("Shop %d", i + 1));
			shops[i].signContract(supplier);
			supplier.addContract(shops[i]);
			shops[i].investMoney(10000);
			shops[i].makeOrder(String.format("Goood %d", i + 1), i + 1);
		}		
		
		supplier.fulfillOrders();
		
		for(Shop shop: shops)
		{
			shop.redeemOrders();
			shop.displayAssortment();
		}
		
		int a = 1;
		Buff buff = new Buff();
		buff.setValue(a);
		
		System.out.printf("%d\n", a);
		
		increase(buff);
		
		a = buff.getValue();		
		
		System.out.printf("%d", a);
		
		
		
		
		
		
		/*SupplierOfGoods supplier = new SupplierOfGoods();

        supplier.setMatgin(20);

        Shop shopA, shopB;

        shopA = new Shop();
        shopB = new Shop();

        shopA.setName("Shop A");
        shopB.setName("Shop B");

        shopA.setMargin(10);
        shopA.setMargin(15);

        supplier.addContract(shopA);
        supplier.addContract(shopB);

        shopA.signContract(supplier);
        shopB.signContract(supplier);

        shopA.investMoney(10000);
        shopB.investMoney(10000);

        shopA.displayAssortment();
        shopB.displayAssortment();

        shopA.makeOrder("A", 150);
        shopB.makeOrder("A", 150);
        shopB.makeOrder("B", 30);

        supplier.fulfillOrders();

        shopA.redeemOrders();
        shopB.redeemOrders();

        shopA.displayAssortment();
        shopB.displayAssortment();

        Customer customer = new Customer();

        customer.rememberShop(shopA);
        customer.rememberShop(shopB);

        int q1 = customer.buyGoods("A", 160);
        int q2 = customer.buyGoods("B", 40);

        shopA.displayAssortment();
        shopB.displayAssortment();

        if (q1 > 0)
            System.out.printf("\n\nThe product A is over. Missing " + q1 + "\n");
        if (q2 > 0)
            System.out.printf("\n\nThe product B is over. Missing " + q2 + "\n");
	*/
	}
}
