#pragma once
#include <cppunit/extensions/HelperMacros.h>	/**< Include for CPPUNIT_TEST_SUITE_REGISTRATION */
#include "..\Game\Character.h"					/**< Include for Fighter class and other related classes */
#include "..\Game\Display.h"					/**< Include for Display class and other related classes */

/**
 * @brief Test class for the character observer pattern.
 *
 * This class contains unit tests for various functionalities of the character observer pattern.
 */
class CharacterObserverTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(CharacterObserverTest);/**< Declare test suite. */
	CPPUNIT_TEST(testAttach);
	CPPUNIT_TEST(testDetach);


	CPPUNIT_TEST_SUITE_END(); /**< End of test suite declaration. */

public:
	/** @brief Sets up the test fixture. */
	void setUp(void);
	/** @brief Tears down the test fixture. */
	void tearDown(void);

protected:
	/** @brief Tests the Attach method of the Subject class. */
	void testAttach(void);

	/** @brief Tests Detach method of the Subject class. */
	void testDetach(void);

	/** @brief Tests Update method of the observer. */
	void testUpdate(void);


private:
	Fighter* myBasicFighter;	 ///< Pointer to a basic Fighter object.
	Display* aDisplay;				///< Pointer to a basic Display object.
	Armor* anArmor;				///< Pointer to a basic Armor object.
};
// Register the test suite
CPPUNIT_TEST_SUITE_REGISTRATION(CharacterObserverTest);