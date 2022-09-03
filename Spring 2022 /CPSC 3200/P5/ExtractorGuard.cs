/*Ethan Tarlov
6/1/2022
ExtractorGuard.cs

Class invariant: This class will use the iGuard interface and composition for
DataExtractors and all of the guard classes.
The functions will just return whatever the function call for each of the functions.
So DataExtractor will return its version of
target and sum and vice versa. The class uses polymorphism in it.
The 3rd arg of the constructor "Choose" is what allows the user to
pick what type of guard they want to interact with dataExtractors.
If they choose 0, it will be a normal guard, 1 will be a qurikyGuard
and any other positive number will end up as skipGuard.
The default constructor will set it to Guard and
assume 0 was chosen.
The number will be stored as well so the correct variation of value is called.

Interface invariant: Any of the limitations with dataExtractors or the guard
classes still apply here.
The arrays must not be empty, and ySize cannot be 0.
Choose MUST be a positive int or 0.
The function calls also face the same limitations as well.
Z cannot be larger than the arraysize in either target or sum.
The client cannot change what guard they chose after the object has been constructed.
The Client cannot access anything inside of the class besides the functions.
 */

using System;
using DataExtractor;
using Guards;
namespace iGuards
{
    public class ExtractorGuard : iGuard
    {
        dataExtractors de;
        Guard g;
        quirkyGuard qg;
        skipGuard sg;
        int chosenOne;
        public ExtractorGuard(int ySize, int[] injection, int choose) 
        {
            if (choose < 0)
                throw new ArgumentException("Choose must be a positive Number or 0");
            de = new dataExtractors(injection, ySize);
            chosenOne = choose;
            if(chosenOne == 0)
            {
                g = new Guard(injection);
            }
            else if(chosenOne == 1)
            {
                qg = new quirkyGuard(injection);
            }
            else
            {
                sg = new skipGuard(injection);
            }
        }
        public ExtractorGuard()
        {
            de = new dataExtractors();
            g = new Guard();
            chosenOne = 0;
        }
        public int value(int x)
        {
            if (chosenOne == 0)
            {
                return g.value(x);
            }
            else if (chosenOne == 1)
            {
                return qg.value(x);
            }
            else
            {
                return sg.value(x);
            }
        }
        public int sum(int z)
        {
            return de.sum(z);
        }
        public int[] any()
        {
            return de.any();
        }
        public int[] target(int z)
        {
            return de.target(z);
        }
    }
}

/*
 Implemtation invariant: Any of the specifications in dataExtractors and
any of the guard classes still apply. The numbers in the array must be
Unique numbers or else they will be doubled. Guard must have a number to
compare prime to (x) as a positive number. They follow the classes the same
way as they are normally followed.
 */
