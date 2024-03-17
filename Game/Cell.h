/**
 * @file Cell.h
 * @brief This file contains the Cell class used in the game.
 *
 * The Cell class represents a single cell in the game map. Each cell can have different types,
 * such as empty, wall, door, or chest, affecting the player's interaction with the game world.
 *
 * ## Game Rules:
 * - A cell of type 'wall' blocks player movement.
 * - A cell of type 'door' allows passage between rooms.
 * - A cell of type 'chest' can contain items for the player to collect.
 *
 * ## Design:
 * The Cell class is designed to be a fundamental building block of the game map, with a simple
 * structure to facilitate easy modification and interaction within the game logic. It supports
 * basic functionality such as setting and getting the cell type, which enables dynamic map generation
 * and interaction.
 *
 * ## Libraries Used:
 * - Standard Template Library (STL): Used for its robust data structures and algorithms which support
 * efficient manipulation and querying of cell properties.
 *
 * @note This class is a part of the map generation module and interacts closely with the Map class to
 * create comprehensive game environments.
 */

#pragma once
#include <iostream>
 // Enum to represent different types of cells within a map
enum class CellType {
	Empty,
	Wall,
	Door,
	Chest,
	Start,
	End,
	Character,
	Opponent
};

/// <summary>
/// Represents a cell within a map
/// </summary>
class Cell
{
public:
	Cell(int x, int y, CellType type);
	/// <summary>
	/// Constructs a cell with a given type
	/// </summary>
	/// <param name="type"> The type of the cell </param>
	Cell(CellType type = CellType::Empty);

	/// <summary>
	/// Returns the type of the cell
	/// </summary>
	/// <returns> The type of the cell </returns>
	CellType getType() const;
	/// <summary>
	/// Sets the type of the cell
	/// </summary>
	/// <param name="type"> The type of the cell </param>
	/// <returns> The type of the cell </returns>
	void setType(CellType type);

	/// <summary>
	/// Returns a string representation of the cell
	/// </summary>
	/// <returns> A string representation of the cell </returns>
	/// <remarks> The string representation is a single character representing the type of the cell </remarks>
	friend std::ostream& operator<<(std::ostream& os, const Cell& cell);

	/// <summary>
	/// Returns the character representation of the cell type
	/// </summary>
	/// <returns> The character representation of the cell type </returns>
	char getCellTypeChar() const; // Returns the character representation of the cell type

	/// <summary>
	/// Returns the x position of the cell
	/// </summary>
	/// <returns> The x position of the cell </returns>
	int getX() const;
	/// <summary>
	/// Returns the y position of the cell
	/// </summary>
	/// <returns> The y position of the cell </returns>
	int getY() const;

private:
	CellType type; // The type of the cell
protected:
	int x, y; // The position of the cell, not used for walls and empty cells
};

