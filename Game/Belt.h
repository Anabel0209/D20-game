/**
 * @file Belt.h
 * @brief Defines the Belt armor piece.
 *
 * ## Game Rules
 * - Belts provide Constitution and Strength bonuses.
 * This class extends the Item base class, specializing in head protection within the game's combat system.
 *
 * @see Item.h
 */


#ifndef BELT_H
#define BELT_H
#include "Item.h"
class Belt : public Item {
    private:

    public:
    //Constructors
    Belt();
    Belt(int Constitution, int Strength);
};

#endif