// Ethan Tarlov
// p4.cpp

#include "heap.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    Heap tree(5);
    srand(time(0));
    for(int i = 0; i < 6; i++){
        tree.insert(rand() % 100 + 1);
    }
    tree.printArray();
    cout << "Removing the min..." << endl;
    cout << tree.removeMin() << endl;
    cout << "Removing the number 50..." << endl;
    tree.insert(50);
    tree.printArray();
    cout << tree.flush(50);
    tree.printArray();
    while(!tree.isEmpty())
    {
        cout << tree.removeMin() << endl;
    }

    return 0;
}
