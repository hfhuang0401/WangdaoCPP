#include "consumer.h"
#include "taskqueue.h"

#include <unistd.h>
#include <iostream> 
 
using std::cout;
using std::endl;
 
namespace wd
{
	Consumer::Consumer(TaskQueue & que)
	:_que(que)
	{}

	void Consumer::run()
	{
		while(true)
		{
			int number = _que.pop();
			cout<<"Consumer->consume a number:"<<number<<endl;
			sleep(2);
		}
	}
}//end of namesapce wd
