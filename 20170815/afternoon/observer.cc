#include "observer.h"
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

void Subject::attach(Observer * observer)
{
	auto iter = std::find(_listObservers.begin(), _listObservers.end(), observer);
	if(iter == _listObservers.end())
		_listObservers.push_back(observer);
}

void Subject::detach(Observer * observer)
{
	auto iter = std::find(_listObservers.begin(), _listObservers.end(), observer);
	if(iter != _listObservers.end())
	{
		_listObservers.erase(iter);
	}
}

void Subject::notify()
{
	cout << "Subject: 通知所有的观察者" << endl;
	for(auto iter = _listObservers.begin();
		iter != _listObservers.end();
		++iter)
	{
		(*iter)->update(this);
	}
}

void ConcreateSubject::setState(State state)
{
	_subState = state;
	notify();
}

State ConcreateSubject::getState()const
{
	return _subState;
}

//如果传递的就是状态本身时，称之为推模式 -- 观察者是被动的
//void ConcreateObserver::update(State state) 
//
//如果传递的是指针或者引用，称之为拉模式 -- 观察者是主动的
void ConcreateObserver::update(Subject * subject)
{
	State tmp = subject->getState();//由观察者决定是否要获取主题的信息
	if(_observerState != tmp)
	{
		_observerState = tmp;
		cout << "Observer: 主题的状态更新为: " << _observerState << endl;
	}
}
