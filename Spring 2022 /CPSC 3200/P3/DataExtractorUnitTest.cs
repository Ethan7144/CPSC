
// Ethan Tarlov
// 4/28/22
// DataExtractorUnitTest.cs


//Unit Testing for Data Extractors
using Microsoft.VisualStudio.TestTools.UnitTesting;
using P3;
using System;

namespace UnitTestDataExtractor
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void NonUnique()
        {
            int[] numsAdded = new int[10];
            dataExtractors obj = new dataExtractors();
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
        public static int checkArray(dataExtractors obj, int num, int[] array)
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
            dataExtractors obj = new dataExtractors();

            try
            {
                obj.sum(2);
            }
            catch(ArgumentException e)
            {
                Console.WriteLine("Obj is empty");
            }
        }
        [TestMethod]
        public void isTargetEmpty()
        {
            dataExtractors obj = new dataExtractors();

            try
            {
                obj.target(2);
            }
            catch (ArgumentException e)
            {
                Console.WriteLine("Obj is empty");
            }
        }
        [TestMethod]
        public void isAnyEmpty()
        {
            dataExtractors obj = new dataExtractors();

            try
            {
                obj.any();
            }
            catch (ArgumentException e)
            {
                Console.WriteLine("Obj is empty");
            }
        }
    }
}
