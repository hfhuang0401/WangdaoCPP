#ifndef __MUTEXLOCK_H__
#define __MUTEXLOCK_H__

#include "noncopy.h"
#include <pthread.h>

namespace wd
{

class MutexLock
:Noncopy
{
public:
	MutexLock();
	~MutexLock();

	void lock();
	void unlock();

	pthread_mutex_t * getMutexLockPtr();

	bool isLocking() const;

private:
	pthread_mutex_t _mutex;
	bool _isLocking;
};

class MutexLockGuard
{
public:
	MutexLockGuard(MutexLock & mutex)
	:_mutex(mutex)
	{
		_mutex.lock();
	}

	~MutexLockGuard()
	{
		_mutex.unlock();
	}

private:
	MutexLock & _mutex;
};

}//end of namespace wd

#endif
