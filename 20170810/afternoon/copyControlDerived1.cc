#include <cstring>
#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class Base
{
public:
	Base(const char * pdata1)
	:_pdata1(new char[strlen(pdata1) + 1]())
	{
		cout<<"Base(const char *)"<<endl;
		strcpy(_pdata1,pdata1);
	}

	Base(const Base & rhs)
	:_pdata1(new char[strlen(rhs._pdata1) + 1]())
	{
		cout<<"Base(const Base &)"<<endl;
		strcpy(_pdata1,rhs._pdata1);
	}

	Base & operator=(const Base & rhs)
	{
		if(this != &rhs)
		{
			delete [] _pdata1;
			_pdata1 = new char[strlen(rhs._pdata1) + 1]();
			strcpy(_pdata1,rhs._pdata1);
		}
		return *this;
	}

	~Base()
	{
		delete [] _pdata1;
		cout<<"~Base()"<<endl;
	}

	void display()const
	{
		cout<<_pdata1<<endl;
	}

private:
	char * _pdata1;
};


//1.当派生类没有显式定义复制控制函数，而基类有显式定义
//则复制一个派生类对象时，会自动调用基类相应的复制控制函数
class Derived:public Base
{
public:
	Derived(const char * pdata)
	:Base(pdata)
	{
		cout<<"Derived(const char *)"<<endl;
	}
};

int main(void)
{
	Derived d1("hello,world");
	cout<<"d1 = ";
	d1.display();

	Derived d2 = d1;
	cout<<"d2 = ";
	d2.display();

	Derived d3("shenzhen");
	cout<<"d3 = ";
	d3.display();
	d1 = d3;
	cout<<"d1 = ";
	d1.display();

	return 0;
}
