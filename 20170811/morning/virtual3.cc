#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class Base
{
public:
//	virtual int func(int x)
	int func(int x)
	{
		cout<<"Base::func() x = "<<x<<endl;
		return x;
	}
private:
	double _dx;
};

class Sub
:public Base
{
public:

#if 1
//	virtual int func(int x)
	int func(int x)
	{
		cout<<"Sub::func(int)= "<< x <<endl;
		return 0;
	}
#endif

#if 0
	virtual int func()
	{
		cout<<"func()"<<endl;
		return 0;
	}
#endif

};

void display(Base * pbase)
{
	pbase->func(10);
}

int test0(void)
{
	Base base;
	Sub sub;

	base.func(1);//如果通过对象名的方式进行调用，则不展现虚函数的特性
	sub.func(1);//此时虚函数退化成一个普通函数

	return 0;
}

int test1(void)
{
	cout<<"sizeof(Base) = "<<sizeof(Base)<<endl;
	cout<<"sizeof(Sub) = "<<sizeof(Sub)<<endl;
	return 0;
}

int main(void)
{
	test0();
	return 0;
}
