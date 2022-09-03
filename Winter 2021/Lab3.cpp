//Ethan Tarlov
// Lab3.cpp
//1/13/21

//Purpose: Focuses on Pass by reference
// description: Asks for an input that request 2 strings, and returns them
// Then swaps the strings from string 1 to string 2 
// and then outputs the two strings 

#include <iostream>

using namespace std;

void inputString(string& str1, string& str2);
void swapStr(string& str1, string& str2);
void output(string str1, string str2);

int main()
{
    cout << endl << endl;

    string str1 = "";
    string str2 = "";

    inputString(str1, str2);
    output(str1, str2);
    swapStr(str1, str2);
    output(str1, str2);
    
    cout << endl << endl;
}

void inputString(string& str1, string& str2)
{
    cout << "What would you like string 1 to be? ";
    cin >> str1;
    cout << endl;
    cout << "What would you like string 2 to be? ";
    cin >> str2;
}

void swapStr(string& str1, string& str2)
{
    string temp = str1;
    str1 = str2;
    str2 = temp;
}

void output(string str1, string str2)
{
    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;
}