using lab11;
using System;
using System.Diagnostics;

namespace Lab11
{
    internal class Program
    {
        private static void Main(string[] args)
        {

           Class1 cl1 = new Class1();
            Type customParam = typeof(string);  
            Reflector.CollectInfo("Class1","string");
            Reflector.InvokeFromFile(cl1, "SayHello", new object[] { });

            var instance = Reflector.Create<Class1>;
            if(instance != null)
            {
                Console.WriteLine($"Created {instance.ToString()}");
            }
        }
    }
}