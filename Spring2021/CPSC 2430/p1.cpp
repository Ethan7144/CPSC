// Ethan Tarlov
// p1.cpp

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};

void insert(Node*& n, int num);
// creates a linked list
void print(Node* n);
// prints the linked list
int findSmallest(Node* n, int& min);
// Finds the smallest value on the linked list
int findLargest(Node* n, int& max);
// Finds the largest value on the linked list
void deleteValue(Node*& n, int num);
// deletes a random int in the linked list
void deleteAll(Node*& list);

void ofFile1(ofstream& out, Node* n);
void ofFile2(ofstream& out, Node* n);
const int MAX = 60;

int main()
{
    cout << endl << endl;

    Node* list = nullptr;
    ofstream myfile;
    int v1 = 0;
    int count = 0;
    int num = 0;
    int maxa = 0;
    int mini = 0;
    // start off by generating the linked list.

    while(count != MAX){
        count++;
        v1 = rand() % 100 + 1;
        insert(list, v1);
    }
    ofFile1(myfile, list);
    findSmallest(list, mini);
    deleteValue(list, mini);
    findLargest(list, maxa);
    deleteValue(list, maxa);
    cout << "What value would you like to delete? ";
    cin >> num;
    deleteValue(list, num);

    ofFile2(myfile, list);

    deleteAll(list);
    cout << endl << endl;

    return 0;
}

void insert(Node*& n, int num)
{
    Node* newNode = new Node;
    newNode->data = num;
    newNode->next = n;
    n = newNode;
}

void print(Node* n)
{
    while(n != nullptr){
        cout << n->data << endl;
        if(n->next != nullptr)
            n = n->next;
    }
}

int findSmallest(Node* n, int& min)
{
    min = 0;
    while(n != nullptr){
        if(n->data < min)
            min = n->data;
        
        else
            n = n->next;
        
    }
    cout << "Min is " << min << endl;
    return min;
}

int findLargest(Node* n, int& max)
{
    max = 0;
    while(n != nullptr){
        if(n->data > max)
            max = n->data;
        
        else
            n = n->next;
        
    }
    cout << "Max is " << max << endl;
    return max;
}

void deleteValue(Node*& n, int num)
{
    Node* ptr = n;
    Node* current = n->next;
    while(current != nullptr){
        if(current->data == num){
            ptr->next = current->next;
            delete current;
        }
        else{
            ptr->next = current;
            current = current->next;
        }
    }
}

void deleteAll(Node*& list)
{
    Node* temp = list;
    while(temp != nullptr){
        Node* trav = temp->next;
        delete temp;
        temp = trav;
    }
    list = nullptr;
}

void ofFile1(ofstream& out, Node* n)
{
    out.open("OutputA.txt");
    while(n != nullptr){
        out << n->data << endl;
        n = n->next;
    }
    out.close();
}

void ofFile2(ofstream& out, Node* n)
{
    out.open("OutputB.txt");
    while(n != nullptr){
        out << n->data << endl;
        n = n->next;
    }
    out.close();
}