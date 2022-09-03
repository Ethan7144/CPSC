/*Ethan Tarlov
4/22/22
Edited 6/1 for P5 and corrections
dataExtractors.cs

 Class invariant: This class will create 2 arrays "x" and "y"
which will store ONLY Unique numbers in the array. X will created via dependency injection.
Any non unique number willbe ignored and not used in the array when it is attempted to be implemented.
Anytime this happens, the state for the object will change, which affects the
any, target, and sum functions of the dataExtractors class. Each state will be changed whenever
a function has been called, it will be changed immediately. If the state has never been
altered, stateAltered will remain false and will cause any, sum and target to run in a specfic manner
as well. A dataExtractor object may add as many ints to the array as they'd like, as there is no size limitation
keep in a mind that a larger object will cause some outputs to look weird due to them taking the size of the
x and y array to operate. Functions are virtual to allow child classes to override them to change them as need be.
And variables are protected so the child class can access them as well.

Interface Invariant:
All of the functions will require the array to have something in the array.
If the array is empty, the constructor will throw an error.
The Client will not be allowed to access any of the variables inside the class,
as it does not need to know the state or if the state has been altered, the output
difference will confirm if it has been altered or not. The client will onluy be able to
run any of the necessary functions and none of the helper functions.

*/
using System;

namespace DataExtractor
{
    public class dataExtractors
    {
        protected int[] x;
        protected int[] y;
        protected bool state;
        protected bool stateAltered;
        protected int minLength;

        public dataExtractors()
        {
            x = new int[1];
            y = new int[1];
            stateAltered = false;
            state = false;

        }
        // Pre: Nothing is needed, as this is a no arg constructor.
        // Post: Will create a dataExtractor class object.
        public dataExtractors(int[] xArray, int ySize)
        {
            state = false;
            if (xArray.Length <= 0 || xArray == null)
                throw new ArgumentException("The Array length has to be greater than 0");
            for (int i = 0; i < xArray.Length - 1; i++)
            {
                for (int j = i + 1; j < xArray.Length; j++)
                {
                    if (xArray[i] == xArray[j])
                    {
                        stateChange();
                    }
                }
            }
            if (ySize == 0)
                throw new ArgumentException("The Array length has to be greater than 0");
            x = new int[xArray.Length];
            for (int i = 0; i < xArray.Length; i++)
            {
                x[i] = xArray[i];
                for (int j = i + 1; j < xArray.Length; j++)
                {
                    if (xArray[i] == xArray[j])
                    {
                        xArray[j] = xArray[j] + xArray[j];
                    }
                }
            }
            y = new int[ySize];
            for (int i = 0; i < y.Length - 1; i++)
            {
                y[i] = ySize;
                ySize++;
            }
            for (int i = x.Length - 1; i >= 0; i--)
            {
                if(minLength == 0) {
                    if (x[i] % 2 == 1)
                    {
                        minLength = x[i];
                    }
            }
        }


        }
        /*
        // Pre: Number must not be a duplicate number already in the array.
        // Post: Number will be added to the xArray and it will be expanded.
        public virtual void addXArray(int num)
        {
            isXEmpty = false;
            int[] temp;
            if (x.Length > 0)
            {
                temp = new int[x.Length + 1];
                for (int i = 0; i < x.Length; i++)
                {
                    if (x[i] == num)
                    {
                        stateChange();
                        stateAltered = true;
                        return;
                    }
                    // temp[i] = x[i];
                }
                Array.Copy(x, temp, x.Length);
                temp[x.Length] = num;
            }
            else
            {
                temp = new int[1];
                temp[0] = num;
            }

            x = new int[temp.Length];
            Array.Copy(temp, x, temp.Length);
        }

        // Pre: Number must not be a duplicate number already in the array.
        // Post: Number will be added to the xArray and it will be expanded.
        public virtual void addYArray(int num)
        {
            isYEmpty = false;
            int[] temp;
            if (y.Length > 0)
            {
                temp = new int[y.Length + 1];
                for (int i = 0; i < y.Length; i++)
                {

                    if (y[i] == num)
                    {
                        stateChange();
                        stateAltered = true;
                        return;
                    }
                    // temp[i] = y[i];
                }
                Array.Copy(y, temp, y.Length);
                temp[y.Length] = num;

            }
            else
            {
                temp = new int[1];
                temp[0] = num;
            }
            y = new int[temp.Length];
            Array.Copy(temp, y, y.Length);
        }
        */
        // Pre: x and y arrays must not be empty
        // Post: will display the array depending on the state at the time.
        // Will contain both x and y if the state has never been altered.
        // Will contain y if the state is false.
        // Will contain x if the state is true.
        public virtual int[] any()
        {
            int[] fullArray;
            if (!stateAltered)
            {
                fullArray = new int[x.Length + y.Length];
                for (int i = 0; i < x.Length; i++)
                {
                    fullArray[i] = x[i];
                }
                for (int i = x.Length; i < x.Length + y.Length; i++)
                {
                    fullArray[i] = y[i - x.Length];
                }
            }
            else if (!state)
            {
                fullArray = new int[y.Length];
                for (int i = 0; i < y.Length; i++)
                {
                    fullArray[i] = y[i];
                }

            }
            else
            {
                fullArray = new int[x.Length];
                for (int i = 0; i < x.Length; i++)
                {
                    fullArray[i] = x[i];
                }
            }
            stateChange();
            return fullArray;
        }

