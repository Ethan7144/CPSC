/*
Ethan Tarlov
6/1/2022
skipGuard.cs

Class invariant:
skipGuard is a child class of guard and will follow the same specifications as Guard.
The numbers do not need to adhere to any specific rules, any int will be allowed into the array.
skipGuard can be in an "up" or "down" mode. This mode will change everytime value is called and will be
switched immediately. This changed the results of the value result, which are dependent based on the mode
the object is in currently. The mode will automatically be set to the up state at the creation of each
object. skipGuard has an int called "k". This int will vary from object to object and
will have k numbers skipped in value.

Interface invariant:
The arrays must not be of 0 length of be empty upon arrival in the class. In value, the x must always be a positive number,
as it is not possible for a negative number to be a prime number, and thus will always make the results skewed.
The client can only access the functions in the class and will not be able to access anything else currently within the class.
The client will also not be allowed to interact with the array stored within the class.
 */
using System;
namespace Guards
{
    public class skipGuard : Guard
    {
        int k;
        public skipGuard() : base()
        {
            k = 1;
        }
        public skipGuard(int[] injectionArray) :
            base(injectionArray)
        {
            k = injectionArray.Length / 4;
        }

        public override int value(int x)
        {
            if (x < 0)
                throw new ArgumentException("X must be a positive Number");
            modeSwitch();
            int prime = 0;
            if (!mode)
            {
                for (int i = k; i < arr.Length; i++)
                {
                    if (isPrime(arr[i]) && arr[i] > x)
                    {
                        if (prime == 0)
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
                for (int i = k; i < arr.Length; i++)
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
    }
}
/*
 Implementation Invariant:
The array may be comprised of any int. The array however, must be of a nonzero length.
The int input into value must be a positive number only, negative numbers will be throw an error
if it is attempted to be inputted. Errors will be thrown to alert the user if the client is
performing an action that is not allowed within the class parameters.
 */