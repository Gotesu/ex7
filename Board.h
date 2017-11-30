#ifndef BOARD_H
#define BOARD_H

#include "Move.h"

enum Side {WHITE = -1, EMPTY = 0, BLACK = 1};

/*****************************
 * class name : Board.
 * this class is a reversi game board which holds the game.
 ******************************/
class Board {
public:
    /***************************
     * Function name : Board
     * Arguments: row and col counts
     * The Function operation : builder. allocates the reversi board according
     * to user's choice or rows and columns count. set's all the slots as ' '
     * except for the central four.
     ***************************/
    Board(int row = 8, int col = 8);
    /***************************
     * Function name : Board()
     * Arguments: a Board refrence
     * The Function operation : a copy-constructor. allocates the reversi board according
     * to the given Board rows and columns value, and copy all the slots.
     ***************************/
    Board(const Board& obj);
    /*******************
     * destructor.
     ****************/
    ~Board();
    /****************************
     * Function name: get(i, j)
     * this is a getter function.
     * @return the value in [i][j].
     ******************************/
    Side get(int row, int col) const;
    /****************************
     * Function name : getter functions : getCol/ getRow / getBoard
     * @return col number / row number / 2D playBoard.
     ******************************/
    int getCol() const;
    int getRow() const;
	/******************************************
	* function name: set()
	* The Input: two numbers, for row and column, and new Side value.
	* The function operation: this is a setter function for playBoard[row][col].
	******************************************/
    void set(int row, int col, Side s);
    /***********************
     * Function name: update
     * @param s the side
     * @param choice the Move of choice
     * Operation: this function changes the board according
     * the player's chosen move.
     */
    void update(Side s, Move *choice);
private:
    //board information is saved in a 2D array of chars.
    Side** playBoard;

    int row;
    int col;
};


#endif //BOARD_H
