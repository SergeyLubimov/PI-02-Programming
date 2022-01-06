import java.util.ArrayList;

public class Contract 
{
	public Shop shop_;
    public ArrayList<Order> orders_;
    public ArrayList<BatchOfGoods> ready_orders_;

    public Contract(Shop shop)
    {
        shop_ = shop;
        orders_ = new ArrayList<Order>();
        ready_orders_ = new ArrayList<BatchOfGoods>();
    }
}
