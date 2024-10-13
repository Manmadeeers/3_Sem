using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab2
{
   
    
    public class  Program
    {
       
        static void Main(string[] args) { 
            Mno Set1 = new Mno(2,"Set1");
            Set1.AddElement(1);
            Set1.AddElement(2);
            
            Set1.Print();
            Set1.PrintInfo();

            Mno Set2 = new Mno(3,"Set2");
            Set2.AddElement(1);
            Set2.AddElement(2);
            Set2.AddElement(3);
           
            Set2.Print();
            Set2.PrintInfo();
            

            Set2.FindIntersection(Set1);
            Console.WriteLine();
            Set1.FindIntersection(Set2);
            Console.WriteLine();

            Set2.FindSubstraction(Set1);
            Console.WriteLine();
            Set1.FindSubstraction(Set2);
            Console.WriteLine();
            List<int> Set4items = new List<int>();
           
            for(int i=0;i<6; i++)
            {
                Set4items.Add(i + 1);
            }
            Mno Set4 = new Mno(Set4items,"Set4");
            Set4.PrintInfo();

            if (Set4.Equals(Set1)) {
                Console.WriteLine("Set 4 equals set 1");
            }
            else
            {
                Console.WriteLine("This sets are not equal");
            }

            Console.WriteLine("Testing ToString override");
            Console.WriteLine(Set2.ToString());
            Console.WriteLine($"Tesing GetHashCode override: {Set1.GetHashCode()} ");

            //creating an array of objects
            Mno oddSet = new Mno(4, "Set of odd");
            oddSet.AddElement(2);
            oddSet.AddElement(4);
            oddSet.AddElement(6);
            oddSet.AddElement(8);
            Mno evenSet = new Mno(4, "Set of even");
            evenSet.AddElement(1);
            evenSet.AddElement(3);
            evenSet.AddElement(5);
            evenSet.AddElement(7);
            Mno negativeSet = new Mno(4, "Set of negative");
            negativeSet.AddElement(-1);
            negativeSet.AddElement(-2);
            negativeSet.AddElement(-3);
            negativeSet.AddElement(-4);
            Mno mixedSet = new Mno(4, "Mixed Set");
            mixedSet.AddElement(1);
            mixedSet.AddElement(3);
            mixedSet.AddElement(-5);
            mixedSet.AddElement(-6);
            Mno[]ArrayOfMnos = {oddSet,evenSet,negativeSet,Set4,mixedSet};
            MnoArray MNArr = new MnoArray(ArrayOfMnos);
            MNArr.PrintOddSets();
            MNArr.PrintEvenSets();
            MNArr.PrintSetsWithNegative();

            int SumofSet4 = 0;
            Set4.SumElements(out SumofSet4);
            Console.WriteLine($"Testing ref and out parametres: {SumofSet4}");


            var Anonym = new { Name = "Anonymous set", Size = 4 };
            Console.WriteLine(Anonym.ToString());
        }
    }
}
