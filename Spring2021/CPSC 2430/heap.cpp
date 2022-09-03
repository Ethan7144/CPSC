// Ethan Tarlov
// heap.cpp

#include "heap.h"

using namespace std;

Heap::Heap(int size)
{
    harr = new int[size];
    max = size;
    curSize = 0;
}

Heap::Heap(const Heap& copy)
{
    max = copy.max;
    curSize = copy.curSize;
    harr = new int[max];
    for(int i = 0; i < curSize; i++){
        harr[i] = copy.harr[i];
    }
}

 Heap& Heap::operator=(const Heap& rhs)
{
    if(this != &rhs){
        delete [] harr;
        max = rhs.max;
        curSize = rhs.curSize;
        harr = new int[max];
        for(int i = 0; i < curSize; i++){
            harr[i] = rhs.harr[i];
        }
    }
    return * this;
}
Heap::~Heap()
{
    delete [] harr;
}

void Heap::flush(int k)
{  
    for(int i = 0; i < curSize; i++){
        if(harr[i] == k)
        {
            changeKeyPosition(i, -1000);
            removeMin();
        }
    }
}

void Heap::insert(int k)
{
    if(curSize == max){
        reSize();
    }
    curSize++;
    int index = curSize - 1;
    harr[index] = k;

    while(index != 0 && harr[parent(index)] > harr[index]){
        swap(harr[index], harr[parent(index)]);
        index = parent(index);
    }
}
void heapify(int index)
{
    int l = left(index);
    int r = right(index);
    int smallest = index;
    if(l < curSize && harr[l] < harr[index])
        smallest = l;
    if(r < curSize && harr[r] < harr[smallest])
        smallest = r;
    if(smallest != index){
        swap(harr[index], harr[smallest]);
        heapify(smallest);
    }
}

int Heap::removeMin()
{
    if(isEmpty())
    {   
        cout << "Cannot remove from an empty heap" << endl;
        return 0;
    }
    if(curSize == 1){
        curSize--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[curSize - 1];
    curSize--;
    heapify(0);

    return root;
}

void Heap::changeKeyPosition(int i, int newVal)
{
    harr[i] = newVal;
    while(i != 0 && harr[parent(i)] > harr[i]){
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}
void Heap::reSize()
{
    int* temp;
    int max = max * 1.5;

    temp = new int[max];

    for(int i = 0; i < curSize; i++)
        harr[i] = temp[i];
    
    harr = temp;
}
void Heap::swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}
void Heap::printArray()
{
    cout << "Index   Value" << endl;
    for(int i = 0; i < curSize; i++){
        cout << setw(5) << i << setw(5) << harr[i] << endl;
    }
}