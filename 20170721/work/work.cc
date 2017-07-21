#include <iostream> 
#include <cstring>
 
using std::cin;
using std::cout;
using std::endl;

class String
{
public:
	String();
	String(const char *pstr);
	String(const String & rhs);
	String & operator = (const String & rhs);
	~String();
	
	void print();
private:
	char *_pstr;
};

String::String()
	:_pstr(new char[1]())
{
	*_pstr = '\0';
}

String::String(const char *pstr)
	:_pstr(new char[strlen(pstr)+1]())
{
	strcpy(_pstr,pstr);
}

String::String(const String & rhs)
	:_pstr(new char[strlen(rhs._pstr)+1]())
{
	strcpy(_pstr,rhs._pstr);
}

String &String::operator = (const String & rhs)
{
	_pstr = new char[strlen(rhs._pstr)+1]();
	strcpy(_pstr,rhs._pstr);
	return *this;
}

void String::print()
{
		cout<<"pstr = "<<_pstr<<endl;
}

String::~String()
{
	if(NULL!=_pstr)
	{
		delete [] _pstr;
		_pstr = NULL;
	}
}

int main(void)
{
	String str1;
	str1.print();

	String str2 = "Hello,world";
	String str3("wangdao");

	str2.print();
	str3.print();

	String str4 = str3;
	str4.print();

	str4 = str2;
	str4.print();
}
