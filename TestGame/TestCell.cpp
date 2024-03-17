/**
 * @file TestCell.cpp
 * @brief Implementation of tests for the Cell class.
 *
 * This file includes the implementation of tests for various functionalities of the Cell class,
 * including construction, type setting and getting, and comparison operations. It makes use of the
 * CppUnit framework for setting up the test suite and assertions.
 */

#include "TestCell.h"
#include "..\Game\Cell.h"

void TestCell::setUp() {
	// Initialization code here
}

void TestCell::tearDown() {
	// Cleanup code here
}

void TestCell::testConstructor() {
	Cell cell(CellType::Empty);
	CPPUNIT_ASSERT(cell.getType() == CellType::Empty);
}

void TestCell::testSetType() {
	Cell cell(CellType::Empty);
	cell.setType(CellType::Wall);
	CPPUNIT_ASSERT(cell.getType() == CellType::Wall);
}

void TestCell::testGetType() {
	Cell cell(CellType::Empty);
	CPPUNIT_ASSERT(cell.getType() == CellType::Empty);
}