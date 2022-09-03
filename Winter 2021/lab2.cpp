// Ethan Tarlov
// lab2.cpp
// 1/10/21

// Purpose: creating functions w/ and w/o 
// parameters and provides practice w/ while
// loops.

// Description: prints out a welcome msg,
// has an input function that asks for a #
// between 5 to 25 ONLY. It also does a 
// summation from 1 to the input #
// and print the result and says goodbye.


#include <iostream>

using namespace std;

void welcome(); // welcomes the user to the program
void goodbye(); // says goodbye to the user when they exit
int inputValue(int num); // asks for a value between 5-25
int summation(int num); // does a summation from 1 to inputValue


int main()
{
    
    cout << endl << endl;
    char ans = 'y';

    int value; // variables

    welcome();
    while(ans = 'y')
    {
    inputValue(value);
    summation(value);
    cout << "Do you wish to repeat the program? (y/n)" << endl;
    cin >> ans;
    ans = tolower(ans);
    while(ans != 'y' && ans != 'n')
    {
        cout << "Please insert 'y' or 'n' ";
        cin >> ans;
        ans = tolower(ans);
        cout << endl;
    }
    }
    goodbye();

    cout << endl << endl;

    return 0;
}

void welcome()
{
    cout << "Welcome to my program!" << endl;
}

void goodbye()
{
    cout << "Goodbye!" << endl;
}

int inputValue(int num)
{
    cout << "Please insert a number from 5 to 25" << endl;
    cin >> num;
    while(num > 25 || num < 5)
    {
        cout << "Invalid number please insert a valid number" << endl;
        cin >> num;
    }
    cout << "Your number is " << num << endl;
    return num;
}

int summation(int num)
{
    int total = 0;
    for(int i = 1; i <= num; i++)
    {
        total =+ i;
    }
    cout << "Sum = " << total;
    return total;
}
