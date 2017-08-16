#include "subject.h"
#include "observer.h"

string Subject::GetSubjectState()
{
	return SubjectState;
}

void Subject::setSubjectState(string state)
{
	this->SubjectState = state;
}

void Boss::Attach(Observer *observer)
{
	observers.push_back(observer);
}

void Boss::Detach(Observer *observer)
{
	list<Observer*>::iterator it;
	for(it = observers.begin();it != observers.end();++it)
	{
		if(*it == observer)
		{
			observers.erase(it);
			break;
		}
	}
}

void Boss::Notify()
{
	list<Observer*>::iterator it;
	for(it = observers.begin();it != observers.end();++it)
	{
		(*it)->Update();
	}
}
