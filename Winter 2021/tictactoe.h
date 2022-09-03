//Ethan Tarlov
// tictactoe.h

#ifndef TICTACTOE_h
#define TICTACTOE_h

#include <iostream>
#include <iomanip>

using namespace std;


class TicTacToe
{
private:
    char **board;
    static const int SIZE = 3;
    static const char SPACE = ' ';
    static const char VERT = '|';
    static const char HOR = '-';
    static const char X = 'X';
    static const char O = 'O';
    int xwin;
    int owin;
public:
    TicTacToe();
    TicTacToe(const TicTacToe& t); // copy
    TicTacToe& operator = (const TicTacToe& p); // overload
    void displayBoard();
    // display board
    bool assignMove(char move, int r, int c);
    // places X's and O's on board
    bool checkWins();
    // returns 0 if ties
    // returns 1 if one if the winner wins
    void resetGame(); // set empty board
    void gameStatus();
    ~TicTacToe(); // destructor
};

#endif // TicTacToe_h