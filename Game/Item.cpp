#include "Item.h"

// Constructors
Item::Item()
{
    intelligence = 0;
    wisdom = 0;
    armor = 0;
    strength = 0;
    constitution = 0;
    charisma = 0;
    dexterity = 0;
    attackBonus = 0;
    damageBonus = 0;
}
Item::Item(int Intelligence, int Wisdom, int Armor, int Strength, int Constitution, int Charisma, int Dexterity, int AttackBonus, int DamageBonus)
{
    intelligence = Intelligence;
    wisdom = Wisdom;
    armor = Armor;
    strength = Strength;
    constitution = Constitution;
    charisma = Charisma;
    dexterity = Dexterity;
    attackBonus = AttackBonus;
    damageBonus = DamageBonus;
}

// Accessors
int Item::getIntelligence()
{
    return intelligence;
}

int Item::getWisdom()
{
    return wisdom;
}

int Item::getArmor()
{
    return armor;
}

int Item::getStrength()
{
    return strength;
}

int Item::getConstitution()
{
    return constitution;
}

int Item::getCharisma()
{
    return charisma;
}

int Item::getDexterity()
{
    return dexterity;
}

int Item::getAttackBonus()
{
    return attackBonus;
}

int Item::getDamageBonus()
{
    return damageBonus;
}

Item::~Item() {
    
}