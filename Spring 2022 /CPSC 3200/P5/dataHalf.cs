/*
Ethan Tarlov
4/22/22

Updated 6/1/22 for P5 and Corrections
DataPlus.cs

Class invariant: This class is a child class of "dataExtractors". It will
have access to the exact same functions and variables (That are protected) as
the parent class will do. Same rules apply as dataExtractors, no non unique numbers, and the
array must not be empty in order to run some of the functions.
However, one of the specific changes is that x will be automatically halfed before entered the
x array Eg. 2 will become 1 before being inserted. The class will also store the any response and print it twice in a row
if it is called again, and will only give a new response after the class calls it the 3rd, 5th, etc... time. It will
also have boundaries set by the client that will shut down the object if the threshold is crossed. Boundary is based
off of the minLength and the ySize of each object, both boundaries for x and y will start at 0.

Interface Invariant:
All of the functions will require the array to have something in the array.
If the array is empty, the constructor will throw an error. 
The Client will not be allowed to access any of the variables inside the class,
as it does not need to know the state or if the state has been altered, the output
difference will confirm if it has been altered or not. The client will only be able to
run any of the necessary functions and none of the helper functions. The class will also
have boundaries, if the boundaries are crossed at any point, the object becomes deactivated and
will no longer be able to run anything.
*/


using System;
namespace DataExtractor
{
    public class dataHalf : dataExtractors
    {
        int boundaryX;
        int boundaryY;
        int boundary;
        int tally;
        int[] arr;
        bool active;

        public dataHalf() : base()
        {
            boundary = 0;
            arr = new int[1];
            tally = 2;
        }
        // Pre: Will require the boundary size.
        // Post: will give a dataHalf obj w/ access to dataExtractors
        public dataHalf(int[] xArray, int ySize)
            : base(xArray, ySize)
        {
            for (int i = 0; i < x.Length; i++)
            {
                x[i] = x[i] / 2;
            }
            boundary = minLength + ySize;
            boundaryX = boundaryY = 0;
            tally = 2;
            active = true;
        }
        /*
        // Will divide any inputted num by 2 before inputting it into the x array
        // will check to make sure the boundary is not crossed, if it is, the obj
        // becomes deactivated.
        // Pre: Number must not be a duplicate number already in the array.
        // Post: Number/2 will be added to the xArray and it will be expanded.
        public override void addXArray(int num)
        {
            if (active)
            {
                int newNum = num / 2;
                if (!withInBoundaryX())
                {
                    return;
                }
                base.addXArray(newNum);
                boundaryX++;
            }
        }

        // Pre: Number must not be a duplicate number already in the array.
        // Post: Number will be added to the yArray and it will be expanded.
        public override void addYArray(int num)
        {
            if (active)
            {
                if (!withInBoundaryY())
                {
                    return;
                }
                base.addYArray(num);
                boundaryY++;
            }
        }
        */

        // Will store the output, and print it a 2nd time if called again.
        // Will get new output if called a 3rd time, 5th time, etc...
        // Pre: x and y arrays must not be empty
        // Post: will return an array storing the result, that may or may print again depending on the
        // tally count in the program.
        // Will contain both x and y if the state has never been altered.
        // Will contain y if the state is false.
        // Will contain x if the state is true.
        public override int[] any()
        {
            if (!withInBoundaryX() || !withInBoundaryY())
                throw new ArgumentException("Out of Bounds");
            if (tally == 2)
            {
                if ((!stateAltered))
                {
                    boundaryX++;
                    boundaryY++;
                    arr = new int[x.Length + y.Length];
                    arr = base.any();
                }
                else if ((!state))
                {
                    boundaryY++;
                    arr = new int[y.Length];
                    arr = base.any();
                }
                else
                {
                    boundaryX++;
                    arr = new int[x.Length];
                    arr = base.any();
                }
                tally = 1;
                return arr;
            }
            else
            {
                tally++;
                return arr;
            }
        }

        public override int[] target(int z)
        {
            if (!withInBoundaryX() || !withInBoundaryY())
                throw new ArgumentException("Out of Bounds");
            boundaryX++;
            boundaryY++;
            return base.target(z);
        }
        public override int sum(int z)
        {
            if (!withInBoundaryX() || !withInBoundaryY())
                throw new ArgumentException("Out of Bounds");
            boundaryX++;
            boundaryY++;
            return base.sum(z);
        }
        //Helper Function
        // Pre: Called when Obj is being moved.
        // Post: will make active true or false depending on if the threshold is crossed.
        private bool withInBoundaryX()
        {
            if (boundaryX >= boundary)
            {
                active = false;
            }
            return active;
        }

        //Helper Function
        // Pre: Called when Obj is being moved.
        // Post: will make active true or false depending on if the threshold is crossed.
        private bool withInBoundaryY()
        {
            if (boundaryY >= boundary)
            {
                active = false;
            }
            return active;
        }

    }
}

/* Implentation Invariant: Only valid integers are accepted into the array.
 * It will not allow any nonunique numbers into that specific array if they are found
 * already inside the array. withInBoundary is used to check if the boundary has been
 * crossed and will make active false if that is the case. ArguementExceptions are for Error Handling and to 
 * let the user know it is doing an action that is not allowed in the driver.
 * Tally is used to keep track of the number of times any is called and will reset if any is called when
 * tally is equal to 2.
*/