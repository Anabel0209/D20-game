/**
 * @file TestContainer.cpp
 * @brief Implementation of tests for the Container class.
 *
 * This file includes the implementation of tests for various functionalities of the Container, 
 * including opening and putting items into the container.
 */
#include "TestContainer.h"
#include "..\Game\Item.h"
#include "..\Game\Container.h"

void TestContainer::setUp() {
	// Initialization code here
}

void TestContainer::tearDown() {
	// Cleanup code here
}
/// <summary>
/// Tests if, when a new container is made with an item, it will open and return said item
/// </summary>
void TestContainer::testContainerOpen() {
	Item item(5, 10, 15, 20, 25, 30, 25, 20, 15);
	Container container(item);
	CPPUNIT_ASSERT(container.Open().getIntelligence() == 5 && container.Open().getWisdom() == 10 && container.Open().getArmor() == 15 && container.Open().getStrength() == 20 && container.Open().getConstitution() == 25 && container.Open().getCharisma() == 30 && container.Open().getDexterity() == 25 && container.Open().getAttackBonus() == 20 && container.Open().getDamageBonus() == 15);
}
/// <summary>
/// Tests if, when a new container is made with an item, a new Item could be put into
/// </summary>
void TestContainer::testContainerPut() {
	Item itemstart(5, 10, 15, 20, 25, 30, 25, 20, 15);
	Container container(itemstart);
	Item item(5, 10, 15, 20, 25, 30, 25, 20, 15);
	container.Put(item);
	CPPUNIT_ASSERT(container.Open().getIntelligence() == 5 && container.Open().getWisdom() == 10 && container.Open().getArmor() == 15 && container.Open().getStrength() == 20 && container.Open().getConstitution() == 25 && container.Open().getCharisma() == 30 && container.Open().getDexterity() == 25 && container.Open().getAttackBonus() == 20 && container.Open().getDamageBonus() == 15);
}