// Ethan Tarlov
// p2.cpp

#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    Stack s1;
    Stack s2(5);
    int testNums[] = {2, -5, 17, 89, 40, -31, 37, 97, 9, 67};

    cout << endl << endl;
    cout << "This program will test the functionality of the stack" << endl
         << "that will only accept prime numbers" << endl << endl;
    // Testing push and isPrime
    cout << "Testing the push and isPrime methods" << endl;
    cout << "The followung values will be pushed onto the stack " << endl;
    for(int i = 0; i < 5; i++){
        cout << testNums[i] << ' ';
        s1.push(testNums[i]);
    }
    cout << endl;

    // pop & isEmpty test
    cout << "Testing pop and isEmpty methods" << endl;
    cout << "The following values should be popped: " << endl;
    cout << "89, 17, 2" << endl;
    while(!s1.isEmpty())
        cout << s1.pop() << ' ';
    cout << endl << endl;
    // resize & full test - push more than 5 values on s2
    cout << "Testing resize & is isFull methods" << endl;
    cout << "The following values will be pushed onto a stack of size 4: "
         << endl;
    for(int i = 0; i < 10; i++){
        cout << testNums[i] << ' ';
        s2.push(testNums[i]);
    }
    cout << "The following values should be popped from the stack: " << endl;
    cout << "67 97 37 31 89 17 2" << endl;
    while(!s2.isEmpty())
        cout << s2.pop() << ' ';
    cout << endl << endl;
    // copy constructor test
    cout << "Now copying S2" << endl;
    for(int i = 0; i < 5; i++){
        cout << "Pushing " << testNums[i] << ' ' << endl;
        s2.push(testNums[i]);
    }
    Stack s3(s2);

    cout << "Stack copied over.";

    // overloaded assignment operator test
    cout << "Testing overloaded assignment operator" << endl;
    cout << "Making a new stack equal to S2" << endl;
    Stack s4 = s2;
    // exception handling test
    cout << "Now testing exception handling" << endl;
    try{
        cout << s1.pop();
    }
    catch (Stack::EmptyStack){
        cout << "ERROR: Cannot pop from an Empty Stack" << endl;
    }
    cout << endl;

    cout << "This concludes the tests" << endl;
    cout << endl << endl;
}