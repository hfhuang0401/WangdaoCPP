#include <iostream> 
 
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

#if 0
//	virtual int func(int x)
	int func(int x)
	{
		cout<<"Sub::fnc(int)= "<< x <<endl;
		return 0;
	}
#endif

	virtual int func()
	{
		cout<<"func()"<<endl;
		return 0;
	}
};

void display(Base * pbase)
{
	pbase->func(10);
}

int test0(void)
{
	Base base;
	Sub sub;

	display(&base);
	display(&sub);

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
