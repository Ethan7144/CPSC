#ifndef TREE_H
#define TREE_H
#include <iostream>

using namespace std;

class BST
{
    private:
    struct Node{
        Node(int value): data(value), left(nullptr), right(nullptr){}
        int data;
        Node* right = nullptr;;
        Node* left = nullptr;;
    };
    Node* root;
    void copyHelper(BST*& current, const BST* other);
public:
    BST();
    BST(const BST &copy);
    BST& operator=(const BST& rhs);
    ~BST();
    void insert(Node* node, int value);
    bool searchTree(Node* node, int value);
    bool printAncestors(Node* node, int value);
    int findHeight(Node* node);
    void printPostOrder(Node* node);
    void printInOrder(Node* node);
    int countLeafs(Node* node);
    
};
#endif
