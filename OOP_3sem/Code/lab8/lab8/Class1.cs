using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab8
{
    public class Class1
    {

        public delegate void SomeDelegate();

        public event SomeDelegate? SomeEvent;

        public void doSomething()
        {
            Console.WriteLine("Something is done");
            SomeEvent?.Invoke();
        }

        public void HandleEvent()
        {
            Console.WriteLine("Event");
        }
    }
}
