#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class A
{
public:

	A(int ix)
	:_ix(ix)
	{
		cout<<"A(int)"<<endl;
	}

	void display() const
	{
		cout<<"A::display()"<<endl;
	}

private:
	int _ix;
};

class B
{
public:

	B(int iy)
	:_iy(iy)
	{
		cout<<"B(int)"<<endl;
	}

	void show() const
	{
		cout<<"B::print()"<<endl;
	}

private:
	int _iy;
};

class C
:public A
,public B
{
public:
	//构造的顺序只和继承的顺序有关
	C(int ix,int iy,int iz)
	:B(iy)
	,A(ix)
	,_iz(iz)
	{
		cout<<"C(int,int,int)"<<endl;
	}

	void show() const
	{
		cout<<"c::show()"<<endl;
	}

private:
	int _iz;
};

int main(void)
{
	C c(1,2,3);
}
