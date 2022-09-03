// Ethan Tarlov
// wgrep.cpp

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


using namespace std;

const int SIZE = 100;

static bool matching(const string& text, const string& pattern)
{
    return string::npos != text.find(pattern);
}

int main(int argc, char const *argv[]) {
    char buff[SIZE];

    if (argc < 2) {
        printf("wgrep: Searchterm file[...]\n");
        return 1;
    }

    for (int i = 2; i < (argc < 3 ? 3 : argc); i++) {
        FILE *file;
        if (i == 2 && argc <= 2) {
            file = stdin;
        } else {
            file = fopen(argv[i], "r");
        }
        if (file == NULL) {
            printf("wgrep: File cannot be opened.");
            return 1;
        }
        while (fgets(buff, SIZE, file)) {
            if (matching(buff, argv[1]))
                printf("%s", buff);
        }
        printf("\n");
        fclose(file);
    }
}