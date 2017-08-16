#include "observer.h"

#include <cstdlib>

#include <iostream> 
 
using std::cout;
using std::endl;
 
//Client,客户端
int main(void)
{
	//通知者
	Subject *huhansan = new Boss();

	//4个观察者实例
	Observer *tongshi1 = new StockObserver("魏关姹",huhansan);
	Observer *tongshi2 = new StockObserver("易管察",huhansan);
	Observer *tongshi3 = new NBAObserver("霍华德",huhansan);
	Observer *tongshi4 = new NBAObserver("林书豪",huhansan);

	//将4个观察者都加入到通知者的通知队列中
	huhansan->Attach(tongshi1);
	huhansan->Attach(tongshi2);
	huhansan->Attach(tongshi3);
	huhansan->Attach(tongshi4);

	//魏关姹没有被通知到，减去
	huhansan->Detach(tongshi1);

	huhansan->setSubjectState("我胡汉三回来了！");

	//通知
	huhansan->Notify();

	delete huhansan;
	delete tongshi1;
	delete tongshi2;
	delete tongshi3;
	delete tongshi4;

	return 0;
}
