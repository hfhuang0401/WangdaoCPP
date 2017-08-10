#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class Base
{
public:
	Base()
	{
		cout<<"Base()"<<endl;
	}
};

class Derived
:public Base
{
public:
	Derived(int ix)
	:_ix(ix)
	{
		cout<<"Derived(int)"<<endl;
	}
	
	void print()const
	{
		cout<<"Derived::_ix = "<<_ix<<endl;
	}
private:
	int _ix;
};

int main(void)
{
	Derived d1(1);
	d1.print();
}
