#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class Base
{
public:

#if 1
	Base()
	:_ibase(0)
	{
		cout<<"Base()"<<endl;
	}
#endif

	Base(int ibase)
	:_ibase(ibase)
	{
		cout<<"Base(int)"<<endl;
	}
	
	void display()const
	{
		cout<<"Base::_ibase = "<<_ibase<<endl;
	}

private:
	int _ibase;
};

class Derived
:public Base
{
public:

	Derived(int ix)
	:Base()	
	,_ix(ix)
	{
		cout<<"Derived(int)"<<endl;
	}

	Derived(int ibase,int ix)
	:Base(ibase)
	,_ix(ix)
	{
		cout<<"Derived(int,int)"<<endl;
	}

	void print()const
	{
		display();
		cout<<"Derived::_ix = "<<_ix<<endl;
	}

private:
	int _ix;
};

int main(void)
{
	Derived d1(1);
	d1.print();
	cout<<"--------------"<<endl;
	Derived d2(3,4);
	d2.print();
}
