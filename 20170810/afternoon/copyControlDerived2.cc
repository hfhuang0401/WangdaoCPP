#include <cstring>
#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class Base
{
public:
	Base()
	:_pdata1(new char[1])
	{
		cout<<"Base()"<<endl;
	}

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
		cout<<"Base: "<<_pdata1<<endl;
	}

private:
	char * _pdata1;
};


//2.当派生类有显式定义复制控制函数，而基类有显式定义
//则复制一个派生类对象时，不会自动调用基类相应的复制控制函数
//必须手动显式调用基类的相应复制控制函数
class Derived:public Base
{
public:
	Derived(const char * pdata1,const char * pdata2)
	:Base(pdata1)
	,_pdata2(new char[strlen(pdata2) + 1]())
	{
		cout<<"Derived(const char *)"<<endl;
		strcpy(_pdata2,pdata2);
	}

	Derived(const Derived & rhs)
	:Base(rhs)//必须加上
	,_pdata2(new char[strlen(rhs._pdata2) + 1]())
	{
		strcpy(_pdata2,rhs._pdata2);
		cout<<"Derived(const Derived &)"<<endl;
	}

	Derived & operator=(const Derived & rhs)
	{
		if(this != &rhs)
		{
			//必须加上
			Base::operator=(rhs);

			delete [] _pdata2;
			_pdata2 = new char[strlen(rhs._pdata2) + 1]();
			strcpy(_pdata2,rhs._pdata2);
		}
		return *this;
	}

	~Derived()
	{
		delete [] _pdata2;
	}

	void display()const
	{
		Base::display();
		cout<<"Derived: "<<_pdata2<<endl;
	}

private:
	char * _pdata2;
};

int main(void)
{
	Derived d1("hello","world");
	cout<<"d1 = ";
	d1.display();

	Derived d2 = d1;
	cout<<"d2 = ";
	d2.display();
	
	cout<<"--------------"<<endl;
#if 1
	Derived d3("shenzhen","wangdao");
	cout<<"d3 = ";
	d3.display();
	d1 = d3;
	cout<<"d1 = ";
	d1.display();
#endif

	return 0;
}
