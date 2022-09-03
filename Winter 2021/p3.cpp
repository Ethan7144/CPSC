#include <iostream>
#include "Queue.h"
#include "Stack.h"

using namespace std;

int main()
{
    int value;
    int grabInt;
    Stack list;
    Queue list3;

    cout << endl << endl;

    cout << "Starting on stacks first" << endl;
    cout << "Will begin adding ints to the stacks" << endl;
    cout << "Hit enter to start";
    cin.get();

    value = 1;
    // Start with pushing one stack
    cout << "Pushing..." << endl;
    for(int i = 0; i < 3; i++){
        cout << "Now pushing" << value << endl;
        list.push(value);
        value++;
        cout << endl;
    }
    // Now copying stack 1 to stack 2
    cout << "Pushing complete. Hit enter to continue";
    cin.get();

    cout << "Copying..." << endl;
    Stack list2(list);

    cout << "Copying complete. Hit enter to continue";
    cin.get();

    // resizing the stack
    cout << "Pushing..." << endl;
    for(int i = 0; i < 8; i++){
        cout << "Now pushing" << value << endl;
        list.push(value);
        value++;
        cout << endl;
    }
    cout << "Pushing resize complete. Hit enter to continue";
    cin.get();

    // now popping stacks
    cout << "Popping stack 2..." << endl;
    while(!list2.isEmpty()){
        cout << list2.pop();
        cout << endl;
    }

    cout << "Popping complete. Hit enter to continue";
    cin.get();

    // same thing as popping stack 2
    cout << "Popping stack 1..." << endl;
    while(!list.isEmpty()){
        cout << list.pop();
        cout << endl;
    }

    cout << "Popping complete. Hit enter to continue";
    cin.get();
    // testing the class exception
    cout << "trying to catch EmptyStack exception" << endl;
    try{
        cout << list.pop();
    }
    catch (Stack::EmptyStack){
        cout << "ERROR: Cannot pop from empty stack" << endl;
    }
    cout << endl;

    cout << "Stack is now complete. Hit enter to continue.";
    cin.get();

    cout << "Beginning testing of Queue" << endl;
    
    // start with enQ
    grabInt = 1;
    cout << "Enqueueing..." << endl;
    for(int i = 0; i < 3; i++){
        cout << "Now Queueing " << grabInt << endl;
        list3.enQ(grabInt);
        grabInt++;
        cout << endl;
    }
    cout << "Enqueueing complete. Hit enter to continue.";
    cin.get();

    // copying Queue over
    cout << "Copying..." << endl;
    Queue list4(list3);

    cout << "Copying complete. Hit enter to continue.";
    cin.get();

    // deQ Queue 2

    cout << "Dequeueing Queue 2..." << endl;
    while(!list4.isQEmpty()){
        cout << list4.deQ(value);
}
    cout << "Dequeueing complete. Hit enter to continue.";
    cin.get();

    // deQ Queue 1

    cout << "Dequeueing Queue 1..." << endl;
    while(!list3.isQEmpty()){
        cout << list3.deQ(value);
}
    cout << "Dequeueing complete. Hit enter to continue.";
    cin.get();

// now testing the emptyQueue exception

    cout << "trying to catch EmptyQueue exception" << endl;
    try{
        cout << list3.deQ(value);
    }
    catch (Queue::EmptyQueue){
        cout << "ERROR: Cannot pop from empty queue" << endl;
    }
    cout << endl;

    cout << "Queue is now complete. Thank you for using this program.";
    cout << endl << endl;
}