#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack()
{
    top = -1;
    size = 10;
    stackArray = new int[size];
}

Stack::Stack(const Stack &copy)
{
    size = copy.size;
    stackArray = new int[size];
    for(int i = 0; i < size; i++){
        stackArray[i] = copy.stackArray[i];
    }
}

Stack::~Stack()
{
    delete [] stackArray;
}

bool Stack::isEmpty() const
{
    // checks if top is empty
    if (top == -1)
        return true;
    return false;
}
void Stack::push(int num)
{
    //check if its full
    if (isFull())
    {
        resize();
        stackArray[top] = num;
        top++;
    }
    else
    {
        stackArray[top] = num;
        top++;
    }
}

int Stack::pop()
{
    // checks if its empty
    if (isEmpty())
        throw EmptyStack();
    else{
        top--;
        return stackArray[top];
    }
}

bool Stack::isFull() const
{
    // check if it top is the maxSize
    if(top == size)
        return true;
    return false;
}

void Stack::resize()
{
    // make a new size
    int newSize = size * 1.5;
    int *temp;

    // allocate more memory
    temp = new int [newSize];

    //copy values over
    for(int i = 0; i < size; i++){
        stackArray[i] = temp[i];
    }
    delete [] stackArray;
    stackArray = temp;
}
