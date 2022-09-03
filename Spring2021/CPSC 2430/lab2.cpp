// Ethan Tarlov
// lab 2

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

const char YES = 'y';
void push(Node** head, int num);
// pushes a num into the node
void search(Node* head, int &target);
// searches list and prints the last negative number
void print(Node* head);

int main()
{
    Node* head = nullptr;
    int check = 0;
    char ans;
    int insert;
    push(&head, 10);
    push(&head, -5);
    push(&head, -3);
    push(&head, 25);
    push(&head, 15);

    print(head);
    cout << "Do you wish to add more nodes? (y/n) ";
    cin >> ans;
    while(tolower(ans) == YES){
        cout << "Insert a number ";
        cin >> insert;
        push(&head, insert);
        cout << "Another? (y/n) ";
        cin >> ans;
    }

    print(head);

    search(head, check);
    return 0;
}

void push(Node** head, int num){
    
    Node* newNode = new Node;
    newNode->data = num;
    newNode->next = *head;
    *head = newNode;
}

void print(Node* head)
{
    Node *target = head;
    while(target != nullptr){
        cout << target->data << endl;
        target = target->next;
    }
    cout << endl;
}

void search(Node* head, int& target)
{
    Node* current = head;
    if(current == nullptr){
        cout <<
        return;
    }
    if(current->data < 0)
        target = current->data;
    search(head->next, target);
    if(target == 0){
        cout << "There are no negative numbers" << endl;
    }else{
        cout << "The last negative number in the list is " << target << endl;
    }
    return 0;
}
