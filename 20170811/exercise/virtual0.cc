#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class A
{
public:
	virtual void disp()=0;
};

class B:public A
{
public:

#if 1
	void disp()
	{
		cout<<"This is B"<<endl;
	}
#endif

};

class C:public B
{
public:

#if 0
	void disp()
	{
		cout<<"This is C"<<endl;
	}
#endif

};

class D:public C
{
public:

	void disp()
	{
		cout<<"This is D"<<endl;
	}

};
void display(A *a)
{
	a->disp();
}

int main(void)
{
//	A *pA = new A;//抽象类无法实例化
	B *pB = new B;
	C *pC = new C;
	D *pD = new D;

//	display(pA);
	display(pB);
	display(pC);
	display(pD);
}
