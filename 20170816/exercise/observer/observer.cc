#include "observer.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

Observer::Observer(){}

Observer::Observer(string name,Subject *sub)
{
	this->name = name;
	this->sub = sub;
}

void Observer::Update()
{
	cout<<"Observer.update()"<<endl;
}

bool Observer::operator == (const Observer & observer)const
{
	return (this->name==observer.name)&&(this->sub==observer.sub);
}

StockObserver::StockObserver(){}

StockObserver::StockObserver(string name,Subject *sub)
{
	this->name = name;
	this->sub = sub;
}

void StockObserver::Update()
{
	cout<<sub->GetSubjectState()<<" "
		<<name<<" "
		<<"关闭股市行情，继续工作！"<<endl;
}

NBAObserver::NBAObserver(){}

NBAObserver::NBAObserver(string name,Subject *sub)
{
	this->name = name;
	this->sub = sub;
}

void NBAObserver::Update()
{
	cout<<sub->GetSubjectState()<<" "
		<<name<<" "
		<<"关闭NBA直播，继续工作！"<<endl;
}
