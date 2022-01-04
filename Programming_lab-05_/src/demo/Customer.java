
package demo;
import java.util.ArrayList;

public class Customer
{
	private ArrayList<Shop> shop_in_mind_;

      	public Customer()
      	{
        	shop_in_mind_ = new ArrayList<Shop>();
      	}

      	public void rememberShop(Shop shop)
      	{
          	if (!(shop_in_mind_.contains(shop)))
              		shop_in_mind_.add(shop);
      	}

      	public int buyGoods(String name, int quantity)
      	{
    	  	int[] q = new int[1];
    	  	q[0] = quantity;
          	int n = shop_in_mind_.size();
          	for (int i = 0; quantity > 0 && i < n; i++)
              		shop_in_mind_.get(i).sellBatchsOfGoods(name, q);
          	return q[0];
      	}
}