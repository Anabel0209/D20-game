#include "Map.h"
#include <iostream>
#include <vector>


//Contructor
Map::Map(int width, int height) : width(width), height(height), grid(height, std::vector<Cell>(width))
{
	grid[0][0].setType(CellType::Start);
	grid[height - 1][width - 1].setType(CellType::End);
	// Set a default fighter to be the player
	player = new Fighter(1);
	setPlayer(player);
}

void Map::setCell(int x, int y, CellType type) {
	// If the cell is the start or end, don't change it
	if ((x == 0 && y == 0) || (x == width - 1 && y == height - 1)) {
		return;
	}

	if (x < width && y < height) {
		grid[y][x].setType(type);
	}
}

CellType Map::getCellType(int x, int y) {
	// If the coordinates are out of bounds, return empty
	if (x < width && y < height) {
		return grid[y][x].getType();
	}
	return CellType::Empty;
}

void Map::clearMap() {
	// Clear the map
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			grid[y][x].setType(CellType::Empty);
		}
	}
	grid[0][0].setType(CellType::Start);
	grid[height - 1][width - 1].setType(CellType::End);
}

bool Map::validatePath(Map& map) {
	std::vector<std::vector<bool>> visited(map.height, std::vector<bool>(map.width, false));

	return dfs(map, 0, 0, visited);
}

bool Map::dfs(Map& map, int x, int y, std::vector<std::vector<bool>>& visited) {
	if (x < 0 || x >= map.width || y < 0 || y >= map.height) {
		return false;
	}
	if (map.getCellType(x, y) == CellType::Wall || map.getCellType(x, y) == CellType::Chest || visited[y][x]) {
		return false;
	}
	if (map.grid[y][x].getType() == CellType::End) {
		return true;
	}

	visited[y][x] = true;
	if (dfs(map, x + 1, y, visited) || dfs(map, x, y + 1, visited) || dfs(map, x - 1, y, visited) || dfs(map, x, y - 1, visited)) {
		return true;
	}
	return false;
}

Map Map::generateRandomMap(int width, int height, double probWall, double probDoor, double probChest) {
	Map map(width, height);


	// Validate and regenerate the map if it doesn't meet the criteria
	do {
		// Clear the map
		map.clearMap();

		// Generate the map
		srand(time(NULL)); // Seed the random number generator

		for (int x = 0; x < width; x++) {
			for (int y = 0; y < height; y++) {
				double r = (double)rand() / RAND_MAX;
				if (r < probWall) {
					// Place a wall
					int wallLength = rand() % 4 + 2; // Randomly choose wall length between 2 and 5

					// Randomly choose wall direction (horizontal or vertical)
					bool isHorizontal = rand() % 2;

					// Place the wall segment
					for (int i = 0; i < wallLength; i++) {
						int newX = x + (isHorizontal ? i : 0);
						int newY = y + (isHorizontal ? 0 : i);

						// Check bounds before placing the wall
						if (newX < width && newY < height) {
							map.setCell(newX, newY, CellType::Wall);
						}
						else {
							// If the wall exceeds bounds, stop extending it
							break;
						}
					}
				}
				else if (r < probWall + probChest) {
					// Place a chest
					map.addChest(new Chest(Item(1, 1, 1, 1, 1, 1, 1, 1, 1), x, y));
				}
			}
		}

		// Place doors only between walls
		for (int x = 1; x < width - 1; x++) {
			for (int y = 1; y < height - 1; y++) {
				if (map.getCellType(x, y) == CellType::Empty) {
					// Check horizontal and vertical neighbors for a potential door placement
					if ((map.getCellType(x - 1, y) == CellType::Wall && map.getCellType(x + 1, y) == CellType::Wall) ||
						(map.getCellType(x, y - 1) == CellType::Wall && map.getCellType(x, y + 1) == CellType::Wall)) {
						if ((double)rand() / RAND_MAX < probDoor) {
							// Doors are only placed in between walls
							map.addDoor(new Door(x, y));
						}
					}
				}
			}
		}
	} while (!validatePath(map));

	return map;
}

