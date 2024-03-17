#pragma once
#include <cppunit/extensions/HelperMacros.h>
#include "..\Game\Map.h"

/**
 * @brief Test class for the Map class.
 *
 * This class contains unit tests for various functionalities of the Map class.
 */

class TestMap : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestMap); /**< Declare test suite. */
	CPPUNIT_TEST(testConstructor);
	CPPUNIT_TEST(testSetAndGetCellType);
	CPPUNIT_TEST(testClearMap);
	CPPUNIT_TEST(testGenerateRandomMap);
	CPPUNIT_TEST(testGenerateMap);
	CPPUNIT_TEST(testValidPath);
	CPPUNIT_TEST(testInvalidPath);
	CPPUNIT_TEST(testGetHeightAndWidth);
	CPPUNIT_TEST_SUITE_END();/**< End of test suite declaration. */

public:
	/** @brief Sets up the test fixture. */
	void setUp() override;
	/** @brief Tears down the test fixture. */
	void tearDown() override;

	/** @brief Tests the constructor of the Map class. */
	void testConstructor();

	/** @brief Tests the set and get cell type functions of the Map class. */
	void testSetAndGetCellType();

	/** @brief Tests the clear map function of the Map class. */
	void testClearMap();

	/** @brief Tests the generate random map function of the Map class. */
	void testGenerateRandomMap();

	/** @brief Tests the generate map function of the Map class. */
	void testGenerateMap();

	/** @brief Tests the validatePath function of the Map class. */
	void testValidPath();

	/** @brief Tests the validatePath function of the Map class by using it on an invalid map. */
	void testInvalidPath();

	/** @brief Tests the getHeight and getWidth functions of the Map class. */
	void testGetHeightAndWidth();

private:
	Map* testMap;
	Map* invalidMap;
};
// Register the test suite
CPPUNIT_TEST_SUITE_REGISTRATION(TestMap);