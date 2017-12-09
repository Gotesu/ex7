//
// Created by gotesu on 28/11/17.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Client/Board.h"


using namespace testing;
/**************************
 * TEST initialization
 * checks a default initialized board starts correctly (all pieces in place).
 ****************************/
TEST(boardTest, initialization) {
    Board *b = new Board();
    int row = b->getRow();
    int col = b->getCol();
    EXPECT_EQ(b->get(row/2 -1, col/2 -1), WHITE);
    EXPECT_EQ(b->get(row/2, col/2), WHITE);
    EXPECT_EQ(b->get(row/2 -1, col/2), BLACK);
    EXPECT_EQ(b->get(row/2, col/2 -1), BLACK);
    delete b;
}

/************************8
 * TEST specInitialize
 * checks a 20 col 20 row constructed Board starts correctly (all pieces in place).
 */
TEST(boardTest, specInitialize) {
    Board *b = new Board(20,20);
    int row = 20;
    int col = 20;
    EXPECT_EQ(b->get(row/2 -1, col/2 -1), WHITE);
    EXPECT_EQ(b->get(row/2 , col/2 ), WHITE);
    EXPECT_EQ(b->get(row/2 -1, col/2), BLACK);
    EXPECT_EQ(b->get(row/2, col/2 -1), BLACK);
    delete b;
}
/*******************************
 * correctUpdate
 * this test checks the board updates the move result correctly.
 */
TEST(boardTest, correctUpdate) {
    Board *b = new Board();
    int row = b->getRow();
    int col = b->getCol();
    vector<int> direct;
    for (int i = 0; i < 8; i ++)
        direct.push_back(0);
    direct.at(1) = 1;
    Move* mov = new Move(2, 3, direct);
    b->update(BLACK, mov);
    EXPECT_EQ(b->get(row/2 -1, col/2 -1), BLACK);
    EXPECT_EQ(b->get(row/2, col/2), WHITE);
    EXPECT_EQ(b->get(row/2 -1, col/2), BLACK);
    EXPECT_EQ(b->get(row/2, col/2 -1), BLACK);
    EXPECT_EQ(b->get(row/2 -2, col/2 -1), BLACK);
    delete b;
    direct.clear();
}
/******************
 * setterTest
 * testing board setter function is working.
 ****************/
TEST(boardInput, setterTest) {
    Board *b = new Board();
    EXPECT_EQ(b->get(0, 0), EMPTY);
    b->set(0, 0, WHITE);
    EXPECT_EQ(b->get(0, 0), WHITE);
}