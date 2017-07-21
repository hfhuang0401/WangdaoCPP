#include <iostream> 
#include<stdio.h>
 
using std::cin;
using std::cout;
using std::endl;

const int a =1;
int b = 2;

int main(void)
{
	const int c = 3;
	int d = 4;
	const char * p = "123456";
	printf("&a = %p\n",&a);
	printf("&b = %p\n",&b);
	printf("&c = %p\n",&c);
	printf("&d = %p\n",&d);
	printf("&p = %p\n",&p);
}
