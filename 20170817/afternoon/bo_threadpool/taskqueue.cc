#include "taskqueue.h"

#include <iostream> 
 
using std::cout;
using std::endl;

namespace wd
{
	TaskQueue::TaskQueue(size_t size)
	:_size(size)
	,_mutex()
	,_notFull(_mutex)
	,_notEmpty(_mutex)
	,_flag(true)
	{}

	bool TaskQueue::full() const
	{
		return _que.size() == _size;
	}

	bool TaskQueue::empty() const
	{
		return _que.empty();
	}

	//该方法的调用是在生产者线程里面
	void TaskQueue::push(const ElemType & elem)
	{
		MutexLockGuard mlg(_mutex);//1.能够保证该函数在执行过程中不会发生死锁
		while(full())//2.为了防止异常唤醒，要使用while，不能使用if
		{
			_notFull.wait();//该条件可能被异常唤醒
		}
		_que.push(elem);//放数据
		_notEmpty.notify();//3.通知消费者线程
	}

	TaskQueue::ElemType TaskQueue::pop()
	{
		//_mutex.lock();

		MutexLockGuard mlg(_mutex);
		while(_flag && empty())
		{
			_notEmpty.wait();
		}

		if(_flag)
		{
			ElemType tmp = _que.front();//取数据
			_que.pop();
			_notFull.notify();//通知生产者线程
			return tmp;
		}else
			return NULL;
	}

	void TaskQueue::wakeup()
	{
		_flag = false;
		_notEmpty.notifyall();
	}

}//end of namespace wd
