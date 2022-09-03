//
// Created by Ethan Tarlov on 4/11/22.
// Edited on 5/11/22 for P4

// This program creates the gridFlea class and all the functions
// including move, revive, reset, and also a function
// to get the value specified in the instructions given.

// Class invariant: This class stores multiple parts of a gridFlea which
//     a collection of x and y positions on a coordinate plane. Each gridFlea will have
//     their own x and y value, each object will have its own instance and variables.
//     Each gridFlea object will not be allowed to go over the upper or lower limit
//     set in the gridFlea class and will be permanently deactivated if it is detected
//     outside the boundaries set by the gridFlea. Each gridFlea will have a size
//     that is determined by multiplying the upper and lower bound together.
//     A gridFlea object may have its x or y values moved via the move function
//     which will move either x or y the exact same number of spots
//     Value  will look for the Value specfied as change in x and y * reward * size.
//     isPermaActive is a helper function to help the functions determine if a gridFlea can
//     be either revived or reset, if it is returned false, a gridFlea will not be allowed to
//     either revive itself or reset itself.
//     The operator + will take in a gridFlea and an int or another gridFlea depending on the user, and
//     will have the new gridFlea move to the position based on the other gridFleas being added to it.
//     The operators all deal with the position of the gridFlea, ++ will move the gridFlea positions by 1,
//     addition will add the positions in a gridFlea + gridFlea or gridFlea + int and move that number of spaces
//     in the new gridFlea. The == and 1+ will check to see if all elements of the gridFlea are the same, such as state,
//     and positions.
// Interface invariant: All of the functions will require a working gridFlea in order to work.
//     if it is not provided, none of the class objects will work and the attempts will fail.
//     The client will be able to access all functions of the gridFlea class, and it will
//     be allowed to try out anything in the gridFlea class itself. Even isPermaActive will be allowed to
//     be used by the client for purposes that they would like to create on their own, or just to see
//     if the object is still able to be moved.
//     Warnings: Any attempt to set a x or y that is outside the allowed upper and lower bounds set
//     in the gridFlea class (the upper limit is 15, the lower is -15) one of the objects will automatically
//     be permanently disabled and will not be allowed to be used again due to this. Do not attempt
//     to set one outside of the preset boundaries.

#ifndef CPSC3200_GRIDFLEA_H
#define CPSC3200_GRIDFLEA_H
#include <iostream>

class gridFlea {
private:
    int initialX, initialY;
    int currentMoves, initialMoves;
    int actualX, actualY;
    int reward;
    int upperBound, lowerBound;
    int size;
    int jumpSize;
    int maxOutsideJump;
    bool jumped;
    bool active;
    bool charged;
    bool permaActive;

public:
    // Pre: Nothing is needed, this creates the object to access the gridFlea class
    // and Run it as well
    // Post: Will create a gridFlea object that can access the class
   gridFlea(int x, int y);

    //Postfix incrementation ++ overload
    // Pre: Needs at least 1 gridFlea created, and object must be permaActive
    // Post: will increment all actualX and actualY values by 1, and return the old values
    gridFlea operator++(int num);

    //Prefix incrementation ++ overload
    // Pre: Needs at least 1 gridFlea created, and object must be permaActive
    // Post: will increment all actualX and actualY values by 1, and return the new values
    gridFlea operator++();

    // gridFlea == operator
    // Will check if the X and Y, and the active states are the same
    // if all are the same, will return true, else will return false.
    // Pre: 2 gridFlea Objects
    // Post: will return if they are = or not.
    bool operator==(const gridFlea& Flea);

    // gridFlea == operator
    // Will check if the X and Y, and the active states are the same
    // if any are different, will return true, else will return false.
    // Pre: 2 gridFlea Objects
    // Post: will return if they are = or not.
    bool operator!=(const gridFlea& Flea);

    /* GridFlea + int addition operator
     * Will move the X and Y however many positions from where the Flea x and y are
     * Will return to the 3rd object and return temp.
     * eg: obj3 = obj2 + obj1
     * Pre: 3 created gridflea objects
     * Post: 3rd object will have new actualX and actualY based on the objs positions.
     */
    gridFlea operator+(const gridFlea& Flea);

    /* GridFlea + int addition operator
     * Will move the X and Y however many positions from where the Flea x and y are
     * Will return to the 3rd object and return temp.
     * eg: obj3 = obj2 + int
     * Pre: 2 created gridFlea objects
     * Post: will move however a # of spots from the obj2 actualX and Y and the int.
     */
    gridFlea operator+(int num);
    // Pre: Object must be active and not be permanently deactivated to move.
    // Post: Changes the location of the actualX or actualY based on the input. Reward increases or decreases
    // based on where it moves.
   void gridFleaMove(int moved, bool x);
   // Pre: Object cannot be permanently deactivated to be revived.
    // Post: Object will be keep current numbers, and be able to move again
   void gridFleaRevive();
    // Pre: Object must be in an active state
    // Post: Object will be reset to base values.
   void gridFleaReset();
    // Pre: Object needs no special condition to access this.
    // Post: Returns the values
   int gridFleaValue();
   //Pre: Object needs to exist
   // Post: will return if the object is permanently active or not.
   bool isPermaActive() { return permaActive;}


};


#endif //CPSC3200_GRIDFLEA_H
