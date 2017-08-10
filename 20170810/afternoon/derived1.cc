#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class Base
{
public:

#if 1
	Base()
	{
		cout<<"Base()"<<endl;
	}
#endif

	Base(int ibase)
	:_ibase(ibase)
	{}

private:
	int _ibase;
};

//2.当派生类没有显式定义构造函数时，在创建派生类对象时，基类部分必须提供一个默认构造函数
class Derived
:public Base
{
public:

#if 0
	Derived(int ix)
	:_ix(ix)
	{
		cout<<"Derived(int)"<<endl;
	}
#endif

	void print()const
	{
		cout<<"Derived::_ix = "<<_ix<<endl;
	}

private:
	int _ix;
};

int main(void)
{
	Derived d1;
	d1.print();
}
