#include <iostream>
#include <cstring>
 
using std::cout;
using std::endl;

class Base
{
public:
	Base(const char *pbase)
	:_pbase(new char[strlen(pbase)+1]())
	{
		cout<<"Base()"<<endl;
		strcpy(_pbase,pbase);
	}

	virtual ~Base()
	{
		cout<<"~Base()"<<endl;
		delete [] _pbase;
	}

	virtual void print()const
	{
		cout<<_pbase<<endl;
	}

private:
	char * _pbase;
};

class Child
:public Base
{
public:
	Child(const char *pbase,const char *pchild)
	:Base(pbase)
	,_pchild(new char[strlen(pchild)+1]())
	{
		cout<<"Child()"<<endl;
		strcpy(_pchild,pchild);
	}

	//一旦基类的析构函数成为虚函数之后，派生类的析构函数会自动成为虚函数
	//即使没有给出virtual关键字
	~Child()
	{
		cout<<"~Child()"<<endl;
		delete [] _pchild;
	}

	void print()const
	{
		Base::print();
		cout<<_pchild<<endl;
	}

private:
	char *_pchild;
};

int main(void)
{
	Base *pbase = new Child("hello,","world");

	pbase->print();

	delete pbase;
}
