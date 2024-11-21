using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//https://learn.microsoft.com/en-us/dotnet/csharp/

namespace lab6
{
    public class CommonException : Exception
    {
        public CommonException() : base() { }
        public CommonException(string message) : base(message)
        {
            HelpLink = "https://learn.microsoft.com/en-us/dotnet/csharp/";
        }
        public CommonException(string message,Exception ex):base(message,ex) 
        {
            HelpLink = "https://learn.microsoft.com/en-us/dotnet/csharp/";
        }

    }

    public class EmptyStorageException : CommonException
    {
        public EmptyStorageException() : base("Storage is empty. No operations could be proceeded") { }
        public EmptyStorageException(string message) : base("EmptyStorageException") { }

    }

    public class WrongElementException : CommonException
    {
        public WrongElementException() : base("There is no such element") { }
        public WrongElementException(string message) : base("EmptyStorageException") { }
    }

}
