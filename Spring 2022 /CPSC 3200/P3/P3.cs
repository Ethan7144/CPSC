/*
Ethan Tarlov
4/28/22
P3.cs
Driver tested dataExtractors, dataHalf, and dataPlus objects.
Create a heterogenous collection of objects of different types.
Will show state changes and the result of each function and functionality of it.
Will limit test the functions to show that special conditions will be in use
after specific conditions have been met.
 */

using System;
namespace P3
{
    public class P3
    {
        static void Main(string[] args)
        {
            Random rand = new Random();
            dataExtractors[] obj = new dataExtractors[] // Setting up random Numbers
            {
                new dataExtractors(),
                new dataExtractors(),
                new dataHalf(rand.Next(10,15)),
                new dataHalf(rand.Next(10,15)),
                new dataPlus(rand.Next(5,8),rand.Next(5,10)),
                new dataPlus(rand.Next(5,8),rand.Next(5,10))
            };

            Console.WriteLine("Adding 5 random numbers to each x y array in each object");
            for (int i = 0; i < 6; i++)
            {
                obj[i].addXArray(rand.Next(0, 5));
                obj[i].addXArray(rand.Next(6, 10));
                obj[i].addXArray(rand.Next(11, 15));
                obj[i].addXArray(rand.Next(16, 20));
                obj[i].addXArray(rand.Next(21, 25));
                obj[i].addYArray(rand.Next(0, 5));
                obj[i].addYArray(rand.Next(6, 10));
                obj[i].addYArray(rand.Next(11, 15));
                obj[i].addYArray(rand.Next(16, 20));
                obj[i].addYArray(rand.Next(21, 25));
            }
            Console.WriteLine("DataExtractor Object");
            Console.WriteLine(string.Join(", ", obj[0].any()));
            Console.WriteLine(obj[0].sum(2));
            // dataExtractor state Change
            obj[0].addXArray(50);
            obj[0].addXArray(50);
            Console.WriteLine(string.Join(", ", obj[0].target(3)));
            Console.WriteLine(string.Join(", ", obj[0].any()));
            Console.WriteLine(obj[0].sum(2));
            obj[0].addXArray(50);
            Console.WriteLine(string.Join(", ", obj[0].target(3)));
            Console.WriteLine(string.Join(", ", obj[0].any()));

            Console.WriteLine(obj[1].sum(5));
            Console.WriteLine(string.Join(", ", obj[1].target(3)));
            Console.WriteLine(string.Join(", ", obj[1].any()));
            obj[0].addYArray(50);
            Console.WriteLine(obj[1].sum(5));
            Console.WriteLine(string.Join(", ", obj[1].target(3)));
            Console.WriteLine(string.Join(", ", obj[1].any()));

            // DataHalf
            Console.WriteLine("DataHalf Object");
            Console.WriteLine(string.Join(", ", obj[2].any()));
            Console.WriteLine(obj[2].sum(2));
            Console.WriteLine("Making Obj 2 push out of bounds");
            obj[2].addXArray(100);
            obj[2].addXArray(101);
            obj[2].addXArray(102);
            obj[2].addXArray(103);
            obj[2].addXArray(104);
            obj[2].addXArray(105);
            obj[2].addXArray(106);
            obj[2].addXArray(107);
            obj[2].addXArray(108);
            obj[2].addXArray(109);
            obj[2].addXArray(110);
            Console.WriteLine(string.Join(", ", obj[2].target(3)));
            Console.WriteLine(string.Join(", ", obj[2].any()));
            Console.WriteLine(obj[2].sum(2));
            obj[2].addXArray(50);
            Console.WriteLine(string.Join(", ", obj[2].target(3)));
            Console.WriteLine(string.Join(", ", obj[2].any()));

            Console.WriteLine(obj[3].sum(5));
            Console.WriteLine(string.Join(", ", obj[3].target(3)));
            Console.WriteLine(string.Join(", ", obj[3].any()));
            obj[3].addYArray(50);
            Console.WriteLine(obj[1].sum(5));
            Console.WriteLine(string.Join(", ", obj[3].target(3)));
            Console.WriteLine(string.Join(", ", obj[3].any()));

            //DataPlus
            Console.WriteLine("DataPlus Object");
            Console.WriteLine(string.Join(", ", obj[5].any()));
            obj[5].addYArray(50);
            obj[5].addYArray(50);
            Console.WriteLine(string.Join(", ", obj[5].any()));
            obj[5].addYArray(51);
            obj[5].addYArray(52);
            obj[5].addYArray(53);
            obj[5].addYArray(54);
            obj[5].addYArray(55);
            Console.WriteLine(string.Join(", ", obj[5].any()));
            Console.WriteLine(string.Join(", ", obj[5].target(3)));
            Console.WriteLine(obj[5].sum(5));

            Console.WriteLine(obj[4].sum(5));
            Console.WriteLine(string.Join(", ", obj[4].target(3)));
            Console.WriteLine(string.Join(", ", obj[4].any()));
            obj[0].addYArray(50);
            Console.WriteLine(obj[4].sum(5));
            Console.WriteLine(string.Join(", ", obj[4].target(3)));
            Console.WriteLine(string.Join(", ", obj[4].any()));
        }
    }
}
