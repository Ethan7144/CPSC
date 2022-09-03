// Ethan Tarlov
// hangman.h
// 1/27/21
// header file of the hangman class

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;

#ifndef HANGMAN_H
#define HANGMAN_H

class Hangman
{
    public:
    Hangman();

    bool initializeFile(string filename);
    // initializes the file to run to program
    // will end if the file fails
    
    bool newWord();
    // chooses a new word

    void displayGame();
    // displays the gameboard including letters, spaces,
    // and avilable letters

    bool guess(char letter, bool& done, bool& won);
    // processes the user's guess
    // true if correct or no more guesses
    // won returns true if word has been guessed

    void displayStatistics();
    // displays wins, losses and remaining words

    void revealWord();
    // shows the word for the round

    private:
    static const int LIST_SIZE = 100;
    static const int BODY_SIZE = 9;
    static const int ALPHA_SIZE = 26;
    static const char UNDERSCORE = '_';
    static const char SPACE = ' ';
    static const char BEGIN = 'A';
    static const int SCREEN_WIDTH = 80;
    static const int MAX_WRONG_GUESSES = 7;
    static const int HEAD = 1;
    static const int NECK = 2;
    static const int LT_ARM = 3;
    static const int RT_ARM = 4;
    static const int TORSO = 5;
    static const int LT_LEG = 6;
    static const int RT_LEG = 7;

    struct BodyPart{
        string firstLine;
        string secondLine;
        string thirdLine;
        bool displaySecond;
        bool displayThird;
    };

    struct WordList{
        string word;
        bool used;
    };

    struct AlphaList{
        char letter;
        bool used;
    };

    WordList list[LIST_SIZE];
    BodyPart body[BODY_SIZE];
    AlphaList alphabet[ALPHA_SIZE];
    int currentWord; // index of current word
    int totalWords; // number of words in file
    int wins; // number of words guesses
    int losses; // number of words played
    unsigned correctChars; // number of chars guesses correctly
    unsigned badGuesses; // number of bad guesses

    void displayBody();
    // displays body

    void displayWord();
    // displays word with blanks and guesses letters

    void displayAlpha();
    // displays available letters

};

#endif