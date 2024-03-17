/**
 * @file Helmet.h
 * @brief Defines the Helmet armor piece.
 *
 * ## Game Rules
 * - Helmets provide Intellingence, Wisdom, and Armor bonuses to characters.
 * This class extends the Item base class, specializing in head protection within the game's combat system.
 *
 * @see Item.h
 */


#ifndef HELMET_H
#define HELMET_H
#include "Item.h"
class Helmet : public Item {
    private:

    public:
    //Constructors
    Helmet();
    Helmet(int Intelligence, int Wisdom, int Armor);
};

#endif