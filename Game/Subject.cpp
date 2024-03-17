//This class defines how to attach, detach and get the notification of change from an object inherited from this class.

#include "Subject.h"
#include <algorithm>

Subject::~Subject() {}
Subject::Subject() {}

//attach an observer to the subject
void Subject::Attach(Observer* o)
{
	observers.push_back(o);
}

//detach an observer from the subject
void Subject::Detach(Observer* o) 
{
	observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
}

//notify all observers uppon state change
void Subject::Notify()
{
	for (Observer* observer : observers) 
	{
		observer->Update(this);
	}
}

//return the vector containing the pointers to every observers of the subject
const std::vector<Observer*>& Subject::getObservers()
{
	return observers;
}
