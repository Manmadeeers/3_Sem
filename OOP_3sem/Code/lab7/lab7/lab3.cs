using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using lab7;

namespace lab3
{
    public class Password
    {
        private string _password;
        private int _length;
        private const string _default = "1234pass";
        private const int _defaultLenght = 8;
        private const int _maxLength = 12;
        private Production production;
        private Developer developer;

        public Production Prod
        {
            get { return production; }
            set { production = value; }
        }

        public Developer Dev
        {
            get { return developer; }
            set { developer = value; }
        }

        public int MaxLength
        {
            get { return _maxLength; }
        }
        public string Default
        {
            get { return _default; }
        }
        public int DefLength
        {
            get { return _defaultLenght; }
        }

        public string Pass
        {
            get { return _password; }
            set { _password = value; }
        }
        public int Length
        {
            get { return _length; }
        }



        public Password() { }
        public Password(string password)
        {
            if (String.IsNullOrEmpty(password))
            {
                throw new Exception("Password could not be initialized with null or empty string");
            }
            _password = password;
            _length = password.Length;
        }

        public class Production
        {
            private string id;

            public string ID
            {
                get { return id; }
                set { id = value; }
            }

            public Production(string id)
            {
                if (string.IsNullOrEmpty(id))
                {
                    throw new Exception("Can not initialize id with a null or empty meaning");
                }
                this.id = id;
            }
        }

        public class Developer
        {
            private string developer;
            private string id;
            private string otd;

            public string Dev
            {
                get { return developer; }
                set { developer = value; }
            }
            public string ID
            {
                get { return id; }
                set { id = value; }
            }
            public string OTD
            {
                get { return otd; }
                set { otd = value; }
            }
            public Developer(string dev, string id, string otd)
            {
                if (String.IsNullOrEmpty(id) || String.IsNullOrEmpty(dev) || String.IsNullOrEmpty(otd))
                {
                    throw new Exception("Can not initialize with a null or empty string!");
                }
                developer = dev;
                ID = id;
                OTD = otd;
            }
        }

        public void PrintPass()
        {
            Console.Write("Shhhhh, don't tell anybody: ");
            Console.Write(_password);
            Console.WriteLine();
        }


        public override bool Equals(object? obj)
        {
            return base.Equals(obj);
        }
        public override int GetHashCode()
        {
            return base.GetHashCode();
        }

        public static bool operator >(Password pass1, Password pass2)
        {
            if (pass1._length > pass2._length)
            {
                return true;
            }
            return false;

        }

        public static bool operator <(Password pass1, Password pass2)
        {
            if (pass1._length < pass2._length)
            {
                return true;
            }
            return false;
        }

        public static bool operator !=(Password pass1, Password pass2)
        {
            if (!pass1._password.Equals(pass2._password))
            {
                return true;
            }
            return false;
        }

        public static bool operator ==(Password pass1, Password pass2)
        {
            if (pass1._password.Equals(pass2._password))
            {
                return true;
            }
            return false;
        }

        public static Password operator ++(Password pass)
        {

            pass._password = pass.Default;
            pass._length = pass.DefLength;
            return pass;

        }
        public static Password operator --(Password pass)
        {
            pass._password = "nullpass";
            pass._length = 8;
            return pass;
        }


        public static bool operator true(Password pass)
        {

            if (pass._length >= 10 && (pass._password.Contains('!') || pass._password.Contains('$')))
            {
                return true;
            }
            return false;
        }

        public static bool operator false(Password pass)
        {
            if (!(pass._length >= 10 && (pass._password.Contains('!') || pass._password.Contains('$'))))
            {
                return false;
            }
            return true;
        }

        public static Password operator -(Password pass, char item)
        {
            if (item.ToString() == "")
            {
                throw new ArgumentException("Could not substract null from a password");
            }
            string modifiedPassword = pass._password.Substring(0, pass._length - 1);
            modifiedPassword += item;
            pass._password = modifiedPassword;
            return pass;
        }

        public override string ToString()
        {
            return Pass;
        }
    }

    internal static class StaticOperation
    {
        public static char GetMiddleSymbol(this string str)
        {
            if (String.IsNullOrEmpty(str))
            {
                throw new Exception("Impossible to find a middle symbol in a null or empty string");
            }
            char middle;
            int middle_position = str.Length / 2;
            middle = str[middle_position];
            return middle;
        }

        public static bool CheckPassLength(this string pass, int minLength, int maxLength)
        {
            if (String.IsNullOrEmpty(pass))
            {
                throw new Exception("Can not check the validity of a null or empty string");
            }
            if (pass.Length >= minLength && pass.Length <= maxLength)
            {
                return true;
            }
            return false;
        }


        public static int GetSum(Password pass1, Password pass2)
        {

            int sum;
            sum = pass1.Length + pass2.Length;
            return sum;

        }

        public static int GetDiffMinandMax(Password pass1, Password pass2)
        {

            if (pass1.Length > pass2.Length)
            {
                return pass1.Length - pass2.Length;
            }
            else if (pass1.Length == pass2.Length)
            {
                return 0;
            }
            else
            {
                return pass2.Length - pass1.Length;
            }


        }

        public static int CountElements(Password[] Passes)
        {
            if (Passes == null)
            {
                throw new Exception("Empty array");
            }
            return Passes.Length;
        }





    }



}
