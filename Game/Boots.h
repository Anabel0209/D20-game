/**
 * @file Boots.h
 * @brief Defines the Boots armor piece.
 *
 * ## Game Rules
 * - Boots provide a bonus to Dexterity and Armor.
 * This class extends the Item base class, specializing in head protection within the game's combat system.
 *
 * @see Item.h
 */


#ifndef BOOTS_H
#define BOOTS_H
#include "Item.h"
class Boots : public Item {
    private:

    public:
    //Constructors
    Boots();
    Boots(int Armor, int Dexterity);
    
};

#endif