// Ethan Tarlov
// lab 1

#include <iostream>

using namespace std;

const int SIZE = 8;
const int MIN = 10;
const int MAX = 100;
const char YES = 'y';
int maxValue(int arr[], int numElements);
// returns the max value

int main()
{
    char ans = YES;
    while(tolower(ans) == YES){
        int list[SIZE];
        int input;
        int count = 0;
        

        cout << endl << endl;
        cout << "Hi! Welcome to my lab 1!" << endl;
        

        while(count < SIZE){
            cout << "Num (even, between " << MIN << " and " << MAX << "?) ";
            cin >> input;
            if (input % 2 == 0 && input > MIN && input < 100){
                list[count] = input;
                count++;
            }
        }

        for(int i = 0; i < SIZE; i++){
            cout << "Index: " << i << " Value: " << list[i] << endl;
        }
        
        
        cout << "The Max Value is: " << maxValue(list, count) << endl;

        cout << "Would you like to run it again? (y/n) ";
        cin >> ans;
    }

    cout << endl << "End of Lab1 Pgm" << endl;

    return 0;
}

int maxValue(int arr[], int numElements)
{
    int max = arr[0];

    for(int i = 0; i < numElements; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}