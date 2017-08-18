#include "thread.h"

#include <iostream> 
 
using std::cout;
using std::endl;
 
namespace wd
{

	Thread::Thread(ThreadCallback && cb)
	:_pthId(0)
	,_isRunning(false)
	,_cb(std::move(cb))
	{}

	Thread::~Thread()
	{
		if(_isRunning)
		{
			pthread_detach(_pthId);
			_isRunning = false;
		}
	}

	void Thread::start()
	{
		pthread_create(&_pthId,NULL,threadFunc,this);
		_isRunning = true;
	}

	void Thread::join()
	{
		if(_isRunning)
		{
			pthread_join(_pthId,NULL);
			_isRunning = false;
		}
	}

	void * Thread::threadFunc(void * arg)
	{
		//该方法的任务就是去执行Thread::run()
		Thread * pthread = static_cast<Thread*>(arg);
		if(pthread)
			pthread->_cb();

		return NULL;
	}

}//end of namespace wd
