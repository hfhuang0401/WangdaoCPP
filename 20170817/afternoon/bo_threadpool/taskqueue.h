#ifndef __TASKQUEUE_H__
#define __TASKQUEUE_H__

#include "mutexLock.h"
#include "condition.h"

#include <functional>
#include <iostream>
#include <queue>

using std::queue;

namespace wd
{

class TaskQueue
{
public:
	typedef std::function<void()> ElemType;

	TaskQueue(size_t size);

	void push(const ElemType & elem);
	ElemType pop();

	bool full() const;
	bool empty() const;

	void wakeup();

private:
	size_t _size;
	queue<ElemType> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
	bool _flag;
};

}//end of namespace wd

#endif
