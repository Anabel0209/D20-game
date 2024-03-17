/**
 * @file Ring.h
 * @brief Defines the Ring armor piece.
 *
 * ## Game Rules
 * - Rings provide Strength, Constitution, Wisdom, Charisma, and Armor.
 * This class extends the Item base class, specializing in head protection within the game's combat system.
 *
 * @see Item.h
 */


#ifndef RING_H
#define RING_H
#include "Item.h"
class Ring : public Item {
    private:

    public:
    //Constructors
    Ring();
    Ring(int Armor, int Strength, int Constitution, int Wisdom, int Charisma);
};

#endif