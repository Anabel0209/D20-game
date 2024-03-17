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

/*this class inherit of the subject class and thus make use of the observer pattern implemented.each time
* a stat of the character is updated, it notify its obersvers.
*/

#include <iostream>
#include "Character.h"

using namespace std;

	Character::Character(int lvl) : Cell(0,0,CellType::Character)
	{
		level = lvl;
		//abilities
		strength = 0;
		dexterity = 0;
		constitution = 0;
		intelligence = 0;
		wisdom = 0;
		charisma = 0;
		myDice = new Dice();	//any character will inherit of this dice and will be able to use it
		myHitDie = "1d6";
		highestOfHitDie = 6;

		//ability modifyers
		strengthMod = 0;
		dexterityMod = 0;
		constitutionMod = 0;
		intelligenceMod = 0;
		wisdomMod = 0;
		charismaMod  = 0;

		hitPoints = 0;
		armorClass = 0;
		attackBonus = 0;
		damageBonus = 0;

		hasArmor = false;
		hasBoots = false;
		hasHelmet = false;
		hasShield = false;
		hasRing = false;
		hasWeapon = false;
		hasBelt = false;

		armorBonus = 0;
		weaponItem = 0;
		damageItem = 0;

		myArmor = nullptr;
		myShield = nullptr;
		myWeapon = nullptr;
		myBoots = nullptr;
		myRing = nullptr;
		myHelmet = nullptr;
		myBelt = nullptr;
	}

	Character::~Character()
	{
		delete myDice;
		myDice = nullptr;
	}

	//getters
	int Character::getStrength() const
	{
		return strength;
	}

	int Character::getDexterity() const
	{
		return dexterity;
	}

	int Character::getConstitution() const
	{
		return constitution;
	}

	int Character::getIntelligence() const
	{
		return intelligence;
	}
	int Character::getWisdom() const
	{
		return wisdom;
	}
	int Character::getCharisma() const
	{
		return charisma;
	}
	//added
	int Character::getArmorClass() const
	{
		return armorClass;
	}
	int Character::getArmorBonus() const
	{
		return armorBonus;
	}
	//added
	int Character::getAttackBonus() const
	{
		return attackBonus;
	}
	//added
	int Character::getDamageBonus() const
	{
		return damageBonus;
	}
	int Character::getStrengthMod() const
	{
		return strengthMod;
	}
	int Character::getDexterityMod() const
	{
		return dexterityMod;
	}
	int Character::getConstitutionMod() const
	{
		return constitutionMod;
	}
	int Character::getIntelligenceMod() const
	{
		return intelligenceMod;
	}
	int Character::getWisdomMod() const
	{
		return wisdomMod;
	}
	int Character::getCharismaMod() const
	{
		return charismaMod;
	}
	int Character::getHitPoints() const
	{
		return hitPoints;
	}
	int Character::getWeaponItem() const
	{
		return weaponItem;
	}
	int Character::getDamageItem() const
	{
		return damageItem;
	}
	//calculate the modifier of an abilityScore and round it down using the property of integer division
	int Character::calculateModifier(int abilityScore)
	{
		return (abilityScore - 10) / 2;
	}

	//Assign to the character the values of the abilities modifiers
	void Character::setModifiers()
	{
		//assign the modify by calling the calculateModifier method on all the abilities
		strengthMod = calculateModifier(strength);
		dexterityMod = calculateModifier(dexterity);
		constitutionMod = calculateModifier(constitution);
		intelligenceMod = calculateModifier(intelligence);
		wisdomMod = calculateModifier(wisdom);
		charismaMod = calculateModifier(charisma);

		//test if the modifiers have been calculated correctly
		/*cout << strengthMod << endl
			<< dexterityMod << endl
			<< constitutionMod << endl
			<< intelligenceMod << endl
			<< wisdomMod << endl
			<< charismaMod << endl;*/
	}

	//equip an item 
	void Character::addItemBuff(Item &myItem)
	{
		//increment the stat given by the item
		intelligence += myItem.getIntelligence();
		wisdom += myItem.getWisdom();
		armorBonus += myItem.getArmor();
		strength += myItem.getStrength();
		constitution += myItem.getConstitution();
		charisma += myItem.getCharisma();
		dexterity += myItem.getDexterity();
		weaponItem += myItem.getAttackBonus();
		damageItem += myItem.getDamageBonus();

		//update the modifiers
		this -> setModifiers();

		//update the armorClass, attackBonus and damageBonus
		setArmorClass();
		setAttackBonus();
		setDamageBonus();

		//notify when a change is made after equiping an item
		Notify();
	}

	//equip an item 
	void Character::removeItemBuff(Item& myItem)
	{
		//increment the stat given by the item
		intelligence -= myItem.getIntelligence();
		wisdom -= myItem.getWisdom();
		armorBonus -= myItem.getArmor();
		strength -= myItem.getStrength();
		constitution -= myItem.getConstitution();
		charisma -= myItem.getCharisma();
		dexterity -= myItem.getDexterity();
		weaponItem -= myItem.getAttackBonus();
		damageItem -= myItem.getDamageBonus();

		//update the modifiers
		this->setModifiers();

		//update the armorClass, attackBonus and damageBonus
		setArmorClass();
		setAttackBonus();
		setDamageBonus();

		//notify when a change is made after removing an item
		Notify();
	}

	//Calculate the hit points and assign it to the character (call this function after each level up)
	void Character:: setHitPoints(bool lvlUp)
	{
		//if the character starts at a specific level, the hit point die will be rolled the amount of time it would have normally been rolled if the player has leveled up level by level
		if (lvlUp == false)
		{
			hitPoints = constitutionMod + highestOfHitDie;

			for (int i = 1; i < level; i++)
			{
				hitPoints += myDice->rollDice(myHitDie);
			}
		}

		//if the method is called to level up a character, it will add a roll of its hit die to its hit points
		if (lvlUp == true)
		{
			hitPoints += myDice->rollDice(myHitDie);
		}

	}

	//calculate armor class and assign it to the character
	void Character:: setArmorClass()
	{
		armorClass = 10 + dexterityMod + armorBonus;
	}

	//calculate the attack bonnus and assign it to the character
	void Character:: setAttackBonus()
	{
		//initialze the attack bonus so that it doesnt increment every time the method is called
		attackBonus = 0;

		//depending on the level of the character, the bonus obtained is different
		if (level >= 1 && level <= 4)
		{
			attackBonus += 2;
		}
		else if (level >= 5 && level <= 8)
		{
			attackBonus += 3;
		}
		else if (level >= 9 && level <= 12)
		{
			attackBonus += 4;
		}
		else if (level >= 13 && level <= 16)
		{
			attackBonus += 5;
		}
		else if (level >= 17 && level <= 20)
		{
			attackBonus += 6;
		}

		//the attack bonus is based on the higher dexterity or strength modifier and a weapon Bonus if there is
		if (dexterityMod > strengthMod)
		{
			attackBonus += dexterityMod + weaponItem;
		}
		else
		{
			attackBonus += strengthMod + weaponItem;
		}
	}

	//calculate the damage bonus and assign it to the character
	void Character:: setDamageBonus()
	{
		damageBonus = strengthMod + damageItem;
	}

	void Character::displayStats()
	{
		//display ability scores
		cout << "-----Ability scores----- " << endl
			<< "Strength: " << strength << endl
			<< "dexterity: " << dexterity << endl
			<< "constitution: " << constitution << endl
			<< "intellignece: " << intelligence << endl
			<< "wisdom: " << wisdom << endl
			<< "charisma: " << charisma << endl
			<< "-------------------------" << endl;

		//dsiplay ability modifiers
		cout << "-----Ability modifiers-----" << endl
			<< "Strength mod : " << strengthMod << endl
			<< "Dexterity mod: " << dexterityMod << endl
			<< "Constitution mod: " << constitutionMod << endl
			<< "Intelligence mod: " << intelligenceMod << endl
			<< "Wisdom mod: " << wisdomMod << endl
			<< "Charisma mod: " << charismaMod << endl
			<< "-------------------------" << endl;

		//display hit points
		cout << "Hit points: " << hitPoints << endl;

		//display armor class
		cout << "Armor class: " << armorClass << endl;

		//display attack bonus
		cout << "Attack bonus: " << attackBonus << endl;

		//display damage bonus 
		cout << "Damage Bonus: " << damageBonus << endl << endl;
		cout << "**************************************" << endl;
	}


	//equip an Armor item or replace the existent one
	void Character::setArmor(Armor &thisArmor) 
	{

		//to equip from the start 
		if (hasArmor == false)
		{
			myArmor = &thisArmor;
			hasArmor = true;

			//do the modification of the stats
			addItemBuff(*myArmor);
		}

		//to replace an item
		else
		{
			removeItemBuff(*myArmor);
			myArmor = &thisArmor;
			addItemBuff(*myArmor);
		}
	}

	//equip a Shield item or replace the existent one
	void Character:: setShield(Shield &thisShield)
	{
		//to equip from the start 
		if (hasShield == false)
		{
			myShield = &thisShield;
			hasShield = true;

			//do the modification of the stats
			addItemBuff(*myShield);
		}

		//to replace an item
		else
		{
			removeItemBuff(*myShield);
			myShield = &thisShield;
			addItemBuff(*myShield);
		}
	}
	

	//equip a Weapon item or replace the existent one
	void Character:: setWeapon(Weapon &thisWeapon)
	{
		//to equip from the start 
		if (hasWeapon == false)
		{
			myWeapon = &thisWeapon;
			hasWeapon = true;

			//do the modification of the stats
			addItemBuff(*myWeapon);
		}

		//to replace an item
		else
		{
			removeItemBuff(*myWeapon);
			myWeapon = &thisWeapon;
			addItemBuff(*myWeapon);
		}
	}


	//equip a Boots item or replace the existent one
	void Character:: setBoots(Boots &thisBoots)
	{
		//to equip from the start 
		if (hasBoots == false)
		{
			myBoots = &thisBoots;
			hasBoots = true;

			//do the modification of the stats
			addItemBuff(*myBoots);
		}

		//to replace an item
		else
		{
			removeItemBuff(*myBoots);
			myBoots = &thisBoots;
			addItemBuff(*myBoots);
		}	
	}

	//equip a Ring item or replace the existent one
	void Character:: setRing(Ring &thisRing)
	{
		//to equip from the start 
		if (hasRing == false)
		{
			myRing = &thisRing;
			hasRing = true;

			//do the modification of the stats
			addItemBuff(*myRing);
		}

		//to replace an item
		else
		{
			removeItemBuff(*myRing);
			myRing = &thisRing;
			addItemBuff(*myRing);
		}
	}

	//equip a Helmet item or replace the existent one
	void Character:: setHelmet(Helmet &thisHelmet)
	{
		//to equip from the start 
		if (hasHelmet == false)
		{
			myHelmet = &thisHelmet;
			hasHelmet = true;

			//do the modification of the stats
			addItemBuff(*myHelmet);
		}

		//to replace an item
		else
		{
			removeItemBuff(*myHelmet);
			myHelmet = &thisHelmet;
			addItemBuff(*myHelmet);
		}
	}

	//equip a Helmet item or replace the existent one
	void Character::setBelt(Belt& thisBelt)
	{
		//to equip from the start 
		if (hasBelt == false)
		{
			myBelt = &thisBelt;
			hasBelt = true;

			//do the modification of the stats
			addItemBuff(*myBelt);
		}

		//to replace an item
		else
		{
			removeItemBuff(*myBelt);
			myBelt = &thisBelt;
			addItemBuff(*myBelt);
		}
	}

	void Character::setPosition(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	//level up the character and call the necessairy updated 
	void Character::levelUp()
	{
		setAttackBonus();
		setHitPoints(true);

		//notify when changes related to leveling up have been made
		Notify();
	}


	Fighter:: Fighter(int lvl): Character(lvl)
	{
		myHitDie = "1d10";
		highestOfHitDie = 10;
		setAbilities();
		setModifiers();
		setArmorClass();
		setAttackBonus();
		setDamageBonus();
		setHitPoints(false); // pass false as a parameter because we are not leveling up the character when creating it

		//does not notify because the object need to already be created to subscribe a object to its changes
	}

	//the fighter class should have strength and constitution with the highest number of ability points
	void Fighter:: setAbilities()
	{
		int abilitiesArray[6];

		//fill the array with random walues created by rolling 3d6
		abilitiesArray[0] = myDice->rollDice("3d6");
		abilitiesArray[1] = myDice->rollDice("3d6");
		abilitiesArray[2] = myDice->rollDice("3d6");
		abilitiesArray[3] = myDice->rollDice("3d6");
		abilitiesArray[4] = myDice->rollDice("3d6");
		abilitiesArray[5] = myDice->rollDice("3d6");

		//test of the random value generated
		/*cout << "Random values generated : " << endl
			<< abilitiesArray[0] << endl
			<< abilitiesArray[1] << endl
			<< abilitiesArray[2] << endl
			<< abilitiesArray[3] << endl
			<< abilitiesArray[4] << endl
			<< abilitiesArray[5] << endl;*/
			
		//assign the first value of the array to our max's pointers
		int* max1 = &abilitiesArray[0];
		int* max2 = &abilitiesArray[0];

		//go through the array and adjust the pointers to the two maximums of the array
		for (int i = 1; i < sizeof(abilitiesArray)/sizeof(int); i++)
		{
			if (abilitiesArray[i] >= *max1)
			{
				max2 = max1;
				max1 = &abilitiesArray[i];
			}
			else if (abilitiesArray[i] >= *max2)
			{
				max2 = &abilitiesArray[i];
			}
		}

		//test if the max values found were the right ones
		/*cout << "max values found: " << endl
			<< "max1: " << *max1 << endl
			<< "max2: " << *max2 << endl;*/

		//assign random values tot he constitution and the strength abilities
		constitution = abilitiesArray[0];
		strength = abilitiesArray[1];
		
		//rcorrect the assignment of the values so that the ficgter receives the max1 and max 2 for its strength and constitution
		int temp = 0;

		if (strength != *max1)
		{
			temp = strength;
			strength = *max1;
			*max1 = temp;
		}

		if (constitution != *max2)
		{
			temp = constitution;
			constitution = *max2;
			*max2 = temp;
		}

		//assign the rest of the values to the remaining abilities
		dexterity = abilitiesArray[2];
		intelligence = abilitiesArray[3];
		wisdom = abilitiesArray[4];
		charisma = abilitiesArray[5];

		//Test if the attribution of the abilitie scores has been done correctly
		/*cout << "final ability scores " << endl
			<< "Strength: " << strength << endl
			<< "dexterity: " << dexterity << endl
			<< "constitution: " << constitution << endl
			<< "intelligneceL " << intelligence << endl
			<< "wisdom: " << wisdom << endl
			<< "charisma: " << charisma << endl;*/

	}

	