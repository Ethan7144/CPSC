// Ethan Tarlov
// stack.cpp

#include "stack.h"

Stack::Stack(int size)
{
    max = size;
    top = -1;
    list = new int [max];
}

Stack::Stack(const Stack& s)
{
    max = s.max;
    list = new int [max];
    for(int i = 0; i < max; i++){
        list[i] = s.list[i];
    }
}

Stack& Stack::operator=(const Stack& rhs)
{
    if(&rhs != this){
        delete [] list;
        max = rhs.max;
        top = rhs.top;
        list = new int[max];

        for(int i = 0; i < top; i++){
            list[i] = rhs.list[i];
        }
    }
    return *this;
}

Stack::~Stack()
{
    delete [] list;
}

void Stack::push(int data)
{
    if(!isPrime(data))
        return;
    if (full()){
        resize();
        list[top] = data;
        top++;
    }
    else{
        list[top] = data;
        top++;
    }
}

int Stack::pop()
{
    if (isEmpty())
        throw EmptyStack();
    else{
        top--;
        return list[top];
    }
}

bool Stack::isEmpty() const
{
    if(top == -1)
        return true;
    return false;
}

bool Stack::full() const
{
    if(top == max)
        return true;
    return false;
}

void Stack::resize()
{
    int* tmp;
    int max = max * 1.5;

    tmp = new int[max];

    for(int i = 0; i < max; i++)
        list[i] = tmp[i];
    
    list = tmp;
}

bool Stack::isPrime(int num)
{
    for(int i = 2; i <= num / 2; i++){
        if(num % i == 0)
            return false;
    }
    return true;
}


