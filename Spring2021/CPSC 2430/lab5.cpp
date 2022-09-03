// Ethan Tarlov
// lab5.cpp

#include <iostream>
#include <fstream>


using namespace std;

struct Pop{
    int censusCount;
    string place;
};


void mergeSort(Pop arr[], Pop temp[], int first, int last);

void merge(Pop arr[], Pop temp[], int leftPos, int rightPos, int rightEnd);

void printArr(Pop arr[], int numRecords); // prints 10

const int MAX = 3200;
const int PRINT_MAX = 10;
const int COL = 8;
const string FILENAME = "/home/fac/sreeder/class/cs2430/countryPop.dat";

int main()
{
    cout << endl << endl;
    ifstream file;
    int count;
    Pop list[MAX];
    Pop tempList[MAX];

    file.open(FILENAME);

    if(file.fail()){
        cout << "The File failed to open";
        return 0;
    }
    while(file >> list[count].censusCount){
        getline(file, list[count].place);
        count++;
    }
    file.close();
    printArr(list, count);
    mergeSort(list, tempList, 0, count - 1);
    printArr(list, count);

    cout << endl << endl;

    return 0;
}

void mergeSort(Pop arr[], Pop temp[], int first, int last)
{
    if(first >= last){
        return;
    }
    int mid = first + (last -1)/2;
    mergeSort(arr, temp, first, mid);
    mergeSort(arr, temp, mid+1, last);
    merge(arr, temp, first, mid + 1 , last);
}

void merge(Pop arr[], Pop temp[], int leftPos, int rightPos, int rightEnd)
{
    int leftEnd = rightPos - 1;
    int tempPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while(leftPos <= leftEnd && rightPos <= rightEnd){
        if(arr[leftPos].censusCount <= arr[rightPos].censusCount){
            temp[tempPos] = arr[leftPos];
            tempPos++;
            leftPos++;
        }else{
            temp[tempPos] = arr[rightPos];
            tempPos++;
            rightPos++;
        }
        while(leftPos <= leftEnd){
            temp[tempPos] = arr[leftPos];
            tempPos++;
            leftPos++;
        }
        while(rightPos <= rightEnd){
            temp[tempPos] = arr[rightPos];
            tempPos++;
            leftPos++;
        }
        for(int i = 0; i < numElements; i++){
            arr[rightEnd] = temp[rightEnd];
            rightEnd--;

    }

    }
}

void printArr(Pop arr[], int numRecords)
{
    cout << "Start of the list... " << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i].censusCount << " " << arr[i].place << endl;
    }
    cout << endl << endl;
    cout << "End of the List..." << endl;

    for(int i = numRecords - 9; i <= numRecords; i++){
        cout << arr[i].censusCount << " " << arr[i].place << endl;
    }
}