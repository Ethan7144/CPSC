// Ethan Tarlov
// 4/4/22
// V1 


// Driver File that will run all the functions to demonstrate how the gridFlea
// class runs and works. Creates a object from the gridFlea class, and will run
// all of the functions regarding it.
// Assumption is that any objects that are moved randomly will move and display
// the correct position due to Visual Studio not letting me run the project at all
// to test if it works properly.
// Will Display the X, Y, and current Moves left after objects are moved and before
// to demonstrate that it moves.


using System;
namespace P1
{
    public class P1
    {
        static void Main(string[] args)
        {
            Random rand = new Random();
            gridFlea[] obj = new gridFlea[] // Setting up random Numbers
            {
                new gridFlea(rand.Next(0,15), rand.Next(0,15)),
                new gridFlea(rand.Next(0,15), rand.Next(0,15)),
                new gridFlea(rand.Next(0,15), rand.Next(0,15)),
                new gridFlea(rand.Next(0,15), rand.Next(0,15)),
                new gridFlea(rand.Next(0,15), rand.Next(0,15)),
                new gridFlea(rand.Next(0,15), rand.Next(0,15)),
                new gridFlea(rand.Next(0,15), rand.Next(0,15)),
                new gridFlea(rand.Next(0,15), rand.Next(0,15)),
                new gridFlea(rand.Next(0,15), rand.Next(0,15)),
                new gridFlea(rand.Next(0,15), rand.Next(0,15)),
            };
            Console.WriteLine("Checking the X, Y, and current Moves in this order");
            Console.WriteLine(obj[0].returnX());
            Console.WriteLine(obj[0].returnY());
            Console.WriteLine(obj[0].checkMoves());
            Console.WriteLine("Moving obj0 5 spaces on the X axis");
            obj[0].gridFleaMove(5, true);
            Console.WriteLine("Showing Obj0 position");
            Console.WriteLine(obj[0].returnX());
            Console.WriteLine(obj[0].returnY());
            Console.WriteLine(obj[0].checkMoves());
            Console.WriteLine("Attempting to Reset Object 0");
            obj[0].gridFleaReset();
            Console.WriteLine("Checking the X, Y, and current Moves in this order");
            Console.WriteLine(obj[0].returnX());
            Console.WriteLine(obj[0].returnY());
            Console.WriteLine(obj[0].checkMoves());
            Console.WriteLine("Moving obj1 4 spaces on the y axis.");
            obj[1].gridFleaMove(4, false);
            Console.WriteLine("Showing Obj 1 position");
            Console.WriteLine(obj[1].returnX());
            Console.WriteLine(obj[1].returnY());
            Console.WriteLine(obj[1].checkMoves());
            Console.WriteLine("Attempting to Revive Object 1");
            obj[1].gridFleaRevive();
            Console.WriteLine("Showing obj0 Value");
            Console.WriteLine(obj[0].gridFleaValue());
            Console.WriteLine("Showing obj1 Value");
            Console.WriteLine(obj[1].gridFleaValue());

            Console.WriteLine("Checking the X, Y, and current Moves in this order");
            Console.WriteLine(obj[2].returnX());
            Console.WriteLine(obj[2].returnY());
            Console.WriteLine(obj[2].checkMoves());
            Console.WriteLine("Checking the X, Y, and current Moves in this order");
            Console.WriteLine(obj[3].returnX());
            Console.WriteLine(obj[3].returnY());
            Console.WriteLine(obj[3].checkMoves());
            Console.WriteLine("Checking the X, Y, and current Moves in this order");
            Console.WriteLine(obj[4].returnX());
            Console.WriteLine(obj[4].returnY());
            Console.WriteLine(obj[4].checkMoves());
            Console.WriteLine("Checking the X, Y, and current Moves in this order");
            Console.WriteLine(obj[5].returnX());
            Console.WriteLine(obj[5].returnY());
            Console.WriteLine(obj[5].checkMoves());
            Console.WriteLine("Checking the X, Y, and current Moves in this order");
            Console.WriteLine(obj[6].returnX());
            Console.WriteLine(obj[6].returnY());
            Console.WriteLine(obj[6].checkMoves());
            Console.WriteLine("Checking the X, Y, and current Moves in this order");
            Console.WriteLine(obj[7].returnX());
            Console.WriteLine(obj[7].returnY());
            Console.WriteLine(obj[7].checkMoves());
            Console.WriteLine("Checking the X, Y, and current Moves in this order");
            Console.WriteLine(obj[8].returnX());
            Console.WriteLine(obj[8].returnY());
            Console.WriteLine(obj[8].checkMoves());
            Console.WriteLine("Checking the X, Y, and current Moves in this order");
            Console.WriteLine(obj[9].returnX());
            Console.WriteLine(obj[9].returnY());
            Console.WriteLine(obj[9].checkMoves());
            Console.WriteLine("Moving Objects randomly");
            obj[2].gridFleaMove(rand.Next(0,6), true);
            obj[3].gridFleaMove(rand.Next(0, 6), true);
            obj[4].gridFleaMove(rand.Next(0, 6), false);
            obj[5].gridFleaMove(rand.Next(0, 6), true);
            obj[6].gridFleaMove(rand.Next(0, 6), false);
            obj[7].gridFleaMove(rand.Next(0, 6), false);
            obj[8].gridFleaMove(rand.Next(0, 6), true);
            obj[9].gridFleaMove(rand.Next(0, 6), false);
            Console.WriteLine("Checking the X, Y, and current Moves in this order");
            Console.WriteLine(obj[2].returnX());
            Console.WriteLine(obj[2].returnY());
            Console.WriteLine(obj[2].checkMoves());
            Console.WriteLine("Checking the X, Y, and current Moves in this order");
            Console.WriteLine(obj[3].returnX());
            Console.WriteLine(obj[3].returnY());
            Console.WriteLine(obj[3].checkMoves());
            Console.WriteLine("Checking the X, Y, and current Moves in this order");
            Console.WriteLine(obj[4].returnX());
            Console.WriteLine(obj[4].returnY());
            Console.WriteLine(obj[4].checkMoves());
            Console.WriteLine("Checking the X, Y, and current Moves in this order");
            Console.WriteLine(obj[5].returnX());
            Console.WriteLine(obj[5].returnY());
            Console.WriteLine(obj[5].checkMoves());
            Console.WriteLine("Checking the X, Y, and current Moves in this order");
            Console.WriteLine(obj[6].returnX());
            Console.WriteLine(obj[6].returnY());
            Console.WriteLine(obj[6].checkMoves());
            Console.WriteLine("Checking the X, Y, and current Moves in this order");
            Console.WriteLine(obj[7].returnX());
            Console.WriteLine(obj[7].returnY());
            Console.WriteLine(obj[7].checkMoves());
            Console.WriteLine("Checking the X, Y, and current Moves in this order");
            Console.WriteLine(obj[8].returnX());
            Console.WriteLine(obj[8].returnY());
            Console.WriteLine(obj[8].checkMoves());
            Console.WriteLine("Checking the X, Y, and current Moves in this order");
            Console.WriteLine(obj[9].returnX());
            Console.WriteLine(obj[9].returnY());
            Console.WriteLine(obj[9].checkMoves());
        }
    }
}
