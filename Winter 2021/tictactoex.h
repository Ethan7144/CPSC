//Ethan Tarlov
// tictactoex.h

#ifndef TICTACTOEX_h
#define TICTACTOEX_h

#include <iostream>
#include <iomanip>

using namespace std;


class TicTacToe
{
private:
    char **board;
    static const int MIN_SIZE = 3;
    static const int MAX_SIZE = 20;
    static const char SPACE = ' ';
    static const char VERT = '|';
    static const char HOR = '-';
    static const char X = 'X';
    static const char O = 'O';
    int xwin;
    int owin;
    int SIZE;
public:
    TicTacToe();
    TicTacToe(const TicTacToe& t); // copy
    TicTacToe& operator = (const TicTacToe& p); // overload
    void displayBoard();
    // display board
    bool assignMove(char move, int r, int c);
    // places X's and O's on board
    bool checkWins(int r, int c);
    // returns 0 if ties
    // returns 1 if one if the winner wins
    void resetGame(); // set empty board
    void gameStatus();
    ~TicTacToe(); // destructor
};

#endif // TicTacToex_h