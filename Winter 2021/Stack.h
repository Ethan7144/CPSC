#ifndef STACK_H
#define STACK_H
#include <iostream>

using namespace std;

class Stack
{
public:
    Stack();
    Stack(const Stack &copy);
    ~Stack();
    bool isEmpty() const;
    void push(int);
    int pop();
    class EmptyStack {};

private:
    int size;
    int top;
    int *stackArray;
    bool isFull() const;
    void resize(); 
};
#endif