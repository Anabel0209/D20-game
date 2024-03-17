#include "Container.h"
#include "Item.h"
#include <random>

Container::Container(const Item& item)
{
	this->item = item;
}
Container::~Container()
{
}
/// <summary>
/// Opens the container and returns the item within
/// </summary>
/// <returns>Item from container</returns>
Item Container::Open()
{
	return item;
}
/// <summary>
/// Replaces the Item in the container
/// </summary>
void Container::Put(Item& item)
{
	this->item = item;
}
