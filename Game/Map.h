/**
 * @file Map.h
 * @brief This file contains the Map class used to represent the game world.
 *
 * The Map class is responsible for managing a 2D array of Cells, representing the game's environment.
 * It supports operations such as map generation, pathfinding, and rendering, providing a dynamic setting
 * for gameplay.
 *
 * ## Game Rules:
 * - The map consists of interconnected rooms and corridors, with doors facilitating movement.
 * - Walls define the boundaries of rooms and corridors, restricting player movement.
 * - Chests and other interactable objects are placed throughout the map for players to discover.
 *
 * ## Design:
 * The Map class uses a combination of procedural generation techniques for map creation, ensuring each
 * game experience is unique. It incorporates pathfinding algorithms to validate map connectivity and to
 * assist AI movement. The class is designed to be flexible, allowing for future expansions such as new
 * cell types or map features.
 *
 * ## Libraries Used:
 * - Standard Template Library (STL): For its efficient data structures, particularly vectors, to store
 * the 2D map grid.
 * - Custom Algorithms: For pathfinding and map validation, tailored to the specific requirements of the
 * game's design and mechanics.
 *
 * @note The Map class is central to the game's mechanics, affecting both the challenge and the exploration
 * aspects of gameplay.
 */

#pragma once
#include <vector>
#include <iostream>
#include "Cell.h"
#include "Character.h"
#include "Chest.h"
#include "Door.h"
class Map
{
public:
	// ----------------Constructor----------------
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="width"> Width of the map</param>
	/// <param name="length"> Length of the map</param>
	Map(int width, int length);


	// ----------------Getters----------------
	/// <summary>
	/// Get the cell at the given position
	/// </summary>
	/// <param name="x"> x position</param>
	/// <param name="y"> y position</param>
	/// <returns>The cell type at the given position</returns>
	CellType getCellType(int x, int y);

	/// <summary>
	/// Get the width of the map
	/// </summary>
	/// <returns>The width of the map</returns>
	int getWidth() const;

	/// <summary>
	/// Get the height of the map
	/// </summary>
	/// <returns>The height of the map</returns>
	int getHeight() const;

	/// <summary>
	/// Get the player's view of the map (5x5 grid)
	/// </summary>
	/// <returns>A 5x5 2D vector of cells</returns>
	std::vector<std::vector<Cell>> getPlayerView() const;//Get the the player's view of the map (5x5 grid)


	// ----------------Setters----------------
	/// <summary>
	/// Set the cell at the given position to the given type
	/// </summary>
	/// <param name="x"> x position</param>
	/// <param name="y"> y position</param>
	/// <param name="type">Type of the cell</param>
	void setCell(int x, int y, CellType type);

	void setPlayer(Character* player);


	// ----------------Methods----------------
	/// <summary>
	/// Clears the map by setting all cells to empty
	/// </summary>
	void clearMap();

	/// <summary>
	/// Overload the << operator to print the map
	/// </summary>
	/// <param name="os"> output stream</param>
	/// <param name="map"> map to print</param>
	/// <returns>The output stream</returns>
	friend std::ostream& operator<<(std::ostream& os, const Map& map);

	//Adding a character, chests and doors to the map
	void addChest(Chest* chest);
	void addDoor(Door* door);


	//Manage the player's movement
	bool movePlayer(int direction, int amount);


	// ----------------Static Methods----------------
	/// <summary>
	/// Generate a random map
	/// </summary>
	/// <param name="width"> Width of the map</param>
	/// <param name="height"> Height of the map</param>
	/// <param name="probWall"> Probability of a cell being a wall</param>
	/// <param name="probDoor"> Probability of a cell being a door</param>
	/// <param name="probChest"> Probability of a cell being a chest</param>
	/// <returns>A random map</returns>
	static Map generateRandomMap(int width, int height, double probWall, double probDoor, double probChest);

	/// <summary>
	/// Generates a predefined 15x15 map
	/// </summary>
	/// <returns>A predefined map</returns>
	static Map generateMap();

	/// <summary>
	/// Validates the map by checking if there is a path from the start of the map to the end
	/// </summary>
	/// <param name="map"> the map to validate</param>
	/// <returns> true if there is a path, false otherwise</returns>
	static bool validatePath(Map& map);

	/// <summary>
	/// Display a 2D vector of Cells
	/// </summary>
	/// <param name="grid">The 2D vector of Cells to display</param>
	static void displayGrid(std::vector<std::vector<Cell>> grid);

private:
	int width, height; // width and height of the map
	std::vector<std::vector<Cell>> grid; // 2D vector of cells
	static bool dfs(Map& map, int x, int y, std::vector<std::vector<bool>>& visited); // depth first search to check if there is a path from the start to the end
	Character* player; // player character
	void checkCollision(); //TODO
};