//
// Created by gotesu on 28/11/17.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Board.h"


using namespace testing;
/**************************
 * TEST initialization
 * checks a default initialized board starts correctly (all pieces in place).
 ****************************/
TEST(boardTest, initialization) {
    Board *b = new Board();
    int row = b->getRow();
    int col = b->getCol();
    EXPECT_EQ(b->getBoard()[row/2 - 1][col/2 - 1], WHITE);
    EXPECT_EQ(b->getBoard()[row/2][col/2], WHITE);
    EXPECT_EQ(b->getBoard()[row/2 - 1][col/2], BLACK);
    EXPECT_EQ(b->getBoard()[row/2][col/2 - 1], BLACK);
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
    EXPECT_EQ(b->getBoard()[row/2 - 1][col/2 - 1], WHITE);
    EXPECT_EQ(b->getBoard()[row/2][col/2], WHITE);
    EXPECT_EQ(b->getBoard()[row/2 - 1][col/2], BLACK);
    EXPECT_EQ(b->getBoard()[row/2][col/2 - 1], BLACK);
    delete b;
}