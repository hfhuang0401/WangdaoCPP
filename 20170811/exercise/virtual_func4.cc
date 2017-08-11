#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class Base
{
public:
	virtual void disp()
	{
		cout<<"hello,base"<<endl;
	}
};

class Child:public Base
{
public:
	void disp()
	{
		cout<<"hello,child"<<endl;
	}
};

int main()
{
	Base b;
	Child c;
	b.disp();
	c.disp();
	cout<<"----------------"<<endl;
	c.Base::disp();
	c.Child::disp();
	
	return 0;
}
