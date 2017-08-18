#include "threadpool.h"
#include "workthread.h"
#include "task.h"

#include <unistd.h>
#include <iostream> 
 
using std::cout;
using std::endl;
using std::shared_ptr;
 
namespace wd
{

	Threadpool::Threadpool(size_t threadNum,size_t queSize)
	:_threadNum(threadNum)
	,_queSize(queSize)
	,_taskQue(_queSize)
	,_isExit(false)
	{
		_threads.reserve(_threadNum);
	}

	Threadpool::~Threadpool()
	{
		if(!_isExit)
		{
			stop();
		}
	}

	void Threadpool::start()
	{
		for(size_t idx = 0;idx != _threadNum; ++idx)
		{
			shared_ptr<Thread> sp(new WorkThread(*this));
			_threads.push_back(sp);
		}

		for(auto & thread : _threads)
		{
			thread->start();
		}
	}

	void Threadpool::stop()
	{
		if(!_isExit)
		{
			while(!_taskQue.empty())
			{
				::sleep(2);
			}
			_isExit = true;
		
			_taskQue.wakeup();

			for(auto & thread : _threads)
			{
				thread->join();
			}
		}
	}

	void Threadpool::addTask(Task * task)
	{
		_taskQue.push(task);
	}
	
	//充当的是生产者角色
	Task * Threadpool::getTask()
	{
		return _taskQue.pop();
	}

	void Threadpool::threadFunc()
	{
		//是子线程要执行的函数，充当的是消费者角色
		while(!_isExit)
		{
			Task * task = getTask();
			if(task)
				task->process();
		}
	}

}//end of namespace wd
