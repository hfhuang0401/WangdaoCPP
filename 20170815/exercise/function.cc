#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::function;

struct Foo
{
	Foo(int num)
	:_num(num)
	{}

	void print_add(int i)const
	{
		cout << _num+i << endl;
	}

	int _num;
};

void print_num(int i)
{
	cout<<i<<endl;
}

struct PrintNum
{
	void operator()(int i)const
	{
		cout<<i<<endl;
	}
};

int main(void)
{
	//自由函数
	function<void(int)> f_display = print_num;
	f_display(-9);

	//成员函数
	function<void(const Foo&,int)> f_add_display = &Foo::print_add;
	const Foo foo(314159);
	f_add_display(foo,1);

	//函数对象
	function<void(int)> f_display_obj = PrintNum();
	f_display_obj(18);

	//std::bind
	function<void()> f_display_31337 = std::bind(print_num,31337);
	f_display_31337();

	//成员函数+对象+占位符
	using std::placeholders::_1;
	function<void(int)> f_add_display2 = std::bind(&Foo::print_add,foo,_1);
	f_add_display2(2);

	//成员函数+对象指针+占位符
	function<void(int)> f_add_display3 = std::bind(&Foo::print_add,&foo,_1);
	f_add_display3(3);

	return 0;
}
