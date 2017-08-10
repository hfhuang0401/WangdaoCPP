#include <iostream>
#include <vector>
#include <string>
 
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
 
void test0()
{
	int a = 1;
	int b = 2;
	int *p = &a;
	vector<int> numbers;
	numbers.push_back(1);

	&a;
	&b;
//	&(a+b);//右值

//	&string("hello");//右值

	string s1 = "hello";
	string s2 = "world";
//	&(s1 + s2);//右值

//	int & ref1 = 1;//非const左值引用不能绑定到右值上
	const int & ref2 = 2;//const左值引用能绑定到右值上

	const int & ref3 = a;//const左值引用还可以绑定到左值上
//	因此，当const左值引用作为函数的参数时，无法确定其传递过来的是左值还是右值
	
}

void test1()
{
	int && ref = 10;//C++新特性，右值引用
	cout<<ref<<endl;

	int a = 10;
//	int && ref2 = a;//右值引用不能绑定到左值
}

int main(void)
{
	test1();
	return 0;
}
