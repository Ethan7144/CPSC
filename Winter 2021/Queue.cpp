#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue()
{
    front = nullptr;
    back = nullptr;
    sizeCheck = 0;
}

Queue::Queue(const Queue &copy)
{
    Queue Node* trav = copy.front;
    while(trav != nullptr){

    }
}
Queue::~Queue()
{
    int value; // dummy variable
    while(!isQEmpty()){
        deQ(value);
    }
}

void Queue::enQ(int num)
{
    cout << "In Queue" << endl;
    // make a new node
    Node* temp = new Node;
    temp->value = num;
    temp->next = nullptr;
    //if Queue is empty, then the new node is front + back
    if(isQEmpty()){
        front = temp;
        back = temp;
    }
    // add a new node to the end and change back
    back->next = temp;
    back = temp;
    //increase the size counter
    sizeCheck++;
}

int Queue::deQ(int &num)
{
    cout << "In DeQueue" << endl;
    // make a temp value
    Node *temp = nullptr;
    // checks if the queue is empty to throw an error if it is
    if(isQEmpty()){
        throw EmptyQueue();
    }else{
        num = front->value;
        // makes the temp the front value
        temp = front;
        front = front->next;
        delete temp;
        // reduces the size by one
        sizeCheck--;
        return front->value;
    }
}

bool Queue::isQEmpty() const
{
    cout << "In empty" << endl;
    //check if sizeCheck is less than 0
    if (sizeCheck <= 0)
        return true;
    return false;
}