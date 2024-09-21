
using System;
using System.Collections.Specialized;
using System.Security.Cryptography.X509Certificates;
using System.Text;

namespace lab1
{
    class LAB1
    {
        public static void Main(string[] args)
        {
            //TASK 1A
            bool boolean_var = false;
            byte unsigned_8bit_int = 14;
            sbyte signed_8bit_int = -122;
            short signed_16bit_int = -14521;
            ushort unsigned_16bit_int = 13555;
            int signed_32bit_int = -1682143;
            uint unsigned_32bit_int = 1223344;
            long signed_64bit_int = -94856984981651;
            ulong unsigned_64bit_int = 10845189491;
            char character_16bit = 'a';
            decimal decimal_16bit = 1.56E10M;
            float float_4bit = 12.2E2F;
            double double_8bit = 15E4D;
            nint native_integer = -181818181;
            nuint native_unsigned_integer = 1433913931;

            Console.WriteLine($"bool: {boolean_var}\nbyte:{unsigned_8bit_int}\nsbyte:{signed_8bit_int}\nshort:{signed_16bit_int}\n" +
                $"ushort:{unsigned_16bit_int}\nint:{signed_32bit_int}\nuint:{unsigned_32bit_int}\nlong:{signed_64bit_int}\n" +
                $"ulong:{unsigned_64bit_int}\nchar:{character_16bit}\ndecimal:{decimal_16bit}\nfloat:{float_4bit}\ndouble:{double_8bit}\n" +
                $"nint:{native_integer}\nnuint:{native_unsigned_integer}");
            Console.WriteLine($"<-------------------->\nTASK 1B");
            //TASK 1B
            int in1 = 15482;
            long lg1 = in1;

            double db1 = 15482.174;
            int in2 = (int)db1;

            float fl1 = 16.124f;
            double db2 = fl1;

            double db3 = 16.12345678910111213;
            float fl2 = (float)db3;

            long lg2 = 59492948595814;
            nint nn1 = (nint)lg2;

            double db4 = 128.15616841;
            int in3 = Convert.ToInt32(db4);

            Console.WriteLine($"<-------------------->\nTASK 1C");
            //TASK 1C
            double smth = 123.456789;
            object smth_obj = smth;//implicit packing
            object smth_obj1 = (object)smth;//explicit packing

            double smth2 = (double)smth_obj;//unpacking. can't be implicit

            Console.WriteLine($"<-------------------->\nTASK 1D");
            //TASK 1D
            int n1 = 16;
            double n2 = 15.23456;
            var non_type = n1 + n2;
            Console.WriteLine(non_type);

            Console.WriteLine($"<-------------------->\nTASK 1E");
            int? nullable_int = null;
            if (nullable_int.HasValue)
            {
                Console.WriteLine("Nullable variable is not null");
            }
            else
            {
                Console.WriteLine("Nullable variable is null");
            }

            Console.WriteLine($"<-------------------->\nTASK 1F");

            var check_fail = 16;
            check_fail = 'a';
            Console.WriteLine(check_fail);

            Console.WriteLine($"<-------------------->\nTASK 2A");
            string literal1 = "It's literal 1";
            string literal2 = "It's literal 2";
            Console.WriteLine(literal1 == literal2);

            Console.WriteLine($"<-------------------->\nTASK 2B");
            string str1 = "Hello!";
            string str2 = "What's ";
            string str3 = "up?";
            string str4;
            //concatenation
            Console.WriteLine($"Concatenation: {str1 + str2 + str3} or {string.Concat(str1, str2, str3)}");
            //copying
            str4 = String.Copy(str2);
            Console.WriteLine($"Copying str2 to str4: {str4}");
            //highlite a substring
            string substring = str1.Substring(str1.Length - 3);
            Console.WriteLine($"A substring from str1: {substring}");
            //devide a string into several words
            string text = "Hello,it's me! Let's drink some beer";
            string[] words = text.Split(new char[] { ' ', '!', ',' }, StringSplitOptions.RemoveEmptyEntries);
            Console.WriteLine("Devision into words:\n");
            foreach (var word in words)
            {
                Console.WriteLine($"{word}\n");
            }
            //insert a substring into a string
            string ToInsert = "Wanna srink some beer?";
            string ResultOfInsertion = str1.Insert(6, ToInsert);
            Console.WriteLine($"Insertion: {ResultOfInsertion}");
            //deletion of a required substring
            string RemoveFrom = "Let's drink beer";
            string SubstringToRemove = "beer";
            string ResultOfDeletion = RemoveFrom.Replace(SubstringToRemove, "");
            Console.WriteLine($"Removing s substring from a string:{ResultOfDeletion}");

            //string interpolation
            string name = "Ivan";
            string FavBeer = "Alivariya Beloye Zoloto";
            string Greet = $"Hi,{name}, your favorite beer is {FavBeer}";
            Console.WriteLine($"String interpolation: {Greet}");
            Console.WriteLine("<-------------------->");
            Console.WriteLine("TASK 2C");
            //creation of null string
            string EmptyString = "";
            string NullString = null;
            if (string.IsNullOrEmpty(EmptyString) && string.IsNullOrEmpty(NullString))
            {
                Console.WriteLine("This strings are empty or null");
            }
            else
            {
                Console.WriteLine("This string is not empty");
            }
            //concatenation with a null string
            string NullConcatenation = String.Concat(name, NullString);
            Console.WriteLine($"Null string concatenation: {NullConcatenation}");
            int FromStringConvertion = Convert.ToInt32(NullString);
            Console.WriteLine($"Convertion to Int32: {FromStringConvertion}");

            if (string.IsNullOrWhiteSpace(NullString))
            {
                Console.WriteLine("This string is sempty");
            }
            else
            {
                Console.WriteLine("THis string is not empty");
            }
            Console.WriteLine("<-------------------->");
            Console.WriteLine("TASK 2D");
            StringBuilder stringBuilder = new StringBuilder("Hi!");
            stringBuilder.Append("Do you like beer?");
            Console.WriteLine($"A string built using StringBuilder: {stringBuilder}");
            stringBuilder.Insert(0, "HHHHH");
            Console.WriteLine(stringBuilder);
            stringBuilder.Remove(5, 5);
            Console.WriteLine(stringBuilder);

            Console.WriteLine("<-------------------->");
            Console.WriteLine("TASK 3A");
            //creation of a 2d array
            int[,] MAtrix = new int[4, 4];
            int NumberToMatrix = 0;
            Console.WriteLine("Filled matrix: ");
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    MAtrix[i, j] = NumberToMatrix;
                    NumberToMatrix++;
                    Console.Write($"{MAtrix[i, j]} ");
                }
                Console.WriteLine();
            }

