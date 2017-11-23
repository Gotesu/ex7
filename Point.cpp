/*
 * Ouriel Gotesdyner
 * gotesdo
 * 305554834
 */
#include "Point.h"

Point::Point(int r, int c):r(r), c(c){}
int Point::getR() const {return r;}
int Point::getC() const {return c;}

void Point::pPrint() const {
    cout << "(" << r + 1 << ", " << c + 1 << ")";
}

bool Point::isEqual(Point *p2) {
    if (p2->getC() == c && p2->getR() == r) {
        return true;
    }
    return false;
}

