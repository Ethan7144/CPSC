// Ethan Tarlov
// lab3.cpp

#include <iostream>


using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node* newNode(int data); // constructor

void printPostOrder(Node* node);

void printInOrder(Node* node);

void printPreOrder(Node* node);

void insert(Node* node, int value);

void deleteTree(Node* node);

int main()
{
    Node* root = nullptr;
    insert(root, 50);
    insert(root, 60);
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 70);
    insert(root, 80);

    cout << "Printing In Order" << endl;
    printInOrder(root);
    cout << endl;
    cout << "Printing Pre Order" << endl;
  
    cout << endl;
    cout << "Printing Post Order" << endl;
    printPostOrder(root);

    deleteTree(root);

}

Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    
    return temp;
}
void insert(Node* node, int value)
{
    if(node == nullptr)
        node = newNode(value);
        return;
    if(node->data < value)
        insert(node->right, value);
    else if(node->data > value)
        insert(node->left, value);
}

void printPostOrder(Node* node)
{
    if(node == nullptr)
        return;
    printPostOrder(node->left);

    printPostOrder(node->right);
    
    cout << node->data << " ";
}

void printInOrder(Node* node)
{
    if(node == nullptr)
        return;
    printInOrder(node->left);

    cout << node->data << " ";

    printInOrder(node->right);
}

void printPreOrder(Node* node)
{
    if(node == nullptr)
        return;
    
    cout <<  node->data << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void deleteTree(Node* node)
{
    if(node == nullptr)
        return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}