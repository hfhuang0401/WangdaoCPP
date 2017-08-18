#ifndef __THREAD_H__
#define __THREAD_H__

#include "noncopy.h"
#include <pthread.h>
#include <functional>

namespace wd
{

class Thread
:Noncopy
{
public:
	typedef std::function<void()> ThreadCallback;

	Thread(ThreadCallback && cb);
	 ~Thread();

	void start();
	void join();

private:
	static void * threadFunc(void *);

private:
	pthread_t _pthId;
	bool _isRunning;
	ThreadCallback _cb;
};

}//end of namespace wd

#endif
