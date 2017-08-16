#ifndef __PRODUCTOR_H__
#define __PRODUCTOR_H__

#include "thread.h"
#include <iostream>

namespace wd
{

class TaskQueue;
class Producer
:public Thread
{
public:
	Producer(TaskQueue & que);

private:
	void run();

private:
	TaskQueue & _que;
};

}//end of namespace 

#endif
