#include "thread.h" 

#include <cstdlib>
#include <unistd.h>

#include <iostream> 
 
using std::cout;
using std::endl;

class MyThread
:public wd::Thread
{
private:
	void run()
	{
		cout<<"run func()"<<endl;
		srand(time(NULL));
		while(true)
		{
			int number = rand() % 100;
			cout << "生成的随机数为：" << number<<endl;;
			sleep(1);
		}
	}
};

int main(void)
{
	wd::Thread * pthread = new MyThread();
	pthread->start();
	pthread->join();

	delete pthread;
	return 0;
}
