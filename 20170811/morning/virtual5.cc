#include <iostream>

using std::cout;
using std::endl;

//1. 在构造函数或析构函数之中调用虚函数采用的是静态联编
//
//2. 构造函数为什么不能是虚函数？
//答: 根据虚函数的使用条件来说，只有先创建对象，才有了
//	  虚函数指针，然后才能通过它去调用虚函数；

class Base0
{
public:
	Base0()
	{
		cout << "Base0()" << endl;
	}

	virtual
	void func1()
	{	
		cout << "Base0::func1()" << endl;
	}

	virtual
	void func2()
	{
		cout << "Base0::func2()" << endl;
	}

	~Base0()
	{
		cout << "~Base0()" << endl;
	}
};

class Base1
:public Base0
{
public:
	Base1()
	: Base0()
	{
		cout << "Base1()" << endl;	
		func1();
	}

#if 1
	virtual
	void func1()
	{	cout << "Base1::func1()" << endl;}
#endif

	virtual
	void func2()
	{	cout << "Base1::func2()" << endl;}

	~Base1()
	{
		func2();
		cout << "~Base1()" << endl;
	}
};

class Sub
: public Base1
{
public:
	Sub()
	: Base1()
	{
		cout << "Sub()" << endl;
		func1();
	}

	~Sub()
	{
		func2();
		cout << "~Sub()" << endl;
	}
	virtual
	void func1()
	{
		cout << "Sub::func1()" << endl;
	}

	virtual
	void func2()
	{
		cout << "Sub::func2()" << endl;
	}

};

int main(void)
{
	Sub sub;

	return 0;
}
