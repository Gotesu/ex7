//
// Created by gotesu on 29/11/17.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Computer.h"
#include "../StdLogic.h"

/**********************
 * checkMinMaxBehavoirDown
 * this test checks the ai make a minmax move with a specialy designed scenraio
 * of the last row almost filled with a chance to fill it before the opponent can
 * convert the whole line.
 */
TEST(AI, checkMinMaxBehavoirDown) {
    Board *b = new Board();
    StdLogic *logic = new StdLogic();
    Computer *ai = new Computer(*logic, *b, WHITE);
    //emptying board.
    b->set(3, 3, EMPTY);
    b->set(4, 4, EMPTY);
    b->set(3, 4, EMPTY);
    b->set(4, 3, EMPTY);
    //filling scenario
    //filling middle of last row with White save the before last slot of a black.
    b->set(7, 6, BLACK);
    b->set(7, 5, WHITE);
    b->set(7, 4, WHITE);
    b->set(7, 3, WHITE);
    b->set(7, 2, WHITE);
    b->set(7, 1, WHITE);
    b->set(6, 6, BLACK);
    b->set(6, 5, BLACK);
    ai->doMove();
    EXPECT_EQ(b->get(7, 7), WHITE);
    delete b;
    delete logic;
    delete ai;
}

/**********************
 * checkMinMaxBehavoirUp
 * this test checks the ai make a minmax move with a specialy designed scenraio
 * of the last row almost filled with a chance to fill it before the opponent can
 * convert the whole line.
 */
TEST(AI, checkMinMaxBehavoirUp) {
    Board *b = new Board();
    StdLogic *logic = new StdLogic();
    Computer *ai = new Computer(*logic, *b, WHITE);
    //emptying board.
    b->set(3, 3, EMPTY);
    b->set(4, 4, EMPTY);
    b->set(3, 4, EMPTY);
    b->set(4, 3, EMPTY);
    //filling scenario
    //filling middle of first row with White save the before last slot of a black.
    b->set(0, 1, BLACK);
    b->set(0, 2, WHITE);
    b->set(0, 3, WHITE);
    b->set(0, 4, WHITE);
    b->set(0, 5, WHITE);
    b->set(0, 6, WHITE);
    b->set(1, 1, BLACK);
    b->set(1, 2, BLACK);
    ai->doMove();
    EXPECT_EQ(b->get(0, 0), WHITE);
    delete b;
    delete logic;
    delete ai;
}

/**********************
 * checkMinMaxBehavoirLeft
 * this test checks the ai make a minmax move with a specialy designed scenraio
 * of the left col almost filled with a chance to fill it before the opponent can
 * convert the whole line.
 */
TEST(AI, checkMinMaxBehavoirLeft) {
    Board *b = new Board();
    StdLogic *logic = new StdLogic();
    Computer *ai = new Computer(*logic, *b, WHITE);
    //emptying board.
    b->set(3, 3, EMPTY);
    b->set(4, 4, EMPTY);
    b->set(3, 4, EMPTY);
    b->set(4, 3, EMPTY);
    //filling scenario
    //filling middle of last row with White save the before last slot of a black.
    b->set(1, 0, BLACK);
    b->set(2, 0, WHITE);
    b->set(3, 0, WHITE);
    b->set(4, 0, WHITE);
    b->set(5, 0, WHITE);
    b->set(6, 0, WHITE);
    b->set(1, 1, BLACK);
    b->set(2, 1, BLACK);
    ai->doMove();
    EXPECT_EQ(b->get(0, 0), WHITE);
    delete b;
    delete logic;
    delete ai;
}

/**********************
 * checkMinMaxBehavoirRight
 * this test checks the ai make a minmax move with a specialy designed scenraio
 * of the right col almost filled with a chance to fill it before the opponent can
 * convert the whole line.
 */
TEST(AI, checkMinMaxBehavoirRight) {
    Board *b = new Board();
    StdLogic *logic = new StdLogic();
    Computer *ai = new Computer(*logic, *b, WHITE);
    //emptying board.
    b->set(3, 3, EMPTY);
    b->set(4, 4, EMPTY);
    b->set(3, 4, EMPTY);
    b->set(4, 3, EMPTY);
    //filling scenario
    //filling middle of last row with White save the before last slot of a black.
    b->set(1, 7, BLACK);
    b->set(2, 7, WHITE);
    b->set(3, 7, WHITE);
    b->set(4, 7, WHITE);
    b->set(5, 7, WHITE);
    b->set(6, 7, WHITE);
    b->set(1, 6, BLACK);
    b->set(2, 6, BLACK);
    ai->doMove();
    EXPECT_EQ(b->get(0, 7), WHITE);
    delete b;
    delete logic;
    delete ai;
}