using Microsoft.VisualStudio.TestTools.UnitTesting;
using Guards;
using System;
namespace GuardUnitTest
{
    [TestClass]
    public class GuardUnitTest
    {
        [TestMethod]
        public void CheckEmptyArray()
        {
            int[] x = new int[5];
            try
            {
                Guard g = new Guard(x);
            }catch (ArgumentException e)
            {
                Console.WriteLine(e.Message);
            }
        }
        [TestMethod]
        public void checkNegNum()
        {
            Guard g = new Guard();
            try
            {
                g.value(-4);
            }catch(ArgumentException e)
            {
                Console.WriteLine(e.Message);
            }
        }
        [TestMethod]
        public void checkPrimeSmall()
        {
            int[] x = new int[3] { 3, 79, 43 };
            Guard g = new Guard(x);
            int result = g.value(5);
            int expected = 3;

            Assert.AreEqual(expected, result);
        }
        [TestMethod]
        public void checkPrimeMid()
        {
            int[] x = new int[3] { 3, 79, 43 };
            Guard g = new Guard(x);
            int result = g.value(50);
            int expected = 43;

            Assert.AreEqual(expected, result);
        }
        [TestMethod]
        public void checkPrimeLarge()
        {
            int[] x = new int[3] { 3, 79, 43 };
            Guard g = new Guard(x);
            g.value(5);
            int result = g.value(50);
            int expected = 79;

            Assert.AreEqual(expected, result);
        }
    }
}
