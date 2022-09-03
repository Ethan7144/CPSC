/*
 Ethan Tarlov
6/1/2022
P5.cs
 
This driver will test all of the guard types and their functions.
This will also test the CrossProduct Classes and Demonstrate how they work with
each type of dataExtractor and Guard called at least one time.
The first 3 in the CrossTest will be dataExtractors with all of the guard types.
The first one will be guard. 2nd will be quirkyguard, the 3rd will be skipGuard.
The last 3 will be guards with all of the dataExtractor Types.
1st one will be a DataExtractor, 2nd will be dataHalf, 3rd will be dataPlus.
Will test each function twice to show state change effects.


Advisory: Sometimes it will not always be different results, due to random being used for the
function calls. Some prime numbers might be the same even in different state changes due to
the vairable being input into the function.
*/

using System;
using Guards;
using DataExtractor;
using iGuards;
namespace P5
{
    public class P5
    {
        static void Main(string[] args)
        {
            GuardTest();
            CrossTest();
        }
           
        static void GuardTest()
        {
            Console.WriteLine("Creating Guard heterogeneous collection");
            Random rand = new Random();
            int size = rand.Next(5, 30);
            int guardSize = 6;
            int[] x = new int[size];
            Guard[] obj = new Guard[guardSize];
            for(int j = 0; j < 2; j++)
            {
                for (int i = 0; i < size; i++)
                {
                    x[i] = rand.Next(1, 100);
                }
                obj[j] = new Guard(x);
            }
            for (int j = 2; j < 4; j++)
            {
                for (int i = 0; i < size; i++)
                {
                    x[i] = rand.Next(1, 100);
                }
                obj[j] = new skipGuard(x);
            }
            for (int j = 4; j < 6; j++)
            {
                for (int i = 0; i < size; i++)
                {
                    x[i] = rand.Next(1, 100);
                }
                obj[j] = new quirkyGuard(x);
            }
            Console.WriteLine("Testing Value for each Guard");
            for(int i = 0; i < guardSize; i++)
            {
                Console.WriteLine("Printing Value");
                Console.WriteLine(obj[i].value(38));
            }
            Console.WriteLine("Testing Value for each Guard a 2nd time");
            for (int i = 0; i < guardSize; i++)
            {
                Console.WriteLine("Printing Value");
                Console.WriteLine(obj[i].value(38));
            }

        }
        static void CrossTest()
        {
            Console.WriteLine("Creating CrossProduct heterogeneous collection");
            Console.WriteLine("Will create one of each Cross Product class");
            Random rand = new Random();
            int size = rand.Next(5, 30);
            int guardSize = 6;
            int[] x = new int[size];
            int chooser = 0;
            iGuard[] obj = new iGuard[guardSize];
            for (int j = 0; j < 3; j++)
            {
                for (int i = 0; i < size; i++)
                {
                    x[i] = rand.Next(1, 100);
                }
                obj[j] = new ExtractorGuard(rand.Next(5,30), x, chooser);
                chooser++;
            }
            chooser = 0;
            for (int j = 3; j < 6; j++)
            {
                for (int i = 0; i < size; i++)
                {
                    x[i] = rand.Next(1, 100);
                }
                obj[j] = new GuardExtractor(rand.Next(5, 30), x, chooser);
                chooser++;
            }
            Console.WriteLine("Testing Value for each CrossProduct");
            for (int i = 0; i < guardSize; i++)
            {
                Console.WriteLine("Printing Value");
                Console.WriteLine(obj[i].value(38));
            }
            Console.WriteLine("Testing Value for each CrossProduct a 2nd time");
            for (int i = 0; i < guardSize; i++)
            {
                Console.WriteLine("Printing Value");
                Console.WriteLine(obj[i].value(38));
            }
            Console.WriteLine("Testing Any for each CrossProduct");
            for (int i = 0; i < guardSize; i++)
            {
                Console.WriteLine("Printing Value");
                Console.WriteLine(String.Join(",",obj[i].any()));
            }
            Console.WriteLine("Testing Any for each CrossProduct a 2nd time");
            for (int i = 0; i < guardSize; i++)
            {
                Console.WriteLine("Printing Value");
                Console.WriteLine(String.Join(",",obj[i].any()));
            }
            Console.WriteLine("Testing Target for each CrossProduct");
            for (int i = 0; i < guardSize; i++)
            {
                Console.WriteLine("Printing Value");
                Console.WriteLine(String.Join(",", obj[i].target(4)));
            }
            Console.WriteLine("Testing Target for each CrossProduct a 2nd time");
            for (int i = 0; i < guardSize; i++)
            {
                Console.WriteLine("Printing Value");
                Console.WriteLine(String.Join(",", obj[i].target(4)));
            }
            Console.WriteLine("Testing Sum for each CrossProduct");
            for (int i = 0; i < guardSize; i++)
            {
                Console.WriteLine("Printing Value");
                Console.WriteLine(obj[i].sum(5));
            }
            Console.WriteLine("Testing Sum for each CrossProduct a 2nd time");
            for (int i = 0; i < guardSize; i++)
            {
                Console.WriteLine("Printing Value");
                Console.WriteLine(obj[i].sum(5));
            }
        }
    }
}