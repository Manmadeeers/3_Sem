using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_4
{
    public abstract class Product
    {
        protected string name;
        public string Name { 
            get { return name; }
            set {
                if (String.IsNullOrEmpty(value))
                {
                    throw new Exception("Can't initialize a field with null or empty meaning");
                }
                name = value; 
            } 
        }

        protected string price;
        public string Price {
            get { return price; } 
            set {
                if (String.IsNullOrEmpty(value)) {
                    throw new Exception("Can't initialize a filed with null or empty value");
                } 
                price = value; 
            } 
        }

        protected Product(string Nname,string Nprice)
        {
            if (String.IsNullOrEmpty(Nname) || String.IsNullOrEmpty(Nprice))
            {
                throw new Exception("Can't initialize field with null or empty meaning");
            }
            name = Nname;
            price = Nprice;
        }



    }//end of Product

    public abstract class Furniture : Product
    {

    }



}
