/*--------------------------------------Rules Characters-----------------------------------------------
*Ability scores: 3d6 are rolled and added for each ability (strength, dexterity, constitution, intelligence,
wisdom and charisma), to give them their scores. (between 3 and 18). Depending on the class, these abilities
might be distributed differently. Per example, the fighter will have its highest scores attributed to his
strength then its constitution (the rest ist distributed randomly).

Ability Modifier: calculated with the formula (ability-10)/2.

Hit points: each class has their own hit die. At the beginning of the game, the Hit points of a character
is decided using the formula: constitution modifier + highest value of the hit die. After each level,
the hit die is rolled and that number is added to the character hit points. If a character starts the
game at a certain level already, let’s say 10, then his hit die will be rolled 9 times. The result of
these 9 rolls will be added and the total value of the hit die will be added once more.

Armor class: calculated using the formula 10+Dexterity Modifier + armorItem. ArmorItem is the buff
given to armor class by a specific object.

Attack Bonus: calculated using the formula: attackBonus + dexterityMod(or strengthMod) + weaponItem. The
attack bonus is depending on the level of the character. WeaponItem is a buff given by an item affecting
the attackBonus.

Damage Bonus: calculated using the formula: strengthMod + damageItem. Where damageItem is a buff given by an item.
*/

/*this class inherit of the subject class and thus make use of the observer pattern implemented.Each time
* a stat of the character is updated, it notify its obersvers (in particular, the character object is attached to
* a display object).
*/
#pragma once
#include "Dice.h"
#include "Item.h"
#include "Armor.h"
#include "Shield.h"
#include "Weapon.h"
#include "Boots.h"
#include "Ring.h"
#include "Helmet.h"
#include "Belt.h"
#include "Cell.h"
#include "Subject.h"

using namespace std;

class Character: public Cell, public Subject
{
public:

	//method that displays the stats of the character
	void displayStats();

	//ability getters
	int getStrength() const;
	int getDexterity() const;
	int getConstitution() const;
	int getIntelligence() const;
	int getWisdom() const;
	int getCharisma() const;
	int getArmorClass() const; //added
	int getAttackBonus() const; //added
	int getDamageBonus() const; //added
	int getArmorBonus() const; // added
	int getHitPoints() const;//added
	int getWeaponItem() const; //added
	int getDamageItem() const; //added

	//modifiers getter 
	int getStrengthMod() const;
	int getDexterityMod() const;
	int getConstitutionMod() const;
	int getIntelligenceMod() const;
	int getWisdomMod() const;
	int getCharismaMod() const;

	//equip an Armor item or replace the existent one
	void setArmor(Armor& thisArmor);

	//equip a Shield item or replace the existent one
	void setShield(Shield& thisShield);

	//equip a Weapon item or replace the existent one
	void setWeapon(Weapon& thisWeapon);

	//equip a Boots item or replace the existent one
	void setBoots(Boots& thisBoots);

	//equip a Ring item or replace the existent one
	void setRing(Ring& thisRing);

	//equip a Helmet item or replace the existent one
	void setHelmet(Helmet& thisHelmet);

	//equip a Belt item or replace the existent one
	void setBelt(Belt& thisBelt);

	//Calculate the hit points and assign it to the character
	void setHitPoints(bool lvlUp);

	//calculate armor class and assign it to the character
	void setArmorClass();

	//calculate the attack bonnus and assign it to the character
	void setAttackBonus();

	//calculate the damage bonus and assign it to the character
	void setDamageBonus();

	//updates the character's postition on the map
	void setPosition(int x, int y);

	//level up a character
	void levelUp();
	
protected:

	//constructor
	Character(int lvl);
	//destructor
	~Character();

	//abilities
	int strength;
	int dexterity;
	int constitution;
	int intelligence;
	int wisdom;
	int charisma;
	
	//ability modifiers
	int strengthMod;
	int dexterityMod;
	int constitutionMod;
	int intelligenceMod;
	int wisdomMod;
	int charismaMod;

	//other character info
	int hitPoints;
	int level;
	int armorClass;
	int attackBonus;
	int damageBonus;
	Dice* myDice;		
	string myHitDie;
	int highestOfHitDie;

	//items
	bool hasArmor;
	bool hasShield;
	bool hasWeapon;
	bool hasBoots;
	bool hasRing;
	bool hasHelmet;
	bool hasBelt;

	//Bonus from items
	int armorBonus;
	int weaponItem;
	int damageItem;

	//equiped items
	Armor* myArmor;
	Shield* myShield;
	Weapon* myWeapon;
	Boots* myBoots;
	Ring* myRing;
	Helmet* myHelmet;
	Belt* myBelt;

	//generate random ability scores and assign them to abilities differently depending onb the character created
	virtual void setAbilities() = 0;

	//Assign to the character the values of the abilities modifiers
	void setModifiers();

	//calculate the value of a modifier
	int calculateModifier(int abilityScore);

	//grant to the to the character the buff provided by an object
	void addItemBuff(Item &myItem);

	//remove from the character the buff provided by an object
	void removeItemBuff(Item &myItem);

	friend class TestFighter;

};

class Fighter : public Character
{
public:

	//constructor
	Fighter(int lvl);

	//generate random ability scores and assign the two highest to constitution and strength
	void setAbilities() override;
};