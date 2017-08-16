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

private:
	pthread_mutex_t _mutex;
	bool _isLocking;

	pthread_mutex_t * getMutexLockPtr();

	bool isLocking() const;
};
}//end of namespace wd

#endif
