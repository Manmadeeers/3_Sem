using lab9;
using System;
using System.Linq.Expressions;

namespace Lab9
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Service service1 = new Service("Cleaning", 200);
            Service service2 = new Service("Coding", 20);
            Service service3 = new Service("Code review", 1000);
            Service service4 = new Service("Sdelat' kursach", 5000);
            Customer John = new Customer("John");
            Customer Mathew = new Customer("Mathew");
            Customer Alice = new Customer("Alice");
            Customer Julie = new Customer("Julie");
            ServiceCollection collection1 = new ServiceCollection();

            collection1.Add(John, service1);
            collection1.Add(Mathew,service2);
            collection1.Add( Alice, service3);
            collection1.Add(Julie, service4);
            collection1.Print();
            collection1.Clear();

            UniverCollection<object>UnivCollection = new UniverCollection<object>();

            for(int i = 0; i < 20; i++)
            {
                UnivCollection.AddElement(i * 25);
            }

            UnivCollection.PrintCollection();

            for(int i = 5; i < 14; i++)
            {
                UnivCollection.DeleteElem(i * 25);
            }
            UnivCollection.PrintCollection();

            UnivCollection.AddElement(John);
            UnivCollection.AddElement(Alice);
            UnivCollection.AddElement(Julie);

            UnivCollection.AddElement(service1);
            UnivCollection.AddElement(service2);
            UnivCollection.AddElement(service3);

            UnivCollection.PrintCollection();

            OneMorecollection sec_coll = new OneMorecollection();
            foreach(var item in UnivCollection.Items)
            {
                sec_coll.PushElem(item);
            }
            sec_coll.PrintCollection();
            sec_coll.findValue(service1);


            AmWatchingYou<Service>Obs= new AmWatchingYou<Service>();
            Obs.OnCollectionChanged += Obs.HandleEvent;
            Obs.AddElem(service1);
            Obs.AddElem(service2);
            Obs.AddElem(service3);
            Obs.AddElem(service4);
            Obs.DelElem(service1);
            
        }
     
    }
}