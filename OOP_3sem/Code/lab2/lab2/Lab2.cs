using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab2
{
    public class MnoArray
    {
        Mno[] MnoArr;
        public MnoArray(Mno[] Mnos) { MnoArr = Mnos; }

        public Mno this[int index] { get { return MnoArr[index]; } }
    }
    
    public class  Program
    {
       
        static void Main(string[] args) { 
            Mno Set1 = new Mno(2);
            Set1.AddElement(1);
            Set1.AddElement(2);
            Set1.PrintElems();
            var MNS = new MnoArray(new[] { Set1, Set1,Set1,Set1});
             Console.Write(MNS[3].id);
        }
    }
}
