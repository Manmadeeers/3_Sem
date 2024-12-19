using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
using static System.Diagnostics.Activity;

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

        public override string ToString()
        {
            return $"Assigned to {this.Name}\t";
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
            return $"Service: {_serviceName}. Cost: {_serviceCost}\t";
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
        public Queue<Customer> Customers
        {
            get { return _CustomerCollection; }
            set { _CustomerCollection = value;  }
        }

        public bool IsFixedSize => false;

        public bool IsReadOnly => false;

        public ICollection Keys
        {
            get
            {
                Customer[] keys = new Customer[_CustomerCollection.Count];
                int key_iterator = 0;
                foreach (var item in _CustomerCollection)
                {
                    keys[key_iterator++] = item;
                }
                return keys;
            }
        }

        public ICollection Values
        {
            get
            {
                Service[] values = new Service[_QCollection.Count];
                int val_iterator = 0;
                foreach(var item in _QCollection)
                {
                    values[val_iterator++] = item;
                }
                return values;
            }
        }

        public int Count => _QCollection.Count;

        public bool IsSynchronized => true;

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
        public void Print()
        {
            Console.WriteLine("<-------------------->");
            Console.Write("Services: ");
            foreach(Service service in _QCollection)
            {
                Console.Write(service.ToString());
            }
            Console.Write("\n");
            Console.Write("Customers: ");
            foreach(Customer customer in _CustomerCollection)
            {
                Console.Write(customer.ToString());
            }
            Console.Write("\n");
            Console.WriteLine("<-------------------->");
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

       

        public IDictionaryEnumerator GetEnumerator()
        {
           return ((IOrderedDictionary)_QCollection).GetEnumerator();
        }

        public void Insert(int index, object key, object value)
        {
            _QCollection.Enqueue((Service)value);
            
            _CustomerCollection.Enqueue((Customer)key);
            

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
            if (value == null)
            {
                throw new ArgumentException("Can;t push null to queue");
            }
            _QCollection.Enqueue((Service)value);
            _CustomerCollection.Enqueue((Customer)key);
        }

        public void Clear()
        {
            _QCollection.Clear();
            _CustomerCollection.Clear();
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


public class UniverCollection<T> 
{
    private List<object> _items = new List<object>();
    private int currentIndex = -1;

    public List<object> Items
    {
        get { return this._items; }
    }
    public void AddElement(object elem)
    {
        _items.Add(elem);
    }
   

    public void Clear()
    {
        _items.Clear();
    }
    public void DeleteElem(object elem)
    {
        _items.Remove(elem);
    }

 

    public T getIndex(int index)
    {
        if (index > _items.Count || index < 0)
        {
            throw new ArgumentException("Are you an idiot???");
        }
        return (T)_items[index];
    }

    public void PrintCollection()
    {
        Console.WriteLine("<-------------------->");
        Console.WriteLine("Universal collection");
        foreach (object elem in _items)
        {
           
            Console.WriteLine(elem.ToString());
          
        }
        Console.WriteLine("<-------------------->");
    }
 
}

public class OneMorecollection
{
    private Stack _coll = new Stack();

    public void PushElem(object elem)
    {
        _coll.Push(elem);
    }

    public void PopElem()
    {
        _coll.Pop();
    }
    public void findValue(object value)
    {
        if (_coll.Contains(value))
        {
            Console.WriteLine("Second collection has such a value");
            Console.WriteLine($"[ {value.ToString()}] ");
        }
        else
        {
            Console.WriteLine("Nope there's no such a value");
        }
    }
    public void PrintCollection()
    {
        Console.WriteLine("<----------Sec---------->");
        foreach(var item in _coll)
        {
            Console.WriteLine(item);
        }
        Console.WriteLine("<-------------------->");
    }


   

}
public class AmWatchingYou<T>
{
    private ObservableCollection<T> _observ = new ObservableCollection<T>();

    public ObservableCollection<T> OBSERV
    {
        get { return _observ; }
    }
    public delegate void Observ();
    public event Observ? OnCollectionChanged;

    public void AddElem(T element)
    {
        _observ.Add(element);
        OnCollectionChanged?.Invoke();
    }
    public void DelElem(T element)
    {
        _observ.Remove(element);
        OnCollectionChanged?.Invoke();
    }
    public void HandleEvent()
    {
        Console.WriteLine("Collection changed");
    }
}
