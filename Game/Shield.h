/**
 * @file Shield.h
 * @brief Defines the Shield armor item class.
 *
 * ## Game Rules
 * - Shields provide a bonus to the player's armor.
 * This class extends the Item base class, specializing in head protection within the game's combat system.
 *
 * @see Item.h
 */


#ifndef SHIELD_H
#define SHIELD_H
#include "Item.h"
class Shield : public Item {
    private:

    public:
    //Constructors
    Shield();
    Shield(int Armor);
};

#endif