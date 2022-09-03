// Ethan Tarlov
// p5.cpp

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

struct HNode{
    string word;
    int count;
    HNode* next;
};

string beforeProcess(string word);
// returns the word w/ punctuation removed

unsigned hashFunction(string word, int tableSize);
// returns the index for hash table
// I got this from Reeders lecture, so its based on BKDRHash by Kernighan and
// Ritchie

int store(int key, HNode* htable[], string word);
// returns num of collisions

int checkCount(string word, HNode* htable);

int storeCheck(int key, HNode* htable, string word);

int countUnique(HNode htable);

const unsigned MIN_WORD = 5;
const int MAX = 33827; // the min is 23570
const string FILE_NAME = "ulyss12.txt";

int main()
{
    HNode* table[MAX];
    int tableSize = 0;
    ifstream file;
    int key;
    int colCount = 0;
    string newWord;
    int unique = 0;

    file.open(FILE_NAME);

    if(file.fail()){
        cout << "The File failed to open";
        return 0;
    }
    while(file >> table[tableSize]->word){
        newWord = beforeProcess(table[tableSize]->word);
        key = hashFunction(newWord, MAX);
        colCount += store(key, table, newWord);
        tableSize++;
    }
    unique = countUnique(table);

    file.close();

    cout << "The total number of Unique words is: " << unique << endl;
    cout << "The total number of collisions is: " << colCount << endl;
    cout << "The total number of words is: " << tableSize << endl;
    cout << "The load factor of the table is: " << unique/tableSize << endl;



}

unsigned hashFunction(string word, int tableSize)
{
    unsigned seed = 1313131313;
    unsigned key = 0;

    for(unsigned i = 0; i < word.length(); i++){
            key = (key * seed) + word[i];
    }
    key = key % tableSize;

    return key;
}

int store(int key, HNode* htable[], string word)
{
    int collisions = 0;
    int check = storeCheck(key,htable,word);
    switch(check){
        case 0:
        {
            HNode* temp = new HNode;
            temp->word = word;
            temp->count = 1;
            htable[key] = temp;
            collisions = 0;
            break;
        }
        case 1:
        {
            //Handled by storeCheck
            collisions = 0;
            break;
        }
        case 2:
        {
            HNode* trav = htable;
            HNode* temp2 = new HNode;
            temp2->word = word;
            temp2->count = 1;
            temp2->next = htable[key];
            htable[key] = temp2;
            while(trav != nullptr){
                collisions++;
                trav = trav->next;
            }
            break;
        }
        default: 
        {
            break;
        }
    }
    return collisions;
}  

int checkCount(string word, HNode* htable)
{
    int count = 0;
    while(htable != nullptr){
        if(word == htable->word)
        count = htable->count;
        htable = htable->next;
    }
    return count;
}

string beforeProcess(string word)
{
    if(word.size() < MIN_WORD){
        return "";
    }
    for(int i = 0; i < word.size(); i++){
        if(ispunct(word[i]))
        {
            word.erase(i--, 1);
        }
    }
    return word;
}

int storeCheck(int key, HNode* htable, string word)
{
    HNode* temp = htable[key];
    if(htable[key] == nullptr)
        return 0;
    while(temp != nullptr){
        if(temp->word == word){
            temp->count++;
            return 1;
        }
        temp = temp->next;
    }
    return 2;
}

int countUnique(HNode htable)
{
    count = 0;
    HNode* trav;
    for(int i = 0; i < MAX; i++){
        if(htable[i] != nullptr){
            count++;
            trav = htable[i];
            while(trav->next != nullptr){
                count++;
                trav = trav->next;
            }
        }
    }
    return count;
}