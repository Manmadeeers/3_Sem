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
            Reflector.CollectInfo("Class1","string","fileContent.json");
        }
    }
}