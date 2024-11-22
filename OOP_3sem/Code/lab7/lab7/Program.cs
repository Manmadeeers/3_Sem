using System;
using lab3;
using lab_4;

namespace lab7
{
    internal class Program
    {
        static void Main(string[] args)
        {
            CollectionType<Password>PassCollection = new CollectionType<Password>();
            Password pass = new Password("1234MYpASS");
            Password pass2 = new Password("nwoiew[ounefn11-3u4");
            PassCollection.Add(pass);
            PassCollection.Add(pass2);
            Password pass3 = new Password("oweoneifnewofn");
            PassCollection.View();
            try
            {
                PassCollection.Delete(pass3);
            }
            catch (RemoveElementException ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                Console.WriteLine($"Could not delete unexisting lement");
                Console.WriteLine("<-------------------->");
            }
            try
            {
                CollectionType<Password> SecPassCollection = new CollectionType<Password>();
                SecPassCollection.View();
            }
            catch(EmptyCollectionException ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                Console.WriteLine("Empty collection exception was called");
                Console.WriteLine("<-------------------->");
            }
            CollectionType<Product>ProductCollection = new CollectionType<Product>();
            Sofa sofa = new Sofa("Sofa", "200");
            Chair chair = new Chair("Chair", "300");
            Closet closet = new Closet("Closet", "1000");
            ProductCollection.Add(sofa);
            ProductCollection.Add(chair);
            ProductCollection.Add(closet);
            ProductCollection.View();
            PassCollection.WriteToFIle();
        }
    }
}
