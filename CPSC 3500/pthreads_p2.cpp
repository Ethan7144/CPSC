//
// Created by Matthew Thayer on 1/13/22.
//

/*
 @file: pthreads_skeleton.cpp

 @author: student name1, student2@uncc.edu
 @author: student name2, student2@uncc.edu
 @author: student name3, student3@uncc.edu

 @description: A program that demonstrates processes.

 @course: CPSC 3500
 @assignment: in-class activity [n]
 */

#include <pthread.h>
#include <iostream>

using namespace std;


int Array[10];
// This function shows the skeleton that pthread
// functions must adhere to.
// Copy this skeleton for any pthread function
// you need to define.
// In the copy, modify the name of the function
// and the function body as needed.
void *routineName(void *arg)
{
    // TODO: Add code that implements
    //       the thread's functionality
    cout << "Thread is running..." << endl;
    return 0;
}

void *countNegatives(void *arg)
{
    int Neg = 0;
    for(int i = 0; i < 10; i++){
        if(Array[i] < 0)
           Neg++;
    }
    cout << "The number of neg nums is " << Neg << endl;
    return 0;
}

void *average(void *arg)
{
    int avg = 0;
    int sum = 0;
    for(int i = 0; i < 10; i++) {
        sum += Array[i];
    }
    avg = sum/10;
    cout << "The average is " << avg << endl;
    return 0;
}

void *reverse(void *arg)
{
    for(int i = 10-1; i > -1; i--){
        cout << Array[i] << endl;
    }
    return 0;
}

int main()
{
    // id is used to store a unique thread identifier,
    // returned by the call to create a new POSIX thread
    pthread_t id;
    pthread_t count;
    pthread_t avg;
    pthread_t rev;
    // rc is used to store the code returned by the
    // call to create a new POSIX thread. The value is
    // zero (0) if the call succeeds.
    int rc, rc1, rc2, rc3;


    // TODO: Add code to perform any needed initialization
    //       or to process user input


    int input;
    for(int i = 0; i < 10; i++){
        cin >> input;
        Array[i] = input;
    }

    // Create thread(s)
    // TODO: Modify according to assignment requirements
    rc = pthread_create(&id, NULL, routineName, NULL);
    rc1 = pthread_create(&count, NULL, countNegatives, NULL);
    rc2 = pthread_create(&avg, NULL, average, NULL);
    rc3 = pthread_create(&rev, NULL, reverse, NULL);

    if (rc){
        cout << "ERROR; return code from pthread_create() is " << rc << endl;
        return -1;
    }
    if (rc1){
        cout << "ERROR; return code from pthread_create() is 1 " << rc << endl;
        return -1;
    }
    if (rc2){
        cout << "ERROR; return code from pthread_create() is 2 " << rc << endl;
        return -1;
    }
    if (rc3){
        cout << "ERROR; return code from pthread_create() is 3 " << rc << endl;
        return -1;
    

    // NOTE: Using exit here will immediately end execution of all threads
    pthread_exit(0);
}


