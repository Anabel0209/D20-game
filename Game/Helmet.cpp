#include "Helmet.h"

Helmet::Helmet() : Item()
{
}
Helmet::Helmet(int Intelligence, int Wisdom, int Armor) : Item(Intelligence, Wisdom, Armor, 0, 0, 0, 0, 0, 0)
{
}