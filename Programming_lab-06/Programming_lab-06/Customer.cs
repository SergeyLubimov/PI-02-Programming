using System;
using System.Collections.Generic;
using System.Text;

namespace Programming_lab_06
{
    struct Customer
    {
        private List<Shop> shop_in_mind_;

        //public Customer()
        //{
        //    shop_in_mind_ = new List<Shop>();
        //}

        public string check_string_;

        public List<Shop> Mind
        {
            get { return shop_in_mind_; }
        }

        public void rememberShop(Shop shop)
        {
            if (shop_in_mind_ == null) shop_in_mind_ = new List<Shop>();
            if (!(shop_in_mind_.Contains(shop)))
                shop_in_mind_.Add(shop);
        }

        public int buyGoods(string name, int quantity)
        {
            int n = shop_in_mind_.Count;
            for (int i = 0; quantity > 0 && i < n; i++)
                shop_in_mind_[i].sellBatchsOfGoods(name, ref quantity);
            return quantity;
        }
    }
}
