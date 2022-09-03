//Ethan Tarlov
// lab9.cpp
// 2/12/21

// Purpose: Focuses on ordered linked lists
// description: will descramble a secret message
// will be able to read a message that is specifically
// typed out after it is done.
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;
struct Node
{
    int position;
    char letter;
    Node* next;
};

void insertOrder(Node*& head, int pos, char let);
// inserts a new node in ascending order

void print(Node* head);
// prints message

void deleteAll(Node*& head);
// deletes all nodess on the list

const string FILENAME = "/home/fac/sreeder/class/cs1430/lab9input.dat";

int main()
{
    ifstream infile;
    char thisLetter;
    int thisPos;
    Node* message = nullptr;

    infile.open(FILENAME);

    cout << endl << endl;

    if(infile.fail()){
        cout << "File error... press enter to exit";
        cin.get();
        return 0;
    }
    while(infile.get(thisLetter)){
        infile >> thisPos;
        infile.get();
        insertOrder(message, thisPos, thisLetter);
    }
    cout << "Printing the message" << endl;
    print(message);
    infile.close();
    
    cout << endl << endl;
    return 0;
}

void insertOrder(Node*& head, int pos, char let)
{
    Node* current;
    Node* prev;
    Node* newNode = new Node;
    newNode->letter = let;
    newNode->position = pos;
    newNode->next = nullptr;
    if(head == nullptr){
        head = newNode;
    }
    else{
        current = head;
        prev = nullptr;
        while(current!= nullptr && current->position < pos){
            prev = current;
            current = current->next;
        }
        if(prev == nullptr){
            head = newNode;
            newNode->next = current;
        }
        else{
            prev->next = newNode;
            newNode->next = current;
        }
    }
}

void print(Node* head)
{
    Node* current = head;
    while(current != nullptr){
        cout << current->letter;
        current = current->next;
    }
    cout << endl;
}

void deleteAll(Node*& head)
{
    Node *temp = head;
    Node *trav = temp->next;
    while (temp != nullptr){
        delete temp;
        temp = trav;
    }
    head = nullptr;
}