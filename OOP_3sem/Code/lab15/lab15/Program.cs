using System;
using System.Diagnostics;

namespace lab15
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int vectorSize = 100000;
            double[]vector = new double[vectorSize];
            Console.Write("Enter the scalar: ");
            double scalar = double.Parse(Console.ReadLine());

            for(int i = 0; i < vectorSize; i++)
            {
                vector[i] = i;
            }

            //for(int i = 0; i < vectorSize; i++)
            //{
            //    Console.WriteLine(vector[i]);
            //}

            Task<double[]> vectorMultiplicationTask = new Task<double[]>(() =>
            {
                double[]result = new double[vectorSize];
                for(int i = 0;i < vectorSize; i++)
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

            for(int i = 0; i < 10; i++)
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
            },cancellationTokenSource.Token);
            Console.WriteLine($"Task id: {vectorMultiplicationTaskCANC.Id}\tTask Status: {vectorMultiplicationTaskCANC.Status}");
            cancellationTokenSource.Cancel();
            Console.WriteLine($"Task id: {vectorMultiplicationTaskCANC.Id}\tTask Status: {vectorMultiplicationTaskCANC.Status}");

            Console.WriteLine("<-----End of cancelation----->");

            Console.WriteLine("<--Three tasks to complete the fourth-->");
            Console.Write("Enter height: ");
            int height = int.Parse(Console.ReadLine());
            Console.Write("Enter width: ");
            int width = int .Parse(Console.ReadLine());
            Console.Write("Enter mass: ");
            int mass = int.Parse(Console.ReadLine());
            Console.Write("Enter accelearation: ");
            int accseleration = int.Parse(Console.ReadLine());


            Task<int>calculateSquare = new Task<int>(() =>
            {
                //Console.WriteLine(height * width);
                return height*width;
            });

            Task<int> calculateForse = new Task<int>(() =>
            {
                //Console.WriteLine(mass * accseleration);
                return mass * accseleration;

            });

            Task<double> calculatePressure = new Task<double>(() =>{
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

            Task<double> awaitedTask =Task<double>.Run(() =>
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
            Parallel.For(0, 100000,FillWithElements);
            watch1.Stop();
            Console.WriteLine($"Parallel.For() was performed in {watch1.ElapsedMilliseconds} ms");
            void FillWithElements(int index)
            {
                array1[index] = index;
                array2[index] = index;
                array3[index] = index;
            }

            watch1.Restart();
            for(int i = 0; i < 100000; i++)
            {
                array1[i] = i;
                array2[i] = i;
                array3[i] = i;
            }
            watch1.Stop();
            Console.WriteLine($"Simple For loop was perfoemed in {watch1.ElapsedMilliseconds} ms");

            Console.WriteLine("<-----End of parallel----->");

        }
    }
}