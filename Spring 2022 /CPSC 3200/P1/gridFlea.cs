// Ethan Tarlov
// 4/4/22
// V1 

// This program creates the gridFlea class and all the functions
// including move, revive, reset, and also a function
// to get the value specified in the instructions given.

using System.Collections.Generic;
using System.Text;
using System;
namespace P1
{
    public class gridFlea
    {
        int initialX, initialY;
        int currentMoves, initialMoves;
        int actualX, actualY;
        int reward;
        int upperBound, lowerBound;
        int size;
        bool active;
        bool charged;
        bool permaActive;

        // Pre: Nothing is needed, this creates the object to access the gridFlea class
        // and Run it as well
        // Post: Will create a gridFlea object that can access the class
        public gridFlea(int x, int y)
        {
            initialX = actualX = x;
            initialY = actualY = y;
            lowerBound = -15;
            upperBound = 15;
            if ((x + y) / 2 > 4)
            {
                currentMoves = 4;
            }
            else
            {
                currentMoves = x + y / 2;
            }
            initialMoves = currentMoves;
            reward = 100;
            size = 225;
            active = true;
            charged = true;
            permaActive = true;
        }

        // Pre: Object must be active and not be permanently deactivated to move.
        // Post: Changes the location of the actualX or actualY based on the input. Reward increases or decreases
        // based on where it moves.
        public void gridFleaMove(int moved, bool x)
        {
            if (permaActive)
            {
                if (active)
                {
                    if (charged)
                    {
                        if (x)
                        {
                            actualX += moved;
                        }
                        else if (!x)
                        {
                            actualY += moved;
                        }
                        if (moved < 0)
                            reward += moved;
                        else
                            reward -= moved;
                    }
                    else if (!charged)
                    {
                        if (moved > 0)
                        {
                            if (x)
                            {
                                actualX++;

                            }
                            if (!x)
                            {
                                actualY++;
                            }

                        }
                        else if (moved < 0)
                        {
                            if (x)
                            {
                                actualX--;

                            }
                            if (!x)
                            {
                                actualY--;
                            }
                            reward--;
                        }
                    }
                    currentMoves--;
                    if (currentMoves == 0)
                        active = false;
                    if (actualX > upperBound || actualX < lowerBound || actualY > upperBound || actualY < lowerBound)
                    {
                        permaActive = false;
                        active = false;
                    }

                }
            }
            
        }
        // Pre: Object cannot be permanently deactived to be revived.
        // Post: Object will be revived and be able to move again.
        public void gridFleaRevive()
        {

            if(permaActive)
            {
                active = true;
                charged = false;
                currentMoves = 4;
            }
            active = true;
            charged = false;
            currentMoves = 4;

        }
        // Pre: Object must be in an active state
        // Post: Object will be reset to base values.
        public void gridFleaReset()
        {
            if (permaActive)
            {
                active = true;
                charged = true;
                actualX = initialX;
                actualY = initialY;
                reward = 100;
                currentMoves = initialMoves;
            }

        }
        // Pre: Object needs no special condition to access this.
        // Post: Returns the values
        public int gridFleaValue()
        {
            int changed = (initialX - actualX) + (initialY - actualY);
            int value = reward * size * changed;
            return value;
        }
        public int returnX()
        {
            return actualX;
        }
        public bool isActive()
        {
            return permaActive;
        }
        public int returnY()
        {
            return actualY;
        }
        public int checkMoves()
        {
            return currentMoves;
        }
    }
}
// Invariant: The user can create a gridFlea object while setting the appropriate X and y
// value defined in it. The reward is intitialized at 100 at all times and will be increased
// or decreased based on how many spaces moved. ActualX and ActualY is the current position of X and Y
// and the initialX and initialY is where it started so it can go back to it. Active will tell if the
// object can move or not, permaActive will tell if the object can be revived or restarted.
// Size is the upper bound times the lower bound, since it can move in that many possible spaces.
// CurrentMoves is set as 4 in specific circumstances, and will increased based on the X and Y.