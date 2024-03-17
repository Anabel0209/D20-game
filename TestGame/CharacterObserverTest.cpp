/**
 * @file CharacterObserverTest.cpp
 * @brief Implementation of tests for observer pattern.
 *
 * This file includes the implementation of tests for various functionalities of the observer patterns,
 * such as attaching an observer, detaching an observer and updating the observer
 */

#include "CharacterObserverTest.h"

//to be executed before all the test cases
void CharacterObserverTest::setUp(void)
{
	//create a fighter, a display and an armor
	myBasicFighter = new Fighter(1);
	aDisplay = new Display(myBasicFighter);
	anArmor = new Armor(2);

}

//to be executed after all the test cases
void CharacterObserverTest::tearDown(void)
{
	//delete all the created objects
	delete anArmor;

	if (aDisplay != nullptr)
	{
		delete aDisplay;
	}
	delete myBasicFighter;
}

//thest the attach method of the subject class
void CharacterObserverTest::testAttach(void)
{
	bool isAttached = false;

	//go through each elements of the list of observers
	for (Observer* observer : myBasicFighter->getObservers())
	{
		//if the display is found in the list, it has been attached correctly and the test passes
		if (observer == aDisplay)
		{
			isAttached = true;
		}
	}
	CPPUNIT_ASSERT(isAttached);
}

//test the detach method of the subject class
void CharacterObserverTest::testDetach(void)
{
	//delete the display (which triggers the destructor and thus the detach method)
	delete aDisplay;
	aDisplay = nullptr;

	bool isDetached = true;

	//go through each elements of the list of observers
	for (Observer* observer : myBasicFighter->getObservers())
	{
		//if the display is found in the list, the display has not beed detached correctly and the test fails
		if (observer == aDisplay)
		{
			isDetached = false;
		}
	}
	CPPUNIT_ASSERT(isDetached);
}

//test the update method of the observer class
void CharacterObserverTest::testUpdate(void)
{
	//add an armor item to the character
	myBasicFighter->setArmor(*anArmor);

	bool hasUpdated = false;

	//if the nb of updates done by the display is bigger than 0 the test passes
	if ((aDisplay->nbUpdates) >= 1)
	{
		hasUpdated = true;
	}
	CPPUNIT_ASSERT(hasUpdated);
}

