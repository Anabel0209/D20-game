/**
 * @file TestDice.cpp
 * @brief Implementation of tests for the Dice class.
 *
 * This file includes the implementation of tests for various functionalities of the Dice,
 * such as rolling a dice and adding a constant to the result.
 */

#include "TestDice.h"
#include "..\Game\Dice.h"

void TestDice::setUp() {
    // Initialization code here
}

void TestDice::tearDown() {
    // Cleanup code here
}

// testing if d4 rolls correctly 
// ex: 2d4+10 result should be between 12 and 18

void TestDice::testRollDice(void) {
    Dice dice1;
    int result = dice1.rollDice("2d4+10");
    CPPUNIT_ASSERT(result >= 12 && result <= 18);
}

// testing xdy[+z] if [+z] works correctly 
//result should be more than 4
    
void TestDice::testAdditionOfDice(void) {
    Dice dice2;
    int result2 = dice2.rollDice("1d4+4");
    CPPUNIT_ASSERT(result2 > 4);
}



