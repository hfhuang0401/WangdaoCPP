#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class Base
{
private:
	int x;
protected:
	Base(int xp = 0)
	{
		x = xp;
	}
public:
	void disp()
	{
		cout<<"x = "<<x<<endl;
	}
};

class Child
:public Base
{
public:
//	Base b;//错误，在派生类中不能创建Base类对象
	Child(int xpp):Base(xpp)
	{}
};

int main(void)
{
//	Base b;//错误，外部不能创建Base类对象
	Child c(1);
	c.disp();

	return 0;
}
