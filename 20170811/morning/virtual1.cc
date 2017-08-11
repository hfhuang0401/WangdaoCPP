#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class Base
{
public:
	virtual int func(int x)
//	int func(int x)
	{
		cout<<"Base::func() x = "<<x<<endl;
		return x;
	}
};

class Sub
:public Base
{
public:
//	virtual int func(int x)
	int func(int x)
	{
		cout<<"Sub::func(int)= "<<x<<endl;
		return 0;
	}
};

void display(Base * pbase)
{
	pbase->func(10);
}

int main(void)
{
	Base base;
	Sub sub;

	display(&base);
	display(&sub);

	return 0;
}
