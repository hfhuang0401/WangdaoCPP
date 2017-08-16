#ifndef __CONSUMER_H__
#define __CONSUMER_H__

#include "thread.h"

namespace wd
{

class TaskQueue;
class Consumer
:public Thread
{
public:
	Consumer(TaskQueue & que);

private:
	void run();

private:
	TaskQueue & _que;
};

}//end of namesapce wd

#endif
