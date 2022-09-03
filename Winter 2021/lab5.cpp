// Ethan Tarlov
// Lab5.cpp
// 1/20/21

// Purpose: Focuses on using structs
// description: Uses an array of structs to do the following tasks:
// find the oldest person, find the person who drinks the least coffee
// print the entire list, print a single record, and to sort the entire list
// and to print the sorted list

#include <iostream>
#include <fstream>

using namespace std;

struct Person {
    string name;
    int age;
    int coffee;
};

void printOne(Person p);

int findOldest (Person clients[], int numRecords);

int findLeastCoffee(Person clients[], int numRecords);

void sortList(Person clients[], int numRecords);
// runs to sort the list

void swapVal(Person& one, Person& two);

// sorts strings



const int MAX = 150;
const string FILENAME = "/home/fac/sreeder/class/cs1430/lab5input.dat";

int main() {

    cout << endl << endl; 

    Person list[MAX];
    int count = 0;
    ifstream infile;

    infile.open(FILENAME);

    if(infile.fail()){
        cout << "File error";
        return 0;
    }

    while(infile >> list[count].name){
        infile >> list[count].age >> list[count].coffee;
        count++;
    }
    infile.close();
    
    // functions called from here
    cout << "This is a Coffee Count program" << endl;

    cout << "This is the oldest person in the list" << endl;
    printOne(list[findOldest(list,count)]);
    cout << endl;

    cout << "This is the person who drinks the least coffee" << endl;
    printOne(list[findLeastCoffee(list, count)]);
    cout << endl;

    cout << "This is printing all records, name, age, then coffee amount";
    cout << endl;
    for(int i = 0; i < count; i++){
        printOne(list[i]);
    }
    cout << endl;
    sortList(list,count);
    cout << "List is sorted... here is sorted list" << endl;
    for(int i = 0; i < count; i++){
        printOne(list[i]);
    }

    cout << endl << endl;

    return 0;
}

void printOne(Person p)
{
    cout << p.name << "  " << p.age << "  " << p.coffee;
    cout << endl;
}

int findOldest (Person clients[], int numRecords)
{
    int oldest = 0;

    for (int i = 1; i < numRecords; i++){
        if (clients[i].age > clients[oldest].age)
            oldest = i;
    }
    return oldest;
}

int findLeastCoffee(Person clients[], int numRecords)
{
    int least = 0;

    for (int i = 1; i < numRecords; i++){
        if (clients[i].coffee < clients[least].coffee)
            least = i;
    }
    return least;
}

void sortList(Person clients[], int numRecords)
{
    int min;
    for (int i = 0; i < numRecords - 1; i++){
        min = i;
        for (int j = i+1; j < numRecords; j++){
            if(clients[j].name < clients[min].name)
                min = j;
        }
        swapVal(clients[min], clients[i]);
    }
}

void swapVal(Person& one, Person& two)
{
    Person temp = one;
    one = two;
    two = temp;
}

