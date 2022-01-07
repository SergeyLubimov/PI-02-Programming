
import java.util.*;

public class Programming_lab_05 
{
	
	private static void increase(Buff buff)
	{
		buff.setValue(buff.getValue() + 1);
	}
		
	public static void main(String[] args)
	{
		BatchOfGoods batch1 = new BatchOfGoods();
		BatchOfGoods batch2 = new BatchOfGoods("Good");
		BatchOfGoods batch3 = new BatchOfGoods("Good", 8754, 10, 20, new Date());
		
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
