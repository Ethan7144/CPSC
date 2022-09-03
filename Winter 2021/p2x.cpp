// Ethan Tarlov
// 2/15/21
// p2x.cpp


// Purpose: Focues on C++ Classes and 2 D arrays
// description: plays a tic tac toe game
// will ask for a move, and keep going until
// someone wins

#include "tictactoex.h"
#include <iostream>
#include <iomanip>

using namespace std;
 
const char YES = 'y'; // answer to keep playing
static const char X = 'X'; // marker for p1
static const char O = 'O'; // marker for p2
int row; // variable for rows
int col; // variable for col

int main()
{   
    TicTacToe game;
    char ans = YES;
    int numMoves = 0;
    bool player1Turn = true;
    int sizeCheck;
    cout << "Insert the size you input again";
    cin >> sizeCheck; // this is for the max num of turns there can be
    for(int i = 0; i < 25; i++){
        cout << endl;
    }

    cout << "Welcome to TicTacToe!" << endl;
    cout << "There are currently 9 places on the board" << endl;
    cout << "Player 1 will be 'X' and Player 2 will be 'O' " << endl;
    cout << "The game will end when somebody gets 3 in a row " << endl;
    cout << "Either in a column, row, or diagnol" << endl;
    cout << "Good luck and have fun!" << endl;
    cout << "Hit enter to continue";
    cin.get();
    

    while(tolower(ans) == YES){
        while(numMoves < sizeCheck * sizeCheck && !game.checkWins(row, col)){
            game.displayBoard();
            if(player1Turn){
                cout << "It's player 1's turn." << endl;
                cout << "Enter row number: ";
                cin >> row;
                cout << endl;
                cout << "Enter column number: ";
                cin >> col;
                game.assignMove(X, row, col);
                player1Turn = false;
                numMoves++;
            } else {
                cout << "It's player 2's turn." << endl;
                cout << "Enter row number: ";
                cin >> row;
                cout << endl;
                cout << "Enter column number: ";
                cin >> col;
                game.assignMove(O, row, col);
                player1Turn = true;
                numMoves++;
            }
        }
        if(numMoves == sizeCheck * sizeCheck){
            cout << "The game was a tie!" << endl;
            numMoves = 0;
        }
        game.gameStatus();
        cout << "Would you like to play again? (y/n)";
        cin >> ans;
        player1Turn = true;
        numMoves = 0;
        game.resetGame();
    }
    cout << endl;
    cout << "Thank you for playing!" << endl;
    cout << endl << endl;

    return 0;
}