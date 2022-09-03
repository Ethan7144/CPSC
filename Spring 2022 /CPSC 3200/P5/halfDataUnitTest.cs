using Microsoft.VisualStudio.TestTools.UnitTesting;
using DataExtractor;
using System;
// Updated for P5 and Corrections
namespace DataExtractorUnitTest
{
    [TestClass]
    public class dataHalfUnit
    {
        [TestMethod]
        public void EmptyArray()
        {
            int[] numsAdded = new int[0];
            try
            {
                dataHalf obj = new dataHalf(numsAdded, 0);
            }
            catch (ArgumentException e)
            {
                Console.WriteLine(e.Message);
            }
        }
        [TestMethod]
        public void sumOfZero()
        {
            dataHalf obj = new dataHalf();

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
            dataHalf obj = new dataHalf();

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
            dataHalf obj = new dataHalf(numsAdded, 5);

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
            dataHalf obj = new dataHalf(numsAdded, 5);

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
            dataHalf obj = new dataHalf(x, 3);

            int result = obj.sum(2);

            Assert.AreEqual(4, result);
        }

        [TestMethod]
        public void checkTarget()
        {
            int[] x = new int[4] { 4, 5, 6, 7 };
            dataHalf obj = new dataHalf(x, 3);
            int[] expect = new int[3] { 0, 4, 6 };

            int[] result = obj.target(2);
            bool check = true;
            for (int i = 0; i < 2; i++)
            {
                if (result[i] != expect[i])
                {
                    check = false;
                }
                Assert.IsTrue(check, "Results are not equal");
            }

        }
        [TestMethod]
        public void checkAny()
        {
            int[] x = new int[2] { 0, 1 };
            dataHalf obj = new dataHalf(x, 2);
            int[] expect = new int[4] { 0, 0, 2, 0 };

            int[] result = obj.any();
            bool check = true;
            for (int i = 0; i < 4; i++)
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
