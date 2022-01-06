
public class Shop
{
	 private String name_;
     private Warehouse warehouse_;
     private float cash_;
     private float margin_;
     private SupplierOfGoods contract_with_supplier_;

     public Shop()
     {
         margin_ = 1;
         name_ = "";
         cash_ = 0;
         warehouse_ = new Warehouse();
     }
     public Shop(String name)
     {
         margin_ = 1;
         name_ = name;
         cash_ = 0;
         warehouse_ = new Warehouse();
     }
     public void setMargin(int percent)
     {
         margin_ = 1 + percent / 100;
     }
     public void setName(String name)
     {
         name_ = name;
     }
     public void signContract(SupplierOfGoods supplier)
     {
         contract_with_supplier_ = supplier;
     }
    

     public boolean makeOrder(String name, int quantity)
     {
         return contract_with_supplier_.acceptOrder(this, name, quantity);
     }

     public String getName()
     {
         return name_;
     }

     public void addBatchOfGoods(BatchOfGoods batch)
     {
         batch.setPrice(batch.getPrice() * margin_);
         warehouse_.addBatchOfGoods(batch);
     }
     public void redeemOrders()
     {
         cash_ -= contract_with_supplier_.sellOrders(this);
     }

     public void investMoney(float money)
     {
         if (money > 0) cash_ += money;
     }

     public boolean sellBatchsOfGoods(String name, int[] quantity)
     {
         boolean ret = true;

         int Q = quantity[0];

         cash_ += warehouse_.sellBatchsOfGoods(name, quantity);

         if (Q == quantity[0]) ret = false; 

         return ret;
     }
     public void displayAssortment()
     {
         String str = String.format("\n\n*** %s ***\n|cash: %f", name_, cash_);

         System.out.println(str + warehouse_.getPackagesAsString());
     }
}
