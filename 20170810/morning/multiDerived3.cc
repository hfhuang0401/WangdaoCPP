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

	void setX(int ix)
	{
		_ix = ix;
	}

	void print() const
	{
		cout<<"A::_ix= "<<_ix<<endl;
	}

private:
	int _ix;
};

class B:virtual public A
//class B:public A
{};

class C:virtual public A
//class C:public A
{};

class D
:public B
,public C
{};

int main(void)
{
	D d;
//	d.B::setX(1);//存储二义性:采用虚继承
//	d.B::print();
	d.setX(1);
	d.print();
}
