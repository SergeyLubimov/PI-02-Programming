import java.util.*;

public abstract class SupplierOfGoods
{
	  private ArrayList<Contract> contracts_;
      private float margin_;
      
      public abstract boolean acceptOrder(Shop shop, String name, int quantity);
      
      
      public ArrayList<Contract> getContracts()
      {
    	  return contracts_;
      }

      public SupplierOfGoods()
      {
          margin_ = 1;
          contracts_ = new ArrayList<Contract>();
      }
      public SupplierOfGoods(int percent)
      {
    	  this();
          setMargin(percent);
      }

      public void setMargin(int percent)
      {
          margin_ = 1 + percent / 100;
      }
      public void addContract(Shop shop)
      {
          int n = contracts_.size();
          for (int i = 0; i < n; i++)
              if (contracts_.get(i).shop_ == shop) n = -1;
          
          if(n >= 0) 
              contracts_.add(new Contract(shop));
      }
      
      public void fulfillOrders()
      {
          for(Contract contract: contracts_)
          {
              for(Order order: contract.orders_)
              {        
            	  BatchOfGoods batch = new BatchOfGoods();
                  batch.setName(order.getName());
                  batch.setID((int)(Math.random() + (int)(order.getName().charAt(0))) % 100000000);
                  batch.setPrice((int)(order.getName().charAt(0)) * margin_);
                  batch.setQuantity(order.getQuantity());
                  batch.setDate(new Date());

                  contract.ready_orders_.add(batch);
              }
          }
      }
      public float sellOrders(Shop shop)
      {
          int i = 0;
          int n = contracts_.size();
          for (; i < n; i++)
              if (contracts_.get(i).shop_ == shop) n = -1;
          i--;

          float sum = 0;
          BatchOfGoods batch;
          while(n < 0 && contracts_.get(i).ready_orders_.size() > 0)
          {
              batch = contracts_.get(i).ready_orders_.get(0);
              sum += batch.getPrice() * batch.getQuantity();
              shop.addBatchOfGoods(batch);
              contracts_.get(i).ready_orders_.remove(0);
          }
          return sum;
      }  
}
