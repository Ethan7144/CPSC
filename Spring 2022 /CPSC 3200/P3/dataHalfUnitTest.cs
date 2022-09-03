// Ethan Tarlov
// 4/28/22
// dataHalfUnitTest.cs


//Unit Testing for Data Extractors
using Microsoft.VisualStudio.TestTools.UnitTesting;
using P3;
using System;
namespace dataHalfUnitTest
{
    [TestClass]
    public class dataHalfUnitTest
    {
        [TestMethod]
        public void NonUnique()
        {
            int[] numsAdded = new int[10];
            dataHalf obj = new dataHalf(20);
            for (int i = 0; i < 10; i++)
            {
                obj.addXArray(i);
                numsAdded[i] = i;
            }

            try
            {
                checkArray(obj, 5, numsAdded);
            }
            catch (ArgumentException e)
            {
                Console.WriteLine(e.Message);
            }


        }
        public static int checkArray(dataHalf obj, int num, int[] array)
        {
            for (int i = 0; i < 10; i++)
            {
                if (array[i] == num)
                {
                    throw new ArgumentException("Number is not unique");
                }
            }
            obj.addXArray(num);
            return num;
        }
        [TestMethod]
        public void isSumEmpty()
        {
            dataHalf obj = new dataHalf(5);

            try
            {
                obj.sum(2);
            }
            catch (ArgumentException e)
            {
                Console.WriteLine(e.Message);
            }
        }
        [TestMethod]
        public void isTargetEmpty()
        {
            dataHalf obj = new dataHalf(5);

            try
            {
                obj.target(2);
            }
            catch (ArgumentException e)
            {
                Console.WriteLine(e.Message);
            }
        }
        [TestMethod]
        public void isAnyEmpty()
        {
            dataHalf obj = new dataHalf(5);

            try
            {
                obj.any();
            }
            catch (ArgumentException e)
            {
                Console.WriteLine(e.Message);
            }
            
        }
        [TestMethod]
        public void outsideBounds()
        {
            int size = 2;
            int caller = 0;
            dataHalf obj = new dataHalf(2);
            for(int i = 0; i < 2; i++)
            {
                obj.addXArray(5);
                caller++;
            }
            try
            {
                checkifFull(obj, size, caller);
            }
            catch (ArgumentOutOfRangeException e)
            {
                Console.WriteLine(e.Message);
            }


        }
        public void checkifFull(dataHalf objs, int size, int called)
        {
            int check = 0;
            for (int i = 0; i < size; i++)
            {
                check++;
            }
            if (check == called)
            {
                throw new ArgumentOutOfRangeException("Out of Bounds");
            }
        }
    }
}
