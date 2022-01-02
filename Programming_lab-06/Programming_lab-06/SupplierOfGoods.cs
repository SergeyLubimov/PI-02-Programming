using System;
using System.Collections.Generic;
using System.Text;

namespace Programming_lab_06
{
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

    class SupplierOfGoods
    {
        private List<Contract> contracts_;
        private float margin_;

        public SupplierOfGoods()
        {
            margin_ = 1;
            contracts_ = new List<Contract>();
        }

        public void setMatgin(int percent)
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
        public bool acceptOrder(Shop shop, string name, int quantity)
        {            
            int n = contracts_.Count;
            int i = 0;
            for(; i < n; i++)            
                if (contracts_[i].shop_ == shop) n = -1;

            bool ret = false;
            if (n < 0)
            {
                ret = true;
                contracts_[i - 1].orders_.Add(new Order(name, quantity));
            }
            return ret;            
        }
        public void fulfillOrders()
        {
            foreach(Contract contract in contracts_)
            {
                foreach(Order order in contract.orders_)
                {
                    Random rdm = new Random();

                    BatchOfGoods batch = new BatchOfGoods();
                    batch.setName(order.getName());
                    batch.setID((rdm.Next() + (int)(order.getName()[0])) / 100000000);
                    batch.setPrice((int)(order.getName()[0]) * margin_);
                    batch.setQuantity(order.getQuantity());
                    batch.setDate(new DateTime());

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
                sum += batch.getPrice() * batch.getQuantity();
                shop.addBatchOfGoods(batch);
                contracts_[i].ready_orders_.RemoveAt(0);
            }
            return sum;
        }
        

    }
}
