#include <iostream>
#include <functional>
 
using std::cin;
using std::cout;
using std::endl;
using std::bind;
using std::function;

//int(int,int)  -->函数标签
//typedef int (*Function)(int,int)
//function<int(int,int)> f1;

int func(int x,int y)
{
	return x + y;
}

struct Foo
{
	Foo()
	:_x(10)
	{}

	int add(int x,int y)
	{
		return x + y;
	}

	int _x;
};

void test0()
{
	//bind提前绑定参数时，未提前绑定的参数所在的位置需使用占位符
	auto f1 = bind(func,10,std::placeholders::_1);
	cout<<f1(20)<<endl;

	auto f2 = bind(func,10,11);
	cout<<f2()<<endl;
}

void test1()
{
	typedef int(*Function)(int,int);//C的函数指针
	Function f = func;//回调函数的注册
	cout<<f(1,2)<<endl;
}

void test2()
{
	//这种赋值的方式可以看成是回调函数的注册
	//可以把function看成是函数类型的容器
	function<int(int)> f1 = bind(func,10,std::placeholders::_1);
	cout<<f1(20)<<endl;

	Foo foo;
	//如果bind要绑定成员函数，要在前面加上取地址符号&
	f1 = bind(&Foo::add,&foo,10,std::placeholders::_1);
	cout<<f1(20)<<endl;

	function<int()> f2 = bind(func,10,11);
	cout<<f2()<<endl;
}

void display(int n1,int n2,int n3,const int &n4,int n5)
{
	cout<<"("<<n1
		<<","<<n2
		<<","<<n3
		<<","<<n4
		<<","<<n5
		<<")"<<endl;
}

void test3()
{
	using namespace std::placeholders;
	int n = 7;
//	function<void(int,int)>  f1 = bind(display,_2,_1,42,std::cref(n),n);
//	bind的占位符所在的位置代表的是形参的位置
//	1.占位符本身的数字代表的是实参传递时要绑定的实参的位置
//	2.auto f1 = bind(display,_2,_1,42,std::cref(n),n);
//	3.bind绑定参数时，采用的是值传递，会进行复制
//	  所以在绑定成员函数时，第一个参数尽量用对象的地址传递
//	4.如果采用auto关键字接收bind的返回值，实参传递时个数不受限制
//	  多余的实参是无效参数
	auto f1 = bind(display,_3,_1,42,std::cref(n),n);

	n = 10;

	f1(11,22,1001,1002,1003,1004);
}

void test4()
{
//	bind除了能够绑定到普通函数，成员函数以外
//	还能绑定到数据成员上
	Foo foo;
	auto f1 = bind(&Foo::_x,&foo);
	cout<<f1()<<endl;
}

int main(void)
{
//	test0();
//	test2();
//	test3();
	test4();

	return 0;
}
