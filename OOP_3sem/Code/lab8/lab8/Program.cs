﻿using System;
using System.Diagnostics.SymbolStore;
namespace lab8
{

    internal class Program
    {
        static void Main(string[] args)
        {

            User user1 = new User("Kfingix");
            User user2 = new User("PDIgnap");
            User user3 = new User("adofaef");
            User user4 = new User("Iouabfoaebf");



            user1.HandleMovement(1, 'X');
            user1.HandleCompression(0.1);
            user2.HandleMovement(2, 'Y');
            user2.HandleCompression(0.3);

            user1.Moved += user1.HandleMovement;
            user1.Compressed += user1.HandleCompression;

            user2.Moved += user2.HandleMovement;

            Console.WriteLine(user1.ToString());
            Console.WriteLine(user2.ToString());


            //Master master = new Master();
            //Slave slave1 = new Slave("Van");
            //master.Moved += slave1.HandleMovement;
            //slave1.HandleMovement(10, 'X');

            //Console.WriteLine(slave1.ToString());

            //slave1.HandleMovement(20, 'Y');
            //Console.WriteLine(slave1.ToString());


            string StrToProcess1 = "inonr,podnvi!!,PDZNEEFNE";
            string ProcessedString1 = StringProcessor.DeletePunktuation(StrToProcess1);
            Console.WriteLine(ProcessedString1);

            string StrToProcess2 = "I love C#      and trim extra spaces";
            string ProcessedString2 = StringProcessor.TrimExtraSpaces(StrToProcess2);
            Console.WriteLine(ProcessedString2);

            string StrToProcess3 = "abcdef";
            Console.WriteLine(StringProcessor.Reverse(StrToProcess3));

            Class1 cl1 = new Class1();

            cl1.SomeEvent += cl1.HandleEvent;
            cl1.doSomething();

           
        }

    }
   

}
