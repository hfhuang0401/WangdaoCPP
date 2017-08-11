#include <iostream> 
 
using std::cout;
using std::endl;

//定义了protected型构造函数的类也是抽象类
class Base
{
public:
	void display()const
	{
		cout<<"Base::_ix = "<<_ix<<endl;
	}
protected:
	Base(int ix)
	:_ix(ix)
	{
		cout<<"Base(int ix)"<<endl;
	}
private:
	int _ix;
};

class Child
:public Base
{
public:
	Child(int ix,int iy)
	:Base(ix)
	,_iy(iy)
	{
		cout<<"Child(int ix,int iy)"<<endl;
	}
private:
	int _iy;
};

int main(void)
{
//	Base base;
	Base *p = new Child(1,2);
	p->display();

	cout<<"------------------"<<endl;
	Child c(3,4);
	c.display();

	return 0;
}
