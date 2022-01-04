
package demo;

public class Programming_lab_05 
{
	public static void main(String[] args)
	{
		SupplierOfGoods supplier = new SupplierOfGoods();

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
	}
}