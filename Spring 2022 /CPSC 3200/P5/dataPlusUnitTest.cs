using Microsoft.VisualStudio.TestTools.UnitTesting;
using DataExtractor;
using System;
// Updated for P5 and Corrections
namespace DataExtractorUnitTest
{
    [TestClass]
    public class dataPlusUnit
    {
        [TestMethod]
        public void EmptyArray()
        {
            int[] numsAdded = new int[0];
            try
            {
                dataPlus obj = new dataPlus(numsAdded, 0);
            }
            catch (ArgumentException e)
            {
                Console.WriteLine(e.Message);
            }
        }
        [TestMethod]
        public void sumOfZero()
        {
            dataPlus obj = new dataPlus();

            try
            {
                obj.sum(0);
            }
            catch (ArgumentException e)
            {
                Console.WriteLine(e.Message);
            }
        }
        [TestMethod]
        public void isTargetZero()
        {
            dataPlus obj = new dataPlus();

            try
            {
                obj.target(0);
            }
            catch (ArgumentException e)
            {
                Console.WriteLine(e.Message);
            }
        }
        [TestMethod]
        public void zLargerThanArray()
        {
            Random rand = new Random();
            int[] numsAdded = new int[5];
            for (int i = 0; i < 5; i++)
            {
                numsAdded[i] = rand.Next(1, 100);
            }
            dataPlus obj = new dataPlus(numsAdded, 5);

            try
            {
                obj.sum(7);
            }
            catch (ArgumentException e)
            {
                Console.WriteLine(e.Message);
            }
        }
        [TestMethod]
        public void zLargerThanArrayTarget()
        {
            Random rand = new Random();
            int[] numsAdded = new int[5];
            for (int i = 0; i < 5; i++)
            {
                numsAdded[i] = rand.Next(1, 100);
            }
            dataPlus obj = new dataPlus(numsAdded, 5);

            try
            {
                obj.target(7);
            }
            catch (ArgumentException e)
            {
                Console.WriteLine(e.Message);
            }
        }
        [TestMethod]
        public void CheckSum()
        {
            int[] x = new int[4] { 4, 3, 2, 1 };
            dataPlus obj = new dataPlus(x, 3);

            int result = obj.sum(2);

            Assert.AreEqual(4, result);
        }

        [TestMethod]
        public void checkTarget()
        {
            int[] x = new int[2] { 0, 1 };
            dataPlus obj = new dataPlus(x, 2);
            int[] expect = new int[6] { 2, 1, 0, 0, 0, 0 };

            int[] result = obj.target(2);
            bool check = true;
            for (int i = 0; i < 6; i++)
            {
                if (result[i] != expect[i])
                {
                    check = false;
                }
            }
            Assert.IsTrue(check, "Results are not equal");
        }
        [TestMethod]
        public void checkAny()
        {
            int[] x = new int[2] { 0, 1 };
            dataPlus obj = new dataPlus(x, 2);
            int[] expect = new int[6] { 0, 1, 0, 2, 2, 0 };

            int[] result = obj.any();
            bool check = true;
            for (int i = 0; i < 6; i++)
            {
                if (result[i] != expect[i])
                {
                    check = false;
                }
                Assert.IsTrue(check, "Results are not equal");
            }
        }
    }
}