#ifndef __WORKTHREAD_H__
#define __WORKTHREAD_H__

#include "thread.h"

namespace wd
{

class Threadpool;

class WorkThread
:public Thread
{
public:
	WorkThread(Threadpool & threadpool);

private:
	void run();

private:
	Threadpool & _threadpool;
};

}//end of namespace wd

#endif
