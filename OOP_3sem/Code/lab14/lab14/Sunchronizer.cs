using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab14
{
    public static class Synchronizer
    {
        private static readonly ManualResetEventSlim eventWaitHandle = new ManualResetEventSlim(true);
        public static void EvenThenOdd(int n)
        {
            
            Mutex mut = new Mutex();
            int firstSleepParam = n / 2 * 100;
            //Console.WriteLine(firstSleepParam);
            int secondSleepParam = (n - n / 2) * 300;
            //Console.WriteLine(secondSleepParam);
            Thread.Sleep(firstSleepParam+secondSleepParam+500);
            Thread EvenNums = new Thread(ShowEven);
            Thread OddNums = new Thread(ShowOdd);
            Thread ShowName = new Thread(() => { Console.WriteLine("<-----Even then odd----->"); });
            ShowName.Start();
            EvenNums.Start(n);
            OddNums.Start(n);
            


            void ShowEven(object n)
            {
                //Console.WriteLine("First stream:");
               
                int numberEdge = (int)n;
              
                for (int i = 1; i <= numberEdge; i++)
                {
                    Thread.Sleep(100);
                    if (i % 2 == 0)
                    {

                        mut.WaitOne();
                        Console.WriteLine($"First: {i} ");
                        mut.ReleaseMutex();
                    }
                }
            }

            void ShowOdd(object n)
            {
                int numberEdge = (int)n;
                //Console.WriteLine("Second stream: ");
              
                for (int i = 1; i <= numberEdge; i++)
                {
                  
                    Thread.Sleep(300);
                    if (i % 2 != 0)
                    {
                        mut.WaitOne();
                        Console.WriteLine($"Second: {i} ");
                        mut.ReleaseMutex();
                    }
                }
            }


        }
        public static void AllEvenThenAllOdd(int n)
        {
           
            Mutex mutex = new Mutex();
            int firstSleepParam = n / 2 * 100;
            //Console.WriteLine(firstSleepParam);
            int secondSleepParam = (n - n / 2) * 300;
            //Console.WriteLine(secondSleepParam);
            Thread.Sleep((firstSleepParam + secondSleepParam + 500) * 2);
            Thread showingAllEven = new Thread(ShowEven);
            Thread showindAllOdd = new Thread(ShowOdd);
            Thread showingTitle = new Thread(() => { Console.WriteLine("<--Showing all even then all odd-->"); });
            showingTitle.Start();
            showingAllEven.Start(n);
            showindAllOdd.Start(n);

            eventWaitHandle.Set();

            void ShowEven(object n)
            {
                //Console.WriteLine("First stream:");

                int numberEdge = (int)n;
                mutex.WaitOne();
                for (int i = 1; i <= numberEdge; i++)
                {
                    Thread.Sleep(100);
                    if (i % 2 == 0)
                    {

                   
                        Console.WriteLine($"First: {i} ");
                      
                    }
                }
                mutex.ReleaseMutex();
            }
            void ShowOdd(object n)
            {
                int numberEdge = (int)n;
                //Console.WriteLine("Second stream: ");
                mutex.WaitOne();
                for (int i = 1; i <= numberEdge; i++)
                {

                    Thread.Sleep(300);
                    if (i % 2 != 0)
                    {
                       
                        Console.WriteLine($"Second: {i} ");
                        
                    }
                }
                mutex.ReleaseMutex();
            }

           

        }
       
    }
}
