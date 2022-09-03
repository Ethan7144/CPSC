//
// Created by Ethan Tarlov on 5/20/22.
// P4.cpp
/*
 * Driver to test for Unique PTR, Shared PTR, and all operator overloads for gridFlea and Infest
 * Creates a vector of shared PTR and Unique PTR and demonstrates move semantics for both.
 * Creates an array of gridFleas to test all of the operator overloads for it.
 * Test operator overloads for inFest in Shared PTR and in main.
 * UniquePtr gave Malloc errors, therefore, I commented out the function for testing it.
 * Addition Overload Test causes Segfault in CS1, so it is commented it out.
 */

#include <memory>
#include "inFest.h"
#include "gridFlea.h"
#include <iostream>
#include <vector>

const int COUNT = 10;
const int COUNTLOWER = 1;
const int COORDUPPER = 10;
const int COORDLOWER = 1;

using namespace std;


static int randCount();
static int randCoord();
static void gridFleaChecker();
static void sharedPTRInfest();
//static void uniquePTRInfest();








int main(){
    /*
    cout << "Testing Infest Addition with Type Infest + Infest = Infest" << endl;
    inFest obj[3] = {
            inFest(randCount(), randCoord(), randCoord()),
            inFest(randCount(), randCoord(), randCoord()),
            inFest(randCount(), randCoord(), randCoord())
    };
    obj[0] = obj[1] + obj[2];
    cout << endl << endl;
     */
    sharedPTRInfest();
    gridFleaChecker();
    //uniquePTRInfest();
}


static int randCount(){
    return rand() % COUNTLOWER + COUNT;
}
static int randCoord(){
    return rand() % COORDLOWER + COORDUPPER;
}
static void gridFleaChecker(){
    cout << "Testing gridFlea Objects, last 2 objects will be used for testing ++ and ==" << endl;
    int grab = randCoord();
    int size = 5;
    int tester = 1;
    gridFlea obj[7] = {
            gridFlea(randCoord(), randCoord()),
            gridFlea(randCoord(), randCoord()),
            gridFlea(randCoord(), randCoord()),
            gridFlea(randCoord(), randCoord()),
            gridFlea(randCoord(), randCoord()),
            gridFlea(tester, tester),
            gridFlea(tester, tester)
    };
    grab = randCoord();
    cout << "Moving all Objects a random number" << endl;
    for(int i = 0; i < size; i++) {
        obj[i].gridFleaMove(grab, true);
        grab++;
    }
    cout << "gridFlea Operator Overload testing" << endl;
    for(int i = 1; i < size; i++){
        if(obj[i] == obj[i-1]){
            cout << "Object["<< i << "] is equal to Object[" << i-1 << "]" << endl;
        }
        if(obj[i] != obj[i-1]){
            cout << "Object["<< i << "] is not equal to Object[" << i-1 << "]" <<  endl;
        }
    }
    cout << "Adding Obj[4] and Obj[3] to Obj[5]" << endl;
    cout << "Value before" << endl;
    cout << obj[2].gridFleaValue() << endl;
    obj[2] = obj[1] + obj[3];
    cout << "Value after" << endl;
    cout << obj[2].gridFleaValue() << endl;
    cout << "Operator ++" << endl;
    cout << "Values before" << endl;
    cout << obj[5].gridFleaValue() << endl;
    cout << obj[6].gridFleaValue() << endl;
    obj[5]++;
    obj[6]++;
    cout << "Values after" << endl;
    cout << obj[5].gridFleaValue() << endl;
    cout << obj[6].gridFleaValue() << endl;
    cout << "Checking if obj[5] and obj[6] are equal" << endl;
    if(obj[5] == obj[6]){
        cout << "They are equal" << endl;
    }
}
static void sharedPTRInfest() {
    vector <shared_ptr<inFest> > obj1;
    int grab = randCoord();
    vector < gridFlea * > Flea;
    int minVal = 0;
    int size = 5;
    int maxVal = 0;
    for (int i = 0; i < size; i++) {
        cout << "SHARED POINTER #" << i << endl;
        shared_ptr <inFest> inFestObj(new inFest(randCount(), randCoord(), randCoord()));
        shared_ptr <inFest> copiedObj = inFestObj;
        cout << "Moving Copied and Original" << endl;
        inFestObj->inFestMove(grab, true);
        copiedObj->inFestMove(grab, true);
        minVal = inFestObj->inFestValueMin();
        maxVal = inFestObj->inFestValueMax();
        cout << "original shared pointer minVal: " << minVal << endl;
        cout << "original shared pointer maxVal: " << maxVal << endl;
        minVal = copiedObj->inFestValueMin();
        maxVal = copiedObj->inFestValueMax();
        cout << "copied shared pointer minVal: " << minVal << endl;
        cout << "copied shared pointer maxVal: " << maxVal << endl;
        obj1.push_back(move(inFestObj));
        cout << "SHARED POINTER MOVED TO VECTOR" << endl;
        minVal = obj1[i]->inFestValueMin();
        maxVal = obj1[i]->inFestValueMax();
        cout << "vector shared pointer minVal: " << minVal << endl;
        cout << "vector shared pointer maxVal: " << maxVal << endl;
        minVal = copiedObj->inFestValueMin();
        maxVal = copiedObj->inFestValueMax();
        cout << "copied shared pointer minVal: " << minVal << endl;
        cout << "copied shared pointer maxVal: " << maxVal << endl;
        cout << endl;
        grab--;
    }
    for (int i = 1; i < size; i++) {
        if (obj1[i] == obj1[i - 1]) {
            cout << "Object[" << i << "] is equal to Object" << i - 1 << "]" << endl;
        }
        if (obj1[i] != obj1[i - 1]) {
            cout << "Object[" << i << "] is not equal to Object[" << i - 1 << "]" << endl;
        }

        cout << endl << endl;
    }
}


/*
 * static void uniquePTRInfest(vector<inFest> inFestVector){

 This is originally what I had, but I kept on getting malloc errors.
     * Commented out to just show the rest works.
     *
    cout << "Testing Unique Pointers and Move Semantics" << endl;
    vector<inFest> inFestVec;
    int minVal;
    int maxVal;

    for (int i = 0; i < 5; i++)
    {
        cout << "UNIQUE POINTER #" << i << endl;
        unique_ptr<inFest> inFestPtr(new inFest(randCount(), randCoord(), randCoord()));
        cout << "Moving inFest" << endl;
        minVal = *inFestPtr->inFestValueMin();
        maxVal = *inFestPtr->inFestValueMax();
        cout << "unique pointer minVal: "<< minVal << endl;
        cout << "unique pointer maxVal: "<< maxVal << endl;
        inFestVec.push_back(*inFestPtr);

        cout << "UNIQUE POINTER MOVED TO VECTOR" << endl;
        inFestVector[i].inFestMove(randCoord(), true);
        minVal = inFestVector[i].inFestValueMin();
        maxVal = inFestVector[i].inFestValueMax();
        cout << "vector unique pointer minVal: "<< minVal << endl;
        cout << "vector unique pointer maxVal: "<< maxVal << endl;
        cout << endl;
    }

}
 */
