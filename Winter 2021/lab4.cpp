// Ethan Tarlov
// Lab5.cpp
// 1/17/21

// Purpose: Focuses on using arrays
// description: sorts ints in a file to 3 types of arrays
// it sorts them in either even, odd, or negative arrays.
// and prints the indexs used in the arrays and the contents.

#include <iostream>
#include <fstream>

using namespace std;

const string FILENAME = "/home/fac/sreeder/class/cs1430/lab4input.dat";
const int SIZE = 30;

int main()
{

    cout << endl << endl;

    int evenNum[SIZE];
    int oddNum[SIZE];
    int negNum[SIZE];
    int num;
    int countEven = 0;
    int countOdd = 0;
    int countNeg = 0;
    int countZero = 0; // just a place to store the # of zeros there are.
    ifstream file;
    file.open(FILENAME);
    if(file.fail())
    {
        cout << "Failed to open file";
        return 0;
    }
    if(file >> num)
    {
        for(int i = 0; i < SIZE; i++)
        {
            if(num == 0)
            {
                countZero++;
            }
            else if(num < 0)
            {
                negNum[countNeg] = num;
                countNeg++;
            }
            else if(num % 2 == 0)
            {
                evenNum[countEven] = num;
                countEven++;
            }
            else 
            {
                oddNum[countOdd] = num;
                countOdd++;
            }
    
        }
    file.close();
    }
    cout << "The file contanined the following: " << endl;

    cout << "Negative Numbers found: " << countNeg << endl;
    cout << "Numbers: ";
    for(int i = 0; i <= countNeg - 1; i++)
    {
        cout << negNum[i] << ", ";
    }
    cout << endl << endl;

    cout << "Even Numbers found: " << countEven << endl;
    cout << "Numbers: ";
    for(int i = 0; i <= countEven - 1; i++)
    {
        cout << evenNum[i] << ", ";
    }
    cout << endl << endl;

    cout << "Odd Numbers found: " << countOdd << endl;
    cout << "Numbers: ";
    for(int i = 0; i <= countOdd - 1; i++)
    {
        cout << oddNum[i] << ", ";
    }
    
    cout << endl << endl << endl;

}