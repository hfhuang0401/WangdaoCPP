#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include "taskqueue.h"

#include <vector>
#include <memory>
#include <functional>

using std::vector;
using std::shared_ptr;

namespace wd
{

typedef std::function<void()> Task;

class Thread;

class Threadpool
{
public:
	Threadpool(size_t threadNum,size_t queSize);
	~Threadpool();

	void start();
	void stop();
	void addTask(Task && task);

private:
	void threadFunc();
	Task getTask();

private:
	size_t _threadNum;
	size_t _queSize;
	vector<shared_ptr<Thread>> _threads;
	TaskQueue _taskQue;
	bool _isExit;
};

}//end of namespace wd

#endif
