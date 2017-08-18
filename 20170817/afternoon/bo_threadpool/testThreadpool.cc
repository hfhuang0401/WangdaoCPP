#include "threadpool.h"

#include <stdlib.h>
#include <unistd.h>

#include <iostream>
#include <memory>

using std::endl;
using std::cout;
using std::unique_ptr;

class MyTask
{
public:
	void process()
	{
		::srand(::clock());
		int number = ::rand() % 100;
		cout<<"produce a number:"<<number<<endl;
		::sleep(1);
	}
};

int main(void)
{
	wd::Threadpool threadpool(4,10);
	threadpool.start();

	int cnt = 20;
	while(cnt--)
	{
		threadpool.addTask(std::bind(&MyTask::process,MyTask()));//生产者角色
		cout<<"cnt = "<<cnt<<endl;
	}

	threadpool.stop();
	return 0;
}
