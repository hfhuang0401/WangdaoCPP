#include "workthread.h"
#include "threadpool.h"

#include <iostream> 
 
using std::cout;
using std::endl;

namespace wd
{

	WorkThread::WorkThread(Threadpool & threadpool)
	:_threadpool(threadpool)
	{}

	void WorkThread::run()
	{
		_threadpool.threadFunc();
	}

}//end of namespace wd
