/**
 * @file TestItem.cpp
 * @brief Implementation of tests for the Item class.
 *
 * This file includes the implementation of tests for various functionalities of the Item,
 * Armor, Belt, Boots, Helmet, Ring, Shield, and Weapon classes.
 */
#include "TestItem.h"
#include "..\Game\Item.h"
#include "..\Game\Armor.h"
#include "..\Game\Belt.h"
#include "..\Game\Boots.h"
#include "..\Game\Helmet.h"
#include "..\Game\Ring.h"
#include "..\Game\Shield.h"
#include "..\Game\Weapon.h"




void TestItem::setUp() {
	// Initialization code here
}

void TestItem::tearDown() {
	// Cleanup code here
}
/// <summary>
/// Tests the constructor of the Item class
/// </summary>
void TestItem::testItem() {
	Item item(5, 10, 15, 20, 25, 30, 25, 20, 15);

	CPPUNIT_ASSERT(item.getIntelligence() == 5 && item.getWisdom() == 10 && item.getArmor() == 15 && item.getStrength() == 20 && item.getConstitution() == 25 && item.getCharisma() == 30 && item.getDexterity() == 25 && item.getAttackBonus() == 20 && item.getDamageBonus() == 15);
}
/// <summary>
/// Tests the constructor of the Armor class
/// </summary>
void TestItem::testArmor() {
	Armor armor(10);
	CPPUNIT_ASSERT(armor.getArmor() == 10);
}
/// <summary>
/// Tests the constructor of the Belt class
/// </summary>
void TestItem::testBelt() {
	Belt belt(10, 15);
	CPPUNIT_ASSERT(belt.getConstitution() == 10 && belt.getStrength() == 15);
}
/// <summary>
/// Tests the constructor of the Boots class
/// </summary>
void TestItem::testBoots() {
	Boots boots(10, 15);
	CPPUNIT_ASSERT(boots.getArmor() == 10 && boots.getDexterity() == 15);
}
/// <summary>
/// Tests the constructor of the helmet class
/// </summary>
void TestItem::testHelmet() {
	Helmet helmet(10, 20, 15);
	CPPUNIT_ASSERT(helmet.getIntelligence() == 10 && helmet.getWisdom() == 20 && helmet.getArmor() == 15);
}
/// <summary>
/// Tests the constructor of the Ring class
/// </summary>
void TestItem::testRing() {
	Ring ring(10, 15, 20, 25, 30);
	CPPUNIT_ASSERT(ring.getArmor() == 10 && ring.getStrength() == 15 && ring.getConstitution() == 20 && ring.getWisdom() == 25 && ring.getCharisma() == 30);
}
/// <summary>
/// Tests the constructor of the Shield class
/// </summary>
void TestItem::testShield() {
	Shield shield(10);
	CPPUNIT_ASSERT(shield.getArmor() == 10);
}
/// <summary>
/// Tests the constructor of the Weapon class
/// </summary>
void TestItem::testWeapon() {
	Weapon weapon(10, 15);
	CPPUNIT_ASSERT(weapon.getAttackBonus() == 10 && weapon.getDamageBonus() == 15);
}