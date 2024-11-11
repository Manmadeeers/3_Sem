using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab5
{
    interface IFurniture
    {
        void isClean();
    }
    public enum Quality
    {
        Amazing = 5,
        Fine = 4,
        Good = 3,
        Medium = 2,
        Bad = 1,
        Frightfull = 0
    }
    public struct Descr
    {
        public string descr;
        public int quantity;
    }

    public abstract class Product
    {
        protected Quality quality;
        protected Descr description;
        protected string name;
        protected bool clean = false;
        protected int weight;
        public string Name
        {
            get { return name; }
        }

        protected string price;
        public string Price
        {
            get { return price; }
        }
        public Quality Quality { get => quality;}
        public int Weight
        {
            get => weight;
            set => weight = value;
        }
        protected Product(string Nname, string Nprice,int Nweight)
        {
            if (String.IsNullOrEmpty(Nname) || String.IsNullOrEmpty(Nprice))
            {
                throw new Exception("Can't initialize field with null or empty meaning");
            }
            name = Nname;
            price = Nprice;
            weight = Nweight;
            quality = Quality.Amazing;
            description.descr = "Description";
            description.quantity = 100;
        }

        public virtual void getDescription()
        {
            Console.WriteLine("<---------->");
            Console.WriteLine($"Description: {description.descr}\nQuantity: {description.quantity}");
            Console.WriteLine("<---------->");

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
        public Furniture(string name, string price,int weight) : base(name, price,weight)
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
    public partial class Sofa : Furniture, IChair, IFurniture
    {
        public Sofa(string name, string price,int weight) : base(name, price,weight) { }
        public void Sit()
        {
            Console.WriteLine("You're sitting on a sofa");
        }


        void IFurniture.isClean()
        {
            Console.WriteLine("Intrerfadce cleaning of sofa");
        }



    }

    public class Bed : Furniture
    {
        public Bed(string name, string price,int weight) : base(name, price,weight) { }
    }
    public class Woredrobe : Furniture
    {
        public Woredrobe(string name, string price,int weight) : base(name, price,weight) { }
    }
    public class Closet : Furniture
    {
        public Closet(string name, string price,int weight) : base(name, price,weight) { }
    }

    sealed class Hanger : Furniture
    {
        public Hanger(string name, string price,int weight) : base(name, price,weight) { }

    }

    public class NightStand : Furniture
    {
        public NightStand(string name, string price,int weight) : base(name, price,weight) { }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }
        public override bool Equals(object? obj)
        {
            return base.Equals(obj);
        }
    }

    public class Chair : Furniture, IChair
    {
        public Chair(string name, string price,int weight) : base(name, price,weight) { }

        public void Sit()
        {
            Console.WriteLine("You are sitting on a wonderful chair now");
        }
    }
    public static class Printer
    {
        static Printer() { }
        public static void IAmPrinting(Product prod)
        {
            Console.WriteLine(prod.ToString());
        }
    }

    //container
    public abstract class ContainerClass<T>
        where T : Product
    {
        protected List<T> elements = new List<T>();
        public abstract void Set(List<T>list);
        public abstract void Get();
        public abstract void AddNew(T element);
        public abstract void Remove(T element);
        public abstract void Clear();
        public abstract void Print(T element);

    }

    public class Storage : ContainerClass<Product>
    {
        public override void Set(List<Product> list)
        {
            elements = list;
        }
        public override void Get()
        {
            Console.WriteLine("<----------Storage---------->");
            foreach (var element in elements)
            {
                Console.WriteLine(element.ToString());
            }
            Console.WriteLine("<--------------------------->");
        }
        public override void AddNew(Product element)
        {
            elements.Add(element);
        }
        public override void Remove(Product element)
        {
            bool InList = false;
            foreach(var item in elements)
            {
                if (item == element)
                {
                    InList = true;
                    break;
                }
            }
            if (InList)
            {
                elements.Remove(element);
            }
            else
            {
                Console.WriteLine("There's no such an element, therefore it could not be deleted");
            }
        }
        public override void Clear()
        {
            elements.Clear();
            Console.WriteLine("List is cleared");
        }
        public override void Print(Product element)
        {
            bool InList = false;
            foreach(var item in elements)
            {
                if(item == element)
                {
                    InList = true;
                    break;
                }
            }
            if (InList)
            {
                Console.WriteLine($"{element.Name}, {element.Quality}, {element.Price}");
                element.getDescription();
            }
            else
            {
                Console.WriteLine("There's no such an element, therefore it could not be printedx");
            }
        }
        public void calculateWoredrobeCost()
        {
            int totalSum = 0;
            foreach(var element in elements)
            {
                if (element is Woredrobe||element is Closet)
                {
                    int price = int.Parse(element.Price);
                    totalSum += price;
                }
                
            }
            Console.WriteLine($"The total price of all Worederobes and Closets is: {totalSum}$");
        }

        public void printPriceRange(int requiredPrice)
        {
            Console.WriteLine($"<----------Items in price range {requiredPrice}---------->");
            bool hasElement = false;
            foreach(var element in elements)
            {
                int currentPrice = int.Parse(element.Price);
                if (currentPrice == requiredPrice)
                {
                    hasElement = true;
                    Console.WriteLine($"{element.Name}");
                }
            }
            if (!hasElement) { Console.WriteLine("There are no elements in such a price range"); }
            Console.WriteLine($"<-------------------------------------------->");
        }
        public void sortBy
    }

}
