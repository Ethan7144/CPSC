// Ethan Tarlov
// p1x.cpp
// 1/28/21
// This is the file that runs the hangman class
// Will play a game of hangman and demostrate that all the 
// functions work properly
// Extra Credit: Running 2 games at once

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
    Hangman secondGame;
    char gameLetter;
    bool gameOver = false;
    bool gameWin = false;
    bool secondGameOver = false;
    bool secondGameWin = false;

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
        }else{
            cout << "The file loaded" << endl << endl;
        }

            // Below is the second game, above is the first game

            if(!secondGame.initializeFile(FILENAME)){
            cout << "Error with the file... exiting program" << endl;
            return 0;
        }else{
            cout << "The file loaded" << endl << endl;
        }

    while(ans == 'y'){
        

        mainGame.displayStatistics();
        cout << endl;
        secondGame.displayStatistics();

        mainGame.newWord();
        secondGame.newWord();

        

        gameOver = false;
        gameWin = false;
        secondGameOver = false;
        secondGameWin = false;

        while(!gameOver && !secondGameOver){
            mainGame.displayGame();
            cout << "Player 1's turn" << endl;
            cout << "What letter do you wish to guess? ";
            cin >> gameLetter;
            mainGame.guess(gameLetter,gameOver,gameWin);
            mainGame.displayGame();
            cout << "Hit enter to continue" << endl;
            cin.get();
            cin.get();
            secondGame.displayGame();

            cout << "Player 2's turn" << endl;
            cout << "What letter do you wish to guess? ";
            cin >> gameLetter;
            secondGame.guess(gameLetter,secondGameOver,secondGameWin);
            secondGame.displayGame();
            cout << "Hit enter to continue" << endl;
            cin.get();
            cin.get();
        }
        if(gameOver && !secondGameOver)
        {
            cout << "Player 1 has finished! (hit enter)" << endl;
            cin.get();
            cout << "Player 2 may finish their game" << endl;
            while(!secondGameOver){
            
            secondGame.displayGame();
            cout << "Player 2's turn" << endl;
            cout << "What letter do you wish to guess? ";
            cin >> gameLetter;
            secondGame.guess(gameLetter,secondGameOver,secondGameWin);
            secondGame.displayGame();
            }
        }
        if(secondGameOver && !gameOver)
        {
            cout << "Player 2 has finished! (hit enter)" << endl;
            cin.get();
            cout << "Player 1 may finish their game" << endl;
            while(!gameOver){
            
            mainGame.displayGame();
            cout << "Player 1's turn" << endl;
            cout << "What letter do you wish to guess? ";
            cin >> gameLetter;
            mainGame.guess(gameLetter,gameOver,gameWin);
            mainGame.displayGame();
            }
        }
        if(gameWin)
            cout << "Player 1 solved their word!" << endl;
        if(secondGameWin)
            cout << "Player 2 has solved their word!" << endl;
        
        cout << "Player 1 word was: ";
        mainGame.revealWord();
        cout << endl;

        cout << "Player 2 word was: " ;
        secondGame.revealWord();
        cout << endl;

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