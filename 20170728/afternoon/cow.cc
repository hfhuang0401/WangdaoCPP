#include <cstdio>
#include <cstring>
#include <iostream>
 
using std::cout;
using std::endl;
using std::ostream;

class String
{
public:
	String();
	~String();
	String(const char *str);
	String(const String &rhs);

	size_t size() const
	{
		return strlen(_pstr);
	}

	size_t refCount() const
	{
		return _pstr[size()+1];
	}

	const char * c_str() const
	{
		return _pstr;
	}

	String & operator = (const String &rhs);
	char & operator [] (size_t idx);
	friend ostream & operator << (ostream &os,const String &rhs);

private:
	void initRefCount()
	{
		_pstr[size()+1] = 1;
	}

	void increaseRefCount()
	{
		++_pstr[size()+1];
	}

	void decreaseRefCount()
	{
		--_pstr[size()+1];
	}

	char *_pstr;
};

String::String()
:_pstr(new char[2]())
{
	initRefCount();
	cout<<"String()"<<endl;
}

String::~String()
{
	decreaseRefCount();
	if(refCount() == 0)
	{
		delete _pstr;
		cout<<"~String()"<<endl;
	}
}

String::String(const char *str)
:_pstr(new char[strlen(str)+2]())
{
	strcpy(_pstr,str);
	initRefCount();
	cout<<"String(const char *str)"<<endl;
}

String::String(const String &rhs)
:_pstr(rhs._pstr)
{
	increaseRefCount();
	cout<<"String(const String &rhs)"<<endl;
}

String & String::operator = (const String &rhs)
{
	if(this != &rhs)
	{
		decreaseRefCount();
		if(refCount() == 0)
			delete [] _pstr;
		_pstr = new char[strlen(rhs._pstr)+2]();
		_pstr = rhs._pstr;
		increaseRefCount();
	}
	return *this;
}

ostream & operator << (ostream &os,const String &rhs)
{
	os << rhs._pstr;
	return os;
}

char & String::operator [] (size_t idx)
{
	static char nullchar = '\0';
	if(idx < size())
	{
		if(refCount()>1)
		{
			decreaseRefCount();
			char *tmp = new char[strlen(_pstr)+2]();
			strcpy(tmp,_pstr);
			_pstr = tmp;
			initRefCount();
		}
		return _pstr[idx];
	}else
	{
		return nullchar;
	}
}

int main(void)
{
	String s1;
	String s2 = "hello";
	String s3(s2);
	String s4 = s3;
	String s5 = "hello";
	String s6(s5);
	
	cout<<"s1 = "<<s1<<endl;
	cout<<"s2 = "<<s2<<endl;
	cout<<"s3 = "<<s3<<endl;
	cout<<"s4 = "<<s4<<endl;
	cout<<"s5 = "<<s5<<endl;
	cout<<"s6 = "<<s6<<endl;
	printf("&s1 = %p\n",s1.c_str());
	printf("&s2 = %p\n",s2.c_str());
	printf("&s3 = %p\n",s3.c_str());
	printf("&s4 = %p\n",s4.c_str());
	printf("&s5 = %p\n",s5.c_str());
	printf("&s6 = %p\n",s6.c_str());

	s1 = s2;
	cout<<"---------------"<<endl;
	cout<<"s1 = "<<s1<<endl;
	cout<<"s2 = "<<s2<<endl;
	cout<<"s3 = "<<s3<<endl;
	cout<<"s4 = "<<s4<<endl;
	cout<<"s5 = "<<s5<<endl;
	cout<<"s6 = "<<s6<<endl;
	printf("&s1 = %p\n",s1.c_str());
	printf("&s2 = %p\n",s2.c_str());
	printf("&s3 = %p\n",s3.c_str());
	printf("&s4 = %p\n",s4.c_str());
	printf("&s5 = %p\n",s5.c_str());
	printf("&s6 = %p\n",s6.c_str());

	s2[0] = 'P';
	cout<<"---------------"<<endl;
	cout<<"s1 = "<<s1<<endl;
	cout<<"s2 = "<<s2<<endl;
	cout<<"s3 = "<<s3<<endl;
	cout<<"s4 = "<<s4<<endl;
	cout<<"s5 = "<<s5<<endl;
	cout<<"s6 = "<<s6<<endl;
	printf("&s1 = %p\n",s1.c_str());
	printf("&s2 = %p\n",s2.c_str());
	printf("&s3 = %p\n",s3.c_str());
	printf("&s4 = %p\n",s4.c_str());
	printf("&s5 = %p\n",s5.c_str());
	printf("&s6 = %p\n",s6.c_str());

#if 1
	cout<<"--------做读操作----------"<<endl;
	cout<<"s1[0] = "<<s1[0]<<endl;
	cout<<"s1 = "<<s1<<endl;
	cout<<"s2 = "<<s2<<endl;
	cout<<"s3 = "<<s3<<endl;
	cout<<"s4 = "<<s4<<endl;
	cout<<"s5 = "<<s5<<endl;
	cout<<"s6 = "<<s6<<endl;
	printf("&s1 = %p\n",s1.c_str());
	printf("&s2 = %p\n",s2.c_str());
	printf("&s3 = %p\n",s3.c_str());
	printf("&s4 = %p\n",s4.c_str());
	printf("&s5 = %p\n",s5.c_str());
	printf("&s6 = %p\n",s6.c_str());
#endif
}
