#include "StdVisual.h"
using namespace std;
StdVisual::StdVisual(Board* b) : Visual(b) , b(b) {
}

char StdVisual::sideRepresentation(Side s) {
    switch(s) {
        case EMPTY : return ' ';
        case WHITE : return 'O';
        case BLACK : return 'X';
        default: return 'E';
    }
}

void StdVisual::printBoard() {
    int row = b->getRow();
    int col = b->getCol();
    int i,j;
    //leftmost slot is empty.
    cout << " " << "|";
    //row of column number loop.
    for(i = 0; i < row; i++) {
        cout << " " << i+1 << " " << "|";
    }
    cout << endl;
    //board filling.
    for(i = 0; i < row; i++) {
        //distinction between rows.
        for (j = 0; j < col - 1; j++) {
            cout << "-----";
        }
        cout << endl;
        //slot information and row number loop.
        for (j = 0; j <= col; j++) {
            //row number column
            if (j == 0){
                cout << i + 1 << "|";
            }//slot information
            else {
                cout << " " << sideRepresentation(b->check(i, j - 1)) << " " << "|" ;
            }
        }
        cout << endl;
    }
}
