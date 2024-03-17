/**
 * @brief Test class for the Cell class.
 *
 * This class contains unit tests for various functionalities of the Cell class.
 */

#pragma once
#include <cppunit/extensions/HelperMacros.h>/**< Include for CPPUNIT_TEST_SUITE_REGISTRATION */
class TestCell : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestCell); /**< Declare test suite. */
	CPPUNIT_TEST(testConstructor);
	CPPUNIT_TEST(testSetType);
	CPPUNIT_TEST(testGetType);
	CPPUNIT_TEST_SUITE_END();/**< End of test suite declaration. */

public:
	/** @brief Sets up the test fixture. */
	void setUp() override;
	/** @brief Tears down the test fixture. */
	void tearDown() override;

	/** @brief Tests the constructor of the Cell class. */
	void testConstructor();
	/** @brief Tests the setType method of the Cell class. */
	void testSetType();
	/** @brief Tests the getType method of the Cell class. */
	void testGetType();
};
// Register the test suite
CPPUNIT_TEST_SUITE_REGISTRATION(TestCell);