#include "Door.h"

Door::Door(int x, int y): Cell(x,y, CellType::Door)
{
	lockedStatus = true;
}

Door::~Door()
{
}

void Door::unlock()
{
	lockedStatus = false;
}

void Door::lock()
{
	lockedStatus = true;
}

bool Door::isLocked() const
{
	return lockedStatus;
}

int Door::getX() const {
	return x;
}

int Door::getY() const {
	return y;
}