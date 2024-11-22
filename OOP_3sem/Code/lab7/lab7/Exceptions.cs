using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab7
{
    public class AddElementException : Exception
    {
        public AddElementException() : base() { }
        public AddElementException(string message) : base("Collection overflow. could not add an element") { }
    }

}
