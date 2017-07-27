#include <cstdlib>

#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;
 
void display(void)
{
	cout<<"display()"<<endl;
}

int main(void)
{
	cout<<"enter main()"<<endl;
	atexit(display);//注册的函数在main函数退出会执行
	atexit(display);
	atexit(display);
	cout<<"exit main()"<<endl;

	return 0;
}

