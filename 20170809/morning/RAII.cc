#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

template <typename T>
class RAII
{
public:
	RAII(T *p)
	:_p(p)
	{}

	T & operator*()
	{
		if(_p)
			return *_p;
	}

	T * operator->()
	{
		return _p;
	}

	T * get()
	{
		return _p;
	}

	~RAII()
	{
		if(_p)
			delete _p;
	}

private:
	T * _p;
};

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{}

	void print()const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

private:
	int _ix;
	int _iy;
};

int test0()
{
	int * p1 = new int(1);
	RAII<int> pInt(p1);

	cout << *p1 << endl;
	cout << *pInt << endl;

	return 0;
}

int test1()
{
	Point * p1 = new Point(1,2);
	RAII<Point> pt(p1);//栈对象

	p1->print();
	pt->print();

	return 0;
}

int main(void)
{
	test1();

	return 0;
}
