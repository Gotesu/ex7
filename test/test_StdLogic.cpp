//
// Created by gotesu on 28/11/17.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Client/StdLogic.h"

using namespace testing;
/*****************************
 * sameVec
 * @param a vector
 * @param b vector
 * @return true if vectors hold same values, false otherwise.
 ****************************/
bool sameVec (vector<Move*> a, vector<Move*> b) {
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
bool uniqueValues(vector<Move*> a) {
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
    vector<Move*> check;
    vector<int> direct;
    for (int i = 0; i < 8; i ++)
        direct.push_back(0);
    direct.at(3) = 1;
    check.push_back(new Move(3, 2, direct));
    direct.at(3) = 0;
    direct.at(0) = 1;
    check.push_back(new Move(2, 3, direct));
    direct.at(0) = 0;
    direct.at(1) = 1;
    check.push_back(new Move(5, 4, direct));
    direct.at(1) = 0;
    direct.at(2) = 1;
    check.push_back(new Move(4, 5, direct));
    EXPECT_EQ(sameVec(log->allowedActions(*b, BLACK), check), true);
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
    b->set(3, 3, BLACK);
    b->set(2, 3, BLACK);
    b->set(4, 3, WHITE);
    b->set(4, 2, WHITE);
    vector<Move*> options = log->allowedActions(*b, BLACK);
    EXPECT_EQ(uniqueValues(options), true);
    options.clear();
    delete b;
    delete log;
}
