#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class A
{
public:
	virtual void disp()const
	{
		cout<<"A::disp()"<<endl;
	}
};

class B:public A
{
public:
	void disp()const
	{
		cout<<"B::disp()"<<endl;
	}
};

void func(A &rhs)
{
	rhs.disp();
}

int main(void)
{
	A a;
	func(a);
	cout<<"-----------------"<<endl;
	B b;
	func(b);
}
