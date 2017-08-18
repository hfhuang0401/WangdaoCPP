#ifndef __CONDITION_H__
#define __CONDITION_H__

#include "noncopy.h"
#include <pthread.h>

namespace wd
{

class MutexLock;

class Condition
:Noncopy
{
public:
	explicit
	Condition(MutexLock & mutex);
	~Condition();

	void wait();
	void notify();
	void notifyall();

private:
	pthread_cond_t _cond;
	MutexLock & _mutex;
};

}//end of namespace wd

#endif
