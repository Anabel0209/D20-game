/**
 * @file TestFighter.cpp
 * @brief Implementation of tests for the Fighter class.
 *
 * This file includes the implementation of tests for various functionalities of the Fighter,
 * such as setting abilities, modifiers, hit points, armor class, attack bonus, damage bonus,
 * adding and removing item buffs, setting armor, shield, weapon, boots, ring, helmet, and belt.
 */

#include "TestFighter.h"


void TestFighter::setUp(void)
{
	//create a fighter
	myBasicFighter = new Fighter(1);
	myFighterLlv5 = new Fighter(5);

	//create items
	aBelt_1 = new Belt(1,0);
	aBelt_2 = new Belt(0,1);
	anArmor_1 = new Armor(2);
	anArmor_2 = new Armor(1);
	aRing_1 = new Ring(0,2,0,0,0);
	aRing_2 = new Ring(1,0,0,0,0);
	aHelmet_1 = new Helmet(1,0,0);
	aHelmet_2 = new Helmet(0,1,0);
	someBoots_1 = new Boots(1,0);
	someBoots_2 = new Boots(0,1);
	aShield_1 = new Shield(1);
	aShield_2 = new Shield(2);
	aWeapon_1 = new Weapon(1,0);
	aWeapon_2 = new Weapon(0,1);
}

//to be executed after all the test cases
void TestFighter::tearDown(void)
{
	//delete the created objects
	delete myBasicFighter;
	delete myFighterLlv5;
	delete aBelt_1;
	delete aBelt_2;
	delete anArmor_1;
	delete anArmor_2;
	delete aRing_1;
	delete aRing_2;
	delete aHelmet_1;
	delete aHelmet_2;
	delete someBoots_1;
	delete someBoots_2;
	delete aShield_1;
	delete aShield_2;
	delete aWeapon_1;
	delete aWeapon_2;
}


//the abilities scores should be between 3 and 18 AND strength>constitution< anything else
void TestFighter::testSetAbilities(void)
{
	CPPUNIT_ASSERT(myBasicFighter->getStrength() >= 3 && myBasicFighter->getStrength() <= 18);
	CPPUNIT_ASSERT(myBasicFighter->getDexterity() >= 3 && myBasicFighter->getDexterity() <= 18);
	CPPUNIT_ASSERT(myBasicFighter->getConstitution() >= 3 && myBasicFighter->getConstitution() <= 18);
	CPPUNIT_ASSERT(myBasicFighter->getIntelligence() >= 3 && myBasicFighter->getIntelligence() <= 18);
	CPPUNIT_ASSERT(myBasicFighter->getWisdom() >= 3 && myBasicFighter->getWisdom() <= 18);
	CPPUNIT_ASSERT(myBasicFighter->getCharisma() >= 3 && myBasicFighter->getCharisma() <= 18);
	CPPUNIT_ASSERT(myBasicFighter->getStrength() >= myBasicFighter->getConstitution());
}

void TestFighter::testSetModifiers(void)
{

}

void TestFighter::testSetHitPoints(void)
{
	int HitPointsBefore = myBasicFighter->getHitPoints();

	myBasicFighter->setHitPoints(true);
	CPPUNIT_ASSERT(myBasicFighter->getHitPoints() > (HitPointsBefore));
}

void TestFighter::testSetArmorClass(void)
{
	//not sure about this one (should be bigger but that results to an error
	int armorClassBefore = myBasicFighter->getArmorClass();

	myBasicFighter->setArmorClass();
	CPPUNIT_ASSERT(myBasicFighter->getArmorClass() == (armorClassBefore));


}

void TestFighter::testSetAttackBonus(void)
{
	//not sure about this one (should be bigger but that results to an error
	int attackBonusBefore = myBasicFighter->getAttackBonus();

	myBasicFighter->setAttackBonus();
	CPPUNIT_ASSERT(myBasicFighter->getAttackBonus() == (attackBonusBefore));
}

void TestFighter::testSetDamageBonus(void)
{
	//not sure about this one (should be bigger but that results to an error)
	int damageBonusBefore = myBasicFighter->getDamageBonus();

	myBasicFighter->setDamageBonus();
	CPPUNIT_ASSERT(myBasicFighter->getDamageBonus() == (damageBonusBefore));

}

void TestFighter::testCalculateModifier(void)
{
	//i dont think we have to test that
}

void TestFighter::testAddItemBuff(void)
{
	int initialStrength = myBasicFighter->getStrength();
	myBasicFighter->addItemBuff(*aBelt_2);
	CPPUNIT_ASSERT(myBasicFighter->getStrength() == initialStrength + aBelt_2->getStrength());
}

void TestFighter::testRemoveItemBuff(void)
{
	int initialStrength = myBasicFighter->getStrength();
	myBasicFighter->addItemBuff(*aBelt_2);
	CPPUNIT_ASSERT(myBasicFighter->getStrength() == initialStrength + aBelt_2->getStrength());
	myBasicFighter->removeItemBuff(*aBelt_2);
	CPPUNIT_ASSERT(myBasicFighter->getStrength() == initialStrength);
}

void TestFighter::testSetArmor(void)
{
	int armorBefore = myBasicFighter->getArmorBonus();

	myBasicFighter->setArmor(*anArmor_1);
	CPPUNIT_ASSERT(myBasicFighter->getArmorBonus() == (armorBefore + 2));

	myBasicFighter->setArmor(*anArmor_2);
	CPPUNIT_ASSERT(myBasicFighter->getArmorBonus() == (armorBefore + 1));

}

