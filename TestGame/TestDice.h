#pragma once
#include <cppunit/extensions/HelperMacros.h>
/**
 * @brief Test suite for the Dice class.
 */
class TestDice : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestDice);  /**< Declare test suite. */
	CPPUNIT_TEST(testRollDice);	/**< Test the RollDice method. */
	CPPUNIT_TEST(testAdditionOfDice); /**< Test the Addition part of the function RollDice. */
	CPPUNIT_TEST_SUITE_END(); /**< End of test suite declaration. */

public:
	/**
	* @brief Set up function to prepare the test environment.
	*/
	void setUp(void);

	/**
	* @brief Test case for the RollDice method.
	*/
	void tearDown(void);
	/**
	 * @brief Test case for the RollDice method.
	 */
	void testRollDice();
	/**
	* @brief Test case for testing the addition part of the RollDice method.
	*/
	void testAdditionOfDice();
};
// Register the test suite for automatic execution
CPPUNIT_TEST_SUITE_REGISTRATION(TestDice);