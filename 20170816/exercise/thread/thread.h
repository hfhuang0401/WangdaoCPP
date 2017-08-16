#ifndef __THREAD_H__
#define __THREAD_H__

#include "noncopy.h"

#include <pthread.h>

namespace wd
{

class Thread
:public Noncopy
{
public:
	Thread();
	virtual ~Thread();

	void start();
	void join();

private:
	virtual void run()=0;

	static void * threadFunc(void *);

private:
	pthread_t _pthId;
	bool _isRunning;
};

}//end of namespace wd

#endif
