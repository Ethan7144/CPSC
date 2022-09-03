// Ethan Tarlov
// tictactoe.cpp

#include "tictactoe.h"

TicTacToe::TicTacToe()
{
    board = new char*[SIZE];
    for (int i = 0; i < SIZE; i++){
        board[i] = new char[SIZE];
    }
    
    for(int r = 0; r < SIZE; r++) {
        for(int c = 0; c < SIZE; c++){
            board[r][c] = SPACE;
        }
    }

    xwin = 0;
    owin = 0;
}

TicTacToe::TicTacToe(const TicTacToe& t)
{
    board = new char*[SIZE];
    for(int i = 0; i < SIZE; i++){
        board[i] = new char [SIZE];
    }
    for(int r = 0; r < SIZE; r++){
        for(int c = 0; c < SIZE; c++){
            board[r][c] = t.board[r][c];
        }
    }
}

TicTacToe& TicTacToe::operator = (const TicTacToe& p)
{
    if(this != &p){
        for(int r = 0; r < SIZE; r++){
            for(int c = 0; c < SIZE; c++){
                board[r][c] = p.board[r][c];
            }
        }
    }
    return *this;
}

void TicTacToe::displayBoard()
{
    cout << endl;
    for(int r = 0; r < SIZE; r++){
        for(int c = 0; c < SIZE; c++){
            cout << board[r][c] << VERT;
        }
        cout << endl;
        for(int i = 0; i < SIZE; i++){
            cout << HOR << SPACE;
        }
        cout << endl;
    }
}

bool TicTacToe::assignMove(char move, int r, int c)
{
    if(r < SIZE && r >= 0 && c >= 0 && c < SIZE && board[r][c] == SPACE) {
        board[r][c] = move;
        return true;
    } else {
        return false;
    }
}

bool TicTacToe::checkWins()
{
    for(int i = 0; i < SIZE; i++){
        if(board[i][0] == X && board[i][1] == X && board[i][2] == X){
            xwin++;
            return true;
        } else if(board[i][0] == O && board[i][1] == O && board[i][2] == O){
            owin++;
            return true;
        }
    }

    for(int i = 0; i < SIZE; i++){
        if(board[0][i] == X && board[1][i] == X && board[2][i] == X){
            xwin++;
            return true;
        } else if(board[0][i] == O && board[1][i] == O && board[2][i] == O){
            owin++;
            return true;
        }
    }

    if(board[0][0] == X && board[1][1] == X && board[2][2] == X){
            xwin++;
            return true;
        } else if(board[0][0] == O && board[1][1] == O && board[2][2] == O){
            owin++;
            return true;
        }

    if(board[0][2] == X && board[1][1] == X && board[2][0] == X){
            xwin++;
            return true;
        } else if(board[0][2] == O && board[1][1] == O && board[2][0] == O){
            owin++;
            return true;
        }
    return false;
}


void TicTacToe::resetGame()
{
    for(int r = 0; r < SIZE; r++) {
        for(int c = 0; c < SIZE; c++) {
            board[r][c] = SPACE;
        }
    }
}

void TicTacToe::gameStatus()
{
    xwin--;
    owin--;
    cout << "Player 1 score: " << xwin << endl;
    cout << "Player 2 score: " << owin << endl;
}

TicTacToe::~TicTacToe()
{
    for(int i = 0; i < SIZE; i++){
        delete [] board[i];
    }
    delete [] board;
}