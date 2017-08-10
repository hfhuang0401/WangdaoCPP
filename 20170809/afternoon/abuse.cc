 ///
 /// @file    abuse.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-09 14:53:05
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::unique_ptr;

class Point
: public std::enable_shared_from_this<Point>  //在类内部获取本对象的shared_ptr的方式
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)"
			 << endl;
	}


	~Point()
	{
		cout << "~Point()" << endl;
	}

#if 0
	Point * addPoint(Point * pt)
	{
		_ix += pt->_ix;
		_iy += pt->_iy;
		return this;
	}
#endif
	shared_ptr<Point> addPoint(Point * pt)
	{
		_ix += pt->_ix;
		_iy += pt->_iy;
		return shared_from_this();
		//return shared_ptr<Point>(this);
	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

int test0(void)
{//误用1: 同时将一个原生裸指针交给不同的智能指针进行托管
	Point * p1 = new Point(1, 2);
	shared_ptr<Point> sp1(p1);
	shared_ptr<Point> sp2(p1);
	unique_ptr<Point> up1(p1);

	return 0;
}

int test1()
{//误用2
	Point * p1 = new Point(1, 2);
	shared_ptr<Point> sp1(p1);
	shared_ptr<Point> sp2(new Point(3, 4));

	sp2.reset(sp1.get());
	cout << "*sp2 = " << *sp2 << endl;
	return 0;
}

int test2()
{//误用3: 函数的返回值是一个原生裸指针 
	shared_ptr<Point> sp1(new Point(1, 2));
	shared_ptr<Point> sp2(new Point(3, 4));

	shared_ptr<Point> sp3(sp1->addPoint(sp2.get()));

	cout << *sp1 << endl;
	return 0;
}


int main(void)
{
	//test0();
	//test1();
	test2();
	return 0;
}