            Console.WriteLine("<-------------------->");
            Console.WriteLine("TASK 3B");
            string[] LineArray = new string[4];
            LineArray[0] = "I like beer";
            LineArray[1] = "Let's drink beer";
            LineArray[2] = "How much is for a beer?";
            LineArray[3] = "I have no beer left";
            Console.WriteLine("An array of strings: ");
            Console.Write('[');
            for (int i = 0; i < 4; i++)
            {
                if (i != 3)
                {
                    Console.Write($" {LineArray[i]} , ");
                }
                else
                {
                    Console.Write($" {LineArray[i]} ");
                }
            }
            Console.Write("] \n");
            Console.WriteLine($"Array's length: {LineArray.Length}");

            Console.WriteLine("Enter an element to be changed: ");
            string ElementToChange = Console.ReadLine();
            int ElementNumber = int.Parse(ElementToChange);



            Console.WriteLine("Enter a new value of a chosen element: ");
            string NewValue = Console.ReadLine();
            LineArray[ElementNumber - 1] = NewValue;
            Console.WriteLine("New version of array: ");
            Console.Write('[');
            for (int i = 0; i < 4; i++)
            {
                if (i != 3)
                {
                    Console.Write($"{LineArray[i]} ,");
                }
                else
                {
                    Console.Write($" {LineArray[i]} ");
                }

            }
            Console.Write("] \n");

            Console.WriteLine("<-------------------->");
            Console.WriteLine("TASK 3C");

            int[][] JaggedArray = new int[3][];
            for (int i = 0; i < 3; i++)
            {
                Console.Write($"Enter the amount of elements in string number {i + 1}: ");
                int Columns = Convert.ToInt32(Console.ReadLine());
                JaggedArray[i] = new int[Columns];
                for (int j = 0; j < Columns; j++)
                {
                    Console.Write($"Enter the value of element number {j + 1} in line number {i + 1}: ");
                    JaggedArray[i][j] = Convert.ToInt32(Console.ReadLine());
                }
            }
            Console.WriteLine("Jagged Array: ");
            //Console.Write('[');
            for (int i = 0; i < JaggedArray.Length; i++)
            {

                for (int j = 0; j < JaggedArray[i].Length; j++)
                {
                    Console.Write($" {JaggedArray[i][j]} ");
                }
                Console.WriteLine();
            }
            //Console.Write("] \n");

