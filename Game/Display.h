/*this class create objects that observes the changes of the character object it is subscribed to. Each time the stats of the
* character change, it triggers a redisplay of the character stats.
* 
* this class inherit of the Observer class and thus make use of the observer pattern (in particular, the display class is subscribed
* to a character object).
*/

#pragma once
#include "Character.h"

//plug a character observer to it
class Display : public Observer
{
public:

	//constructor
	Display(Character* s);

	//destructor 
	~Display();

;	//called when the state of the character is changed
	virtual void Update(Subject* changedSubject)override;

private:
	Character* myCharacter;
};