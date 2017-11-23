/*
 * Ouriel Gotesdyner
 * gotesdo
 * 305554834
 */

#ifndef EX1_BOARD_H
#define EX1_BOARD_H
enum Side {WHITE, BLACK, EMPTY};

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
    /*******************
     * destructor.
     ****************/
    ~Board();

    /****************************
     * Function name : getter functions : getCol/ getRow / getBoard
     * @return col number / row number / 2D playBoard.
     ******************************/
    int getCol() const;
    int getRow() const;
    Side** getBoard();
private:
    //board information is saved in a 2D array of chars.
    Side** playBoard;

    int row;
    int col;
};


#endif //EX1_BOARD_H
