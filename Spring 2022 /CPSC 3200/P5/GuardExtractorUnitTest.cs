using Microsoft.VisualStudio.TestTools.UnitTesting;
using Guards;
using DataExtractor;
using iGuards;
using System;

namespace iGuardUnitTesting
{
    [TestClass]
    public class GuardExtractorTest
    {
        [TestMethod]
        public void InvalidChoice()
        {
            int[] x = new int[1] { 5 };
            try
            {
                GuardExtractor eg = new GuardExtractor(2, x, -5);
            }
            catch (ArgumentException e)
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
                GuardExtractor eg = new GuardExtractor(0, x, 0);
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
            GuardExtractor obj = new GuardExtractor(3, x, 0);

            int result = obj.sum(2);

            Assert.AreEqual(4, result);
        }

        [TestMethod]
        public void checkTarget()
        {
            int[] x = new int[2] { 0, 1 };
            GuardExtractor obj = new GuardExtractor(2, x, 2);
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
        public void sumOfZero()
        {
            GuardExtractor obj = new GuardExtractor();

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
        public void checkAny()
        {
            int[] x = new int[2] { 0, 1 };
            GuardExtractor obj = new GuardExtractor(2, x, 1);
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
        [TestMethod]
        public void checkPrimeGuard()
        {
            int[] x = new int[3] { 3, 79, 43 };
            GuardExtractor g = new GuardExtractor(3, x, 0);
            int result = g.value(5);
            int expected = 3;

            Assert.AreEqual(expected, result);
        }

    }
}
