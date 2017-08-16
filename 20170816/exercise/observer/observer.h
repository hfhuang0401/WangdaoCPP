#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include "subject.h"

#include <list>
#include <iostream>
#include <string>

using std::string;
using std::list;

//Observer,抽象观察者
class Observer
{
protected:
	string name;
	Subject *sub;

public:
	Observer();
	virtual ~Observer(){}
	Observer(string name,Subject *sub);
	virtual void Update();
	bool operator == (const Observer&)const;
};

//ConcreteObserver,具体观察者:股票观察者
class StockObserver
:public Observer
{
public:
	StockObserver();
	StockObserver(string name,Subject *sub);
	void Update();
};

//ConcreteObserver,具体观察者:NBA观察者
class NBAObserver
:public Observer
{
public:
	NBAObserver();
	NBAObserver(string name,Subject *sub);
	void Update();
};

#endif
