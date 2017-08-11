#include <iostream> 
 
using std::cout;
using std::endl;

class A
{
public:
	virtual void func(int x)
//	void func(int x)
	{
		cout<<"A::func() x = "<<x<<endl;
	}
};

class B
:public A
{
public:
	void func(const char *s)
	{
		cout<<"B::func()"<<s<<endl;
	}

#if 1
	virtual void func(int x)
	{
		cout<<"B::fnc(int) x = "<<x<<endl;
	}
#endif
};

int main(void)
{
	B b;
//	b.func(10);//error
	b.func("hello");
	b.func(10);

	A *p = new B;
	p->func(10);//覆盖

	return 0;
}
