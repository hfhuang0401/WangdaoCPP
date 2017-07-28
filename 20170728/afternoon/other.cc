 ///
 /// @file    string.cc
 /// @author  rosy821142980(821142980@qq.com)
 /// @date    2017-07-28 12:29:58
 ///
#include <stdio.h> 
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
//using std::string;

class String
{
	public:
		String();
		String(const char* pstr);
		String(const String & rhs);
		String & operator=(const String & rhs);
		~String();
		String & operator[](size_t idx);
		String & operator=(const char ch);
		const char* c_str() const
		{
			return  _pstr;
		}
		size_t size() const
		{
			return strlen(_pstr);
		}
		size_t refcount() const
		{
			return _pstr[size()+1];
		}
		friend std::ostream & operator<<(std::ostream& os,const String & rhs);
	private:
		void initRefcount()
		{
			_pstr[size()+1]=1;
		}
		void increaseRefcount()
		{
			++_pstr[size()+1];
		}
		void decreaseRefcount()
		{
			--_pstr[size()+1];
		}

		char* _pstr;
		size_t pos;
};

String::String()
:_pstr(new char[2]())
{
	cout<<"String()"<<endl;
	initRefcount();
}

String::String(const char* pstr)
:_pstr(new char[strlen(pstr)+2]())
{
	cout<<"String(const char*)"<<endl;
	strcpy(_pstr,pstr);
	initRefcount();
}

String::String(const String& rhs)
:_pstr(rhs._pstr)
{
	increaseRefcount();
}

String& String::operator=(const String & rhs)
{
	if(this!=&rhs)
	{
		decreaseRefcount();
		if(refcount()==0)
		{
			delete [] _pstr;
			cout<<"operator=:delete this's _pstr"<<endl;
		}
		_pstr=rhs._pstr;
		increaseRefcount();
	}
		return *this;
}

String::~String()
{
	decreaseRefcount();
	if(refcount()==0)
	{
		delete [] _pstr;
		cout<<"~String"<<endl;
	}
}

std::ostream& operator<<(std::ostream& os,const String & rhs)
{
	os<<rhs._pstr;
		return os;
}

String& String::operator[](size_t idx)
{
	if(idx>=size())
		cout<<"越界 不可访问!"<<endl;
	pos=idx;  //新增数据成员pos
	return *this;
}

String& String::operator=(const char ch)
{
	cout<<"i am changing ch  pos="<<pos<<endl;
	if(pos<size())
	{
		if(refcount()>1)
		{
			decreaseRefcount();
			char* ptmp=new char[size()+2]();
			strcpy(ptmp,_pstr);
			_pstr=ptmp;
			initRefcount();
		}
		_pstr[pos]=ch;
	}
	else
		cout<<"越界，不可更改!"<<endl;
	return *this;
}
int main()
{
	String s1;
	String s2 = "hello";
	String s3(s2);
	String s4 = s3;
	
	cout<<"s1 = "<<s1<<endl;
	cout<<"s2 = "<<s2<<endl;
	cout<<"s3 = "<<s3<<endl;
	cout<<"s4 = "<<s4<<endl;
	cout << "s1's refcount = " << s1.refcount() << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s3's refcount = " << s3.refcount() << endl;
	cout << "s4's refcount = " << s4.refcount() << endl;
	printf("&s1 = %p\n",s1.c_str());
	printf("&s2 = %p\n",s2.c_str());
	printf("&s3 = %p\n",s3.c_str());
	printf("&s4 = %p\n",s4.c_str());

	s1 = s2;
	cout<<"---------------"<<endl;
	cout<<"s1 = "<<s1<<endl;
	cout<<"s2 = "<<s2<<endl;
	cout<<"s3 = "<<s3<<endl;
	cout<<"s4 = "<<s4<<endl;
	cout << "s1's refcount = " << s1.refcount() << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s3's refcount = " << s3.refcount() << endl;
	cout << "s4's refcount = " << s4.refcount() << endl;
	printf("&s1 = %p\n",s1.c_str());
	printf("&s2 = %p\n",s2.c_str());
	printf("&s3 = %p\n",s3.c_str());
	printf("&s4 = %p\n",s4.c_str());

	s2[0] = 'P';
	cout<<"------做写操作-------"<<endl;
	cout<<"s1 = "<<s1<<endl;
	cout<<"s2 = "<<s2<<endl;
	cout<<"s3 = "<<s3<<endl;
	cout<<"s4 = "<<s4<<endl;
	cout << "s1's refcount = " << s1.refcount() << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s3's refcount = " << s3.refcount() << endl;
	cout << "s4's refcount = " << s4.refcount() << endl;
	printf("&s1 = %p\n",s1.c_str());
	printf("&s2 = %p\n",s2.c_str());
	printf("&s3 = %p\n",s3.c_str());
	printf("&s4 = %p\n",s4.c_str());

	cout<<"--------做读操作----------"<<endl;
	cout<<"s1[0] = "<<s1[0]<<endl;
	cout<<"s1 = "<<s1<<endl;
	cout<<"s2 = "<<s2<<endl;
	cout<<"s3 = "<<s3<<endl;
	cout<<"s4 = "<<s4<<endl;
	cout << "s1's refcount = " << s1.refcount() << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s3's refcount = " << s3.refcount() << endl;
	cout << "s4's refcount = " << s4.refcount() << endl;
	printf("&s1 = %p\n",s1.c_str());
	printf("&s2 = %p\n",s2.c_str());
	printf("&s3 = %p\n",s3.c_str());
	printf("&s4 = %p\n",s4.c_str());

	return 0;
}
