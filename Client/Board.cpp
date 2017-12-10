#include "Board.h"
#include <cstdlib>

using namespace std;

Board::Board(int row, int col): row(row), col(col){
    int i,j;
    try {
        playBoard = new Side *[row];
        for (i = 0; i < row; i++) {
            playBoard[i] = new Side[col];
        }
    }catch(exception& e1) {
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

Board::Board(const Board& obj): row(obj.getRow()), col(obj.getCol()){
    int i,j;
    try {
        playBoard = new Side *[row];
        for (i = 0; i < row; i++) {
            playBoard[i] = new Side[col];
        }
    }catch(exception& e1) {
        cout << "Failed allocating memory"<<endl;
        exit;
    }
    //copy every place from the given board
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            this->playBoard[i][j] = obj.get(i, j);
        }
    }
}

Side Board::get(int row, int col) const {
	return this->playBoard[row][col];
}

int Board::getRow() const {
    return row;
}
int Board::getCol() const {
    return col;
}

void Board::set(int row, int col, Side s) {
	if ((row >= 0) && (row < this->row) &&
			(col >= 0) && (col < this->col))
		playBoard[row][col] = s;
}

Board::~Board() {
    for (int i = 0; i < row; i++) {
        delete playBoard[i];
    }
    delete playBoard;
}

void Board::update(Side s, Move *choice) {
	int i = choice->getR(), j = choice->getC();
	// change the chosen place
	playBoard[i][j] = s;
	// change the up direction
	for (int r = 1; r <= choice->getDir(up); r++) {
		playBoard[i - r][j] = s;
	}
	// change the down direction
	for (int r = 1; r <= choice->getDir(down); r++) {
		playBoard[i + r][j] = s;
	}
	// change the right direction
	for (int r = 1; r <= choice->getDir(righ); r++) {
		playBoard[i][j + r] = s;
	}
	// change the left direction
	for (int r = 1; r <= choice->getDir(lef); r++) {
		playBoard[i][j - r] = s;
	}
	// change the up-right direction
	for (int r = 1; r <= choice->getDir(upright); r++) {
		playBoard[i - r][j + r] = s;
	}
	// change the up-left direction
	for (int r = 1; r <= choice->getDir(upleft); r++) {
		playBoard[i - r][j - r] = s;
	}
	// change the down-right direction
	for (int r = 1; r <= choice->getDir(downright); r++) {
		playBoard[i + r][j + r] = s;
	}
	// change the down-left direction
	for (int r = 1; r <= choice->getDir(downleft); r++) {
		playBoard[i + r][j - r] = s;
	}
}
