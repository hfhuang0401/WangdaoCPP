#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include "taskqueue.h"

#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;

namespace wd
{

class Thread;
class Task;
class WorkThread;

class Threadpool
{
	friend WorkThread;
public:
	Threadpool(size_t threadNum,size_t queSize);
	~Threadpool();

	void start();
	void stop();
	void addTask(Task *);

private:
	void threadFunc();
	Task * getTask();

private:
	size_t _threadNum;
	size_t _queSize;
	vector<shared_ptr<Thread>> _threads;
	TaskQueue _taskQue;
	bool _isExit;
};

}//end of namespace wd

#endif
