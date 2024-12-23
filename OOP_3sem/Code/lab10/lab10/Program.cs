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
        }
    }
}