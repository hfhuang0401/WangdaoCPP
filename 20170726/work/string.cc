#include <cstring>
#include <iostream> 

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::size_t;

class String
{
public:
	String();
	~String();

	String(const char *pstr);
	String(const String & rhs);

	String & operator = (const String & rhs);
	String & operator = (const char * str);
	
	String & operator += (const String & rhs);
	String & operator += (const char * str);
	
	char & operator [] (size_t index);
	const char & operator [] (size_t index) const;

	size_t size() const;
	const char* c_str() const;

	friend bool operator == (const String &lhs,const String &rhs);
	friend bool operator != (const String &lhs,const String &rhs);
	
	friend bool operator < (const String &lhs,const String &rhs);
	friend bool operator > (const String &lhs,const String &rhs);
	friend bool operator <= (const String &lhs,const String &rhs);
	friend bool operator >= (const String &lhs,const String &rhs);
	
	friend ostream & operator << (ostream &os,const String &rhs);
	friend istream & operator >> (istream &is,String &rhs);
	

	void print();
	
private:
	char *_pstr;
};




String::String()
	:_pstr(new char[1]())
{
	*_pstr = '\0';
}

String::~String()
{
	if(NULL!=_pstr)
	{
		delete [] _pstr;
		_pstr = NULL;
	}
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
	if (this != &rhs)
	{
		delete [] _pstr;
		_pstr = new char[strlen(rhs._pstr)+1]();
		strcpy(_pstr,rhs._pstr);
	}
	
	return *this;
}

String & String::operator = (const char * str)
{
	delete [] _pstr;
	_pstr = new char[strlen(str)+1]();
	strcpy(_pstr,str);

	return *this;
}
	
String & String::operator += (const String & rhs)
{
	int len = strlen(_pstr);
	char *tmp = new char[len+1]();
	strcpy(tmp,_pstr);
	delete [] _pstr;
	_pstr = new char[len+strlen(rhs._pstr)+1]();
	strcpy(_pstr,tmp);
	strcat(_pstr,rhs._pstr);
	delete [] tmp;

	return *this;
}

String & String::operator += (const char * str)
{
	int len = strlen(_pstr);
	char *tmp = new char[len+1]();
	strcpy(tmp,_pstr);
	delete [] _pstr;
	_pstr = new char[len+strlen(str)+1]();
	strcpy(_pstr,tmp);
	strcat(_pstr,str);
	delete [] tmp;

	return *this;
}

char & String::operator [] (size_t index)
{
	static char nullchar = '\0';
	if(index < strlen(_pstr))
	{
		return _pstr[index];
	}else
	{
		return nullchar;
	}
}

const char & String::operator [] (size_t index) const
{
	cout <<"const char func is called..."<<endl;
	static char null_const = '\0';
	if(index < strlen(_pstr))
	{
		return _pstr[index];
	}else
	{
		return null_const;
	}
}

size_t String::size() const
{
	return strlen(_pstr);
}

const char* String::c_str() const
{
	return _pstr;
}

bool operator == (const String &lhs,const String &rhs)
{
	if(strcmp(lhs._pstr,rhs._pstr) == 0)
		return true;
	else
		return false;
}

bool operator != (const String &lhs,const String &rhs)
{
	if(strcmp(lhs._pstr,rhs._pstr) != 0)
		return true;
	else
		return false;
}

bool operator < (const String &lhs,const String &rhs)
{
	if(strcmp(lhs._pstr,rhs._pstr) < 0)
		return true;
	else
		return false;
}

bool operator > (const String &lhs,const String &rhs)
{
	if(strcmp(lhs._pstr,rhs._pstr) > 0)
		return true;
	else
		return false;
}

bool operator <= (const String &lhs,const String &rhs)
{
	if(strcmp(lhs._pstr,rhs._pstr) <= 0)
		return true;
	else
		return false;
}

bool operator >= (const String &lhs,const String &rhs)
{
	if(strcmp(lhs._pstr,rhs._pstr) >= 0)
		return true;
	else
		return false;
}

ostream & operator << (ostream &os,const String &rhs)
{
	os << rhs._pstr;
	return os;
}

istream & operator >> (istream &is,String &rhs)
{
	rhs._pstr = new char[512];
	is >> rhs._pstr;
	return is;
}

String operator + (const String &lhs,const String &rhs)
{
	String tmp(lhs);
	tmp += rhs;
	return tmp;
}

String operator + (const String &lhs,const char *str)
{
	String tmp1(lhs);
	String tmp2(str);
	tmp1 += tmp2;
	return tmp1;
}

String operator + (const char *str,const String &rhs)
{
	String tmp1(str);
	String tmp2(rhs);
	tmp1 += tmp2;
	return tmp1;
}

void String::print()
{
	cout<<"pstr = "<<_pstr<<endl;
}


int main(void)
{
	String s0("equal");
	String s1("equal");
	if(s0 <= s1)
		cout<<"s0 <= s1"<<endl;
	if(s0 >= s1)
		cout<<"s0 >= s1"<<endl;
	String s = "hello";
	String s2 = "hello";
	String s3 = "hi";
	String s4 = "zz";
	String s5;
	if(s == s2)
		cout<<"s = s2"<<endl;
	if(s != s3)
		cout<<"s != s3"<<endl;
	if(s2 < s3)
		cout<<"s2 < s3"<<endl;
	if(s3 > s4)
		cout<<"s3 < s4"<<endl;
	cout<<"---------------"<<endl;
	s5 = s3 + s4;
	s5.print();
	cout<<"---------------"<<endl;
	String s6;
	s6 = s5 + "hehe";
	s6.print();
	cout<<"---------------"<<endl;
	String s7;
	s7 = "HEAD" + s6;
	String empty;
	cout<<empty<<endl;
	cout<<"the empty str..."<<endl;
	cout<<"---------------"<<endl;
	cout << s7 << endl;
	cout<<"---------------"<<endl;
	String s8;
	cin >> s8;
	cout<<"this is s8"<<endl;
	cout<<s8<<endl;
	cout<<"---------------"<<endl;
	const char *str = s.c_str();
	s.print();
	cout<<"s.size = "<<s.size()<<endl;
	cout<<"s.c_str = "<<str<<endl;
	cout<<"---------------"<<endl;
	s += s;
	s.print();
	cout<<"---------------"<<endl;
	s += "bye";
	s.print();
	cout<<"---------------"<<endl;
	cout<<"s = "<<s[50]<<endl;
	cout<<"==============="<<endl;
	const String ss = "string";
	cout<<"s[0]="<<ss[0]<<endl;
	if(s == ss)
		cout<<"yes"<<endl;
	if (s != ss)
		cout<<"not equal"<<endl;

	return 0;
}
