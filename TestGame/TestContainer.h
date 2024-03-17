#pragma once
#include <cppunit/extensions/HelperMacros.h>

/**
 * @brief Test class for the Container class.
 *
 * This class contains unit tests for various functionalities of the Container class.
 */

class TestContainer : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestContainer);/**< Declare test suite. */
	CPPUNIT_TEST(testContainerOpen);
	CPPUNIT_TEST(testContainerPut);
	CPPUNIT_TEST_SUITE_END();/**< End of test suite declaration. */

public:
	/** @brief Sets up the test fixture. */
	void setUp() override;
	/** @brief Tears down the test fixture. */
	void tearDown() override;

	/** @brief Tests the Container::open() method. */
	void testContainerOpen();
	/** @brief Tests the Container::put() method. */
	void testContainerPut();
};
// Register the test suite
CPPUNIT_TEST_SUITE_REGISTRATION(TestContainer);