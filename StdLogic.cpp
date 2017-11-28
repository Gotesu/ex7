#include "StdLogic.h"
using namespace std;
StdLogic::StdLogic():Logic() {}

vector<Move*> StdLogic::allowedActions(Board* b, Side s) {
    //array of directions symbols.
    char directions[] = {'R','L','D','U','\\','/',',','`'};
    vector<Move*> positions;
    positions = mapPositions(b, s);
    vector<Move*> allowedMoves;
    //we need to check legitimate moves for each piece.
    for (int k = 0; k < positions.size(); k++) {
        for (int i = 0; i < 8; i++) {
            Move *pos = findPossibility(positions[k], b, s, directions[i]);
            //making sure we are not putting a Move which is already there.
            if (pos != 0 && isANewOne(allowedMoves, pos)) {
                allowedMoves.push_back(pos);
            }
        }
    }
    //freeing the positions vector.
    for (int j = 0; j < positions.size(); j++) {
        delete positions[j];
    }
    positions.clear();
    return allowedMoves;
}

std::vector<Move *> StdLogic::mapPositions(Board* b, Side s) {
    vector<Move*> positions;
    //mapping all the relevant pieces of s side to a vector.
    for (int i = 0; i < b->getRow(); i++) {
        for (int j = 0; j < b->getCol(); j++) {
            if (s == b->getBoard()[i][j]) {
                Move *p = new Move(i, j);
                positions.push_back(p);
            }
        }
    }
    return positions;
}

Move* StdLogic::findPossibility(Move* p, Board* b, Side s, char c) {
    int i;
    switch(c) {
        //down direction.
        case 'D':
            i = 1;
            while (p->getR() + i < b->getRow()) {
                if (b->getBoard()[p->getR() + i][p->getC()] != s
                        && b->getBoard()[p->getR() + i][p->getC()] != EMPTY) {
                    i++;
                }
                else {
                    break;
                }
            }
            if (p->getR() + i < b->getRow()
                && b->getBoard()[p->getR() + i][p->getC()] == EMPTY && i != 1) {
                Move* opMove = new Move(p->getR() + i, p->getC());
                return opMove;
            }
            break;
        //up direction
        case 'U':
            i = 1;
            while (p->getR() - i > 0) {
                if (b->getBoard()[p->getR() - i][p->getC()] != s
                    && b->getBoard()[p->getR() - i][p->getC()] != EMPTY) {
                    i++;
                }
                else {
                    break;
                }
            }
            if (p->getR() - i >= 0
                && b->getBoard()[p->getR() - i][p->getC()] == EMPTY && i != 1) {
                Move* opMove = new Move(p->getR() - i, p->getC());
                return opMove;
            }
            break;

        //Right direction
        case 'R':
            i = 1;
            while (p->getC() + i < b->getCol()) {
                if (b->getBoard()[p->getR()][p->getC() + i] != s
                    && b->getBoard()[p->getR()][p->getC() + i] != EMPTY) {
                    i++;
                }
                else {
                    break;
                }
            }
            if (b->getBoard()[p->getR()][p->getC() + i] == EMPTY && i != 1) {
                Move* opMove = new Move(p->getR(), p->getC() + i);
                return opMove;
            }
            break;
        //left
        case 'L':
            i = 1;
            while (p->getC() - i > 0) {
                if (b->getBoard()[p->getR()][p->getC() - i] != s
                    && b->getBoard()[p->getR()][p->getC() - i] != EMPTY) {
                    i++;
                }
                else {
                    break;
                }
            }
            if (b->getBoard()[p->getR()][p->getC() - i] == EMPTY && i != 1) {
                Move* opMove = new Move(p->getR(), p->getC() - i);
                return opMove;
            }
            break;
        //lower right direction
        case '\\':
            i = 1;
            while (p->getR() + i < b->getRow() && p->getC() + i < b->getCol()) {
                if (b->getBoard()[p->getR() + i][p->getC() + i] != s
                        && b->getBoard()[p->getR() + i][p->getC() +i] != EMPTY) {
                    i++;
                }
                else {
                    break;
                }
            }
            if (p->getR() + i < b->getRow()
                && b->getBoard()[p->getR() +i][p->getC() +i] == EMPTY && i != 1) {
                Move* opMove = new Move(p->getR() + i, p->getC() + i);
                return opMove;
            }
            break;
        //upper right direction
        case '/':
            i = 1;
            while (p->getR() - i > 0 && p->getC() + i < b->getCol()) {
                if (b->getBoard()[p->getR() - i][p->getC() + i] != s
                    && b->getBoard()[p->getR() - i][p->getC() + i] != EMPTY) {
                    i++;
                }
                else {
                    break;
                }
            }
            if (p->getR() - i >= 0
                && b->getBoard()[p->getR() - i][p->getC() + i] == EMPTY && i != 1) {
                Move* opMove = new Move(p->getR() - i, p->getC() + i);
                return opMove;
            }
            break;
        //upper left direction
        case '`':
            i = 1;
            while (p->getR() - i > 0 && p->getC() - i > 0) {
                if (b->getBoard()[p->getR() - i][p->getC() - i] != s
                    && b->getBoard()[p->getR() - i][p->getC() - i] != EMPTY) {
                    i++;
                }
                else {
                    break;
                }
            }
            if (p->getR() - i >= 0
                && b->getBoard()[p->getR() - i][p->getC() - i] == EMPTY && i != 1) {
                Move* opMove = new Move(p->getR() - i, p->getC() - i);
                return opMove;
            }
            break;
        //lower left direction.
        case ',':
            i = 1;
            while (p->getR() + i < b->getRow() && p->getC() - i > 0) {
                if (b->getBoard()[p->getR() + i][p->getC() - i] != s
                    && b->getBoard()[p->getR() + i][p->getC() - i] != EMPTY) {
                    i++;
                }
                else {
                    break;
                }
            }
            if (p->getR() + i < b->getRow()
                && b->getBoard()[p->getR() + i][p->getC() - i] == EMPTY && i != 1) {
                Move* opMove = new Move(p->getR() + i, p->getC() - i);
                return opMove;
            }
            break;
    };
    return 0;
}

