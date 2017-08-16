#ifndef __TASKQUEUE_H__
#define __TASKQUEUE_H__

#include "mutexLock.h"
#include "condition.h"

#include <iostream>
#include <queue>

using std::queue;

namespace wd
{

class Task;

class TaskQueue
{
public:
	typedef Task* ElemType;

	TaskQueue(size_t size);

	void push(const ElemType & elem);
	ElemType pop();

	bool full() const;
	bool empty() const;

private:
	size_t _size;
	queue<ElemType> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
};

}//end of namespace wd

#endif
