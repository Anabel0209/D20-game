// Game.cpp : Driver File for the Game

#include <iostream>
#include "Map.h"
#include "Character.h"
#include "Dice.h"
#include "Belt.h"
#include "Item.h"
#include "Display.h"

//---------------------------------------------------------
//CharacterDriver
//---------------------------------------------------------
void CharacterDriver()
{
    //create a fighter 
    Fighter aFighter(1);
    aFighter.displayStats();

    //equip the fighter with a belt
    cout << "\n\nequiping a belt of +1 constitution: " << endl;
    Belt* aBelt;
    aBelt = new Belt(1, 0);
    aFighter.setBelt(*aBelt);
    cout << "new stats: " << endl;
    cout <<"Constitution: " << aFighter.getConstitution() << endl;
    cout << "Strength: " << aFighter.getStrength() << endl;

    //replace the belt
    cout << "Replacing the belt with a new one of +1 strength: " << endl;
    Belt* anotherBelt;
    anotherBelt = new Belt(0, 1);
    aFighter.setBelt(*anotherBelt);
    cout << "new stats: " << endl;
    cout << "Constitution: " << aFighter.getConstitution() << endl;
    cout << "Strength: " << aFighter.getStrength() << endl <<endl;
}


//---------------------------------------------------------
//MapDriver
//---------------------------------------------------------
void MapDriver()
{
    // Generate a random map and print it
    Map map = Map::generateRandomMap(35, 35, 0.1, 0.08, 0.005);
    std::cout << map;
    // Print if the path is valid
    std::cout << "Path is " << (Map::validatePath(map) ? "valid" : "invalid") << std::endl;
}


//---------------------------------------------------------
//ItemDriver
//---------------------------------------------------------
void ItemDriver()
{
    //Create an Item with Item constructor
    Item item(5, 10, 0, 0, 0, 0, 0, 0, 0);
    //Print Item Stats
    std::cout << "Item's Intelligence: " << item.getIntelligence() << " Wisdom: " << item.getWisdom() << " Dexterity: " << item.getDexterity() << std::endl;

    // Create a Helmet with Helmet  constructor
    Helmet helmet(5, 3, 7);
    //Print Helmet Stats
    std::cout << "Helmet's Intelligence: " << helmet.getIntelligence() << " Wisdom: " << helmet.getWisdom() << " Armor: " << helmet.getArmor() << " Dexterity: " << helmet.getDexterity() << std::endl;
}

//---------------------------------------------------------
//DiceDriver
//---------------------------------------------------------
void DiceDriver()
{
    // Roll a d20 and print the result
    Dice d20;
    std::cout << "Rolling a d20: " << d20.rollDice("3d6") << std::endl;
}

// TEST FOR MAP
void test()
{
	Map map = Map::generateMap();
    std::cout << map;
    Map::displayGrid(map.getPlayerView());
    map.movePlayer(1, 1);
    Chest chest(Item(1, 1, 1, 1, 1, 1, 1, 1, 1),2,2);
    map.addChest(&chest);
    std::cout << map;
    Map::displayGrid(map.getPlayerView());
}


int main()
{
    //Test
    //test();

    //create a fighter to be observed
    Fighter *myFighter = new Fighter(1); 

    //create a Display object connected to myFighter
    Display* aDisplay = new Display(myFighter);

    //if uncomment this line, it will show that the character stop being updated
    //delete aDisplay;

    //add a belt to the fighter 
    cout << "==========We equip the fighter with a belt +1 constitution==========\n";
    Belt* myBelt;
    myBelt = new Belt(1, 0);
    myFighter->setBelt(*myBelt);

    //exchange the belt with another belt, the stats should be displayed twice since replacing 
    //an item involve removing it (which changes the stats) the equiping another (which also changes them)
    cout << "==========We replace the fighter's belt with a belt +1 strength==========\n";
    Belt* anotherBelt;
    anotherBelt = new Belt(0, 1);
    myFighter->setBelt(*anotherBelt);


    //Call the driver functions and print seperators
   
    std::cout << "--CharacterDriver--" << std::endl;
    CharacterDriver();
    std::cout << "--------------------------------" << std::endl;
 
    std::cout << "--MapDriver--" << std::endl;
    MapDriver();
    std::cout << "--------------------------------" << std::endl;

    std::cout << "--ItemDriver--" << std::endl;
    ItemDriver();
    std::cout << "--------------------------------" << std::endl;

    std::cout << "--DiceDriver--" << std::endl;
    DiceDriver();
    std::cout << "--------------------------------" << std::endl;
}