using System;
using lab2;
namespace lab10
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            string[] months = { "June", "July", "May", "December", "January", "February", "March", "April", "August", "September", "October", "November" };
            Console.WriteLine("Src month");
            foreach(string month in months)
            {
                Console.WriteLine(month);
            }
            Console.WriteLine("<---------->");
            //Console.Write("Enter the length: ");
            int n = 5;

            Console.WriteLine($"Months with length {n}");
            var lengtMonth = months.Where(m => m.Length == n);
            foreach( var item in lengtMonth )
            {
                Console.WriteLine(item);
            }
            Console.WriteLine("<---------->");

            Console.WriteLine("Summer months");
            var summerMonths = months.Where(m => m == "June" || m == "July" || m == "August");
            foreach(var item in summerMonths)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine("<---------->");
            Console.WriteLine("Winter months");
            var winterMonths = months.Where(m => m == "December" || m == "January" || m == "February");
            foreach(var item in winterMonths)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine("<---------->");
            Console.WriteLine("Months in alphabetical order");
            var alphMonth = months.OrderBy(m => m);
            foreach (var item in alphMonth)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine("<---------->");
            Console.WriteLine("Months with u and length not more then four");
            var selectedMonth = months.Where(m => m.Contains('u') && m.Length >= 4);
            foreach(var item in selectedMonth)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine("<---------->");

            List<Mno> coll = new List<Mno>();

            List<int> mn1 = new List<int>(new[] { 1, 2, 3,4,5,6 });
            Mno mno1 = new Mno(mn1, "Set1");
            coll.Add(mno1);
            List<int> mn2 = new List<int>(new[] {10,23,14,1,32 });
            Mno mno2 = new Mno(mn2, "Set2");
            List<int> mn3 = new List<int>(new[] { 7, 8, 9, 10, 11, 12 });
            Mno mno3 = new Mno(mn3, "Set3");
            coll.Add(mno3);

            List<int> mn4 = new List<int>(new[] { 15, 20, 25, 30, 35 });
            Mno mno4 = new Mno(mn4, "Set4");
            coll.Add(mno4);

            List<int> mn5 = new List<int>(new[] { 40, 50, 60, 70, 80 });
            Mno mno5 = new Mno(mn5, "Set5");
            coll.Add(mno5);

            List<int> mn6 = new List<int>(new[] { 100, 200, 300, 400, 500 });
            Mno mno6 = new Mno(mn6, "Set6");
            coll.Add(mno6);

            List<int> mn7 = new List<int>(new[] { 600, 700, 800, 900, 1000 });
            Mno mno7 = new Mno(mn7, "Set7");
            coll.Add(mno7);

            List<int> mn8 = new List<int>(new[] { 1100, 1200, 1300, 1400, 1500 });
            Mno mno8 = new Mno(mn8, "Set8");
            coll.Add(mno8);

            List<int> mn9 = new List<int>(new[] { 1600, 1700, 1800, 1900, 2000 });
            Mno mno9 = new Mno(mn9, "Set9");
            coll.Add(mno9);

            List<int> mn10 = new List<int>(new[] { 2100, 2200, 2300, 2400, 2500,-256 });
            Mno mno10 = new Mno(mn10, "Set10");
            coll.Add(mno10);
            


            var minSumMnos = coll.Min(m => m.getSum());

            Console.WriteLine($"Minimal sum: {minSumMnos}");
            var maxSumMnos = coll.Max(m => m.getSum());
            Console.WriteLine($"Maximal sum: {maxSumMnos}");

            var mnosWithNegative = coll.Where(sub => sub.Items.Any(item => item < 0));
            Console.WriteLine("Sets with negative elements:");
            foreach(var item in mnosWithNegative)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine("<---------->");

            int requiredValue = 100;
            var mnosWithRequired = coll.Where(sub => sub.Items.Contains(requiredValue));
            Console.WriteLine($"Sets woth required value ({requiredValue}):");
            foreach(var item in mnosWithRequired)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine("<---------->");

            int requiredForFirst = 50;

            var firstMnoWithRequired = coll.FirstOrDefault(sub => sub.Items.Contains(requiredForFirst));
            Console.WriteLine(firstMnoWithRequired);
            Console.WriteLine("<---------->");

            Console.WriteLine("Sets oredered by the first element");
            var orderedByFirst = coll.OrderBy(sub => sub.Items.First());
            foreach(var item in orderedByFirst)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine("<---------->");

        }
    }
}