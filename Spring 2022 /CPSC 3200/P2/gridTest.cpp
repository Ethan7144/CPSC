//
// Created by Ethan Tarlov on 4/14/22.
//


#include "gridFlea.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    gridFlea object (10, 10);
    gridFlea object2 (10, 10);

    object.gridFleaMove(3, true);
    object2.gridFleaMove(-3, true);
    int value1, value2;
    value1 = object.gridFleaValue();
    value2 = object2.gridFleaValue();

    cout << value1 << endl;
    cout << value2 << endl;
}