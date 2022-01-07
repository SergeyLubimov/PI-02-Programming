


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
			//shop.displayAssortment();
		}
		
		shops[0].displayAssortment();
		
		BatchOfGoods.setDateFormat("d MMMM yyyy G");
		
		shops[0].displayAssortment();
		
		
		
		
	}
}
