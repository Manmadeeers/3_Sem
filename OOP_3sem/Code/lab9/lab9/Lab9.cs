using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace lab9
{
    public class Service
    {
        private string _serviceName;
        public string Name
        {
            get { return _serviceName; }
            set { _serviceName = value; }
        }
        private int _serviceCost;
        public int Cost
        {
            get { return _serviceCost; }
            set { _serviceCost = value; }
        }

        public Service(string name,int cost) { 
            _serviceName = name;
            _serviceCost = cost;
        }

        public override string ToString()
        {
            return $"Service: {_serviceName}. Cost: {_serviceCost}";
        }
    }

    public class ServiceCollection:IOrderedDictionary
    {
        private Queue<Service> _QCollection;

        public Queue<Service> Services
        {
            get { return _QCollection; }
            set { _QCollection = value;}
        }

        public ServiceCollection()
        {
            _QCollection = new Queue<Service>();
        }

        public void Add(Service service)
        {
            _QCollection.Enqueue(service);
        }
        public void Delete(Service service)
        {
            if (_QCollection.Contains(service))
            {
                Queue<Service> tmpQueue = new Queue<Service>();
                foreach(var serv in _QCollection)
                {
                    if (!(serv.Equals(service)))
                    {
                        tmpQueue.Enqueue(serv);
                    }
                }
                _QCollection.Clear();
                _QCollection = tmpQueue;
                Console.WriteLine($"Element {service.ToString()} was deleted");
            }
            else
            {
                throw new Exception("Impossible to delete unexisting element");
            }
        }

        public void Print()
        {
            Console.WriteLine("<-------------------->");
            foreach(Service service in _QCollection)
            {
                Console.WriteLine(service.ToString());
            }
            Console.WriteLine("<-------------------->");
        }

        public bool Search(string name)
        {
            foreach (Service service in _QCollection)
            {
                if(service.Name == name)
                {
                    return true;
                }
            }
            return false;
        }

        public void PrintCostRange(int cost)
        {
            Console.WriteLine("<-------------------->");
            foreach(Service service in _QCollection)
            {
                if(service.Cost == cost)
                {
                    Console.WriteLine(service.ToString());
                }
            }
            Console.WriteLine("<-------------------->");
        }

        //IOrderedDictionary methods implementation
        public IDictionaryEnumerator GetEnumerator()
        {
           
        }
    }
}
