#include "threadpool.h"
#include "task.h"

#include <stdlib.h>
#include <unistd.h>

#include <iostream> 
#include <memory>
 
using std::cout;
using std::endl;
using std::unique_ptr;
 
class MyTask
:public wd::Task
{
public:
	void process()
	{
		::srand(::clock());//设置的时间种子是以秒计算的
		int number = ::rand() % 100;
		cout<<"produce a number:"<<number<<endl;
		::sleep(1);
	}
};

int main(void)
{
	unique_ptr<wd::Task> task(new MyTask);

	wd::Threadpool Threadpool(4,10);
	Threadpool.start();

	int cnt = 20;
	while(cnt--)
	{
		Threadpool.addTask(task.get());//生产者角色
		cout<<"cnt = "<<cnt<<endl;
	}

	Threadpool.stop();
	return 0;
}
