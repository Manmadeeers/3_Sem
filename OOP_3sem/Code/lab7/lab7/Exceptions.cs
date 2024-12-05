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
    public class RemoveElementException : Exception
    {
        public RemoveElementException() : base() { }
        public RemoveElementException(string message) : base(message) { }
    }

    public class EmptyCollectionException : Exception
    {
       
        public EmptyCollectionException() : base() { }
        public EmptyCollectionException(string message) : base("collection is empty. Thus no elements can be printed") { }
    }

    public class UnexistingFileException : Exception
    {
        public UnexistingFileException() : base() { }
        public UnexistingFileException(string message) : base("Such a file does not exist. Please doublechek it") { }
    }

}
