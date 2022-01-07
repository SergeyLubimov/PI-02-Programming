using System;
using System.Collections.Generic;
using System.Text;

namespace Programming_lab_06
{
    class PackageOfGoods
    {
        private string name_;
        private List<BatchOfGoods> batchs_;

        public PackageOfGoods()
        {
            name_ = "";
            batchs_ = new List<BatchOfGoods>();
        }
        public PackageOfGoods(string name)
        {
            name_ = name;
            batchs_ = new List<BatchOfGoods>();
        }
        public PackageOfGoods(BatchOfGoods batch)
        {
            batchs_ = new List<BatchOfGoods>();

            if (batchs_.Count == 0)
                setName(batch.Name);
            batchs_.Add(batch);
        }
        public void setName(string name)
        {
            name_ = name;
        }

        public string getName()
        {
            return name_;
        }
        public void addBatchOfGoods(BatchOfGoods batch)
        {
            if (batchs_.Count == 0)
                setName(batch.Name);
            batchs_.Add(batch);
        }
        public float sellBatchsOfGoods(ref int quantity)
        {
            batchs_.Sort((x, y) => x.Date.CompareTo(y.Date));

            int n = batchs_.Count;
            float sum = 0;

            for(int i = 0; quantity > 0 && i < n; i++)
            {
                sum += batchs_[0].sellBatchOfGoods(ref quantity);
                if(batchs_[0].Quantity == 0) batchs_.RemoveAt(0);
            }
            return sum;
        }
        public string getPackageAsString()
        {
            batchs_.Sort((x, y) => x.Date.CompareTo(y.Date));

            string str = "\n";

            for (int i = 0; i < 21; i++) str += "=";
            str += "\n" + name_ + "\n";
            for (int i = 0; i < 21; i++) str += "=";

            foreach(BatchOfGoods batch in batchs_)
                str += batch.getBatchAsStringWithoutName();

            return str;
        }
    }
    class Warehouse
    {
        private List<PackageOfGoods> packages_;

        public static Warehouse operator +(Warehouse w1, Warehouse w2)
        {
            Warehouse warehouse = new Warehouse();

            foreach (PackageOfGoods p in w1.packages_) warehouse.packages_.Add(p);
            foreach (PackageOfGoods p in w2.packages_) warehouse.packages_.Add(p);

            return warehouse;
        }

        public Warehouse()
        {
            packages_ = new List<PackageOfGoods>();
        }

        public PackageOfGoods this[int index]
        {
            get
            {
                return packages_[index];
            }
        }

        public void addBatchOfGoods(BatchOfGoods batch)
        {
            int n = packages_.Count;
            int i = 0;
            for (; i < n; i++)
            {
                if (packages_[i].getName() == batch.Name)
                    n = -1;
            }

            if (n < 0) packages_[i - 1].addBatchOfGoods(batch);
            else packages_.Add(new PackageOfGoods(batch));
        }
        public float sellBatchsOfGoods(string name, ref int quantity)
        {
            int n = packages_.Count;
            int i = 0;
            for (; i < n; i++)
            {
                if (packages_[i].getName() == name)
                    n = -1;
            }
            float ret = 0;

            if (n < 0) ret = packages_[i - 1].sellBatchsOfGoods(ref quantity);

            return ret;
        }

        public string getPackagesAsString()
        {
            packages_.Sort((x, y) => x.getName().CompareTo(y.getName()));

            string str = "";

            foreach(PackageOfGoods package in packages_)
                str += package.getPackageAsString();

            return str;
            
        }       
    }
}
