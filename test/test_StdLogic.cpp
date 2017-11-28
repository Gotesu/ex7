//
// Created by gotesu on 28/11/17.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../StdLogic.h"

using namespace testing;
/*****************************
 * sameVec
 * @param a vector
 * @param b vector
 * @return true if vectors hold same values, false otherwise.
 ****************************/
bool sameVec (vector<Point*> a, vector<Point*> b) {
    int flag = 0;
    for (unsigned long i = 0; i < a.size(); i++) {
        for (unsigned long j = 0; j < b.size(); j++) {
            if (a.at(i)->isEqual(b.at(j))) {
                flag++;
            }
        }
    }
    return flag == a.size() && flag == b.size();
}
/************************
 * uniqueValues
 * @param a vector
 * @return true if a values are unique, else returns false.
 *********************/
bool uniqueValues(vector<Point*> a) {
    unsigned long j;
    for (unsigned long i = 0; i < a.size(); i++) {
        for (j = i + 1; j < a.size(); j++) {
            if (a.at(i)->isEqual(a.at(j)))
                return false;
        }
    }
    return true;

}
/***************************
 * TEST legitimateMove
 * verifies allowed actions returns a vector of all the legitimate moves (for the first X move).
 **************************/
TEST(LogicTest, legitimateMove) {
    Board *b = new Board();
    StdLogic *log = new StdLogic();
    vector<Point*> check;
    check.push_back(new Point(3, 2));
    check.push_back(new Point(2, 3));
    check.push_back(new Point(5, 4));
    check.push_back(new Point(4, 5));
    EXPECT_EQ(sameVec(log->allowedActions(b, BLACK), check), true);
    check.clear();
    delete b;
    delete log;
}
/********************
 * TEST noSameMove
 * verifies options vector does not hold two instances of the same move.
 * a specific case was crafted that would suggest the same possible move
 * from two different directions, hence the test can check if the same suggestion
 * is saved twice or once.
 *****************************/
TEST(LogicTest, noSameMove) {
    Board *b = new Board();
    StdLogic *log = new StdLogic();
    b->getBoard()[3][3] = BLACK;
    b->getBoard()[2][3] = BLACK;
    b->getBoard()[4][3] = WHITE;
    b->getBoard()[4][2] = WHITE;
    vector<Point*> options = log->allowedActions(b, BLACK);
    EXPECT_EQ(uniqueValues(options), true);
    options.clear();
    delete b;
    delete log;
}