            Console.WriteLine("<-------------------->");
            Console.WriteLine("TASK 3D");

            var StoreArray = new[] { 1, 2, 3 };
            Console.WriteLine("An array of implicit type: ");
            Console.Write('[');
            for (int i = 0; i < StoreArray.Length; i++)
            {
                Console.Write($" {StoreArray[i]} ");
            }
            Console.Write("] \n");
            var StoreString = "Implicit string";
            Console.Write($"String of an implicit type: {StoreString} \n");


            Console.WriteLine("<-------------------->");
            Console.WriteLine("TASK 4A and B");
            (int, string, char, string, ulong) MyTouple = (15, "Touple", 'a', "C#", 131313131);
            Console.WriteLine($"The whole touple: {MyTouple}");
            Console.WriteLine($"Some elements of touple: {MyTouple.Item1}, {MyTouple.Item3}");

            Console.WriteLine("<-------------------->");
            Console.WriteLine("TASK 4C");
            //implicit deconstruction
            (var FirstTP, var SecondTP, var ThirdTP, var FourthTP, var FivthTP) = MyTouple;
            Console.WriteLine($"Implicit deconstruction: {FirstTP} , {SecondTP} , {ThirdTP} , {FourthTP} , {FivthTP} ");
            //Explicit deconstruction
            (int FirstT, string SecondT, char ThirdT, string FourthT, ulong FivthT) = MyTouple;
            Console.WriteLine($"Explicit deconstruction: {FirstT} , {SecondT} , {ThirdT} , {FourthT} , {FivthT}");
            //Deconstruction using _
            (_, string TPStr, _, string TPStr2, _) = MyTouple;
            Console.WriteLine($"Get only strings from a touple: {TPStr} , {TPStr2}");

            Console.WriteLine("<-------------------->");
            Console.WriteLine("TASK 4D");
            (int NumA, double NumB) ToupleA = (14, 18.123);
            (int NumB, double NumC) ToupleB = (14, 18.123);
            Console.WriteLine("Touple comparison:");
            Console.WriteLine(ToupleA == ToupleB);

            (int NumT, int NumD) ToupleC = (18, 124);
            Console.WriteLine(ToupleC == ToupleA);

            Console.WriteLine("<-------------------->");
            Console.WriteLine("TASK 5");

            (int,int,int,char) GetTouple(int[]InputArray,string InputString)
            {
                int MaxArrayElem = InputArray.Max();
                int MinArrayElem = InputArray.Min();
                int SumOfElements = 0;
                for(int i = 0;i<InputArray.Length;i++)
                {
                    SumOfElements += InputArray[i];
                }
                char StrFirstLetter = InputString[0];
                
                return (MaxArrayElem,MinArrayElem,SumOfElements,StrFirstLetter);
            }
            int[] ArrToFunc = new int[5];
            for(int i = 0; i < ArrToFunc.Length; i++)
            {
                ArrToFunc[i] = (i + 1) * 5;
            }
            string StrToFunc = "Why am i doing this?";

            (int,int,int,char)ReturnedTouple =  GetTouple(ArrToFunc, StrToFunc);
            Console.WriteLine(ReturnedTouple);

            Console.WriteLine("<-------------------->");
            Console.WriteLine("TASK 6A, B and C");

            void Checked()
            {
                try
                {
                    checked
                    {
                        int MaximalINTCH = int.MaxValue;
                        Console.WriteLine($"Checked max int: {MaximalINTCH + 1}");
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.Message);
                }
      
            }
            Checked();
            void Unchecked()
            {
                try
                {
                    unchecked
                    {
                        int MaximalINTUN = int.MaxValue;
                        Console.WriteLine($"Uncahecked int max: {MaximalINTUN + 1}");
                    }
                }
                catch(Exception ex) 
                { 
                    Console.WriteLine( ex.Message); 
                }
               
            }
            Unchecked();
        }

    }
}


