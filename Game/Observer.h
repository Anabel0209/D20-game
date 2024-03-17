/*this abstract class gives a model to be implemented by each observer objects. The actions to be taken when the update
* function is called depend on the nature of the observer.
*/

#pragma once

class Subject;

class Observer
{
public:
	virtual void Update(Subject* changedSubject) = 0;
	int nbUpdates;
};