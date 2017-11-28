#ifndef EX2_VISUAL_H
#define EX2_VISUAL_H

#include "Board.h"
class Visual {
public:
    //constructor.
    Visual(Board* b);
    //destroyer
    ~Visual(){};
    /**********************
     * printBoard
     * Operation : represents the board visually.
     **********************/
    virtual void printBoard(){};
private:
    Board* b;
};


#endif //EX2_VISUAL_H
