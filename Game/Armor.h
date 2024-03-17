/**
 * @file Armor.h
 * @brief Defines the Armor piece of equipment.
 *
 * ## Game Rules
 * - Armor provides an armor bonus to the player's character.
 * This class extends the Item base class, specializing in armor bonuses within the game.
 *
 * @see Item.h
 */


#ifndef ARMOR_H
#define ARMOR_H
#include "Item.h"
class Armor : public Item {
    private:

    public:
    //Constructors
    Armor();
    Armor(int Armor);
};

#endif