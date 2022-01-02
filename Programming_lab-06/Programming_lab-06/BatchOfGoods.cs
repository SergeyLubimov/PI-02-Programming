using System;
using System.Collections.Generic;
using System.Text;

namespace Programming_lab_06
{
    class BatchOfGoods
    {
        private string name_;
        private int ID_;
        private float price_;
        private int quantity_;
        private DateTime date_;

        public BatchOfGoods()
        {
            name_ = "";
            ID_ = 0;
            price_ = 0;
            quantity_ = 0;
            DateTime date = new DateTime();
            date_ = date;
        }

  
        public string getName()
        {
            return name_;
        }
        public int getID()
        {
            return ID_;
        }
        public float getPrice()
        {
            return price_;
        }
        public int getQuantity()
        {
            return quantity_;
        }
        public DateTime getDate()
        {
            return date_;
        }
        public void setName(string name)
        {
            name_ = name;
        }
        public void setID(int id)
        {
            if(Math.Log10(id) <= 8)
            {
                ID_ = id;
            }
        }
        public void setPrice(float price)
        {
            if (price > 0)
            {
                price_ = price;
            }
        }
        public void setQuantity(int quantity)
        {
            if (quantity > 0)
            {
                quantity_ = quantity;
            }
        }
        public void setDate(DateTime date)
        {
            date_ = date;
        }
        public void setDate(string str)
        {
            string[] s = str.Split('.');
            DateTime date = new DateTime(Convert.ToInt32(s[2]), 
                Convert.ToInt32(s[1]), Convert.ToInt32(s[0]));

            date_ = date;
        }
        public BatchOfGoods Clone()
        {
            BatchOfGoods batch = new BatchOfGoods();

            batch.setName(String.Copy(name_));
            batch.setID(ID_);
            batch.setPrice(price_);
            batch.setQuantity(quantity_);
            batch.setDate(date_);

            return batch;            
        }
        public float sellBatchOfGoods(ref int quantity)
        {
            float ret;

            if (quantity_ > quantity)
            {
                ret = quantity * price_;
                quantity_ -= quantity;
                quantity = 0;
            }
            else
            {
                ret = quantity_ * price_;
                quantity -= quantity_;
                quantity_ = 0;
            }
            return ret;
        }
        public string getBatchAsStringWithoutName()
        {
            string str = "";

            str += "\n   | ID: ";

            int n = (int)Math.Log10(ID_);

            for (; n < 7; n++) str += "0";          

            str += ID_;

            str += String.Format("\n   | Price: {0}", price_);
            str += String.Format("\n   | Quantity: {0}", quantity_);
            str += String.Format("\n   | Date: {0}\n   ", date_.ToShortDateString());

            for (int i = 0; i < 18; i++) str += "-";


            return str;
        }
    }
}
