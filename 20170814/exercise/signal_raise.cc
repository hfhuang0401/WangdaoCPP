#include <iostream>
#include <csignal>
#include <cstdlib>
#include <unistd.h>
 
using namespace std;

void signalHandler(int signum)
{
	cout<<"Interrupt signal (" 
		<<signum
		<<") received"<<endl;

	exit(signum);
}


int main(void)
{
	int i = 0;
	
	//注册信号 SIGINT 和信号处理程序
	signal(SIGINT,signalHandler);

	while(++i)
	{
		cout<<"Going to sleep..."<<endl;
		if(i == 3)
		{
			raise(SIGINT);
			//raise()函数用来生成信号,该函数带有一个整数信号编号作为参数
		}
		sleep(1);
	}

	return 0;
}
