//This class defines how to attach, detach and get the notification of change from an object inherited from this class.

#pragma once
#include <vector>
#include "Observer.h"

class Subject
{
public:
	//destructor
	virtual~Subject();

	//attach an observer to the subject
	virtual void Attach(Observer* o);

	//detach an observer from the subject 
	virtual void Detach(Observer* o);

	//notify all observers upon state change
	virtual void Notify();

	//get the list of observers
	const std::vector<Observer*>& getObservers();

protected:
	//constructor
	Subject();

private:
	//vector containing the observers
	std::vector<Observer*> observers;

};