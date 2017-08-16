#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include <string>
#include <list>

using std::string;
using std::list;

//前向声明
class Observer;

//Subject类，抽象通知者或者主题
class Subject
{
protected:
	string SubjectState;

public:
	virtual ~Subject(){}
	virtual void Attach(Observer *observer)=0;
	virtual void Detach(Observer *observer)=0;
	virtual void Notify()=0;

	string GetSubjectState();
	void setSubjectState(string state);
};

//ConcreteSubject，具体通知者或具体主题
class Boss
:public Subject
{
private:
	list<Observer*> observers;
	string action;

public:
	void Attach(Observer *observer);
	void Detach(Observer *observer);
	void Notify();
};

#endif
