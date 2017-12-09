#ifndef VISUAL_H
#define VISUAL_H

#include "Board.h"
class Visual {
public:
    //constructor.
    Visual(Board* b):b(b){};
    //destroyer
    virtual ~Visual(){};
    /**********************
     * printBoard
     * Operation : represents the board visually.
     **********************/
    virtual void printBoard(){};
private:
    Board* b;
};


#endif //VISUAL_H
