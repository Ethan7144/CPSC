//
// Created by Ethan Tarlov on 4/13/22.
// Edited on 5/11/22 for P4
// V2
// inFest.h
// A class which encapsulates multiple gridFlea objects
// Class invariant: This class stored a double pointer array "gridFleaList" which
//     is a collection of multiple gridFlea instances. Each instance has their
//     own x and y value, each object will have its own instance and variables.
//     Each gridFlea object will not be allowed to go over the upper or lower limit
//     set in the gridFlea class, so it will prevent that from happening in the
//     constructor. A new instance can be deep copied from a previous one via
//     the copy constructor, or deep copied via the overloaded assignment
//     operator. Ownership of an instance may also be transferred via the move
//     constructor or move assignment operator.
//     A gridFlea object may have all values moved via the move function
//     which will move all gridFleas inside of the list the exact same number of spots
//     MinValue and MaxValue will look for the Max and Min value respectively in all of
//     the gridFleas available in the gridFleaList and return the smallest or largest one.
//     inFestRestore will only work if more than half the gridFleas return false on the
//     permanently disabled check. If it doesn't pass that, it will not attempt to restore.
//     inFestResponse is a helper function to help the Restore function check.
// Interface invariant: All of the functions will require a working gridFleaList in order to work.
//     if it is not provided, none of the class objects will work and the attempts will fail.
//     However, the client cannot access any of the gridFlea class objects respectively, and it will
//     only be called when needed by the inFest class. inFestResponse will also not be allowed to be
//     accessed by the client as the only function for it is to run and check to see if the object
//     is active or not and will not be allowed to be used by the user otherwise.
//     Warnings: Any attempt to set a x or y that is outside the allowed upper and lower bounds set
//     in the gridFlea class (the upper limit is 15, the lower is -15) one of the objects will automatically
//     be permanently disabled and will not be allowed to be used again due to this. Do not attempt
//     to set one outside of the preset boundaries.


#ifndef CPSC3200_INFEST_H
#define CPSC3200_INFEST_H
#include "gridFlea.h"

class gridFlea;
class inFest {

private:

    int numGridFleas;
    gridFlea **gridFleaList;
    int upperBound;
    int lowerBound;

    // Helper Function
    // This function is only used to help see if a gridFlea
    // is permaActive or not.
    // can only be accessed inside of inFestRestore.
    // Pre: Must be accessed via inFestRestore.
    // Post: will return true if the gridFlea is active and false if it is not.
    bool inFestResponse(int index);

    // Trys to Restore all the gridFleas inside a list.
    // Pre: more than half of the gridFleas must be deactivated.
    // Post: Any gridFleas that can be reactivated, will be reactivated via gridFleaRevive().
    void inFestRestore();

    //Counts number of active gridFleas and Returns true if more than half are inactive
    // Pre: Infest Object must be created and in use.
    // Post: returns true or false if more than half are inactive
    bool countResponse();

public:

    // Constructor with arguments
    // Initialized the set number of gridFleas determined by "count"
    // Will begin with the set x and y position and increase by one
    // for every new gridFlea.
    // will reset to 0 if the x or y is set to go past 15.
    inFest(int count, int x, int y);

    // Deconstructor
    ~inFest();

    // Copy Constructor
    // Will create a new instance of a gridFleaList based off
    // the one that is being copied from. Copies all the
    // gridFleas, and also the number of gridFleas in it.
    // Pre: Original Class has already been constructed.
    // Post: Deep copy of class created.
    inFest(const inFest &list);

    // Overloaded assignment operator
    // Copies an existing instance of gridFleaList to another instance.
    // Deep copies the gridFleaList and numGridFleas.
    // Pre: Both class instances have already been constructed
    // Post: Contents replaced with deep copy of original.
    inFest& operator=(inFest &list);

    // overloaded addition operator
    // Takes an existing infest, and add all the actualX and Y from the corresponding position to each spot
    // I.E: gridFleaList[0] will have gridFleaList2[0] added to it. so
    // gridFleaList[0] actualX will have gridFleaList2[0] actualX added to it.
    // Pre: 2 inFest types created
    // Post: New Infest with all actualX and actualY incremented from the 2nd list.
    inFest operator+(const inFest& list);

    //overloaded == operator
    // Uses gridFlea == to see if the entire infest is equal.
    // if All of it is the same, it is true, else false
    // Pre: 2 inFest objects created
    // Post: Return if the objs are = or not
    bool operator==(const inFest& list);

    //overloaded != operator
    // Uses gridFlea != to see if the entire infest is equal.
    // if any of it is different, it is true, else false
    // Pre: 2 inFest objects created
    // Post: Return if the objs are = or not
    bool operator!=(const inFest& list);

    // Move Constructor
    // Creates a new inFest object from an existing one.
    // Ownership is transferred from the original instance to the new one.
    // Pre: Class object must be constructed.
    // Post: Ownership of the original is transferred.
    inFest(const inFest &&list);

    // Move Assignment operator
    // Transfers ownership of an existing inFest object to another one.
    // Ownership is transfered from the original instance to the new one.
    // Pre: Class object must be constructed.
    // Post: Ownership of the original is transfered.
    inFest& operator=(inFest &&list);

    // Move Function
    // Will move all gridFleas inside an gridFleaList.
    // Pre: Objects MUST be active.
    // Post: All objects will move the number of spaces specified and on whatever axis specified.
    void inFestMove(int moved, bool checkX);

    // Pre: Object needs no special condition to access this.
    // Post: Returns the smallest Value in the gridFleaList.
    int inFestValueMin();

    // Pre: Object needs no special condition to access this.
    // Post: Returns the largest Value in the gridFleaList.
    int inFestValueMax();


};


#endif //CPSC3200_INFEST_H
