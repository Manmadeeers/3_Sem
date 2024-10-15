using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Password pass1 = new Password("1234!$strongpassihope");
            Password pass2 = new Password("Weakpass");
            pass1.PrintPass();
            pass2.PrintPass();
            Console.WriteLine($"{pass1.Pass} > {pass2.Pass}?: {pass1 > pass2}. And {pass1.Pass} < {pass2.Pass}?: {pass1<pass2}");

            pass2++;
            Console.WriteLine($"Result of ++ operator: {pass2.Pass}");
            pass2--;
            Console.WriteLine($"Result of -- operator: {pass2.Pass}");

            pass1 = pass1 - 'E';
            Console.WriteLine($"Testing - operator: {pass1.Pass}");

            Console.WriteLine($"Result of {pass1.Pass} != {pass2.Pass} : {pass1 != pass2}");
            Console.WriteLine($"Result of {pass1.Pass} == {pass2.Pass} : {pass1 == pass2}");


            Console.WriteLine($"Checking extensions: {StaticOperation.GetMiddleSymbol(pass1.Pass)}");
            Console.WriteLine($"Also checking extensions: {StaticOperation.CheckPassLength(pass1.Pass,pass1.MaxLength,pass1.DefLength)}");

        }
    }
}