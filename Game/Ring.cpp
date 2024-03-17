#include "Ring.h"

Ring::Ring() : Item()
{
}
Ring::Ring(int Armor, int Strength, int Constitution, int Wisdom, int Charisma) : Item(0, Wisdom, Armor, Strength, Constitution, Charisma, 0, 0, 0)
{
}