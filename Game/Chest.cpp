#include "Chest.h"
#include "Item.h"

Chest::Chest(const Item& item , int x, int y): Container(item), Cell(x, y, CellType::Chest)
{
	openStatus = false;
}

Chest::~Chest()
{
}

bool Chest::wasOpened() const
{
	return openStatus;
}

Item Chest::Open()
{
	openStatus = true;
	return Container::Open();
}

void Chest::Put(Item& item)
{
	openStatus = false;
	Container::Put(item);
}