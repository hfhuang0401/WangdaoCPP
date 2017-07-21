 ///
 /// @file    memory1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-21 10:52:01
 ///
 
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


int a = 0;
char * p1;

int main(void)
{
	int b;
	char s[] = "123456";//s是一个常量, 位于栈上
	char * p2;
	const char * p3 = "123456";//位于文字常量区
	static int c = 0;
	p1 = new char[10];
	p2 = new char[5];
//	strcpy(p1, "123456");

	printf("123456 = %p\n" ,"123456");

	//*p3 = 'x';//error,文字常量区不能修改，只能读取

	//s = 0x0;

	printf("&a = %p\n", &a);
	printf("&c = %p\n", &c);
	printf("&p1 = %p\n", &p1);
	printf("p1 = %p\n", p1);
	printf("&p2 = %p\n", &p2);
	printf("p2 = %p\n", p2);
	printf("&p3 = %p\n", &p3);
	printf("p3 = %p\n", p3);
	printf("&b = %p\n", &b);
	printf("s = %p\n", s);

	return 0;
}
