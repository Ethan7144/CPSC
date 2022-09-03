//
// Created by Ethan Tarlov on 4/11/22.
// Edited on 5/11/22 for P4

#include "gridFlea.h"
#include <iostream>

using namespace std;

// This program creates the gridFlea class and all the functions
// including move, revive, reset, and also a function
// to get the value specified in the instructions given.



// Pre: Nothing is needed, this creates the object to access the gridFlea class
// and Run it as well
// Post: Will create a gridFlea object that can access the class
gridFlea::gridFlea(int x, int y)
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
    jumped = false;
    maxOutsideJump = 25;
    jumpSize = 10;
}

gridFlea gridFlea::operator++(int) {
    gridFlea temp = *this;
    this->gridFleaMove(1, true);
    this->gridFleaMove(1, false);
    return temp;
}

gridFlea gridFlea::operator++() {
    gridFleaMove(1, true);
    gridFleaMove(1, false);
    return *this;
}
gridFlea gridFlea::operator+(const gridFlea& Flea) {
    gridFlea temp = *this;
    temp.gridFleaMove(Flea.actualX, true);
    temp.gridFleaMove(Flea.actualY, true);
    return temp;
}

gridFlea gridFlea::operator+(int num){
    gridFlea temp = *this;
    temp.gridFleaMove(num, true);
    temp.gridFleaMove(num, false);
    return temp;
}

/* bool gridFlea::operator<(const gridFlea& Flea) {
    if (actualX < Flea.actualX){
        if(actualY < Flea.actualY){
            return true;
        }
    }
    if(actualX == Flea.actualX && actualY < Flea.actualY){
        return true;
    }
    if(actualX < Flea.actualX && actualY == Flea.actualY){
        return true;
    }
    return false;
}

bool gridFlea::operator>(const gridFlea& Flea) {
    if (actualX > Flea.actualX){
        if(actualY > Flea.actualY){
            return true;
        }
    }
    if(actualX == Flea.actualX && actualY > Flea.actualY){
        return true;
    }
    if(actualX > Flea.actualX && actualY == Flea.actualY){
        return true;
    }
    return false;
} */

bool gridFlea:: operator==(const gridFlea& Flea){
    if(actualX == Flea.actualX && actualY == Flea.actualY && active == Flea.active && permaActive == Flea.permaActive
    && currentMoves == Flea.currentMoves){
        return true;
    }
    return false;
}
bool gridFlea::operator!=(const gridFlea &Flea) {
    if(actualX != Flea.actualX || actualY != Flea.actualY || active != Flea.active || permaActive != Flea.permaActive
       || currentMoves != Flea.currentMoves){
        return true;
    }
    return false;
}
// Pre: Object must be active and not be permanently deactivated to move.
// Post: Changes the location of the actualX or actualY based on the input. Reward increases or decreases
// based on where it moves.
void gridFlea::gridFleaMove(int moved, bool x) {
    if (permaActive) {
        if (active) {
            if (charged) {
                if (x) {
                    actualX += moved;
                } else if (!x) {
                    actualY += moved;
                }
                if (moved < 0)
                    reward += moved;
                else
                    reward -= moved;
            } else if (!charged) {
                if (moved > 0) {
                    if (x) {
                        actualX++;

                    }
                    if (!x) {
                        actualY++;
                    }

                } else if (moved < 0) {
                    if (x) {
                        actualX--;

                    }
                    if (!x) {
                        actualY--;
                    }
                    reward--;
                }
            }
            currentMoves--;
            if (currentMoves == 0)
                active = false;
            if (actualX > upperBound || actualX < lowerBound || actualY > upperBound || actualY < lowerBound) {
                permaActive = false;
                active = false;
            }

        }
    }
    if(!jumped && !permaActive){
        if(x && actualX <= maxOutsideJump && moved <= jumpSize ){
            actualX += moved;
        }
        if(!x && actualY <= maxOutsideJump && moved <= jumpSize){
            actualY += moved;
        }
        if(x && actualX <= maxOutsideJump && moved >= jumpSize ){
            actualX += jumpSize;
        }
        if(!x && actualY <= maxOutsideJump && moved >= jumpSize){
            actualY += jumpSize;
        }
        jumped = true;
    }
}
// Pre: Object cannot be permanently deactivated to be revived.
// Post: Object will be keep current numbers, and be able to move again
void gridFlea::gridFleaRevive()
{
    if(permaActive)
    {
        active = true;
        charged = false;
        currentMoves = 4;
    }
}
// Pre: Object must be in an active state
// Post: Object will be reset to base values.
void gridFlea::gridFleaReset()
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
int gridFlea::gridFleaValue()
{
    int changed = (initialX - actualX) + (initialY - actualY);
    int value = reward * size * changed;
    return value;
}


// Implementation Invariant: The user can create a gridFlea object while setting the appropriate X and y
// value defined in it. The reward is initialized at 100 at all times and will be increased
// or decreased based on how many spaces moved. ActualX and ActualY is the current position of X and Y
// and the initialX and initialY is where it started, so it can go back to it. Active will tell if the
// object can move or not, permaActive will tell if the object can be revived or restarted.
// Size is the upper bound times the lower bound, since it can move in that many possible spaces.
// CurrentMoves is set as 4 in specific circumstances, and will increase based on the X and Y.
// gridFleaValue will take in the current reward, the size (which does not change) and the
// changed position from the initialX and Y to the actualX and Y. It will calcuate the "value"
// based off of these things and return said value.