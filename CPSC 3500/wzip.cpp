// Ethan Tarlov
// wzip.cpp

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


using namespace std;

const int SIZE = 100;


int main(int argc, char const *argv[]){
    char buff[SIZE];
    //int count = 0;
    if(argc == 1){
        printf("wzip: file1[file2...]\n");
        return 1;
    }

    for (int i = 1; i < argc; i++){
        FILE *pf = fopen(argv[i], "r");
        if(pf == NULL) { 
            printf("wzip: File cannot be zipped\n");
            return 1;
        }

        char curr;
        int count = -1;
        while(fgets(buff,SIZE,pf)){
            for(unsigned int i = 0; i < strlen(buff); i++){
                if(count < 0){
                    curr = buff[i];
                    count = 0;
                } else if (curr != buff[i]){
                    cout.write((char*) &count, sizeof(int));
                    cout.write((char*) &curr, sizeof(char));
                    curr = buff[i];
                    count = 0;
                }
                count++;
            }
            if(count > 0) {
                cout.write((char*) &count, sizeof(int));
                cout.write((char*) &curr, sizeof(char));
            }
        }
        fclose(pf);
    }
}