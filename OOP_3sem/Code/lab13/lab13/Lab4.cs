using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab13
{
    interface IFurniture
    {
        void isClean();
    }
    public abstract class Product
    {
        protected string name;
        protected bool clean = false;
        public string Name
        {
            get { return name; }
        }

        protected string price;
        public string Price
        {
            get { return price; }
        }

        protected Product(string Nname, string Nprice)
        {
            if (String.IsNullOrEmpty(Nname) || String.IsNullOrEmpty(Nprice))
            {
                throw new Exception("Can't initialize field with null or empty meaning");
            }
            name = Nname;
            price = Nprice;
        }

        public virtual void Clean()
        {
            Console.WriteLine($"{name} is now clean");
            clean = true;
        }
        public abstract void isClean();

        public virtual void Buy()
        {
            Console.WriteLine($"You've bought a {name} for {price}");
        }


    }//end of Product

    interface IChair
    {
        void Sit();
    }

    public abstract class Furniture : Product, IFurniture
    {
        public Furniture(string name, string price) : base(name, price)
        {

        }
        public override string ToString()
        {
            return name + " costs  " + price;
        }
        public override void isClean()
        {
            Console.WriteLine($"This {name} is clean");
        }

    }
}
