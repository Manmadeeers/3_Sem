using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using lab10;

namespace lab2
{
    public class Mno:IComparable<Mno>
    {
        private string _name;
        private int size;
        private List<int> items;
        public readonly int id = MaxElements / 15;
        const int MaxElements = 100;
        private static int indexer = 0;

        public List<int> Items
        {
            get { return items; }
            set { items = value; }
        }
        public int Size { get { return size; } set { } }

        public string Name { get { return _name; } }

        //constructors
        public Mno() { }

        public Mno(int newsize, string newname)
        {
            if (newsize > MaxElements) { throw new Exception("Array subscript out of range"); }
            if (String.IsNullOrEmpty(newname)) { throw new Exception("A set could not be initialized without the name"); }
            items = new List<int>();
            size = newsize;
            _name = newname;
            id = newsize * 100 - 4;
            indexer++;
        }

        public Mno(List<int> items, string newname)
        {
            size = items.Count;
            if (String.IsNullOrEmpty(newname))
            {
                throw new Exception("A set could not be initialized without the name");
            }
            if (items == null)
            {
                throw new Exception("A transfered list could not be null");
            }
            Items = items;
            _name = newname;
            id = items.Count * 100 - 4;
            indexer++;
        }

        static Mno()
        {
            indexer++;
        }

        private Mno(int size, List<int> items) { Size = size; Items = items; }

        public Mno ClosedMno()
        {
            return new Mno(size = 5, items = new List<int>());
        }


        //methods

        public void AddElement(int value)
        {
            items.Add(value);

        }

        public int getSum()
        {
            int sum = 0;
            foreach(int item in Items)
            {
                sum += item;
            }
            return sum;
        }
       

        public void DeleteElement(int value)
        {
            if (items.Contains(value))
            {
                items.Remove(value);
            }
            else
            {
                throw new Exception("Could not delete such value!");
            }

        }

        public void SumElements(out int result)
        {
            Console.WriteLine();
            result = 0;
            foreach (var item in Items)
            {
                result += item;
            }
        }


        public void FindIntersection(Mno SetToCompare)
        {
            List<int> intersection = new List<int>();
            if (size <= SetToCompare.size)
            {
                foreach (var item in items)
                {
                    if (SetToCompare.items.Contains(item))
                    {
                        intersection.Add(item);
                    }
                }
            }
            else
            {
                foreach (var item in SetToCompare.items)
                {
                    if (items.Contains(item))
                    {
                        intersection.Add(item);
                    }
                }
            }

            Console.Write($"Intersection of {_name} and {SetToCompare._name}:");
            foreach (var item in intersection)
            {
                Console.Write(item + " ");
            }
            Console.WriteLine();
        }

        public void FindSubstraction(Mno SetToCompare)
        {
            Console.WriteLine();
            List<int> substraction = new List<int>();

            foreach (var item in SetToCompare.items)
            {
                if (!items.Contains(item))
                {
                    substraction.Add(item);
                }
            }
            Console.Write($"Substraction of {SetToCompare._name} from {_name}: ");
            if (substraction.Count == 0)
            {
                Console.WriteLine("Result of substraction is an empty set");
            }
            else
            {
                foreach (var item in substraction)
                {
                    Console.Write(item + " ");
                }
            }

            Console.WriteLine();
        }

        public void Print()
        {
            if (size == 0) { throw new Exception("Array ia still empty"); }
            Console.Write($"{_name} items: ");
            foreach (var item in items)
            {
                Console.Write(item + " ");
            }
            Console.WriteLine();
        }

        public void PrintInfo()
        {
            Console.WriteLine($"<----------{_name} Info---------->");
            Console.WriteLine($"Set size: {size}");
            Console.Write("Set Items: ");
            foreach (var item in items)
            {
                Console.Write(item + " ");
            }
            Console.WriteLine();
            Console.WriteLine($"ID: {id}");
            Console.WriteLine($"Index number: {indexer}");
            Console.WriteLine("<----------------------------->");
            Console.WriteLine();
        }
        public override bool Equals(object obj)
        {
            if (obj == null)
            {
                return false;
            }
            if (this.GetType() != obj.GetType())
            {
                return false;
            }

            return true;
        }
        public override string ToString()
        {
            return $"Size: {Size} & Sum: {this.getSum()} & Name: {this.Name}";
        }

        public override int GetHashCode()
        {
            return base.GetHashCode() ^ items.GetHashCode();
        }

        public int CompareTo(Mno? other)
        {
            if(other==null)
            {
                return 1;
            }
            else
            {
                return this.Size.CompareTo(other.Size);
            }
        }

    }

    public class MnoArray
    {
        private Mno[] MnoArr;
        private int size;
        public MnoArray(Mno[] Mnos)
        {
            MnoArr = Mnos;
            size = MnoArr.Length;
            if (size == 0)
            {
                throw new Exception("Array could not be initialized with null meaning");
            }
        }

        public Mno[] MNoARR
        {
            get { return MnoArr; }
            set { MnoArr = value; }
        }
        public int Size
        {
            get { return size; }
        }

        public Mno this[int index]
        {
            get { return MnoArr[index]; }
            set { MnoArr[index] = value; }
        }

        public void PrintOddSets()
        {
            Console.WriteLine("Odd Sets: ");
            int countOddSets = 0;
            for (int i = 0; i < size; i++)
            {
                bool hasEven = false;

                foreach (var item in MnoArr[i].Items)
                {
                    if (item % 2 != 0)
                    {
                        hasEven = true;
                        break;
                    }
                }
                if (!hasEven)
                {
                    countOddSets++;
                    Console.Write($"{MnoArr[i].Name}:");
                    foreach (var item in MnoArr[i].Items)
                    {
                        Console.Write(item + " ");
                    }
                    Console.WriteLine();
                }

            }
            if (countOddSets == 0)
            {
                Console.WriteLine("There are no odd sets in this array");
            }
        }

        public void PrintEvenSets()
        {
            Console.WriteLine("Even sets:");
            int countEvenSets = 0;
            for (int i = 0; i < size; i++)
            {
                bool hasOdd = false;
                foreach (var item in MnoArr[i].Items)
                {
                    if (item % 2 == 0)
                    {
                        hasOdd = true;
                        break;
                    }
                }
                if (!hasOdd)
                {
                    countEvenSets++;
                    Console.Write($"{MnoArr[i].Name}");
                    foreach (var item in MnoArr[i].Items)
                    {
                        Console.Write(item + " ");
                    }
                    Console.WriteLine();
                }
            }
            if (countEvenSets == 0)
            {
                Console.WriteLine("There are no even sets in array");
            }
        }

        public void PrintSetsWithNegative()
        {
            Console.WriteLine("Sets with negative elements:");
            int countSetsWithNegative = 0;
            for (int i = 0; i < size; i++)
            {

                bool hasNegative = false;
                foreach (var item in MnoArr[i].Items)
                {
                    if (item < 0)
                    {
                        hasNegative = true;
                        break;
                    }
                }
                if (hasNegative)
                {
                    countSetsWithNegative++;
                    Console.Write($"{MnoArr[i].Name}: ");
                    foreach (var item in MnoArr[i].Items)
                    {
                        Console.Write(item + " ");
                    }
                }
            }
            if (countSetsWithNegative == 0)
            {
                Console.WriteLine("There are no sets with negative elements in array");
            }
        }
    }
}
