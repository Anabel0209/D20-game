#include "Weapon.h"

Weapon::Weapon() : Item()
{
}
Weapon::Weapon(int AttackBonus, int DamageBonus): Item(0, 0, 0, 0, 0, 0, 0, AttackBonus, DamageBonus)
{
}