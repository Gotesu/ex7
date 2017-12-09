#include "Move.h"

Move::Move(int r, int c, vector<int> dir): r(r), c(c), dir(dir) {}

int Move::getR() const {return r;}

int Move::getC() const {return c;}

int Move::getDir(int i) {
	if ((i < dir.size()) && (i >= 0))
		return dir[i];
	return -1;
};

void Move::pMove() const {
    cout << "(" << r + 1 << ", " << c + 1 << ")";
}

bool Move::isEqual(int r2, int c2) {
    if ((c2 == c) && (r2 == r)) {
        return true;
    }
    return false;
}

bool Move::isEqual(Move * m2) {
    if ((m2->getC() == c) && (m2->getR() == r)) {
        return true;
    }
    return false;
}
