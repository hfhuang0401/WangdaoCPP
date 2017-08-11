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

	void print()
	{
		cout<<"A::print()"<<endl;
	}
};

class B:public A
{
public:
	void disp()const
	{
		cout<<"B::disp()"<<endl;
	}

	void print()
	{
		cout<<"B::print()"<<endl;
	}
};

int main(void)
{
	A *pA;
	A a;
	pA = &a;
	pA->disp();
	pA->print();
	cout<<"-----------------"<<endl;
	B b;
	pA = &b;
	pA->disp();
	pA->print();
}
