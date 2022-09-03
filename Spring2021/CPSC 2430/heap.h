//Ethan Tarlov
//heap.h

#include <iostream>

#ifndef HEAP_H
#define HEAP_H

class Heap
{
    private:
        int* harr;
        int max;
        int curSize;
        void reSize(); // will change size if need 
        void swap(int& x, int& y); // basic swap
    public:
        Heap(int size);
        Heap(const Heap& copy);
        Heap& operator=(const Heap& rhs);
        ~Heap();
        void flush(int k); // will remove a specific value
        void insert(int k); // insert function
        void heapify(int); // min heap
        int parent(int i) { return (i-1)/2; } // getter for parent
        int left(int i) { return (2*i + 1); } // getter for left
        int right(int i) { return (2*i + 2); } // getter for right
        int getMin() { return harr[0]; } // gets the min
        int removeMin(); // will remove the min
        void changeKeyPosition(int i, int newVal);
        bool isEmpty() { return curSize == 0; } // checks if its empty
        void printArray();
    
};

#endif