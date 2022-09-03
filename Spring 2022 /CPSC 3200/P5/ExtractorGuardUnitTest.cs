using Microsoft.VisualStudio.TestTools.UnitTesting;
using Guards;
using DataExtractor;
using iGuards;
using System;

namespace iGuardUnitTesting
{
    [TestClass]
    public class ExtractorGuardTest
    {
        [TestMethod]
        public void InvalidChoice()
        {
            int[] x = new int[1] { 5 };
            try
            {
                ExtractorGuard eg = new ExtractorGuard(2, x, -5);
            }catch(ArgumentException e)
            {
                Console.WriteLine(e.Message);
            }
        }
        [TestMethod]
        public void InvalidSize()
        {
            int[] x = new int[1] { 5 };
            try
            {
                ExtractorGuard eg = new ExtractorGuard(0, x, 0);
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
            ExtractorGuard obj = new ExtractorGuard(3, x, 0);

            int result = obj.sum(2);

            Assert.AreEqual(4, result);
        }

        [TestMethod]
        public void checkTarget()
        {
            int[] x = new int[4] { 4, 5, 6, 7 };
            ExtractorGuard obj = new ExtractorGuard(3, x, 0);
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
            int[] x = new int[4] { 4, 5, 6, 7 };
            ExtractorGuard obj = new ExtractorGuard(3, x, 0);
            int[] expect = new int[7] { 4, 5, 6, 7, 3, 4, 0 };

            int[] result = obj.any();
            bool check = true;
            for (int i = 0; i < 7; i++)
            {
                if (result[i] != expect[i])
                {
                    check = false;
                }
                Assert.IsTrue(check, "Results are not equal");
            }

        }
        [TestMethod]
        public void checkPrimeGuard()
        {
            int[] x = new int[3] { 3, 79, 43 };
            ExtractorGuard g = new ExtractorGuard(3, x, 0);
            int result = g.value(5);
            int expected = 3;

            Assert.AreEqual(expected, result);
        }
        [TestMethod]
        public void checkPrimeQuriky()
        {
            int[] x = new int[3] { 3, 79, 43 };
            ExtractorGuard g = new ExtractorGuard(3, x, 0);
            int result = g.value(50);
            int expected = 43;

            Assert.AreEqual(expected, result);
        }
        [TestMethod]
        public void checkPrimeSkip()
        {
            int[] x = new int[3] { 3, 79, 43 };
            ExtractorGuard g = new ExtractorGuard(3, x, 0);
            g.value(5);
            int result = g.value(50);
            int expected = 79;

            Assert.AreEqual(expected, result);
        }

    }
}
