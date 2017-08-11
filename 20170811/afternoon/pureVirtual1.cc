#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

#if 1
class A
{//拥有纯虚函数的类就是一个接口类
public:
	//拥有纯虚函数的类是一个抽象类，抽象类是不能创建对象的
	virtual void display()=0;
	virtual void print()=0;
};
#endif

class B
:public A
//当派生类继承自抽象类，必须要实现基类所有的纯虚函数，才能够创建对象
//只要有一个纯虚函数没有实现，其依然是一个抽象类
{
public:
	void display()
	{
		cout<<"B::display()"<<endl;
	}
};

class C
:public B
{
public:

	void display()
	{
		cout<<"C::display()"<<endl;
	}

	void print()
	{
		cout<<"C::print()"<<endl;
	}
};

int main(void)
{
//	A a;//ERROR

//	A *p = new B;

//	p->display();

//	cout<<"sizeof(B) = "<<sizeof(B)<<endl;

	A *p = new C;
	p->display();
	p->print();

	return 0;
}
