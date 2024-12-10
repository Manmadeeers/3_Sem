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
    public class Customer
    {
        private string _name;
        public string Name
        {
            get
            {
                return _name;
            }
            set
            {
                _name = value;
            }
        }
        public Customer(string name)
        {
            _name = name;
        }
    }
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

    //----->
    public class ServiceCollection:IOrderedDictionary
    {
        private Queue<Service> _QCollection;
        private Queue<Customer> _CustomerCollection;

        public Queue<Service> Services
        {
            get { return _QCollection; }
            set { _QCollection = value;}
        }

        public bool IsFixedSize => false;

        public bool IsReadOnly => false;

        public ICollection Keys
        {
            get
            {
              Queue<string> q = new Queue<string>();
                foreach (Service s in _QCollection)
                {
                    q.Enqueue(s.Name);
                }
                return q;
            }
        }

        public ICollection Values
        {
            get
            {
                Queue<int>q = new Queue<int>();
                foreach(Service s in _QCollection)
                {
                    q.Enqueue(s.Cost);
                }
                return q;
            }
        }

        public int Count => _QCollection.Count;

        public bool IsSynchronized => false;

        public object SyncRoot => null;

        public object? this[object key] {
            get 
            {
                Service serv = null;
                foreach(Service s in _QCollection)
                {
                    if (s.Equals(key))
                    {
                        serv = s;
                        break;
                    }
                }
                if(serv== null)
                {
                    throw new ArgumentException("No such value");
                }
                return serv;
            }
            set
            {
                _QCollection.Enqueue((Service)key);
            }
        }
        public object? this[int index]
        {
            get
            {
                return index;
            }
            set
            {
                
            }
        }

        public ServiceCollection()
        {
            _QCollection = new Queue<Service>();
            _CustomerCollection = new Queue<Customer>();
        }

        //public void Delete(Service service)
        //{
        //    if (_QCollection.Contains(service))
        //    {
        //        Queue<Service> tmpQueue = new Queue<Service>();
        //        foreach(var serv in _QCollection)
        //        {
        //            if (!(serv.Equals(service)))
        //            {
        //                tmpQueue.Enqueue(serv);
        //            }
        //        }
        //        _QCollection.Clear();
        //        _QCollection = tmpQueue;
        //        Console.WriteLine($"Element {service.ToString()} was deleted");
        //    }
        //    else
        //    {
        //        throw new Exception("Impossible to delete unexisting element");
        //    }
        //}

        public void Print()
        {
            Console.WriteLine("<-------------------->");
            foreach(Service service in _QCollection)
            {
                Console.WriteLine(service.ToString());
            }
            Console.WriteLine("<-------------------->");
        }

        //public bool Search(string name)
        //{
        //    foreach (Service service in _QCollection)
        //    {
        //        if(service.Name == name)
        //        {
        //            return true;
        //        }
        //    }
        //    return false;
        //}

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
           return ((IOrderedDictionary)_QCollection).GetEnumerator();
        }

        public void Insert(int index, object key, object? value)
        {
            
        }

        public void RemoveAt(int index)
        {
            if (index < 0 || index >= _QCollection.Count)
            {
                throw new ArgumentException("You're out of collection range");
            }
            int iterator = 0;
            Service val_to_delete = null;
            foreach(Service service in _QCollection)
            {
                iterator++;
                if (iterator == index)
                {
                    val_to_delete = service;
                    break;
                }
            }
            if (val_to_delete == null)
            {
                throw new Exception("Element not found");
            }

            Queue<Service> queue = new Queue<Service>();
            foreach(Service service in _QCollection)
            {
                if (service != val_to_delete)
                {
                    queue.Enqueue(service);
                }
            }
            _QCollection.Clear();
            _QCollection = queue;
        }

        public void Add(object key, object? value)
        {
            if(value == null)
            {
                throw new ArgumentException("Can;t push null to queue");
            }
            _QCollection.Enqueue((Service)value);
        }

        public void Clear()
        {
            _QCollection.Clear();
        }

        public bool Contains(object key)
        {
            return _QCollection.Contains(key);
        }

        public void Remove(object key)
        {
            Console.WriteLine("There's already several methods to delete values from queue.\n PLEASE STOP!!!");
        }

        public void CopyTo(Array array, int index = 0)
        {
            array = _QCollection.ToArray();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            throw new NotImplementedException();
        }
    }
}
