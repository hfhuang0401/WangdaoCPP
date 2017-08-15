#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include <iostream>
#include <list>

using std::list;
using std::cout;
using std::endl;

class Observer;

typedef int State;

class Subject
{
public:
	void attach(Observer * observer);
	void detach(Observer * observer);
	void notify();

	virtual State getState()const=0;
	virtual void setState(State state)=0;

	virtual ~Subject(){}

protected:
	list<Observer *> _listObservers;
	//list<Observer *> _vipObservers;
	//list<Observer *> _goldObservers;
};

class ConcreateSubject
: public Subject
{
public:
	ConcreateSubject()
	: _subState(-1)
	{
		cout << "ConcreateSubject()" << endl;
	}

	void setState(State state);
	State getState() const;

	~ConcreateSubject()
	{
		cout << "~ConcreateSubject()" << endl;
	}
private:
	State _subState;
};

class Observer
{
public:
	virtual void update(Subject * subject)=0;
	virtual ~Observer(){}
};

class ConcreateObserver
: public Observer
{
public:
	ConcreateObserver()
	: _observerState(-1)
	{
		cout << "ConcreateObserver()" << endl;
	}
	void update(Subject * subject);

	~ConcreateObserver()
	{
		cout << "~ConcreateObserver()" << endl;
	}

private:
	State _observerState;
};

#endif