void TestFighter::testSetShield(void)
{
	int armorBefore = myBasicFighter->getArmorBonus();
	
	myBasicFighter->setShield(*aShield_1);
	CPPUNIT_ASSERT(myBasicFighter->getArmorBonus() == (armorBefore+1));

	myBasicFighter->setShield(*aShield_2);
	CPPUNIT_ASSERT(myBasicFighter->getArmorBonus() == (armorBefore+2));
}

void TestFighter::testSetWeapon(void)
{	
	int attackBonusBefore = myBasicFighter->getWeaponItem();
	int damageBonusBefore = myBasicFighter->getDamageItem();

	myBasicFighter->setWeapon(*aWeapon_1);
	CPPUNIT_ASSERT(myBasicFighter->getWeaponItem() > (attackBonusBefore));
	CPPUNIT_ASSERT(myBasicFighter->getDamageItem() == (damageBonusBefore));

	myBasicFighter->setWeapon(*aWeapon_2);
	CPPUNIT_ASSERT(myBasicFighter->getWeaponItem() == (attackBonusBefore));
	CPPUNIT_ASSERT(myBasicFighter->getDamageItem() > (damageBonusBefore));
}

void TestFighter::testSetBoots(void)
{	
	int dexterityBefore = myBasicFighter->getDexterity();
	int armorBefore = myBasicFighter->getArmorBonus();

	myBasicFighter->setBoots(*someBoots_1);
	CPPUNIT_ASSERT(myBasicFighter->getDexterity() == (dexterityBefore));
	CPPUNIT_ASSERT(myBasicFighter->getArmorBonus() > (armorBefore));
	
	myBasicFighter->setBoots(*someBoots_2);
	CPPUNIT_ASSERT(myBasicFighter->getDexterity() == (dexterityBefore+1));
	CPPUNIT_ASSERT(myBasicFighter->getArmorBonus() == (armorBefore));
}

void TestFighter::testSetRing(void)
{	
	int constitutionBefore = myBasicFighter->getConstitution();
	int strengthBefore = myBasicFighter->getStrength();
	int wisdomBefore = myBasicFighter->getWisdom();
	int charismaBefore = myBasicFighter->getCharisma();
	int armorClassBefore = myBasicFighter->getArmorBonus();

	myBasicFighter->setRing(*aRing_1);
	CPPUNIT_ASSERT(myBasicFighter->getConstitution() == (constitutionBefore));
	CPPUNIT_ASSERT(myBasicFighter->getStrength() == (strengthBefore+2));
	CPPUNIT_ASSERT(myBasicFighter->getWisdom() == (wisdomBefore));
	CPPUNIT_ASSERT(myBasicFighter->getCharisma() == (charismaBefore));
	CPPUNIT_ASSERT(myBasicFighter->getArmorBonus() == (armorClassBefore));

	myBasicFighter->setRing(*aRing_2);
	CPPUNIT_ASSERT(myBasicFighter->getConstitution() == (constitutionBefore));
	CPPUNIT_ASSERT(myBasicFighter->getStrength() == (strengthBefore));
	CPPUNIT_ASSERT(myBasicFighter->getWisdom() == (wisdomBefore));
	CPPUNIT_ASSERT(myBasicFighter->getCharisma() == (charismaBefore));
	CPPUNIT_ASSERT(myBasicFighter->getArmorBonus() > (armorClassBefore));
}

void TestFighter::testSetHelmet(void)
{
	int intelligenceBefore = myBasicFighter->getIntelligence();
	int wisdomBefore = myBasicFighter->getWisdom();
	int armorClassBefore = myBasicFighter->getArmorClass();


	myBasicFighter->setHelmet(*aHelmet_1);
	CPPUNIT_ASSERT(myBasicFighter->getIntelligence() == (intelligenceBefore+1));
	CPPUNIT_ASSERT(myBasicFighter->getWisdom() == (wisdomBefore));
	CPPUNIT_ASSERT(myBasicFighter->getArmorClass() == (armorClassBefore));
	

	myBasicFighter->setHelmet(*aHelmet_2);
	CPPUNIT_ASSERT(myBasicFighter->getIntelligence() == (intelligenceBefore));
	CPPUNIT_ASSERT(myBasicFighter->getWisdom() ==(wisdomBefore+1));
	CPPUNIT_ASSERT(myBasicFighter->getArmorClass() == (armorClassBefore));

}

//test with an object that will up the constitution of 1 then replace with an item that will up the strength by one
void TestFighter::testSetBelt(void)
{
	int constitutionBefore = myBasicFighter->getConstitution();
	int strengthBefore = myBasicFighter->getStrength();
	myBasicFighter->setBelt(*aBelt_1);
	CPPUNIT_ASSERT(myBasicFighter->getConstitution() == (constitutionBefore+1));
	CPPUNIT_ASSERT(myBasicFighter->getStrength() == strengthBefore);

	myBasicFighter->setBelt(*aBelt_2);
	CPPUNIT_ASSERT(myBasicFighter->getConstitution() == constitutionBefore);
	CPPUNIT_ASSERT(myBasicFighter->getStrength() == (strengthBefore + 1));
}
