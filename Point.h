/*
 * Ouriel Gotesdyner
 * gotesdo
 * 305554834
 */
#ifndef EX2_POINT_H
#define EX2_POINT_H
#include <iostream>
using namespace std;
/****************
 * class Point objective is just to be a more human readable representation of a position in our board
 * which I made analogic with row and col axis' ( I defined it as a point in space just for
 * convenience).
 */
class Point {
public:
    /***************
     * Constructor
     * @param x row value.
     * @param y col value.
     */
    Point(int x, int y);
    /****************
     * getters : getX/getY
     * @return x/y values.
     */
    int getR() const;
    int getC() const;
    /************************
     * Function name : pPrint
     * prints the point in a conventional way (row,col).
     **********************/
    void pPrint() const;
    /************************
     * Function name : isEqual
     * boolean if second point equal this, compared r to r and c to c.
     **********************/
    bool isEqual(Point* p2);
private:
    int r;
    int c;
};


#endif //EX2_POINT_H
