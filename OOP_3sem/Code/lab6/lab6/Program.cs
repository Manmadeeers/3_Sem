
using lab5;

namespace lab6
{
    internal class Program
    {
        static void Main(string[] args)
        {
           
          
            try
            {
               
                Storage storage = new Storage();
                storage.Print();

            }
            catch(EmptyStorageException ex)
            {
                Console.WriteLine("An exception was called: "+ex.Message+"\nVisit this link for more details: "+ex.HelpLink);
            }
            finally
            {
             
                Console.WriteLine("-----first-----");
            }
            try
            {
                Storage storage = new Storage();
                Sofa sofa1 = new Sofa("Sofa", "200", 120);
                storage.AddNew(sofa1);
                Sofa sofa2 = new Sofa("Sof", "300", 100);
                storage.Remove(sofa2);

            }
            catch(WrongElementException ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                Console.WriteLine("-----second-----");
            }


        }
    }
}