        // If State is false, y will be checked, and if the stateAltered is
        // false, it will check for evens, else it checks for odds.
        // If State is true, y will be checked, and if the stateAltered is
        // false, it will check for evens, else it checks for odds.
        // Pre: x and y arrays must not be empty
        // Post: will return z ints in the form of an array.
        public virtual int[] target(int z)
        {
            if (z < 0 || z > x.Length || z > y.Length)
                throw new ArgumentException("Z cannot be 0 or larger than the arrays");
            int[] targets;
            int check = 0;
            if (!state)
            {
                targets = new int[y.Length]; ;
                for (int i = 0; i < y.Length; i++)
                {
                    if (check != z)
                    {
                        if (!stateAltered)
                        {
                            if (y[i] % 2 == 0)
                            {
                                targets[i] = y[i];
                                check++;
                            }
                        }
                        else
                        {
                            if (y[i] % 2 == 1)
                            {
                                targets[i] = y[i];
                                check++;
                            }
                        }
                    }
                }
            }
            else
            {
                targets = new int[x.Length];
                for (int i = 0; i < x.Length; i++)
                {
                    if (check != z)
                    {
                        if (!stateAltered)
                        {
                            if (x[i] % 2 == 0)
                            {
                                targets[i] = x[i];
                                check++;
                            }
                        }
                        else
                        {
                            if (x[i] % 2 == 1)
                            {
                                targets[i] = x[i];
                                check++;
                            }
                        }
                    }
                }
            }
            stateChange();
            return targets;

        }

        // If State is false, y will be checked, and if the stateAltered is
        // false, it will check for evens, else it checks for odds.
        // If State is true, y will be checked, and if the stateAltered is
        // false, it will check for evens, else it checks for odds.
        // Pre: x and y arrays must not be empty
        // Post: will return the sum of z ints.
        public virtual int sum(int z)
        {
            if (z < 0 || z > x.Length || z > y.Length)
                throw new ArgumentException("Z cannot be 0 or larger than the arrays");
            int total = 0;
            int check = 0;
            if (!state)
            {
                for (int i = 0; i < y.Length; i++)
                {
                    if (check != z)
                    {
                        if (!stateAltered)
                        {
                            if (y[i] % 2 == 0)
                            {
                                total += y[i];
                                check++;
                            }
                        }
                        else
                        {
                            if (y[i] % 2 == 1)
                            {
                                total += y[i];
                                check++;
                            }
                        }
                    }
                }
            }
            else
            {
                for (int i = 0; i < x.Length; i++)
                {
                    if (check != z)
                    {
                        if (!stateAltered)
                        {
                            if (x[i] % 2 == 0)
                            {
                                total += x[i];
                                check++;
                            }
                        }
                        else
                        {
                            if (x[i] % 2 == 1)
                            {
                                total += x[i];
                                check++;
                            }
                        }
                    }
                }
            }
            stateChange();
            return total;
        }

        // Pre: Object must have recieved a duplicate number
        // Post: will change the state.
        // Helper Function
        private void stateChange()
        {
            state = !state;
            stateAltered = true;
        }


    }
}

/* Implentation Invariant: Only valid integers are accepted into the array.
 * It will not allow any nonunique numbers into that specific array if they are found
 * already inside the array. Statealtered is used to check for specific conditional cases
 * to allow for specific things. ArguementExceptions are for Error Handling and to 
 * let the user know it is doing an action that is not allowed in the driver.
 * Array.Copy is to help with moving the array from x or y to temp and back to x or y as 
 * temp will expand the size by one, and the x or y array will be automatically 
 * garbage collected when it points to temp.

*/