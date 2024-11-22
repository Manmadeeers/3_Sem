using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using lab3;

namespace lab7
{
    public interface IGenericOperations<T>
    {
        void Add(T elem);
        void Delete(T elem);
        void View();
        void FindByPredicate(Predicate<T> predicate);

    }
    public class CollectionType<T> : IGenericOperations<T> where T : class
    {
        private List<T> _collection = new List<T>();
        private const int MaxCount = 20;
        public void Add(T elem)
        {
            if (_collection.Count + 1 >= MaxCount)
            {
                throw new AddElementException();
            }
            
            _collection.Add(elem);
        }
        public void Delete(T elem)
        {
            _collection.Remove(elem);
            Console.WriteLine($"Element {elem} was removed");
        }
        public void View()
        {
            Console.WriteLine("<----------Items---------->");
            foreach(var item in _collection)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine("<-------------------->");
        }

        public void FindByPredicate(Predicate<T> predicate)
        {
            var foundElements = _collection.FindAll(predicate);
            if (foundElements.Count > 0)
            {
                Console.WriteLine("<----------Elements found---------->");
                foreach (var item in foundElements)
                {
                    Console.WriteLine(item);
                }
                Console.WriteLine("<----------End---------->");
            }
        }


        
    }



}
