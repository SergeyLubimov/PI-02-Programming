
public class Order 
{
	 private String name_;
     private int quantity_;
     
     public Order(String name, int quantuty)
     {
         name_ = name;
         quantity_ = quantuty;
     }
     public String getName() { return name_; }
     public int getQuantity() { return quantity_; }
}
