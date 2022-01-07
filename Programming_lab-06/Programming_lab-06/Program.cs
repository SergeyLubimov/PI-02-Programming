using System;

namespace Programming_lab_06
{
    class Program
    {
        static void Func1(ref string a)
        {
            a = "C#";
        }
        static void Func2(out string a)
        {
            a = "C#";
        }
        static void Func3(ref string a)
        {
            ;
        }
        //static void Func4(out string a)
        //{
        //    ;
        //}
        static void Main(string[] args)
        {
            try
            {
                BatchOfGoods batch = new BatchOfGoods();
                batch.Price = -200;
            }
            catch (ArgumentException e)
            {
                Console.WriteLine(e.Message + '\n');
            }

        }
    }
}
