/*
Ethan Tarlov
6/1/2022
Guard.cs

Class invariant:
Guard will take in an array via dependency injection and store it into an array in the class.
The numbers do not need to adhere to any specific rules, any int will be allowed into the array.
Guard can be in an "up" or "down" mode. This mode will change everytime value is called and will be
switched immediately. This changed the results of the value result, which are dependent based on the mode
the object is in currently. The mode will automatically be set to the up state at the creation of each
object.

Interface invariant:
The arrays must not be of 0 length of be empty upon arrival in the class. In value, the x must always be a positive number,
as it is not possible for a negative number to be a prime number, and thus will always make the results skewed.
The client can only access the functions in the class and will not be able to access anything else currently within the class.
The client will also not be allowed to interact with the array stored within the class.
 */

using System;
namespace Guards
{
    public class Guard
    {
        protected bool mode;
        protected int[] arr;
        public Guard()
        {
            arr = new int[1];
            mode = false;
        }
        public Guard(int[] injectionArray)
        {
            if(injectionArray == null || injectionArray.Length == 0)
            {
                throw new ArgumentException("The array cannot be a length of 0");
            }
            mode = false;
            arr = new int[injectionArray.Length];
            for(int i = 0; i < injectionArray.Length; i++)
            {
                arr[i] = injectionArray[i];
            }
        }

        public virtual int value(int x)
        {
            if (x < 0)
                throw new ArgumentException("X must be a positive Number");
            modeSwitch();
            int prime = 0;
            if (!mode)
            {
                for (int i = 0; i < arr.Length; i++)
                {
                    if (isPrime(arr[i]) && arr[i] > x)
                    {
                        if(prime == 0)
                        {
                            prime = arr[i];
                            
                        }
                            
                        if (arr[i] < prime)
                        {
                            prime = arr[i];
                        }
                            
                    }
                    
                }

            }
            else
            {
                for (int i = 0; i < arr.Length; i++)
                {
                    if (isPrime(arr[i]) && arr[i] < x)
                    {
                        if (prime == 0)
                        {
                            prime = arr[i];

                        }

                        if (arr[i] > prime)
                        {
                            prime = arr[i];
                        }
                    }

                }

            }
            return prime;
        }
        
        protected bool isPrime(int n)
        {
            if (n <= 1)
                return false;
            if (n == 2)
                return true;
            if (n % 2 == 0)
                return false;
            for(int i = 3; i < n; i++)
            {
                if (n % i == 0)
                    return false;
            }
            return true;

        }
        

        protected virtual void modeSwitch()
        {
            mode = !mode;
        }
    }
}
/*
 Implementation Invariant:
The array may be comprised of any int. The array however, must be of a nonzero length.
The int input into value must be a positive number only, negative numbers will be throw an error
if it is attempted to be inputted. Errors will be thrown to alert the user if the client is
performing an action that is not allowed within the class parameters.
 */