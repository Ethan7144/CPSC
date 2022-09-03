// Ethan Tarlov
// p4.cpp

#include "heap.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    Heap tree(5);
    int check = 0;
    srand(time(0));
     cout << "Index   Value" << endl;
    for(int i = 0; i < 6; i++){
        check = tree.insert(rand() % 100 + 1);
        cout << setw(5) << i << setw(5) << tree[i];
    }
    cout << "Removing the min..." << endl;
    cout << tree.removeMin() << endl;
    cout << "Removing " << check << "..." << endl;
    cout << tree.flush(check) << endl;
    cout << "Index   Value" << endl;
    for(int i = 0; i < 5; i++){
        cout << setw(5) << i << setw(5) << tree[i];
    }
    while(!tree.isEmpty())
    {
        tree.removeMin();
    }

    return 0;
}
