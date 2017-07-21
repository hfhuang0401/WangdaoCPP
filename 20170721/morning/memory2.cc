 ///
 /// @file    memory2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-21 11:17:13
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;


int a = 10;
const int b = 20;//放在文字常量区


int test(void)
{
	int c = 30;
	const int d = 40;//放在栈区,与其生命周期有关
	const char * p1 = "123456";

	printf("&a = %p\n", &a);
	printf("&b = %p\n", &b);
	printf("&c = %p\n", &c);
	printf("&d = %p\n", &d);
	printf("p1 = %p\n", p1);
	return 0;
}

int main(void)
{
	test();
	return 0;
}
