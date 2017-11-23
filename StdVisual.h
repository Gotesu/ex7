/*
 * Ouriel Gotesdyner
 * gotesdo
 * 305554834
 */

#ifndef EX2_STDVISUAL_H
#define EX2_STDVISUAL_H

#include "Visual.h"
#include <iostream>
/***********************
 * StdVisual is a visual derived class that represents
 * the board using the usual terminal output.
 */
class StdVisual: public Visual {
public:
    //constructor.
    StdVisual(Board* b);
    /*************************
 * Function name: printBoard
 * Arguments : none.
 * Output : prints the Board with a nice look on terminal.
 * Operation : using loops to print line and columns of dividers and prints the board info
 *          inbetween them.
 ***************************/
    virtual void printBoard();
private:
    Board* b;
    /************************
     * Function name : sideRepresentation
     * used in order to translate the enum into the appropriate char.
     * @return 'X' for BLACK, 'O' for WHITE and ' ' for EMPTY
     */
    char sideRepresentation(Side);
};


#endif //EX2_STDVISUAL_H
