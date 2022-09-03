#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

using namespace std;

class Queue
{
private:
    struct Node{
        int value;
        Node* next;
        Node* front;
        Node* back;
    };

    int sizeCheck;

public:
    Queue();
    ~Queue();
    Queue(const Queue &);
    void enQ(int);
    int deQ(int &);
    bool isQEmpty() const;
    class EmptyQueue {};
};
#endif