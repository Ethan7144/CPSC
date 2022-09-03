// Ethan Tarlov
// p3.cpp

#include <iostream>
#include "tree.h"


using namespace std;

int main()
{
    cout << endl << endl;
    BST b = nullptr;
    cout << "Inserting variables into the tree now" << endl;
    b.insert(50);
    b.insert(tree, 60);
    b.insert(tree, 10);
    b.insert(tree, 20);
    b.insert(tree, 30);
    b.insert(tree, 40);
    b.insert(tree, 70);
    b.insert(tree, 80); 
    b.insert(tree, 15);
    b.insert(tree, 32);
    b.insert(tree, 43);
    b.insert(tree, 65);
    b.insert(tree, 21);
    b.insert(tree, 13);
    b.insert(tree, 16);
    b.insert(tree, 54);
    b.insert(tree, 57);
    b.insert(tree, 2);
    b.insert(tree, 5);
    b.insert(tree, 90);
    b.insert(tree, 14);
    b.insert(tree, 12);
    b.insert(tree, 23);
    b.insert(tree, 67);

    cout << "Inserting complete" << endl;
    cout << "Now printing tree in Order" << endl;
    b.printInOrder(tree);
    cout << "Now printing post Order" << endl;
    b.printPostOrder(tree);
    cout << "Now looking for a value of 5" << endl;
    cout << b.searchTree(tree, 5) << endl;
    cout << "Now counting the # of ancestors from 5" << endl;
    b.printAncestors(tree, 5);
    cout << "Now finding the height" << endl;
    cout << b.findHeight(tree) << endl;
    cout << "Now counting leaves" << endl;
    cout << b.countLeafs(tree) << endl;
    cout << "Now copying" << endl;
    BST* Tree3(tree);
    b.printPostOrder(Tree3);
    cout << "Now making equal" << endl;
    BST* tree2 = tree;
    b.printPostOrder(tree2);
    cout << "Complete." << endl;
    cout << endl << endl;
}