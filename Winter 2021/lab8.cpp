//Ethan Tarlov
// lab8.cpp
// 2/10/21

//Purpose: Focuses on linked lists
// description: Will make a node for a linked list,
// will request and int until the user is done
// Prints the finished list in a column
// deletes all nodes

#include <iostream>
#include <cctype>

using namespace std;

struct Node{
    int data;
    Node *next;
};
void insert(Node*& list, int num);
// inserts num into a new node

void print(Node* list);
// prints the entire list

void deleteAll(Node*& list);
// deletes all nodes on the linked list

const char YES = 'y';
int main()
{    
    cout << endl << endl;

    Node *head = nullptr;
    char ans = YES;
    int number;

    while(tolower(ans) == YES){
        cout << "What number? ";
        cin >> number;

        insert(head, number);

        cout << "Would you like to run it again? (y/n) ";
        cin >> ans; 
    }

    print(head);

    deleteAll(head);

    cout << endl << endl;

    return 0;
}

void insert(Node*& list, int num)
{
    Node *newNode = new Node;
    newNode->data = num;
    newNode->next = list;
    list = newNode;

}

void print(Node* list)
{
    Node *target = list;
    while(target != nullptr){
        cout << target->data << endl;
        target = target->next;
    }
    cout << endl;
}

void deleteAll(Node*& list)
{
    Node *temp = list;
    while (temp != nullptr){
        Node *trav = temp->next;
        delete temp;
        temp = trav;
    }
    list = nullptr;
}