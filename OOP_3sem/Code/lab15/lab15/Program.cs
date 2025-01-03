using System.Collections.Concurrent;
using System.Diagnostics;

namespace lab15
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int vectorSize = 100000;
            double[] vector = new double[vectorSize];
            Console.Write("Enter the scalar: ");
            double scalar = double.Parse(Console.ReadLine());

            for (int i = 0; i < vectorSize; i++)
            {
                vector[i] = i;
            }

            //for(int i = 0; i < vectorSize; i++)
            //{
            //    Console.WriteLine(vector[i]);
            //}

            Task<double[]> vectorMultiplicationTask = new Task<double[]>(() =>
            {
                double[] result = new double[vectorSize];
                for (int i = 0; i < vectorSize; i++)
                {
                    result[i] = vector[i] * scalar;
                }


                Console.WriteLine("Multiplication completed");
                return result;
            });
            var watch = new Stopwatch();
            Console.WriteLine($"Task id:{vectorMultiplicationTask.Id}\tTask status: {vectorMultiplicationTask.Status}");


            vectorMultiplicationTask.Start();
            watch.Start();
            Console.WriteLine($"Task id:{vectorMultiplicationTask.Id}\tTask status: {vectorMultiplicationTask.Status}");


            vectorMultiplicationTask.Wait();
            watch.Stop();
            Console.WriteLine($"Task id:{vectorMultiplicationTask.Id}\tTask status: {vectorMultiplicationTask.Status}");


            Console.WriteLine($"Task has been completed in {watch.ElapsedMilliseconds} ms");
            Console.WriteLine("Showing first few lines to be shure");

            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine(vectorMultiplicationTask.Result[i]);
            }

            Console.WriteLine("<-----End of vector multiplication----->");



            Console.WriteLine("\n<-----Same task with cancelation----->");

            CancellationTokenSource cancellationTokenSource = new CancellationTokenSource();
            Task<double[]> vectorMultiplicationTaskCANC = new Task<double[]>(() =>
            {
                double[] result = new double[vectorSize];
                for (int i = 0; i < vectorSize; i++)
                {
                    result[i] = vector[i] * scalar;
                }


                Console.WriteLine("Multiplication completed");
                return result;
            }, cancellationTokenSource.Token);
            Console.WriteLine($"Task id: {vectorMultiplicationTaskCANC.Id}\tTask Status: {vectorMultiplicationTaskCANC.Status}");
            cancellationTokenSource.Cancel();
            Console.WriteLine($"Task id: {vectorMultiplicationTaskCANC.Id}\tTask Status: {vectorMultiplicationTaskCANC.Status}");

            Console.WriteLine("<-----End of cancelation----->");

            Console.WriteLine("<--Three tasks to complete the fourth-->");
            Console.Write("Enter height: ");
            int height = int.Parse(Console.ReadLine());
            Console.Write("Enter width: ");
            int width = int.Parse(Console.ReadLine());
            Console.Write("Enter mass: ");
            int mass = int.Parse(Console.ReadLine());
            Console.Write("Enter accelearation: ");
            int accseleration = int.Parse(Console.ReadLine());


            Task<int> calculateSquare = new Task<int>(() =>
            {
                //Console.WriteLine(height * width);
                return height * width;
            });

            Task<int> calculateForse = new Task<int>(() =>
            {
                //Console.WriteLine(mass * accseleration);
                return mass * accseleration;

            });

            Task<double> calculatePressure = new Task<double>(() =>
            {
                //Console.WriteLine(calculateForse.Result / calculateSquare.Result);
                return calculateForse.Result / calculateSquare.Result;
            });
            int g = 10;
            int volume = 5;
            Task<double> calculateDencity = new Task<double>(() =>
            {
                return calculatePressure.Result / (volume * g);
            });

            calculateSquare.Start();
            calculateForse.Start();
            calculatePressure.Start();

            calculateForse.Wait();
            calculatePressure.Wait();
            calculateSquare.Wait();

            calculateDencity.Start();
            Console.WriteLine($"Calculated dencity: {calculateDencity.Result}");
            calculateDencity.Wait();
            Console.WriteLine("<-----End fo four tasks----->");


            Console.WriteLine("\n<-----Tasks with continuations----->");

            Task firstTask = new Task(() => Console.Write("First task"));

            Task secondTask = firstTask.ContinueWith(t => Console.WriteLine("...Continued by second task(ContinueWith)"));
            firstTask.Start();
            secondTask.Wait();


            Console.Write("Enter number between 1 and 100: ");
            int num = int.Parse(Console.ReadLine());
            Console.Write("Enter the power: ");
            int power = int.Parse(Console.ReadLine());

            Task<double> awaitedTask = Task<double>.Run(() =>
            {
                return Math.Pow(num, power);
            });
            var awaiter = awaitedTask.GetAwaiter();
            awaiter.OnCompleted(async () =>
            {
                double result = awaiter.GetResult();
                Console.WriteLine($"The result of mathematic performance was: {result}\n" +
                    $"<-----End of continuations----->");
            });


            Console.WriteLine("<-----Using Parallel----->");
            var array1 = new int[100000];
            var array2 = new int[100000];
            var array3 = new int[100000];

            var watch1 = new Stopwatch();
            watch1.Start();
            Parallel.For(0, 100000, FillWithElements);
            watch1.Stop();
            Console.WriteLine($"Parallel.For() was performed in {watch1.ElapsedMilliseconds} ms");
            void FillWithElements(int index)
            {
                array1[index] = index;
                array2[index] = index;
                array3[index] = index;
            }

            watch1.Restart();
            for (int i = 0; i < 100000; i++)
            {
                array1[i] = i;
                array2[i] = i;
                array3[i] = i;
            }
            watch1.Stop();
            Console.WriteLine($"Simple For loop was perfoemed in {watch1.ElapsedMilliseconds} ms");

            int accumulator = 0;
            watch1.Restart();
            Parallel.ForEach(array2, GetElemetnsSumm);
            watch1.Stop();
            Console.WriteLine($"Parallel.ForEach() was performed in {watch1.ElapsedMilliseconds} ms");
            void GetElemetnsSumm(int element)
            {
                accumulator += element;
            }

            watch1.Restart();
            accumulator = 0;
            foreach (int item in array2)
            {
                accumulator += item;
            }
            watch1.Stop();
            Console.WriteLine($"Simple ForeEach loop ws performed in {watch1.ElapsedMilliseconds} ms");


            Console.WriteLine("<-----End of parallel----->");


            Console.WriteLine("\n<-----Using Parallel.Invoke()----->");

            var array16 = new int[10000000];
            var array26 = new int[10000000];
            var array36 = new int[10000000];


            Parallel.Invoke
            (

                () =>
                {
                    for (var i = 0; i < array16.Length; i++)
                    {
                        array16[i] = i;
                    }
                },
                () =>
                {
                    for (var i = 0; i < array26.Length; i++)
                    {
                        array26[i] = i;
                    }
                },
                () =>
                {
                    for (var i = 0; i < array36.Length; i++)
                    {
                        array36[i] = i;
                    }
                }
            );

            Console.WriteLine("<-----End of Invoke----->");

            Console.WriteLine("\n<-----Shop task----->");

            Console.WriteLine();
            BlockingCollection<string> bc = new BlockingCollection<string>(5);

            //5 suppliers
            Task[] sellers = new Task[5]
            {
    new Task(() =>
    {
        while (true)
        {
            Thread.Sleep(700);
            bc.Add("Washing machine");
        }
    }),
    new Task(() =>
    {
        while (true)
        {
            Thread.Sleep(400);
            bc.Add("Blender");
        }
    }),
    new Task(() =>
    {
        while (true)
        {
            Thread.Sleep(500);
            bc.Add("Washing machine");
        }
    }),
    new Task(() =>
    {
        while (true)
        {
            Thread.Sleep(300);
            bc.Add("Microwave oven");
        }
    }),
    new Task(() =>
    {
        while (true)
        {
            Thread.Sleep(700);
            bc.Add("Robot vacuum cleaner");
        }
    })
            };

            foreach (var i in sellers)
                if (i.Status != TaskStatus.Running)
                    i.Start();

            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine($"Number of goods in stock: {bc.Count}");
                Thread.Sleep(600);
                Thread thr = new Thread(Customer);
                thr.Start();
            }

            void Customer()
            {
                Console.ForegroundColor = ConsoleColor.Cyan;
                if (bc.Count == 0)
                {
                    Console.WriteLine("Customer left without buying anything");
                    return;
                }
                Console.WriteLine($"Customer bought {bc.Take()}");
                Console.ForegroundColor = ConsoleColor.White;
            }


            Console.WriteLine("\n\n<-----Async/Await----->");

            Thread.Sleep(1000);
            Console.WriteLine();
            int Fibonacci(int n)
            {
                if (n == 0 || n == 1)
                {
                    return n;
                }

                Thread.Sleep(100);
                return Fibonacci(n - 1) + Fibonacci(n - 2);
            }

            async void FibonacciAsync(int n)
            {
                Console.WriteLine($"Started calculating {n}-th Fibonacci number");
                var result = Task<int>.Factory.StartNew(() => Fibonacci(n));
                int value = await result;
                Console.WriteLine($"Result: {value}");
            }

            FibonacciAsync(7);
            Console.ReadKey();


            Console.WriteLine("<-----End of async----->");
        }


    }
}