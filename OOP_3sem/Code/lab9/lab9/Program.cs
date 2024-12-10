using lab9;
using System;
using System.Linq.Expressions;

namespace Lab9
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Service service1 = new Service("Cleaning", 200);
            Service service2 = new Service("Coding", 20);
            Service service3 = new Service("Code review", 1000);
            Service service4 = new Service("Sdelat' kursach", 5000);

            ServiceCollection collection1 = new ServiceCollection();
            collection1.Add(service1,service1);
            collection1.Add(service2,service2);
            collection1.Add(service3,service3);
            collection1.Add(service4,service4);
            collection1.Print();
            
        }
    }
}