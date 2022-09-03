// Ethan Tarlov
// wunzip.cpp

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


using namespace std;

const int SIZE = 100;


int main(int argc, char const *argv[]){
    char buff[SIZE];
    int count = 0;
    char c;
    if(argc == 1){
        printf("wunzip: file1[file2...]\n");
        return 1;
    }

    for (int i = 1; i < argc; i++){
        ifstream infile;
        infile.open(argv[i]);
        if(infile.fail()) { 
            printf("wunzip: File cannot be opened\n");
            return 1;
        }
        while(!infile.fail()){
            infile.read((char*) &count, sizeof(int));
            infile.read(&c, sizeof(char));

            for(int j = 0; j < count && !infile.fail(); j++){
                cout << c;
            }
        }
    }
}
