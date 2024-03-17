/**
 * @file Container.h
 * @brief This file contains the definition of the Container class, which is part of a game's inventory system.
 *
 * Game Rules:
 * - The Container class is designed to represent a storage mechanism for Items in the game.
 *   It allows for the addition, removal, and manipulation of Items within the game's world.
 *
 * Design Description:
 * - It is designed with flexibility in mind, supporting a variety of Item types through polymorphism.
 *   This allows the game to introduce new types of Items without modifying the container logic.
 */
#ifndef CONTAINER_H
#define CONTAINER_H
#include "Item.h"
#include "Dice.h"
class Container
{
private:
    /// <summary>
    /// The item found in the Container
    /// </summary>
    Item item;

public:
    /// <summary>
    /// Constructor for the Container
    /// </summary>
    /// <param name="item">The Item to be found inside the container</param>
    Container(const Item& item);
    ~Container();
    /// <summary>
    /// Opens Container  and returns Item within
    /// </summary>
    /// <returns></returns>
    Item Open();
    /// <summary>
    /// Rep,ace the Item in the Container
    /// </summary>
    /// <param name="item">Item to be put in the container</param>
    void Put(Item& item);
};

#endif
