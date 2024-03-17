/**
 * @file Weapon.h
 * @brief Defines the Weapon armor piece.
 *
 * ## Game Rules
 * - Weapons provide an attack bonus and a damage bonus.
 * This class extends the Item base class, specializing in head protection within the game's combat system.
 *
 * @see Item.h
 */


#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"
class Weapon : public Item {
    private:

    public:
    //Constructors
    Weapon();
    Weapon(int AttackBonus, int DamageBonus);
};

#endif