#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

class Data
{
public:
	Data()
	:_size(5)
	{
	}

	int length()
	{
		return _size;
	}
	
private:
	int _size;

	friend ostream & operator << (ostream & os,const Data & rhs);
};

ostream & operator << (ostream & os,const Data &rhs)
{
	os << rhs._size;
	return os;
}

class DataPtr
{
public:
	DataPtr()
	:_pData(new Data)
	{}

	~DataPtr()
	{
		delete _pData;
	}

	Data * operator->()
	{
		return _pData;
	}

	Data & operator*()
	{
		return *_pData;
	}

private:
	Data * _pData;
};

class ThirdLayer
{
public:
	ThirdLayer()
	:_p(new DataPtr)
	{}
	
	~ThirdLayer()
	{
		delete _p;
	}

	DataPtr & operator->()
	{
		return *_p;
	}
private:
	DataPtr * _p;
};

int main(void)
{
	DataPtr dp;
	cout<<dp->length()<<endl;
	cout<<dp.operator->()->length()<<endl;

	cout<<"----------------"<<endl;
	cout<<*dp<<endl;

	ThirdLayer tl;
	cout<<tl->length()<<endl;
	cout<<(tl.operator->()).operator->()->length()<<endl;

	
}
