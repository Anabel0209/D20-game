/**
 * @file Item.h
 * @brief This file contains the definition of the Item class, which is the base class for all items within the game.
 *
 * @details The Item class serves as a foundation for various types of items that can exist in the game, including weapons and armor.
 * It defines common attributes and functionalities that all items share.
 *
 * Game Rules:
 * - Items can affect the character's attributes or provide them with special abilities when used or equipped.
 *
 * Design:
 * - The Item class is designed to be extended by specific item types, each implementing their own effects and characteristics.
 * - It provides a virtual method for use or application of the item, allowing derived classes to specify the effect.
 *
 * Libraries Used:
 * - No specific libraries are used directly within the Item class; it serves as a base class for inheritance.
 *
 * Rationale:
 * - The Item class is kept abstract and lightweight, focusing on common attributes and functionalities to provide a flexible
 *   foundation for a variety of item types. This approach facilitates the extension and customization of item behaviors and attributes.
 */

#ifndef ITEM_H
#define ITEM_H
class Item
{
private:
    /// <summary>
    /// Intelligence boost
    /// </summary>
    int intelligence;
    /// <summary>
    /// Wisdom boost
    /// </summary>
    int wisdom;
    /// <summary>
    /// Armor boost
    /// </summary>
    int armor;
    /// <summary>
    /// Strength boost
    /// </summary>
    int strength;
    /// <summary>
    /// Constitution boost
    /// </summary>
    int constitution;
    /// <summary>
    /// Charisma boost
    /// </summary>
    int charisma;
    /// <summary>
    /// Dexterity boost
    /// </summary>
    int dexterity;
    /// <summary>
    /// Attack Bonus
    /// </summary>
    int attackBonus;
    /// <summary>
    /// Damage Bonus
    /// </summary>
    int damageBonus;

public:
    // Constructors and Destructors
    Item();
    /// <summary>
    /// Constructor for a new Item
    /// </summary>
    /// <param name="Intelligence">Intelligence</param>
    /// <param name="Wisdom">Wisdom</param>
    /// <param name="Armor">Armor</param>
    /// <param name="Strength">Strength</param>
    /// <param name="Constitution">Constitution</param>
    /// <param name="Charisma">Charisma</param>
    /// <param name="Dexterity">Dexterity</param>
    /// <param name="AttackBonus">Attack Bonus</param>
    /// <param name="DamageBonus">Damage bonus</param>
    Item(int Intelligence, int Wisdom, int Armor, int Strength, int Constitution, int Charisma, int Dexterity, int AttackBonus, int DamageBonus);
    ~Item();

    // Accessors
    virtual int getIntelligence();
    virtual int getWisdom();
    virtual int getArmor();
    virtual int getStrength();
    virtual int getConstitution();
    virtual int getCharisma();
    virtual int getDexterity();
    virtual int getAttackBonus();
    virtual int getDamageBonus();
};

#endif