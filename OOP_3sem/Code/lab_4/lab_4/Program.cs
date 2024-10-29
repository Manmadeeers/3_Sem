using System;


namespace lab_4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Sofa sofa1 = new Sofa("Sofa", "200$");
            Console.WriteLine(sofa1.ToString());

            Console.WriteLine("Interfase and base class methods");
            sofa1.isClean();
            IFurniture sf = sofa1 as IFurniture;
            sf.isClean();
            Console.WriteLine("<-----End----->");


            Chair chair1 = new Chair("Chair", "60$");
            chair1.Sit();
            chair1.isClean();

            Hanger hanger1 = new Hanger("Hanger", "10$");

            NightStand NS1 = new NightStand("Night stand", "150$");
            Console.WriteLine($"Night Stand hash code: {NS1.GetHashCode()}");
            Console.WriteLine($"If Night Stand equals to Hanger: {NS1.Equals(hanger1)}");

            Closet closet1 = new Closet("Closet", "500$");

          

            Bed bed1 = new Bed("Bed", "1000$");
            bed1.Buy();

            Console.WriteLine("Working with a list of products");

            List<Product>products = new List<Product>();
            products.Add(sofa1);
            products.Add(bed1);
            products.Add(closet1);
            products.Add(hanger1);
            foreach(var item in products)
            {
                Printer.IAmPrinting(item);
            }
            Console.WriteLine("Checking how is operator works");
            foreach(var item in products)
            {
                if(item is Sofa||item is Chair)
                {
                    item.Buy();
                }
                if(item is Bed||item is Closet)
                {
                    item.isClean();
                }
                if(item is Hanger)
                {
                    Hanger? hng =  item as Hanger;
                    Console.WriteLine($"I found a hanger!!! It's {hng.Name} and it costs {hng.Price} ");
                }
            }
        }
    }
}