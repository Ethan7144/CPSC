// Ethan Tarlov
// 4/4/22
// V1 

// Unit Testing File for P1
using Microsoft.VisualStudio.TestTools.UnitTesting;
using P1;
using System;
namespace UnitTestP1_
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestOutOfBounds()
        {
            gridFlea[] obj = new gridFlea[]
            {
                new gridFlea(20,20),


            };
            Console.WriteLine("Checking Exception");
            try
            {
                CheckException(obj[0]);
            }
            catch (ArgumentException e)
            {
                 Console.WriteLine(e.Message);
            }

        }

        public static int CheckException(gridFlea obj)
        {
            if(obj.returnX() > 15)
            {
                throw new ArgumentException("Out of Bounds");
            }

            return obj.returnX();
        }
        [TestMethod]
        public void reviveResetTest()
        {
            Random rand = new Random();
            int testCheck = 10;
            gridFlea[] obj = new gridFlea[testCheck];
            for (int i = 0; i < testCheck; i++)
            {
                obj[i] = new gridFlea(10, 10);
            }
            for(int i = 0; i < testCheck; i++)
            {
                obj[i].gridFleaMove(1, true);
                obj[i].gridFleaMove(1, false);
                obj[i].gridFleaRevive();
                obj[i].gridFleaReset();
                bool check = obj[i].isActive();
                Assert.IsTrue(check, "Object is permanently deactived");
            }
        }
        [TestMethod]
        public void movesOutofBounds()
        {
            Random rand = new Random();
            int testCheck = 10;
            gridFlea[] obj = new gridFlea[testCheck];
            for (int i = 0; i < testCheck; i++)
            {
                obj[i] = new gridFlea(10, 10);
            }
            for (int i = 0; i < testCheck; i++)
            {
                obj[i].gridFleaMove(16, true);
                obj[i].gridFleaMove(16, false);
                bool check = obj[i].isActive();
                Assert.IsFalse(check, "Object is permanently deactived");
            }

        }
        [TestMethod]
        public void movesInBounds()
        {
            Random rand = new Random();
            int testCheck = 10;
            gridFlea[] obj = new gridFlea[testCheck];
            for (int i = 0; i < testCheck; i++)
            {
                obj[i] = new gridFlea(10, 10);
            }
            for (int i = 0; i < testCheck; i++)
            { 
                obj[i].gridFleaMove(1, true);
                obj[i].gridFleaMove(1, false);
                bool check = obj[i].isActive();
                Assert.IsTrue(check, "Object is permanently deactived");
            }

        }

    }
}
