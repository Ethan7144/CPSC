#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <pthread.h>
#include <stdlib.h>


using namespace std;
int g = 5;
int h = 9;

int foo(int &x, int &y, int z){
    int a = x + y + z;
    if (a >0){
        int f = x + y;
        int g = y + z;
        if (f>g){
            x++;
            cout << x << " " << y << " " << z << " " << g << " " << h << endl;
            cout << "Point A" << endl;
        }
    }
    y += 2;
    h += 3;
    return a;
}
int i = 5;
int main(){
    int r = 10;
    int s = foo(r,i,h);
    return 0;

}

