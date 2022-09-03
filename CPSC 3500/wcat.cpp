// Ethan Tarlov
// wcat.cpp

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


using namespace std;

const int SIZE = 100;

int main(int argc, char const *argv[]){
    char buff[SIZE];
    if(argc == 1){
        printf("wcat: file[...]\n");
        return 1;
    }

    for (int i = 1; i < argc; i++){
        FILE *pf = fopen(argv[i], "r");
        if(pf == NULL) { 
            printf("wcat: File cannot be opened\n");
            return 1;
        }
        while (fgets(buff,SIZE,pf)){
            printf("%s", buff);
        }
        printf("\n");
        fclose(pf);
    }
    return 0;
}