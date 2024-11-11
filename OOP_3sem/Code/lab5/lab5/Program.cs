namespace lab5
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Sofa sofa1 = new Sofa("Sofa", "200$",150);
            Console.WriteLine(sofa1.Quality);
            sofa1.getDescription();

            Woredrobe wrd1 = new Woredrobe("Woredrobe", "500",100);
            Chair chair1 = new Chair("Chair", "100",10);
            Woredrobe wrd2 = new Woredrobe("Smaller woredrobe", "400",90);
            Closet closet1 = new Closet("Closet", "600",200);
            Closet closet2 = new Closet("Smaller closet", "500",150);

            Storage storage = new Storage();
            storage.AddNew(wrd1);
            storage.AddNew(wrd2);
            storage.AddNew(closet1);
            storage.AddNew(closet2);
            storage.AddNew(chair1);
            storage.Get();
            storage.calculateWoredrobeCost();
            storage.printPriceRange(500);
        }
    }
}