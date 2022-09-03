/*Ethan Tarlov
6/1/2022
GuardExtractor.cs

Class invariant: This class will use the iGuard interface and composition for
guard and all of the dataExtractor classes.
The functions will just return whatever the function call for each of the functions.
So DataExtractor will return its version of
target and sum and vice versa. The class uses polymorphism in it.
The 3rd arg of the constructor "Choose" is what allows the user to
pick what type of dataExtractor they want to interact with Guard.
If they choose 0, it will be a normal dataExtractor, 1 will be a dataHalf
and any other positive number will end up as dataPlus.
The default constructor will set it to dataExtractor and a
assume 0 was chosen.
The number will be stored as well so the correct variation of value is called.

Interface invariant: Any of the limitations with dataExtractors or the guard
classes still apply here.
The arrays must not be empty, and ySize cannot be 0.
Choose MUST be a positive int or 0.
The function calls also face the same limitations as well.
Z cannot be larger than the arraysize in either target or sum.
The client cannot change what dataExtractor they chose after the object has been constructed.
The Client cannot access anything inside of the class besides the functions.
 */

using System;
using DataExtractor;
using Guards;
namespace iGuards
{
    public class GuardExtractor : iGuard
    {
        dataExtractors de;
        dataHalf dh;
        dataPlus dp;
        Guard g;
        int chosenOne;
        public GuardExtractor(int ySize, int[] injection, int choose)
        {
            if (choose < 0)
                throw new ArgumentException("Choose must be a positive Number");
            g = new Guard(injection);
            chosenOne = choose;
            if (chosenOne == 0)
            {
                de = new dataExtractors(injection, ySize);
            }
            else if (chosenOne == 1)
            {
                dh = new dataHalf(injection, ySize);
            }
            else
            {
                dp = new dataPlus(injection, ySize);
            }
        }
        public GuardExtractor()
        {
            de = new dataExtractors();
            g = new Guard();
            chosenOne = 0;
        }
        public int value(int x)
        {
            return g.value(x);
        }
        public int sum(int z)
        {
            if (chosenOne == 0)
            {
                return de.sum(z);
            }
            else if (chosenOne == 1)
            {
                return dh.sum(z);
            }
            else
            {
                return dp.sum(z);
            }
        }
        public int[] any()
        {
            if (chosenOne == 0)
            {
                return de.any();
            }
            else if (chosenOne == 1)
            {
                return dh.any();
            }
            else
            {
                return dp.any();
            }
        }
        public int[] target(int z)
        {
            if (chosenOne == 0)
            {
                return de.target(z);
            }
            else if (chosenOne == 1)
            {
                return dh.target(z);
            }
            else
            {
                return dp.target(z);
            }
        }
    }
}
/*
 Implemtation invariant: Any of the specifications in dataExtractors and
any of the guard classes still apply. The numbers in the array must be
Unique numbers or else they will be doubled. Guards must have a number to
compare prime to (x) as a positive number. They follow the classes the same
way as they are normally followed.
 */