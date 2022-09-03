// Ethan Tarlov
//tree.cpp

#include "tree.h"
#include <stack>

using namespace std;

BST::BST()
{
    root = nullptr;
}



BST::BST(const BST& copy)
{
    root = copy.root;
    root->left = copy.root->left;
    root->right = copy.root->right;
    root->data = copy.root->data;
}

BST& BST::operator=(const BST& rhs)
{
    if(rhs.root == nullptr){
        root = nullptr;
    }else{
        copyHelper(root, rhs.root);
    }
    return *this;
}

void BST::copyHelper(Node*& current, const Node* other)
{
    if(other == nullptr){
        delete current;
        current = nullptr;
    }else{
        current = new Node;
        current->data = other->data;
        copyHelper(current->left, other->left);
        copyHelper(current->right, other->right);
    }
}

BST::~BST()
{
    delete root;
}

void BST::insert(Node* node, int value)
{
    if(node == nullptr){
        node = new Node(value);
        root = node;
    }
    
    else if(node->data < value)
        insert(node->right, value);
    else if(node->data > value)
        insert(node->left, value);
}

bool BST::searchTree(Node* node, int value)
{
    if(node == nullptr)
        return false;
    if(node->data == value)
        return true;
    else if(node->data < value)
       searchTree(node->right, value);
    else if(node->data > value)
        searchTree(node->left, value);
    return false;
}

bool BST::printAncestors(Node* node, int value)
{
    if(node == nullptr)
        return false;
    if(node->data == value)
        return true;
    if(printAncestors(node->left, value) ||
       printAncestors(node->right, value))
       {
           cout << root->data << " ";
           return true;
       }
    return false;
}

int BST::findHeight(Node* node)
{
    if(node == nullptr)
        return 0;
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

void BST::printPostOrder(Node* node)
{
    if(node == nullptr)
        return;
    printPostOrder(node->left);

    printPostOrder(node->right);
    
    cout << node->data << " ";
}

void BST::printInOrder(Node* node)
{
    stack<Node*> temp;
    Node* curr = node;

    while(curr != nullptr || temp.empty() == false){
        while(curr != nullptr){
            temp.push(curr);
            curr = curr->left;
        }
        curr = temp.top();
        temp.pop();
        cout << curr->data << " ";

        curr = curr->right;
    }

}

int BST::countLeafs(Node* node)
{
    if(node == nullptr){
        return 0;
    }
    if(node->left == nullptr && node->right == nullptr)
        return 1;
    else
        return countLeafs(node->left) + countLeafs(node->right);
}

