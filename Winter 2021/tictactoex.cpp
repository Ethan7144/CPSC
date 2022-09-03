// Ethan Tarlov
// tictactoe.cpp

#include "tictactoex.h"

TicTacToe::TicTacToe()
{
    cout << "Pick the size of your gameboard (between 3 - 20) ";
    cin >> SIZE;
    cout << endl;
    while(SIZE > MAX_SIZE || SIZE < MIN_SIZE){
        cout << "That num is invalid, please insert a valid number ";
        cin >> SIZE;
        cout << endl;
    }
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

bool TicTacToe::checkWins(int r, int c)
{
    int diagCheckX = 0;
    int antiDiagCheckX = 0;
    int rowCheckX = 0;
    int colCheckX = 0;
    int diagCheckO = 0;
    int antiDiagCheckO = 0;
    int rowCheckO = 0;
    int colCheckO = 0;

    for(int i = 0; i < SIZE; i++){ // check row
        if(board[r][i] == X){
            rowCheckX++;
        }
        if(rowCheckX == SIZE){
            xwin++;
            return true;
        }
        if(board[r][i] == O){
            rowCheckO++;
        }
        if(rowCheckO == SIZE){
            owin++;
            return true;
        }
    }

    for(int i = 0; i < SIZE; i++){ // check col
        if(board[i][c] == X){
            colCheckX++;
        }
        if(colCheckX == SIZE){
            xwin++;
            return true;
        }
        if(board[i][c] == O){
            colCheckO++;
        }
        if(colCheckO == SIZE){
            owin++;
            return true;
        }
    }

    for(int i = 0; i < SIZE; i++){ // diagnol check
        if(board[i][i] == X){
            diagCheckX++;
        }
        if(diagCheckX == SIZE){
            xwin++;
            return true;
        }
        if(board[i][i] == O){
            diagCheckO++;
        }
        if(diagCheckO == SIZE){
            owin++;
            return true;
        }
    }

   for(int i = 0; i < SIZE; i++){ // anti diagnol check
        if(board[i][(SIZE-1)-i] == X){
            antiDiagCheckX++;
        }
        if(antiDiagCheckX == SIZE){
            xwin++;
            return true;
        }
        if(board[i][(SIZE-1)-i] == O){
            antiDiagCheckO++;
        }
        if(antiDiagCheckO == SIZE){
            owin++;
            return true;
        }
    }

    diagCheckX = 0;
    antiDiagCheckX = 0;
    rowCheckX = 0;
    colCheckX = 0;
    diagCheckO = 0;
    antiDiagCheckO = 0;
    rowCheckO = 0;
    colCheckO = 0;
    return false;
}


void TicTacToe::resetGame(int size)
{
    for(int r = 0; r < SIZE; r++) {
        for(int c = 0; c < SIZE; c++) {
            board[r][c] = SPACE;
        }
    }
}

void TicTacToe::gameStatus()
{
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