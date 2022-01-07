﻿using System;
using System.Collections.Generic;
using System.Text;

namespace Programming_lab_06
{
    class Shop
    {
        private string name_;
        private Warehouse warehouse_;
        private float cash_;
        private float margin_;
        private SupplierOfGoods contract_with_supplier_;

        private static string str_ = "Checking a static field!";

        public static string Str
        {
            get { return str_; }
            set { str_ = value; }
        }


        public static Shop operator ++(Shop shop)
        {
            shop.cash_ += 10000;
            return shop;
        }

        public Shop()
        {
            margin_ = 1;
            name_ = "";
            cash_ = 0;
            warehouse_ = new Warehouse();
            contract_with_supplier_ = null;
        }
        public Shop(string name): this()
        {            
            this.setName(name);
        }
        public Shop(String name, int percent, float cash): this(name)
        {
            setMargin(percent);
            cash_ = cash;
        }
        public void setMargin(int percent)
        {
            margin_ = 1 + percent / 100;
        }
        public void setName(string name)
        {
            name_ = name;
        }
        public void signContract(SupplierOfGoods supplier)
        {
            supplier.addContract(this);
            contract_with_supplier_ = supplier;
        }

        public bool makeOrder(string name, int quantity)
        {
            return contract_with_supplier_.acceptOrder(this, name, quantity);
        }

        public string getName()
        {
            return name_;
        }

        public void addBatchOfGoods(BatchOfGoods batch)
        {
            batch.Price = batch.Price * margin_;
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

        public bool sellBatchsOfGoods(string name, ref int quantity)
        {
            bool ret = true;

            int Q = quantity;

            cash_ += warehouse_.sellBatchsOfGoods(name, ref quantity);

            if (Q == quantity) ret = false; 

            return ret;
        }
        public void displayAssortment()
        {
            string str = String.Format($"\n\n*** {name_} ***\n|cash: {cash_}");

            Console.WriteLine(str + warehouse_.getPackagesAsString());
        }

        
        
    }
}
