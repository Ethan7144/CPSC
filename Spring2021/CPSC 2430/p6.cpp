// Ethan Tarlov
// p6.cpp

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <stack>

using namespace std;

void print(stack<int> &s, int& count);
// prints the stack
void remove(stack<int> &s);
// removes 5s from the stack
void primeRemove(stack<int> &s);
// remove primes if they are in between an odd and even number
bool isPrime(int y);
// checks if the num is prime


const int MAX = 1000;
int main()
{
    stack<int> stack;
    srand(time(0));
    int count = 1;
    int insertNum = 0;
    // step 1 and step 2

    for(int i = 0; i < MAX; i++){
        insertNum = (rand() % 100 + 1);
        stack.push(insertNum);
    }

    // step 3

    print(stack,count);
    count = 1;
    // step 4
    remove(stack);
    cout << endl << endl;
    print(stack, count);

    // step 5

    for(int i = 0; i <= 10; i++){
        primeRemove(stack);
        count = 1;
        print(stack,count);
        cout << endl << endl;
    }
}


void print(stack<int> &s, int& count)
{
    if(s.empty()){
        cout << endl;
        return;
    }
    int x = s.top();
    s.pop();
    print(s,count);
    s.push(x);
    if(count % 5 == 0){
        cout << x << endl;
    }
    else{
        cout << x << " ";
    }
    count++;
}

void remove(stack<int> &s)
{
    if(s.empty()){
        return;
    }
    int x = s.top();
    s.pop();
    remove(s);
    if(x % 5 != 0){
        s.push(x);
    }
}

void primeRemove(stack<int> &s){

 if(s.empty()){
        return;
    }
    int x = s.top();
    s.pop();
    if(s.empty()){
        s.push(x);
        return;
    }
    int y = s.top();
    s.pop();
    if(s.empty()){
        s.push(y);
        s.push(x);
        return;
    }
    int z = s.top();
    s.pop();
    primeRemove(s);
    if((x % 2 == 0 && z % 2 == 1) || (x % 2 == 1 && z % 2 == 0)){
        if(isPrime(y)){ // checks if it is prime to remove it
            s.push(z);
            s.push(x);
        }
        else{
            s.push(z);
            s.push(y);
            s.push(x);
        }
    }

}

bool isPrime(int y)
{
    if(y <= 1)
        return false;

        for(int i = 2; i < y; i++)
            if(y % i == 0)
                return false;
    return true;
}