// Ethan Tarlov
// stack.h
// Stack ADT for ints

#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

class Stack
{
    public:
    class EmptyStack{};
    // thrown when the stack is empty

    explicit Stack(int size = 50);
    // constructor

    Stack (const Stack& s);
    // copy constructor

    Stack& operator=(const Stack& rhs);
    // overloaded assignment operator

    ~Stack();
    // destructor

    void push(int data);
    // adds data to stack
    // data must be prime or it will not be pushed

    int pop();
    // removes and returns data from stack
    // can throw EmptyStack if needed

    bool isEmpty() const;
    // returns status of stack

    private:
    int* list; // stack
    int max;
    int top;

    bool full() const;
    // returns status of the stack

    void resize();
    // allocates more stack memory

    bool isPrime(int num);
    // returns true if num is prime
    // returns fale if num is non-prime
};

#endif 