bool StdLogic::isANewOne(vector<Move *> &vec, Move *p) {
=======
vector<Point*> StdLogic::allowedActions(Board* b, Side s) {
    //array of directions symbols.
    char directions[] = {'R','L','D','U','\\','/',',','`'};
    vector<Point*> positions;
    positions = mapPositions(b, s);
    vector<Point*> allowedMoves;
    //we need to check legitimate moves for each piece.
    for (int k = 0; k < positions.size(); k++) {
        for (int i = 0; i < 8; i++) {
            Point *pos = findPossibility(positions[k], b, s, directions[i]);
            //making sure we are not putting a point which is already there.
            if (pos != 0 && isANewOne(allowedMoves, pos)) {
                allowedMoves.push_back(pos);
            }
        }
    }
    //freeing the positions vector.
    for (int j = 0; j < positions.size(); j++) {
        delete positions[j];
    }
    positions.clear();
    return allowedMoves;
}

std::vector<Point *> StdLogic::mapPositions(Board* b, Side s) {
    vector<Point*> positions;
    //mapping all the relevant pieces of s side to a vector.
    for (int i = 0; i < b->getRow(); i++) {
        for (int j = 0; j < b->getCol(); j++) {
            if (s == b->getBoard()[i][j]) {
                Point *p = new Point(i, j);
                positions.push_back(p);
            }
        }
    }
    return positions;
}

Point* StdLogic::findPossibility(Point* p, Board* b, Side s, char c) {
    int i;
    switch(c) {
        //down direction.
        case 'D':
            i = 1;
            while (p->getR() + i < b->getRow()) {
                if (b->getBoard()[p->getR() + i][p->getC()] != s
                        && b->getBoard()[p->getR() + i][p->getC()] != EMPTY) {
                    i++;
                }
                else {
                    break;
                }
            }
            if (p->getR() + i < b->getRow()
                && b->getBoard()[p->getR() + i][p->getC()] == EMPTY && i != 1) {
                Point* opPoint = new Point(p->getR() + i, p->getC());
                return opPoint;
            }
            break;
        //up direction
        case 'U':
            i = 1;
            while (p->getR() - i > 0) {
                if (b->getBoard()[p->getR() - i][p->getC()] != s
                    && b->getBoard()[p->getR() - i][p->getC()] != EMPTY) {
                    i++;
                }
                else {
                    break;
                }
            }
            if (p->getR() - i >= 0
                && b->getBoard()[p->getR() - i][p->getC()] == EMPTY && i != 1) {
                Point* opPoint = new Point(p->getR() - i, p->getC());
                return opPoint;
            }
            break;

        //Right direction
        case 'R':
            i = 1;
            while (p->getC() + i < b->getCol()) {
                if (b->getBoard()[p->getR()][p->getC() + i] != s
                    && b->getBoard()[p->getR()][p->getC() + i] != EMPTY) {
                    i++;
                }
                else {
                    break;
                }
            }
            if (b->getBoard()[p->getR()][p->getC() + i] == EMPTY && i != 1) {
                Point* opPoint = new Point(p->getR(), p->getC() + i);
                return opPoint;
            }
            break;
        //left
        case 'L':
            i = 1;
            while (p->getC() - i > 0) {
                if (b->getBoard()[p->getR()][p->getC() - i] != s
                    && b->getBoard()[p->getR()][p->getC() - i] != EMPTY) {
                    i++;
                }
                else {
                    break;
                }
            }
            if (b->getBoard()[p->getR()][p->getC() - i] == EMPTY && i != 1) {
                Point* opPoint = new Point(p->getR(), p->getC() - i);
                return opPoint;
            }
            break;
        //lower right direction
        case '\\':
            i = 1;
            while (p->getR() + i < b->getRow() && p->getC() + i < b->getCol()) {
                if (b->getBoard()[p->getR() + i][p->getC() + i] != s
                        && b->getBoard()[p->getR() + i][p->getC() +i] != EMPTY) {
                    i++;
                }
                else {
                    break;
                }
            }
            if (p->getR() + i < b->getRow()
                && b->getBoard()[p->getR() +i][p->getC() +i] == EMPTY && i != 1) {
                Point* opPoint = new Point(p->getR() + i, p->getC() + i);
                return opPoint;
            }
            break;
        //upper right direction
        case '/':
            i = 1;
            while (p->getR() - i > 0 && p->getC() + i < b->getCol()) {
                if (b->getBoard()[p->getR() - i][p->getC() + i] != s
                    && b->getBoard()[p->getR() - i][p->getC() + i] != EMPTY) {
                    i++;
                }
                else {
                    break;
                }
            }
            if (p->getR() - i >= 0
                && b->getBoard()[p->getR() - i][p->getC() + i] == EMPTY && i != 1) {
                Point* opPoint = new Point(p->getR() - i, p->getC() + i);
                return opPoint;
            }
            break;
        //upper left direction
        case '`':
            i = 1;
            while (p->getR() - i > 0 && p->getC() - i > 0) {
                if (b->getBoard()[p->getR() - i][p->getC() - i] != s
                    && b->getBoard()[p->getR() - i][p->getC() - i] != EMPTY) {
                    i++;
                }
                else {
                    break;
                }
            }
            if (p->getR() - i >= 0
                && b->getBoard()[p->getR() - i][p->getC() - i] == EMPTY && i != 1) {
                Point* opPoint = new Point(p->getR() - i, p->getC() - i);
                return opPoint;
            }
            break;
        //lower left direction.
        case ',':
            i = 1;
            while (p->getR() + i < b->getRow() && p->getC() - i > 0) {
                if (b->getBoard()[p->getR() + i][p->getC() - i] != s
                    && b->getBoard()[p->getR() + i][p->getC() - i] != EMPTY) {
                    i++;
                }
                else {
                    break;
                }
            }
            if (p->getR() + i < b->getRow()
                && b->getBoard()[p->getR() + i][p->getC() - i] == EMPTY && i != 1) {
                Point* opPoint = new Point(p->getR() + i, p->getC() - i);
                return opPoint;
            }
            break;
    };
    return 0;
}

bool StdLogic::isANewOne(vector<Point *> &vec, Point *p) {
>>>>>>> branch 'master' of https://github.com/Jed-El/ex3
    for (int i = 0; i < vec.size(); i++){
        if (p->isEqual(vec[i]))
            return false;
    }
    return true;
}

