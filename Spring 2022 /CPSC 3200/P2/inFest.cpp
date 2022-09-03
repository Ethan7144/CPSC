//
// Created by Ethan Tarlov on 4/13/22.
// inFest.cpp
// Edited on 5/11 for P4
// A class that encapsulates multiple gridFlea objects

#include "inFest.h"
#include "gridFlea.h"
#include <iostream>

using namespace std;


inFest::inFest(int count, int x, int y) {
    if (count < 1)
    {
        throw invalid_argument("Cannot have less than 1 gridFlea made");
    }
    upperBound = 15;
    lowerBound = -15;
    numGridFleas = count;
    gridFleaList = new gridFlea*[numGridFleas];
    for(int i = 0; i < numGridFleas; i++) {
        gridFleaList[i] = new gridFlea(x, y);
        if(x >= upperBound || lowerBound > x){
            x = 0;
        } else{
            x++;
        }
        if(y >= upperBound || lowerBound > y){
            y = 0;
        }
        else{
            y++;
        }

    }
}

inFest::~inFest() {
    for(int i = 0; i < numGridFleas; i++){
        delete[] gridFleaList[i];
    }
    delete []gridFleaList;
}

inFest::inFest(const inFest &list) {
    numGridFleas = list.numGridFleas;
    gridFleaList = new gridFlea*[numGridFleas];

    for(int i = 0; i < numGridFleas; i++){
        gridFleaList[i] = list.gridFleaList[i];
    }
}

inFest &inFest::operator=(inFest &list) {
    if (this != &list) {
        for (int i = 0; i < numGridFleas; i++) {
            delete gridFleaList[i];
            gridFleaList[i] = nullptr;
        }
        delete[] gridFleaList;

        numGridFleas = list.numGridFleas;
        gridFleaList = new gridFlea *[numGridFleas];

        for (int i = 0; i < list.numGridFleas; i++) {
            gridFleaList[i] = new gridFlea(*list.gridFleaList[i]);
        }
    }
    return *this;
}

inFest::inFest(const inFest &&list) {
    numGridFleas = list.numGridFleas;
    gridFleaList = list.gridFleaList;

    for (int i = 0; i < list.numGridFleas; i++)
    {
        gridFleaList[i] = list.gridFleaList[i];
    }
}

inFest &inFest::operator=(inFest &&list) {
    if (this != &list) {
        for (int i = 0; i < numGridFleas; i++) {
            delete gridFleaList[i];
            gridFleaList[i] = nullptr;
        }
        delete[] gridFleaList;

        numGridFleas = list.numGridFleas;
        gridFleaList = new gridFlea *[numGridFleas];

        for (int i = 0; i < list.numGridFleas; i++) {
            gridFleaList[i] = new gridFlea(*list.gridFleaList[i]);
        }
        list.gridFleaList = nullptr;
        list.numGridFleas = 0;
    }

    return *this;
}

inFest inFest::operator+(const inFest& list) {
    int count = numGridFleas + list.numGridFleas;
    int checker = list.numGridFleas;
    inFest temp(count, 1, 1);
    for(int i = 0; i < checker; i++){
        temp.gridFleaList[i] = list.gridFleaList[i];
    }
    for(int i = checker; i < count; i++){
        temp.gridFleaList[i] = this->gridFleaList[i];
    }
    return temp;
}

bool inFest::operator==(const inFest &list) {
    if(this->numGridFleas == list.numGridFleas){
        for(int i = 0; i < this->numGridFleas; i++){
            if(this->gridFleaList[i] != list.gridFleaList[i]){
                return false;
            }
        }
    }else{
        return false;
    }
    return true;
}
bool inFest::operator!=(const inFest &list) {
    if(this->numGridFleas == list.numGridFleas){
        for(int i = 0; i < this->numGridFleas; i++){
            if(this->gridFleaList[i] != list.gridFleaList[i]){
                return true;
            }
        }
    }else{
        return false;
    }
    return true;
}



bool inFest::inFestResponse(int index) {
    if(gridFleaList[index]->isPermaActive()){
        return true;
    }
    else
    {
        return false;
    }

}

bool inFest::countResponse(){
    int responseCount = 0;
    for(int i = 0; i < numGridFleas; i++){
        if(!gridFleaList[i]->isPermaActive())
            responseCount++;
    }
    if(responseCount > numGridFleas/2){
        return true;
    }
    return false;
}
void inFest::inFestRestore() {
    if(countResponse()){
        for(int i = 0; i < numGridFleas; i++){
            gridFleaList[i]->gridFleaRevive();
        }
    }
}

void inFest::inFestMove(int moved, bool checkX) {
    for(int i = 0; i < numGridFleas; i++){
        gridFleaList[i]->gridFleaMove(moved, checkX);
    }
    inFestRestore();
}

int inFest::inFestValueMin() {
    int min = gridFleaList[0]->gridFleaValue();
    for (int i = 0; i < numGridFleas; i++){
        if(min > gridFleaList[i]->gridFleaValue()){
            min = gridFleaList[i]->gridFleaValue();
        }
    }
    return min;
}

int inFest::inFestValueMax() {
    int max = gridFleaList[0]->gridFleaValue();
    for (int i = 0; i < numGridFleas; i++){
        if(max < gridFleaList[i]->gridFleaValue()){
            max = gridFleaList[i]->gridFleaValue();
        }
    }
    return max;
}

// Implementation invariant: Only valid integer values are accepted as value
// parameters (including negative numbers) up to a limit to 15. The inFestRestore will only work
// if the more than half of the objects return false in the checker, if not it will
// not even run. if the set x or y is set to go over the Upper Limit (15) then it
// will reset it back to 0 to prevent it from going Out of Bounds.