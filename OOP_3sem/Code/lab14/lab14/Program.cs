using System;
using System.ComponentModel.DataAnnotations;
using System.Diagnostics;
using System.Reflection;

namespace lab14
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            var allProcess = Process.GetProcesses();
            Console.WriteLine("<-----Processes----->");
            foreach (var process in allProcess)
            {
                try
                {
                    Console.WriteLine(
                        $"ID: {process.Id}\n" +
                        $"Process name: {process.ProcessName}\n" +
                        $"Priority: {process.BasePriority}\n" +
                        $"VirtualMemorySize64: {process.VirtualMemorySize64}\n" +
                        $"Start time: {process.StartTime}\n" +
                        $"Process time: {process.TotalProcessorTime}\n");
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.Message);
                }

            }
            Console.WriteLine("<-----End of processes----->");

            AppDomain currentDomain = AppDomain.CurrentDomain;
            Console.WriteLine("<-----Info abount current domain----->");
            Console.WriteLine($"Domain name: {currentDomain.FriendlyName}\n" +
                $"Configuration details:{currentDomain.SetupInformation}");
            Console.WriteLine("All assemblies: ");
            Assembly[] assemblies = currentDomain.GetAssemblies();
            foreach (Assembly assembly in assemblies)
            {
                Console.WriteLine(assembly.GetName().Name);
            }


            try
            {
                AppDomain domain = AppDomain.CreateDomain("New");
                domain.Load("@C:\\Users\\Manmade\\Desktop\\3_Sem\\OOP_3sem\\Code\\lab13\\lab13\\bin\\Debug\\net6.0\\lab13.dll");
                AppDomain.Unload(domain);
                Console.WriteLine("Assembly was sucsessfully loaded and unloaded");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            Console.WriteLine("<-----End of domain info----->");

            Console.WriteLine("<-----Calculations----->");

            var myFirstThread = new Thread(ThreadInfo);
            myFirstThread.Start(Thread.CurrentThread);
            Thread.Sleep(1000);

            int n;
            Console.Write("Enter n: ");
            n = int.Parse(Console.ReadLine());

            using (StreamWriter sw = new StreamWriter("file.txt", false))
            {
                Console.Write("Simple numbers: ");
                for (int i = 1; i <= n; i++)
                {
                    bool isSimple = true;
                    for (int j = 2; j <= i / 2; j++)
                        if (i % j == 0)
                        {
                            isSimple = false;
                            break;
                        }

                    if (isSimple)
                    {
                        Console.Write($"{i} ");
                        sw.Write($"{i} ");
                    }
                }
            }


            void ThreadInfo(object thread)
            {
                Console.WriteLine("<-----Thread info----->");

                var currentThread = thread as Thread;
                Console.WriteLine($"Thread status: {currentThread.ThreadState}\n" +
                    $"Thread name: {currentThread.Name}\n" +
                    $"Thread priority: {currentThread.Priority}\n" +
                    $"Thread Id: {currentThread.ManagedThreadId}");

                Console.WriteLine("<-----End of thread info----->");
            }


            Console.WriteLine("\n<-----And now we have two streams----->");

            Console.WriteLine("Enter n one more time: ");
            n = int.Parse(Console.ReadLine());
            Thread showingEven = new Thread(ShowEven);
            Thread showingOdd = new Thread(ShowOdd) { Priority = ThreadPriority.Highest };
            //Thread showingName = new Thread(() => { Console.WriteLine("<-----End of two streams----->"); });
            showingEven.Start(n);
            showingOdd.Start(n);
            //showingName.Start();


            void ShowEven(object n)
            {
                //Console.WriteLine("First stream:");
                int numberEdge = (int)n;
                for (int i = 1; i <= numberEdge; i++)
                {
                    Thread.Sleep(100);
                    if (i % 2 == 0)
                    {
                        Console.WriteLine($"First: {i} ");
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
                        Console.WriteLine($"Second: {i} ");
                    }
                }
            }

            Synchronizer.EvenThenOdd(n);
            Synchronizer.AllEvenThenAllOdd(n);

            TimerCallback tm = new TimerCallback(ShowCurrenrTime);
            Timer timer = new Timer(tm, null, 1000, 1000);
            Thread.Sleep(7000);

            void ShowCurrenrTime(object obj)
            {
                Console.WriteLine($"\nCurrent time - {DateTime.Now.Hour}:{DateTime.Now.Minute}:{DateTime.Now.Second}");
            }

        }
       
    }
}