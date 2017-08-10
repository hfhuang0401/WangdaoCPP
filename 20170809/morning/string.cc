#include <cstring>
#include <iostream>
#include <vector>
 
using std::cin;
using std::cout;
using std::endl;
using std::vector;
 
class String
{
public:
	String()
	:_pstr(new char[1])
	{}
	
	String(const char * pstr)
	:_pstr(new char[strlen(pstr) + 1]())
	{
		cout<<"String(const char *)"<<endl;
		strcpy(_pstr,pstr);
	}
	
	//具有复制语义
	//复制构造函数
	String(const String & rhs)
	:_pstr(new char[strlen(rhs._pstr) + 1]())
	{
		strcpy(_pstr,rhs._pstr);
		cout<<"String(const String &)"<<endl;
	}

	//赋值运算符函数
	String & operator=(const String & rhs)
	{
		cout<<"String & operator=(const String & rhs)"<<endl;
		if(this != &rhs)
		{
			delete [] _pstr;
			_pstr = new char[strlen(rhs._pstr) + 1]();
			strcpy(_pstr,rhs._pstr);
		}

		return *this;
	}

	//具有移动语义的函数会优先执行
	//移动赋值运算符函数
	String & operator = (String && rhs)
	{
		if(this != &rhs)
		{
			cout<<"String & operator = (String && rhs)"<<endl;
			delete [] _pstr;
			_pstr = rhs._pstr;
			rhs._pstr = NULL;
		}

		return *this;
	}

	//移动构造函数
	String(String && rhs)//传递过来的实参是右值，但函数体内，该右值具有了一个名字rhs，因此又变成了一个左值
	:_pstr(rhs._pstr)//浅拷贝
	{
		rhs._pstr = NULL;
		cout<<"String(String && rhs)"<<endl;
	}

	~String()
	{
		delete [] _pstr;
		cout<<"~String()"<<endl;
	}

	friend std::ostream & operator<<(std::ostream &os,const String & rhs);

private:
	char * _pstr;
};

#if 0
String && func()
{
	//...
}
#endif

std::ostream & operator<<(std::ostream &os,const String & rhs)
{
	os<<rhs._pstr;
	return os;
}

int test0(void)
{
	vector<String> vec;
	vec.push_back("hello,world");

	return 0;
}

int test1()
{
	String s1("hello");
	String s2("wangdao");
	cout<<"s1 = "<<s1<<endl;
	cout<<"s2 = "<<s2<<endl;

	s1 = "world";
	cout<<"s1 = "<<s1<<endl;

	//s1 = std::move(s1);//move函数的作用就是强制把一个左值转换为右值使用
	cout<<endl;
	s2 = std::move(s1);//使用移动语义时，要注意该语句之后，该对象不会再使用了
	cout<<"s2 = "<<s2<<endl;
	cout<<"s1 = "<<s1<<endl;

	cout<<"----------"<<endl;
	return 0;
}

int main(void)
{
	test1();
	//String && ref = func();
	return 0;
}
