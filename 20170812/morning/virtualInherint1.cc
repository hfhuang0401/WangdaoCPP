#include <iostream> 
 
using std::cout;
using std::endl;

class A
{
public:
	virtual void f1()
	{
		cout<<"A::f1()"<<endl;
	}
private:
	int _ia;
};

class B
//:virtual public A
:public A
{
public:
	virtual void f1()
	{
		cout<<"B::f1()"<<endl;
	}

	virtual void f2()
	{
		cout<<"B::f2()"<<endl;
	}

private:
	int _ib;
	int _ic;
};

class C
:public B
{
public:
	virtual void f1()
	{
		cout<<"C::f1()"<<endl;
	}

	virtual void f2()
	{
		cout<<"C::f2()"<<endl;
	}
	virtual void f3()
	{
		cout<<"C::f3()"<<endl;
	}
};

int main(void)
{
	cout<<"sizeof(A) = "<<sizeof(A)<<endl;
	cout<<"sizeof(B) = "<<sizeof(B)<<endl;
	cout<<"sizeof(C) = "<<sizeof(C)<<endl;
}
