#include "bo_thread.h"

#include <cstdlib>
#include <unistd.h>

#include <iostream> 

using std::cout;
using std::endl;
 
class MyTask
{
public:
	void run()
	{
		srand(time(NULL));
		while(true)
		{
			int number = rand() % 100;
			cout << "生成的随机数为：" << number << endl;
			sleep(1);
		}
	}
};

void getRandomNumber()
{
	srand(time(NULL));
	while(true)
	{
		int number = rand() % 100;
		cout << "生成的随机数为：" << number << endl;
		sleep(1);
	}
}

int main(void)
{
	wd::Thread pthread(std::bind(&MyTask::run,MyTask()));
//	wd::Thread pthread(getRandomNumber);
	pthread.start();
	pthread.join();
}
