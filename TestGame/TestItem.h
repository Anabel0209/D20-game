#pragma once
#include <cppunit/extensions/HelperMacros.h>

/**
 * @brief Test class for the Item class.
 *
 * This class contains unit tests for various functionalities of the Item class.
 */
class TestItem : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestItem);/**< Declare test suite. */
	CPPUNIT_TEST(testItem);
	CPPUNIT_TEST(testArmor);
	CPPUNIT_TEST(testBelt);
	CPPUNIT_TEST(testBoots);
	CPPUNIT_TEST(testHelmet);
	CPPUNIT_TEST(testRing);
	CPPUNIT_TEST(testShield);
	CPPUNIT_TEST(testWeapon);
	CPPUNIT_TEST_SUITE_END();/**< End of test suite declaration. */

public:
	/** @brief Sets up the test fixture. */
	void setUp() override;
	/** @brief Tears down the test fixture. */
	void tearDown() override;

	/** @brief Tests the Item class. */
	void testItem();

	/** @brief Tests the Armor class. */
	void testArmor();

	/** @brief Tests the Belt class. */
	void testBelt();

	/** @brief Tests the Boots class. */
	void testBoots();

	/** @brief Tests the Helmet class. */
	void testHelmet();

	/** @brief Tests the Ring class. */
	void testRing();

	/** @brief Tests the Shield class. */
	void testShield();

	/** @brief Tests the Weapon class. */
	void testWeapon();
};

// Register the test suite
CPPUNIT_TEST_SUITE_REGISTRATION(TestItem);