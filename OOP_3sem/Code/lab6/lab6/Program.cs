
using lab5;
using System.Diagnostics;

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
            try
            {
                Storage stor = new Storage();
                stor.Clear();
            }
            catch(EmptyStorageException ex)
            {
                Console.WriteLine(ex.Message);
                Console.WriteLine(ex.HelpLink);

            }
            finally
            {
                Console.WriteLine("-----third-----");
            }
            try
            {
                Storage stor = new Storage();
                StorageController.printPriceRange(stor,-10);
            }
            catch (WrongRangeException ex)
            {
                Console.WriteLine(ex.Message);
                Console.WriteLine(ex.HelpLink);
            }
            finally
            {
                Console.WriteLine("-----fourth-----");
            }
            try
            {
                Storage store = new Storage();
                StorageController.SortByPriceWeight(store);
            }
            catch(EmptyStorageException ex)
            {
                Console.WriteLine(ex.Message);
                Console.WriteLine(ex.HelpLink);

            }
            finally
            {
                Console.WriteLine("-----fivth-----");
            }

            try
            {
                try
                {
                    Storage store = new Storage();
                    Sofa sof = new Sofa("Sofa", "200", 100);
                    Chair chair = new Chair("Chair", "200", 10);
                    store.AddNew(sof);
                    store.AddNew(chair);
                    StorageController.printPriceRange(store,10);
                }
                catch 
                {
                    Console.WriteLine("Exception was called");
                    throw;
                }
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.Message);
                Console.WriteLine(ex.HelpLink);
            }
            finally
            {
                Console.WriteLine("-----Throw up-----");
            }
            //Storage storr = new Storage();
            //Sofa sofr = new Sofa("Sofa", "200", 100);
            //Chair chaur = new Chair("Chair", "200", 10);
            //storr.AddNew(sofr);
            //storr.AddNew(chaur);
            //StorageController.printPriceRange(storr, 0);
        }
    }
}