using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

namespace lab13
{
    interface IFurniture
    {
        void isClean();
    }
    
    [Serializable]
    public abstract class Product
    {
        protected string name;
        protected bool clean = false;
        [NonSerialized]
        protected string personalInfo = "Name and Address";
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
        protected Product()
        {

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

    [Serializable]
    public abstract class Furniture : Product, IFurniture
    {
        public Furniture(string name, string price) : base(name, price)
        {

        }
        public Furniture() : base()
        {

        }
        public override string ToString()
        {
            return $"Name:{Name} ; Price:{Price}";
        }
        public override void isClean()
        {
            Console.WriteLine($"This {name} is clean");
        }

    }
    [Serializable]
    public class Sofa : Furniture, IChair, IFurniture
    {
        public Sofa(string name, string price) : base(name, price) { }
        public Sofa() : base() { }
        public void Sit()
        {
            Console.WriteLine("You're sitting on a sofa");
        }

        public override void isClean()
        {
            Console.WriteLine("THIS SOFA IS  CLEAN NOW");
        }
        void IFurniture.isClean()
        {
            Console.WriteLine("Intrerfadce cleaning of sofa");
        }



    }
    [Serializable]
    public class Bed : Furniture
    {
        public Bed(string name, string price) : base(name, price) { }
    }
    [Serializable]
    public class Woredrobe : Furniture
    {
        public Woredrobe(string name, string price) : base(name, price) { }
    }
    [Serializable]
    public class Closet : Furniture
    {
        public Closet(string name, string price) : base(name, price) { }
    }
    [Serializable]
    sealed class Hanger : Furniture
    {
        public Hanger(string name, string price) : base(name, price) { }

    }

    [Serializable]
    public class NightStand : Furniture
    {
        public NightStand(string name, string price) : base(name, price) { }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }
        public override bool Equals(object? obj)
        {
            return base.Equals(obj);
        }
    }
    [Serializable]

    public class Chair : Furniture, IChair
    {
        public Chair(string name, string price) : base(name, price) { }

        public void Sit()
        {
            Console.WriteLine("You are sitting on a wonderful chair now");
        }
    }
    //[Serializable]
    public static class Printer
    {
        static Printer() { }
        public static void IAmPrinting(Product prod)
        {
            Console.WriteLine(prod.ToString());
        }
    }

}

