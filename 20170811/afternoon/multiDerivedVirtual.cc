#include <iostream> 
 
using std::cout;
using std::endl;

class A
{
public:
	virtual void a()
	{
		cout<<"A::a()"<<endl;
	}
	virtual void b()
	{
		cout<<"A::b()"<<endl;
	}
	virtual void c()
	{
		cout<<"A::c()"<<endl;
	}
private:
	double _dx;
};

class B
{
public:
	virtual void a()
	{
		cout<<"B::a()"<<endl;
	}
	virtual void b()
	{
		cout<<"B::b()"<<endl;
	}
	void c()
	{
		cout<<"B::c()"<<endl;
	}
	void d()
	{
		cout<<"B::d()"<<endl;
	}
private:
	double _dy;
};

class C
:public A
,public B
{
public:
	virtual void a()
	{
		cout<<"C::a()"<<endl;
	}

	void c()
	{
		cout<<"C::c()"<<endl;
	}

	void d()
	{
		cout<<"C::d()"<<endl;
	}
private:
	double _dz;
};

int main(void)
{
	cout<<"sizeof(A) = "<<sizeof(A)<<endl;
	cout<<"sizeof(B) = "<<sizeof(B)<<endl;
	cout<<"sizeof(C) = "<<sizeof(C)<<endl;

	A a;
	B b;
	C c;

	c.a();
//	c.b();//二义性
	c.c();
	c.d();
	cout<<endl;

	A *pA = &c;
	pA->a();//虚函数C::a()
	pA->b();//虚函数A::b()
	pA->c();//虚函数C::c()
	cout<<endl;

	B *pB = &c;
	pB->a();//虚函数C::a()
	pB->b();//虚函数B::b()
	pB->c();//非虚函数B::c()
	pB->d();//非虚函数B::d()

	cout<<endl;

	C *pC = &c;
	pC->a();
//	pC->b();//二义性
	pC->c();
	pC->d();

	return 0;
}
