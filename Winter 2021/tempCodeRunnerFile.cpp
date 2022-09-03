// Ethan Tarlov
// hangman.cpp
// 1/27/21
// Implementation of hangman.h

#include "hangman.h"

Hangman::Hangman()
{
    body[0].firstLine = "   ----\n";
    body[1].firstLine = "   |  |\n";
    body[2].firstLine = "      |\n";
    body[2].secondLine = "   O   |\n";
    body[3].firstLine = "      |\n";
    body[3].secondLine = "   |   |\n";
    body[4].firstLine = "      |\n";
    body[4].secondLine = "  -|   |\n";
    body[4].thirdLine = "  -|- |\n";
    body[5].firstLine = "      |\n";
    body[5].secondLine = "   |   |\n";
    body[6].firstLine = "      |\n";
    body[6].secondLine = "  /    |\n";
    body[6].thirdLine = "  / \\ |\n";
    body[7].firstLine = "      |\n";
    body[8].firstLine = "______|____\n";

    for(int i = 0; i < BODY_SIZE; i++){
        body[i].displaySecond = false;
        body[i].displayThird = false;
    }
    char letter = BEGIN;
    for(int i = 0; i < ALPHA_SIZE; i++){
        alphabet[i].letter = letter;
        letter++;
        alphabet[i].used = false;
    }

    currentWord = -1;
    totalWords = 0;
    wins = 0;
    losses = 0;
    correctChars = 0;
    badGuesses = 0;

    srand(time(0)); // this is to set rand()

}

bool Hangman::initializeFile(string filename)
{
    ifstream inFile;

    inFile.open(filename);

    if(inFile.fail())
        return false;

    while(inFile >> list[totalWords].word){
        list[totalWords].used = false;
        totalWords++;
    }
    inFile.close();
    return true;
}

bool Hangman::newWord()
{
    return true;
}
// haven't figured this out yet, will do it later

void Hangman::displayGame()
{
    displayBody();
    cout << endl << endl;
    displayWord();
    cout << endl << endl;
    displayAlpha();
    cout << endl << endl;
}

bool Hangman::guess(char letter, bool& done, bool& won)
{
    int letterPosition = toupper(letter) - BEGIN;
    unsigned correctCount = 0;

    if(isalpha(letter))
        return false;
        // this checks if the guess is even a letter

    letter = toupper(letter);
    // will force the letter to uppercase to read it due to
    // all letters being displayed in uppercase

    if(alphabet[letterPosition].used)
        return false;
    // checks if letter has been used before
    
    alphabet[letterPosition].used = true;

    for(unsigned i = 0; i < list[currentWord].word.length(); i++)
        if(list[currentWord].word.at(i) == letter)
            correctCount++;
        // checks if the letter put in is valid at any position
    if(correctCount == 0)
        badGuesses++;
    else
        correctChars += correctCount;
        
    if(correctChars == list[currentWord].word.length()){
        done = true;
        won = true;
        wins++;
    }
    // this checks to see if the word is correct, if it is
    // it will add a win to the current wins
    if(badGuesses == MAX_WRONG_GUESSES){
        done = true;
        losses++;
    }
    // excact same thing as earlier, just now checks if you lost

    if (badGuesses == 1)
        body[2].displaySecond = true;
    else if (badGuesses == 2)
        body[3].displaySecond = true;
    else if (badGuesses == 3)
        body[4].displaySecond = true;
    else if (badGuesses == 4)
        body[4].displayThird = true;
    else if (badGuesses == 5)
        body[5].displaySecond = true;
    else if (badGuesses == 6)
        body[6].displaySecond = true;
    else if (badGuesses == 7)
        body[6].displayThird = true;
    // will add body parts if badguesses are added up.

    return true;    
    
}

void Hangman::displayStatistics()
{
    int remainingWords = 0;

    for(int i = 0; i < totalWords; i++)
        if(!list[i].used)
            remainingWords++;
    
    cout << "Total Words: " << totalWords << endl;
    cout << "Words still available: " << remainingWords << endl;
    cout << "Wins: " << wins << endl;
    cout << "Losses: " << losses << endl;

}

void Hangman::displayBody()
{
    int spaces = (SCREEN_WIDTH - body[8].firstLine.length())/2;

    for (int i = 0; i < BODY_SIZE; i++){
        
        for (int j = 0; j < spaces; j++)
            cout << SPACE;
        if(body[i].displayThird == true)
            cout << body[i].thirdLine;
        else if(body[i].displaySecond == true)
            cout << body[i].secondLine;
        else
            cout << body[i].firstLine;
    }
}

void Hangman::displayAlpha()
{
    int spaces = (SCREEN_WIDTH - (ALPHA_SIZE * 2 - 1))/2;

    for (int i = 0; i < spaces; i++)
            cout << SPACE;

    for(int i = 0; i < ALPHA_SIZE; i++){
        if(!alphabet[i].used){
            cout << alphabet[i].letter << SPACE;
        }else
            cout << SPACE << SPACE;
    }
}

void Hangman::revealWord()
{
    int spaces = (SCREEN_WIDTH - (list[currentWord].word.length() * 2))/2;

    for (int i = 0; i < spaces; i++)
            cout << SPACE;
    
    for(unsigned i = 0; i < list[currentWord].word.length(); i++)
        cout << list[currentWord].word.at(i) << SPACE;
    
    cout << endl;
}

void Hangman::displayWord()
{
    int spaces = (SCREEN_WIDTH - (list[currentWord].word.length() * 2))/2;

    for (int i = 0; i < spaces; i++)
            cout << SPACE;
    
    for (unsigned i = 0; i < list[currentWord].word.length(); i++){
        if (alphabet[list[currentWord].word.at(i) - BEGIN].used)
            cout << list[currentWord].word.at(i) << SPACE;
        else 
            cout << UNDERSCORE << SPACE;
    }
}
