#include "mutexLock.h"

#include <iostream> 

using namespace wd;
 
using std::cout;
using std::endl;
 
MutexLock::MutexLock()
:_isLocking(false)
{
	pthread_mutex_init(&_mutex,NULL);
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&_mutex);
}

void MutexLock::lock()
{
	_isLocking = true;
	pthread_mutex_lock(&_mutex);
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(&_mutex);
	_isLocking = false;
}

bool MutexLock::isLocking() const
{
	return _isLocking;
}

pthread_mutex_t * MutexLock::getMutexLockPtr()
{
	return &_mutex;
}

