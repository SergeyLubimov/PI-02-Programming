using System;
using System.Collections.Generic;
using System.Text;

namespace Programming_lab_06
{
    class SupplierOfBook: SupplierOfGoods
    {
        public override bool acceptOrder(Shop shop, string name, int quantity)
        {
            int n = Contracts.Count;
            int i = 0;
            for (; i < n; i++)
                if (Contracts[i].shop_ == shop) n = -1;

            bool ret = false;
            if (n < 0)
            {
                ret = true;
                Contracts[i - 1].orders_.Add(new Order(name, quantity));
            }
            return ret;
        }
    }
}
