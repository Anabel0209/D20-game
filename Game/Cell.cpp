#include "Cell.h"
#include <iostream>
Cell::Cell(CellType type)
{
    this->type = type;
}

Cell::Cell(int x, int y, CellType type)
{
	this->type = type;
	this->x = x;
	this->y = y;
}

char Cell::getCellTypeChar() const {
    switch (type) {
    case CellType::Empty: return ' ';
    case CellType::Wall:  return '#';
    case CellType::Door:  return 'D';
    case CellType::Chest: return 'C';
    case CellType::Start: return 'S';
    case CellType::End:   return 'E';
    case CellType::Character: return 'P';
    case CellType::Opponent: return 'O';
    default:              return '?';
    }
}

std::ostream& operator<<(std::ostream& os, const Cell& cell) {
    os << cell.getCellTypeChar();
    return os;
}

CellType Cell::getType() const {
	return type;
}

void Cell::setType(CellType type) {
	this->type = type;
}

int Cell::getX() const {
	return x;
}

int Cell::getY() const {
	return y;
}