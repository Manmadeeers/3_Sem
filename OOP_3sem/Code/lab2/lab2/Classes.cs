using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace lab2
{
    public class Mno
    {
        private int size;
        private int[] arr;
        public readonly int id = MaxElements/15;
        private int controll_elements = 0;
        const int MaxElements = 100;

        public int[] Arr { 
            get { return arr; }
            set { }
        }
        public int GetSize { get { return size + 100; } set { } }

        //constructors
        public Mno() { }

        public Mno(int newsize) { 
            if (newsize > MaxElements) { throw new Exception("Array subscript out of range"); } arr = new int[newsize];size = newsize ;
        }

        public Mno(int[] arr) { }

        static Mno() { }

       // private Mno(int size, int[] arr) { Size = size; Arr = arr; }

        

        //methods

        public void AddElement(int value)
        {
            arr[controll_elements] = value;
            controll_elements++;
            if(controll_elements >= MaxElements)
            {
                throw new Exception("Set subscript out of range");
            }
        }

        public void DeleteElement(int value)
        {
            int position = -1;
            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] == value)
                {
                    position = i;
                }
            }
            var temp = new List<int>(size);
            if (position!=-1) {

                temp.RemoveAt(position);
                arr = temp.ToArray();
            }
            else
            {
                throw new Exception("Cannot delete such element because it is not in a required array");
            }
        }

        public bool CheckPresense(List<int> list,int element)
        {
            bool hasElement = false;
            foreach (var item in list) {
                if (item == element) {
                    return hasElement = true;
                }
            }
            return hasElement;
        }
        public int[] FindIntersection(Mno set1,Mno set2)
        {
            var inter_temp = new List<int>();
            if (set1.size > set2.size) {
                for(int i = 0; i < set2.size; i++)
                {
                    if (set2.arr[i] == set1.arr[i] && !CheckPresense(inter_temp, set2.arr[i]))
                    {
                        inter_temp.Add(set2.arr[i]);
                    }
                }
            }
            else
            {
                for(int i=0;i<set1.size; i++)
                {
                    if (set1.arr[i]== set2.arr[i] && !CheckPresense(inter_temp, set1.arr[i]))
                    {
                        inter_temp.Add(set2.arr[i]);
                    }
                }
            }
            return inter_temp.ToArray();
        }

        public int[] FindSubstraction(Mno set1, Mno set2) {

            var sub_temp = new List<int>();
            for(int i = 0; i < set1.size; i++)
            {
                if (set1.arr[i]!= set2.arr[i] && !CheckPresense(sub_temp, set1.arr[i]))
                {
                    sub_temp.Add(set1.arr[i]);
                }
            }
            return sub_temp.ToArray();
        }

        public void PrintElems()
        {
            if (size == 0) { throw new Exception("Array ia still empty"); }
            for(int i = 0; i < size; i++)
            {
                Console.Write(arr[i]+" ");
            }
        }

    }
}
