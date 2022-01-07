
import java.util.*;

public class PackageOfGoods
{
	private String name_;
	private ArrayList<BatchOfGoods> batchs_;
	
	public PackageOfGoods()
	{
		name_ = "";
		batchs_ = new ArrayList<BatchOfGoods>();
	}
	public PackageOfGoods(String name)
    {
		this();
        setName(name);
    }
	public void setName(String name)
	{
		name_ = name;
	}
	public String getName()
	{
		return name_;
	}
	 public PackageOfGoods(BatchOfGoods batch)
     {
		 batchs_ = new ArrayList<BatchOfGoods>();

         if (batchs_.size() == 0)
             setName(batch.getName());
         batchs_.add(batch);
     }
	 public float sellBatchsOfGoods(int[] quantity)
     {
         batchs_.sort((x, y) -> x.getDate().compareTo(y.getDate()));

         int n = batchs_.size();
         float sum = 0;

         for(int i = 0; quantity[0] > 0 && i < n; i++)
         {
             sum += batchs_.get(0).sellBatchOfGoods(quantity);
             if(batchs_.get(0).getQuantity() == 0) batchs_.remove(0);
         }
         return sum;
     }
	 
	 public String getPackageAsString()
     {
		 batchs_.sort((x, y) -> x.getDate().compareTo(y.getDate()));
		 
         String str = "\n";

         for (int i = 0; i < 21; i++) str += "=";
         str += "\n" + name_ + "\n";
         for (int i = 0; i < 21; i++) str += "=";

         for(BatchOfGoods batch: batchs_)
             str += batch.getBatchAsStringWithoutName();

         return str;
     }
	 
	 public void addBatchOfGoods(BatchOfGoods batch)
     {
         if (batchs_.size() == 0)
             setName(batch.getName());
         batchs_.add(batch);
     }

}
