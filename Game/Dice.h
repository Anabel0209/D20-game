/**
 * @file Dice.h
 * @brief This file contains the definition of the Dice class, which is utilized for generating random outcomes within the game.
 *
 * @details The Dice class simulates the roll of dice, a fundamental mechanism in many game actions such as combat, skill checks, and random event determination.
 * It supports rolling multiple dice at once and adding modifiers to the roll, reflecting the various scenarios where dice rolls are required in the game.
 *
 * Game Rules:
 * - Dice rolls determine the outcomes of certain actions like combat attacks, skill challenges, and other random elements in the game.
 * - Multiple dice can be rolled at once to calculate damage, determine success in challenges, or generate other random values.
 * - Modifiers may be applied to dice rolls to reflect character abilities, situational advantages, or equipment bonuses.
 *
 * Design:
 * - The Dice class encapsulates the logic for rolling one or more dice, including the ability to add modifiers to the roll.
 * - It utilizes a flexible design that allows specifying the number of dice, the number of sides on the dice, and any additional modifiers.
 */

#ifndef DICE_H
#define DICE_H

#include <string>
using namespace std;

class Dice {
public:
    //Constructor
    Dice();
    /// <summary>
    /// Rolls a dice with the given dice notation and returns the result
    /// </summary>
    /// <param name="dice_notation"> The dice notation to roll </param>
    /// <returns> The result of the roll </returns>
    int rollDice(std::string dice_notation);
};

#endif // DICE_H