//Ethan Tarlov
// lab7.cpp
// 2/5/21

//Purpose: Focuses on pointers
// description: Will define  reg variable, and a pointer
// will follow steps requested in the description for the program
// once done it will delete all the memory

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    
    cout << endl << endl;

    int num;
    int * number;

    // steps 1 and 2
    cout << "What number would you like to assign? ";
    cin >> num;
    cout << endl;
    number = &num;

    // step 3
    cout << "Value stored in the variable num " << num << endl;
    cout << "At the address " << &num << endl;
    cout << "Pointer number points to " << *number << " and holds address "
    << number << endl;

    // step 4
    number = new int;

    // step 5;
    *number = 21;

    // step 6
    cout << "Num is " << num << " at address " << &num << endl;
    cout << "Pointer number points to " << *number << " and holds address "
    << number << endl;

    // step 7
    delete number;

    // step 8
    cout << "Input a small number, please ";
    cin >> num;
    number = new int [num];

    // step 9
    srand(time(0));
    for(int i = 0; i < num; i++){
        number[i] = rand();
    }

    // step 10
    for(int i = 0; i < num; i++){
        cout << number[i] << endl;
    }
    
    // step 11
    
        delete [] number;
    cout << endl << endl;
    return 0;

}