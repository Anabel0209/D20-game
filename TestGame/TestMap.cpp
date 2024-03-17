/**
 * @file TestMap.cpp
 * @brief Implementation of tests for the Map class.
 *
 * This file includes the implementation of tests for various functionalities of the Map,
 * such as the constructor, setting and getting cell types, clearing the map, generating
 * random maps, and validating paths.
 */

#include "TestMap.h"
#include "..\Game\Map.h"
#include "..\Game\Cell.h"


void TestMap::setUp() {
	testMap = new Map(10, 20);
	invalidMap = new Map(2, 2);
	invalidMap->setCell(0,1,CellType::Wall);
	invalidMap->setCell(1,0,CellType::Wall);
}

void TestMap::tearDown() {
	delete testMap;
	delete invalidMap;
}

void TestMap::testConstructor() {
    
    CPPUNIT_ASSERT(testMap->getWidth() == 10 && testMap->getHeight() == 20);
}

void TestMap::testSetAndGetCellType() {
	testMap->setCell(5, 5, CellType::Wall);
	CPPUNIT_ASSERT(testMap->getCellType(5, 5) == CellType::Wall);
}

void TestMap::testClearMap() {
	testMap->setCell(5, 5, CellType::Wall);
	testMap->clearMap();
	CPPUNIT_ASSERT(testMap->getCellType(5, 5) == CellType::Empty);
}

void TestMap::testGenerateRandomMap() {
	int width = 10;
	int height = 20;
	double probWall = 0.07;
	double probDoor = 0.08;
	double probChest = 0.002;
	Map tempMap = Map::generateRandomMap(width, height, probWall, probDoor, probChest);
	CPPUNIT_ASSERT(tempMap.getWidth() == 10 && tempMap.getHeight() == 20);
	CPPUNIT_ASSERT(Map::validatePath(tempMap));
}

void TestMap::testGenerateMap() {
	Map tempMap = Map::generateMap();
	CPPUNIT_ASSERT(tempMap.getWidth() == 15 && tempMap.getHeight() == 15);
	CPPUNIT_ASSERT(Map::validatePath(tempMap));
}

void TestMap::testValidPath() {
	CPPUNIT_ASSERT(testMap->validatePath(*testMap));
}

void TestMap::testInvalidPath() {
	CPPUNIT_ASSERT(!invalidMap->validatePath(*invalidMap));
}

void TestMap::testGetHeightAndWidth() {
	CPPUNIT_ASSERT(testMap->getWidth() == 10 && testMap->getHeight() == 20);
}