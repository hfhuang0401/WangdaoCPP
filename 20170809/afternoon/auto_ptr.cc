 ///
 /// @file    auto_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-09 14:36:27
 ///
 
#include <stdio.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::auto_ptr;


int main(void)
{
	int * p1 = new int(66);
	auto_ptr<int> api(p1);
	cout << "*api = " << *api << endl;
	cout << "*p1 = " << *p1 << endl;

	printf("api's ptr = %p\n", api.get());
	printf("p1 = %p\n", p1);

	auto_ptr<int> api2 = api;//在语法层面是要表达复制语义的
							 //在实现时，右操作数将托管的对象指针交给了左操作数,
							 //发生了所有权的转移
							 //这与复制语义是矛盾的, 该智能指针存在缺陷
	cout << "*api2 = " << *api2 << endl;
	cout << "*api = " << *api << endl;//api不能再正常使用

	return 0;
}
