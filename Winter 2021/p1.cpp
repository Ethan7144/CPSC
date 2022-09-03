// Ethan Tarlov
// p1.cpp
// 1/28/21
// This is the file that runs the hangman class
// Will play a game of hangman and demostrate that all the 
// functions work properly

#include <iostream>
#include <string>
#include <cctype>
#include "hangman.h"
using namespace std;


const string FILENAME = "/home/fac/sreeder/class/cs1430/p1input.dat";

int main()
{

    cout << endl << endl;

    Hangman mainGame;
    char gameLetter;
    bool gameOver = false;
    bool gameWin = false;
    char ans = 'y';

    cout << "Welcome to Hangman!" << endl;
    cout << "This game will be played like a normal hangman game is" << endl;
    cout << "Do you wish to continue? (y/n) ";
    cin >> ans;
    ans = tolower(ans);
    cout << endl;

    while(ans != 'y' && ans != 'n'){
        cout << "Please insert 'y' or 'n' ";
        cin >> ans;
        ans = tolower(ans);
        cout << endl;
    }

    if(ans == 'n'){
        cout << "Thnaks for using the program!" << endl;
        cout << endl << endl;
        return 0;
    }
    if(!mainGame.initializeFile(FILENAME)){
            cout << "Error with the file... exiting program" << endl;
            return 0;
        }else
            cout << "The file loaded" << endl << endl;


    while(ans == 'y'){
        
        mainGame.displayStatistics();

        mainGame.newWord();
        mainGame.displayGame();
        gameOver = false;
        gameWin = false;

        while(!gameOver){
            cout << "What letter do you wish to guess? ";
            cin >> gameLetter;
            mainGame.guess(gameLetter,gameOver,gameWin);
            mainGame.displayGame();
        }
        mainGame.revealWord();
        if(gameWin)
            cout << "Congrats you won!" << endl;

        cout << "Do you wish to keep playing? (y/n) ";
        cin >> ans;
        ans = tolower(ans);
        cout << endl;

        while(ans != 'y' && ans != 'n'){
            cout << "Please insert 'y' or 'n' ";
            cin >> ans;
            ans = tolower(ans);
            cout << endl;
        }

    }
    cout << "Thank you for playing!" << endl;
    cout << endl << endl;
    return 0;
}