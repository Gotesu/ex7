
#include "Board.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Board::Board(int row, int col): row(row), col(col){
    int i,j;
    try {
        playBoard = new Side *[row];
        for (i = 0; i < row; i++) {
            playBoard[i] = new Side[col];
        }
    }catch(exception e1) {
        cout << "Failed allocating memory"<<endl;
        exit;
    }
    //first we will set all array slots as EMPTY (empty slots will be
    // represented as ' ' to maintain the board's shape.
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            playBoard[i][j] = EMPTY;
        }
    }
    playBoard[row/2 - 1][col/2 - 1] = WHITE;
    playBoard[row/2][col/2] = WHITE;
    playBoard[row/2 - 1][col/2] = BLACK;
    playBoard[row/2][col/2 - 1] = BLACK;
}

int Board::getRow() const {
    return row;
}
int Board::getCol() const {
    return col;
}
Side** Board::getBoard() {
    return playBoard;
}

Board::~Board() {
    for (int i = 0; i < row; i++) {
        delete playBoard[i];
    }
    delete playBoard;
}

