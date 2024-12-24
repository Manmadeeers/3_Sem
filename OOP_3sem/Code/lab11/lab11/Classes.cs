using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab11
{
    public class Class1
    {
        private string _name;
        private int _age;

        public string Name
        {
            get { return _name; }
        }
        public int Age
        {
            get { return _age; }
        }
        public void PrintName()
        {
            Console.WriteLine(Name);
        }
        public string SayHello(string message)
        {
            return $"Hello {message}";
        }
    }
}
