/*this class create objects that observes the changes of the character object it is subscribed to. Each time the stats of the
* character change, it triggers a redisplay of the character stats.
* 
*  this class inherit of the Observer class and thus make use of the observer pattern (in particular, the display class is subscribed
*  to a character object).
*/

#include "Display.h"

//Display constructor
Display::Display(Character* s)
{
    myCharacter = s;
    myCharacter->Attach(this);
    nbUpdates = 0;
}

//called when the state of the character is changed
void Display::Update(Subject* changedSubject)
{
    if (changedSubject == myCharacter)
    {
        myCharacter->displayStats();
        nbUpdates++;
    }
}

//detach the game object from the character
Display::~Display()
{
    myCharacter->Detach(this);
}