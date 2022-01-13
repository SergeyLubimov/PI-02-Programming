import java.util.ArrayList;

public class Warehouse implements Cloneable 
{
	private ArrayList<PackageOfGoods> packages_;
	
	@Override
    public Warehouse clone() throws CloneNotSupportedException
    {
        Warehouse copy = (Warehouse) super.clone();
        copy.packages_ = (ArrayList<PackageOfGoods>) this.packages_.clone();
        //Driver driver = this.getDriver().clone();
        //newCar.setDriver(driver);
        return copy;
    }
	
	public Warehouse()
    {
        packages_ = new ArrayList<PackageOfGoods>();
    }
	
	public void addBatchOfGoods(BatchOfGoods batch)
	{
		int n = packages_.size();
	    int i = 0;
	    for (; i < n; i++)
	    {
	        if (packages_.get(i).getName() == batch.getName())
	            n = -1;
	    }
	
	    if (n < 0) packages_.get(i - 1).addBatchOfGoods(batch);
	    else packages_.add(new PackageOfGoods(batch));
	}
	
	 public float sellBatchsOfGoods(String name, int[] quantity)
     {
         int n = packages_.size();
         int i = 0;
         for (; i < n; i++)
         {
             if (packages_.get(i).getName() == name)
                 n = -1;
         }
         float ret = 0;

         if (n < 0) ret = packages_.get(i - 1).sellBatchsOfGoods(quantity);

         return ret;
     }
	 
	 public String getPackagesAsString()
     {
         packages_.sort((x, y) -> x.getName().compareTo(y.getName()));

         String str = "";

         for(PackageOfGoods p: packages_)
             str += p.getPackageAsString();

         return str;         
     }
}
