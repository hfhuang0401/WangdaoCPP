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
};

#if 0
class C
:public A,public B
{
private:
	int _id;
};
#endif

#if 0
class C
:public A,public B
{
};
#endif

class C
:public A,public B
{
private:
	int _ic;
//	int _id;
};

int main(void)
{
	cout<<"sizeof(A) = "<<sizeof(A)<<endl;
	cout<<"sizeof(B) = "<<sizeof(B)<<endl;
	cout<<"sizeof(C) = "<<sizeof(C)<<endl;

	return 0;
}
