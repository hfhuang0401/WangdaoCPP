#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class A
{
public:
	void display() const
	{
		cout<<"A::display()"<<endl;
	}
};

class B
{
public:
	void print() const
	{
		cout<<"B::print()"<<endl;
	}
};

class C
:public A
,public B
{
public:
	void show() const
	{
		cout<<"c::show()"<<endl;
	}
};

int main(void)
{
	C c;
	c.print();
	c.show();
	c.display();
}
