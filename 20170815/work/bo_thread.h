#ifndef __BO_THREAD_H__
#define __BO_THREAD_H__

#include <pthread.h>
#include <functional>

namespace wd
{

class Thread
{
public:
	typedef std::function<void()> ThreadCallBack;

	Thread(ThreadCallBack && cb);
	~Thread();

	void start();
	void join();

private:
	pthread_t _pthId;
	bool _isRunning;
	ThreadCallBack _cb;

	static void * threadFunc(void *);
};

}//end of namespace wd

#endif
