using System;
using System.Collections.Generic;
using System.Text;

namespace Programming_lab_06
{
    abstract class SupplierOfGoods
    {
        private List<Contract> contracts_;
        private float margin_;

        public List<Contract> Contracts
        {
            get { return contracts_; }
        }

        public abstract bool acceptOrder(Shop shop, string name, int quantity);        

        public SupplierOfGoods()
        {
            margin_ = 1;
            contracts_ = new List<Contract>();
        }
        public SupplierOfGoods(int percent): this()
        {
            setMargin(percent);
        }


        public void setMargin(int percent)
        {
            margin_ = 1 + percent / 100;
        }
        public void addContract(Shop shop)
        {
            int n = contracts_.Count;
            for (int i = 0; i < n; i++)
                if (contracts_[i].shop_ == shop) n = -1;
            
            if(n >= 0) 
                contracts_.Add(new Contract(shop));
        }
        
        public void fulfillOrders()
        {
            foreach(Contract contract in contracts_)
            {
                foreach(Order order in contract.orders_)
                {
                    Random rdm = new Random();

                    BatchOfGoods batch = new BatchOfGoods();

                    batch.Name = order.getName();
                    batch.ID = (rdm.Next() + (int)(order.getName()[0])) % 100000000;
                    batch.Price = (int)(order.getName()[0]) * margin_;
                    batch.Quantity = order.getQuantity();
                    batch.Date = DateTime.Now;               

                    contract.ready_orders_.Add(batch);
                }
            }
        }
        public float sellOrders(Shop shop)
        {
            int i = 0;
            int n = contracts_.Count;
            for (; i < n; i++)
                if (contracts_[i].shop_ == shop) n = -1;
            i--;

            float sum = 0;
            BatchOfGoods batch;
            while(n < 0 && contracts_[i].ready_orders_.Count > 0)
            {
                batch = contracts_[i].ready_orders_[0];
                sum += batch.Price * batch.Quantity;
                shop.addBatchOfGoods(batch);
                contracts_[i].ready_orders_.RemoveAt(0);
            }
            return sum;
        }  
    }
    class Order
    {
        private string name_;
        private int quantity_;

        public Order(string name, int quantuty)
        {
            name_ = name;
            quantity_ = quantuty;
        }
        public string getName() { return name_; }
        public int getQuantity() { return quantity_; }

    }
    class Contract
    {
        public Shop shop_;
        public List<Order> orders_;
        public List<BatchOfGoods> ready_orders_;

        public Contract(Shop shop)
        {
            shop_ = shop;
            orders_ = new List<Order>();
            ready_orders_ = new List<BatchOfGoods>();
        }
    }
}