// Generate a 15x15 map with a fixed layout
// Easy for quick showcase
Map Map::generateMap() {
	Map map(15, 15);
	map.setCell(1, 1, CellType::Wall);
	map.setCell(1, 2, CellType::Wall);
	map.setCell(1, 3, CellType::Wall);
	map.setCell(1, 4, CellType::Wall);
	map.setCell(1, 5, CellType::Wall);
	map.setCell(1, 6, CellType::Wall);
	map.setCell(1, 7, CellType::Wall);
	map.setCell(1, 8, CellType::Wall);
	map.setCell(1, 9, CellType::Wall);
	map.setCell(2, 9, CellType::Wall);
	map.setCell(3, 9, CellType::Wall);
	map.setCell(4, 9, CellType::Wall);
	map.setCell(5, 9, CellType::Wall);
	map.setCell(6, 9, CellType::Wall);
	map.setCell(7, 9, CellType::Wall);
	map.setCell(8, 9, CellType::Wall);
	map.setCell(9, 9, CellType::Wall);
	map.setCell(10, 9, CellType::Wall);
	map.setCell(11, 9, CellType::Wall);
	map.setCell(12, 9, CellType::Wall);
	map.setCell(13, 9, CellType::Wall);
	map.setCell(14, 9, CellType::Wall);
	map.setCell(4, 9, CellType::Wall);
	map.setCell(4, 10, CellType::Wall);
	map.setCell(4, 11, CellType::Wall);
	map.setCell(4, 12, CellType::Wall);
	map.setCell(4, 13, CellType::Wall);
	map.setCell(3, 13, CellType::Wall);
	map.setCell(2, 13, CellType::Wall);
	map.setCell(2, 12, CellType::Wall);
	map.setCell(2, 11, CellType::Wall);
	map.setCell(2, 2, CellType::Wall);
	map.setCell(3, 2, CellType::Wall);
	map.setCell(4, 2, CellType::Wall);
	map.setCell(5, 2, CellType::Wall);
	map.setCell(6, 2, CellType::Wall);
	map.setCell(7, 2, CellType::Wall);
	map.setCell(7, 3, CellType::Wall);
	map.setCell(7, 4, CellType::Wall);
	map.setCell(7, 5, CellType::Wall);
	map.setCell(6, 5, CellType::Wall);
	map.setCell(5, 5, CellType::Wall);
	map.setCell(5, 6, CellType::Wall);
	map.setCell(2, 4, CellType::Wall);
	map.setCell(3, 4, CellType::Wall);
	map.addChest(new Chest(Item(1, 1, 1, 1, 1, 1, 1, 1, 1), 2, 3));
	map.addDoor(new Door(3, 14));

	return map;
}

void Map::displayGrid(std::vector<std::vector<Cell>> grid) {
	// Print the map
	std::cout << '+' << std::string(grid.size(), '-') << '+' << '\n';
	for (const auto& row : grid) {
		std::cout << '|';
		for (const auto& cell : row) {
			std::cout << cell;
		}
		std::cout << '|' << '\n';
	}
	std::cout << '+' << std::string(grid.size(), '-') << '+' << '\n';
}

std::ostream& operator<<(std::ostream& os, const Map& map) {
	//Copy the grid and add the player
	auto tempGrid = map.grid;
	tempGrid[map.player->getY()][map.player->getX()] = Cell(CellType::Character);
	// Print the map
	os << '+' << std::string(map.width, '-') << '+' << '\n';
	for (const auto& row : tempGrid) {
		os << '|';
		for (const auto& cell : row) {
			os << cell;
		}
		os << '|' << '\n';
	}
	os << '+' << std::string(map.width, '-') << '+' << '\n';
	return os;
}

int Map::getWidth() const {
	return width;
}

int Map::getHeight() const {
	return height;
}

void Map::addChest(Chest* chest) {
	grid[chest->getY()][chest->getX()].setType(CellType::Chest);
}

void Map::addDoor(Door* door) {
	grid[door->getY()][door->getX()].setType(CellType::Door);
}

void Map::setPlayer(Character* player) {
	this->player = player;
	player->setPosition(0, 0);
}

bool Map::movePlayer(int direction, int amount) {
	// Assume player's current position is stored in playerX and playerY
	int targetX = player->getX();
	int targetY = player->getY();

	// Calculate target position based on direction and amount
	switch (direction) {
	case 0: // North
		targetY -= amount;
		break;
	case 1: // East
		targetX += amount;
		break;
	case 2: // South
		targetY += amount;
		break;
	case 3: // West
		targetX -= amount;
		break;
	default:
		return false; // Invalid direction
	}

	// Check map boundaries
	if (targetX < 0 || targetX >= width || targetY < 0 || targetY >= height) {
		return false; // Out of bounds
	}

	// Check cell type at target position
	CellType targetType = getCellType(targetX, targetY);
	if (targetType == CellType::Empty || targetType == CellType::Door) {
		// Move player to the new position
		player->setPosition(targetX, targetY);
		return true;
	}

	return false; // Target cell is not empty or a door
}

std::vector<std::vector<Cell>> Map::getPlayerView() const {
	// Get the player's position
	int playerX = player->getX();
	int playerY = player->getY();

	//Character view size
	int viewSize = 5;

	// Create a 3x3 grid centered around the player
	std::vector<std::vector<Cell>> view(viewSize, std::vector<Cell>(viewSize));
	for (int x = -2; x <= 2; x++) {
		for (int y = -2; y <= 2; y++) {
			// Calculate the position of the cell in the map
			int mapX = playerX + x;
			int mapY = playerY + y;

			// Check if the position is within the map boundaries
			if (mapX >= 0 && mapX < width && mapY >= 0 && mapY < height) {
				// Copy the cell from the map to the view
				view[y + 2][x + 2] = grid[mapY][mapX];
			}
			else {
				// If the position is outside the map, set the cell type to wall
				view[y + 2][x + 2].setType(CellType::Wall);
			}
		}
	}
	// Set the center cell to the player character
	view[2][2].setType(CellType::Character);
	return view;
}