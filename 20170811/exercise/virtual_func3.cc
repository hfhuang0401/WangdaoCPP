#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class A
{
public:
	A(int ix = 0)
	:_ix(ix)
	{}

	virtual void disp()const
	{
		cout<<"A::disp()"<<endl;
	}
private:
	int _ix;
};

class B:public A
{
public:
	B(int ix,int iy = 0)
	:A(ix)
	,_iy(iy)
	{}

	void disp()
	{
		cout<<"B::disp()"<<endl;
		//cout<<"_iy = "<<_iy<<endl;
	}
private:
	int _iy;
};

int main(void)
{
	A *pA;
	A a;
	pA = &a;
	pA->disp();
	cout<<"-----------------"<<endl;
	B b(1,2);
	pA = &b;
	pA->disp();
}
