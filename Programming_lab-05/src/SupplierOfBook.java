
public class SupplierOfBook extends SupplierOfGoods
{
	@Override
	public boolean acceptOrder(Shop shop, String name, int quantity)
	{      
		boolean ret = false;
		
		if(name.indexOf("Book:") == 0)
		{
	        int n = getContracts().size();
	        int i = 0;
	        for(; i < n; i++)            
	            if (getContracts().get(i).shop_ == shop) n = -1;
	
	        
	        if (n < 0)
	        {
	        	getContracts().get(i - 1).orders_.add(new Order(name, quantity));
	        }
		}
        return ret;            
    }

}
