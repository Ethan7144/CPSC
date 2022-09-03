/*
Ethan Tarlov
4/22/22

Updated 6/1/22 for P5 and Corrections
dataPlus.cs

 Class invariant: This class is a child class of "dataExtractors". It will
have access to the exact same functions and variables (That are protected) as
the parent class will do. Same rules apply as dataExtractors, no non unique numbers, and the
array must not be empty in order to run the functions.
However, one of the specific changes is that y will be automatically implemented in the constructor
to allow for "ya" to take place. It will just take that number implemented and decrement it by one and
add that number to the array. It will then add all the numbers in the array as the "a" and tack that on at the end.
It will also keep track of the requests to the client when the client calls for a number to be added to any
of the arrays. Once it hits a specified number from the constructor, it will multiple the numRequest and request
together and add that to the array. A helper function is there to make sure that request is either equal to or higher than
the numRequest.

Interface Invariant:
All of the functions will require the array to have something in the array.
If the array is empty, the constructor will throw an error.
The Client will not be allowed to access any of the variables inside the class,
as it does not need to know the state or if the state has been altered, the output
difference will confirm if it has been altered or not. The client will only be able to
run any of the necessary functions and none of the helper functions.

*/

using System;
namespace DataExtractor
{
    public class dataPlus : dataExtractors
    {
        int request;
        int numConcatenated;
        int numRequest;
        bool met;

        public dataPlus() : base()
        {
            request = 0;
            numRequest = 1;
            met = false;
            y[0] = numConcatenated;


        }
        // Pre: Will require k and what number to start with in the y array.
        // Post: will give a dataPlus obj w/ a created y array and access to dataExtractors
        public dataPlus(int[] xArray, int ySize)
            : base(xArray, ySize)
        {

            request = 0;
            met = false;
            numConcatenated = 0;
            numRequest = x.Length / 4;
            for (int i = 0; i < y.Length; i++)
            {
                numConcatenated += y[i];
            }
            y[y.Length - 1] = numConcatenated;

        }
        /*
        // Pre: Number must not be a duplicate number already in the array.
        // Post: Number will be added to the xArray and it will be expanded.
        public override void addXArray(int num)
        {
            request++;
            base.addXArray(num);

        }

        // Pre: Number must not be a duplicate number already in the array.
        // Post: Number will be added to the yArray and it will be expanded.
        // if isMet is true, it will run the numConcatenated conditional. Else
        // it will function as the dataExtractor addYArray would.
        public override void addYArray(int num)
        {
            if (isMet())
            {
                numConcatenated = request * numRequest;
                base.addYArray(num);
                base.addYArray(numConcatenated);
            }
            else
            {
                base.addYArray(num);
            }
            request++;
        }
        */
        // y will only check for evens, x will only check for odds.
        // Pre: x and y arrays must not be empty
        // Post: will return z ints in the form of an array.
        public override int[] target(int z)
        {

            if (z < 0 || z > x.Length || z > y.Length)
                throw new ArgumentException("Z cannot be 0 or larger than the arrays");
            if (isMet())
                concatenatedArr();
            int[] targets;
            request++;
            int check = 0;
            targets = new int[y.Length + x.Length];
            for (int i = 0; i < y.Length; i++)
            {
                if (check != z)
                {
                    if (y[i] % 2 == 0)
                    {
                        targets[i] = y[i];
                        check++;
                    }
                }
            }
            check = 0;
            for (int i = 0; i < x.Length; i++)
            {
                if (x[i] % 2 == 1)
                {
                    targets[i] = x[i];
                    check++;
                }
            }
            return targets;
        }

        public override int[] any()
        {
            if (isMet())
                concatenatedArr();
            request++;
            return base.any();
        }
        public override int sum(int z)
        {
            if (isMet())
                concatenatedArr();
            request++;
            return base.sum(z);
        }
        // Pre: Object created
        // Post: return true or false if the request is = or > numRequest
        // Helper Function
        private bool isMet()
        {
            if (request == numRequest || request > numRequest)
            {
                met = true;
            }
            else
            {
                met = false;
            }
            return met;
        }
        private void concatenatedArr()
        {
            int[] xArr = new int[x.Length + 1];
            int[] yArr = new int[y.Length + 1];

            numConcatenated = request * numRequest;
            for (int i = 0; i < x.Length; i++)
            {
                xArr[i] = x[i];
            }
            xArr[x.Length] = numConcatenated;
            x = xArr;
            for (int i = 0; i < y.Length; i++)
            {
                yArr[i] = y[i];
            }
            yArr[y.Length] = numConcatenated;
            y = yArr;
            request = 0;
        }
    }
}
/* Implentation Invariant: Only valid integers are accepted into the array.
 * It will not allow any nonunique numbers into that specific array if they are found
 * already inside the array. isMet() is used to check to see if the number needs to be 
 * concatinated to the y array. ArguementExceptions are for Error Handling and to 
 * let the user know it is doing an action that is not allowed in the driver.
*/