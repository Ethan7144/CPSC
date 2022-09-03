/*
Ethan Tarlov
6/1/2022
quirkyGuard.cs

Class invariant:
QuirkyGuard will take in an array via dependency injection and store it into an array in the class.
The numbers do not need to adhere to any specific rules, any int will be allowed into the array.
QuirkyGuard can be in an "up" or "down" mode. This mode will change everytime value is called and will be
switched immediately. This changed the results of the value result, which are dependent based on the mode
the object is in currently. The mode will automatically be set to the up state at the creation of each
object. QuirkyGuard will randomly add a new number to the array, the number that will cause this will vary from
object to object. Depending on the mode of the object, it will add a specific number to the array. If it is in up mode,
it will add a prime number, down will just add non prime number. QuirkyGuard can only call a specific amount of mode changes 

Interface invariant:
The arrays must not be of 0 length of be empty upon arrival in the class. In value, the x must always be a positive number,
as it is not possible for a negative number to be a prime number, and thus will always make the results skewed.
The client can only access the functions in the class and will not be able to access anything else currently within the class.
The client will also not be allowed to interact with the array stored within the class. If a -1 is returned upon a value call,
that means the number of mode changes has been reached.
 */
using System;
namespace Guards
{
    public class quirkyGuard : Guard
    {
        int tally;
        int switchCounter;
        int maxSwitch;
        int maxTally;
        int changer;
        bool active;
        public quirkyGuard() : base()
        {
            tally = 0;
            maxTally = 1;
            switchCounter = 0;
            maxSwitch = 1;
            changer = 0;
            active = true;
        }
        public quirkyGuard(int[] injectionArray) : base(injectionArray)
        {
            tally = switchCounter = 0;
            maxSwitch = injectionArray.Length + 6;
            maxTally = injectionArray.Length / 6;
            changer = 0;
            active = true;
        }
        public override int value(int x)
        {
            if (x < 0)
                throw new ArgumentException("X must be a positive Number");
            statusCheck();
            if (active)
            {
                modeSwitch();
                tally++;
                changer++;
                int newNum = arr.Length;
                int prime = 0;
                int[] newArr = new int[arr.Length + 1];
                if (!mode)
                {
                    for (int i = 0; i < arr.Length; i++)
                    {
                        if (isPrime(arr[i]) && arr[i] > x)
                        {
                            if (prime == 0)
                            {
                                switchCounter++;
                                prime = arr[i];

                            }

                            if (arr[i] < prime)
                            {
                                switchCounter++;
                                prime = arr[i];
                            }

                        }

                    }
                    for (int i = 0; i < arr.Length; i++)
                    {
                        newArr[i] = arr[i];
                    }
                    newArr[newArr.Length - 1] = prime;
                    arr = newArr;
                }
                else
                {
                    for (int i = 0; i < arr.Length; i++)
                    {
                        if (isPrime(arr[i]) && arr[i] < x)
                        {
                            if (prime == 0)
                            {
                                switchCounter++;
                                prime = arr[i];

                            }

                            if (arr[i] > prime)
                            {
                                switchCounter++;
                                prime = arr[i];
                            }
                        }

                    }
                    for (int i = 0; i < arr.Length; i++)
                    {
                        newArr[i] = arr[i];
                    }
                    if (arr.Length % 2 == 0)
                        newNum = arr.Length;
                    while (isPrime(newNum))
                    {
                        newNum++;
                    }
                    newArr[newArr.Length - 1] = newNum;
                    arr = newArr;

                }
                if (changer == arr.Length)
                    changer = changer / 2;
                if (tally == maxTally)
                {
                    arr[changer] = arr[changer] + maxTally;
                }
                return prime;
            }
            return -1;
        }
        private bool statusCheck()
        {
            if(maxSwitch == switchCounter)
                active = false;
            return active;
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