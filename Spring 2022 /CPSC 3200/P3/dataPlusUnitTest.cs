// Ethan Tarlov
// 4/28/22
// dataPlusUnitTest.cs


//Unit Testing for Data Extractors
using Microsoft.VisualStudio.TestTools.UnitTesting;
using P3;
using System;
namespace dataPlusUnitTest
{
    [TestClass]
    public class dataPlusUnitTest
    {
        [TestMethod]
        public void NonUnique()
        {
            int[] numsAdded = new int[10];
            dataPlus obj = new dataPlus(5, 2);
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
        public static int checkArray(dataPlus obj, int num, int[] array)
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
            dataPlus obj = new dataPlus(5, 1);

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
            dataPlus obj = new dataPlus(5, 1);

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
            dataPlus obj = new dataPlus(5, 1);

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
        public void isEmptyConst()
        {
            try
            {
                dataPlus obj = new dataPlus(5, 0);
            }
            catch (ArgumentException e)
            {
                Console.WriteLine(e.Message);
            }
        }
    }
}

