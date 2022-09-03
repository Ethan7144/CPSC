// Created by Ethan Tarlov on 4/13/22.
// P2.cpp
// Driver testing inFest functions
// Creates collections of smart pointers to inFest objects
// Will test all the functions created and attempt to test the copy and assignment
// operators as well.
// Will test to restore all gridFleas in an object, and to also find
// the minValue and maxValue on an object as well.

#include "inFest.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int random = rand() % 15;
    inFest obj = inFest(8, random, random);
    inFest obj2 = inFest(obj);
    inFest obj3 = obj;
    cout << "Moving all objects" << endl;
    obj.inFestMove(1, true);
    obj2.inFestMove(3, false);
    obj3.inFestMove(5, true);

    cout << "Now printing Min Value from obj1" << endl;
    cout << obj.inFestValueMin() << endl;

    cout << "Now printing the Max Value from obj1" << endl;
    cout << obj.inFestValueMax() << endl;


}
