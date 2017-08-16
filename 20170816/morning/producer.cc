#include "producer.h"
#include "taskqueue.h"

#include <unistd.h>
#include <time.h>

#include <iostream> 
 
using std::cout;
using std::endl;

namespace wd
{

	Producer::Producer(TaskQueue & que)
	:_que(que)
	{}

	void Producer::run()
	{
		::srand(::time(NULL));
		while(true)
		{
			int number = ::rand() % 100;
			_que.push(number);
			cout<<"Producer->make a number:"<<number<<endl;
			sleep(1);
		}
	}
}//end of namespace wd
