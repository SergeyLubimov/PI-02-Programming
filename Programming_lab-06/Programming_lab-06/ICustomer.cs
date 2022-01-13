using System;
using System.Collections.Generic;
using System.Text;

namespace Programming_lab_06
{
    interface ICustomer
    { 
        public void rememberShop(Shop shop);

        public int buyGoods(string name, int quantity);
    }
}
