// Ethan Tarlov
// lab4.cpp

#include <iostream>
#include <iomanip>

using namespace std;


const int MAX_SIZE = 30;
const int MAX = 23;
const int COL_SIZE = 5;
const int NUM_SIZE = 100;
const int COLS = 5;

void insertNode(int arr[], int Key, int& curSize);

int remove(int arr[], int& size);

void percDown(int arr[], int size, int index);

void swap(int& x, int& y);
// swap func

int main()
{
    int heap[MAX_SIZE] = {0};
    int currentSize = 0;
    int count;
    srand(time(0));
    cout << endl << endl;

    for(int i = 0; i < 2; i++){
        currentSize = 0;
        count = 0;
        for(int j = 0; j < MAX; j++)
            insertNode(heap,(rand() % NUM_SIZE + 1), currentSize);
        cout << "This is the heap..." << endl;
        cout << "Index   Value" << endl;

        for(int j = 1; j < MAX + 1; j++){
            cout << setw(COL_SIZE) << j << setw(COL_SIZE) << heap[j] << endl;
        }
            cout << endl;
            cout << endl;

        while(currentSize > 0){
            cout << setw(COL_SIZE) << remove(heap, currentSize);
            count++;
            if(count % COLS == 0)
                cout << endl;
        }

        cout << endl << endl;
        cout << "Press enter to continue";
        cin.get();

    
    }
    cout << endl << endl;
    cout << "All Done!" << endl << endl;

    return 0;
}

void insertNode(int arr[], int Key, int& curSize)
{
    curSize++;
    int i = curSize - 1;
    arr[i] = Key;
    int parent = (i - 1) / 2;
    while(i != 0 && arr[parent] > arr[i]){
        swap(arr[i], arr[parent]);
        i = parent;
    }
}

int remove(int arr[], int& size)
{
    if(size == 1){
        size--;
        return arr[0];
    }
    int lastElement = arr[0];
    arr[0] = arr[size - 1];
    size--;
    percDown(arr, size, 0);
    return lastElement;
}

void percDown(int arr[], int size, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;
    if(left < size && arr[left] < arr[index])
        smallest = left;
    if (right < size && arr[right] < arr[smallest])
        smallest = right;
    if(smallest != index){
        swap(arr[index], arr[smallest]);
    }
    

}

void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}