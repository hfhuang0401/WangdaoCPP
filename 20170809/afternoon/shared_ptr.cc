 ///
 /// @file    shared_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-09 14:53:05
 ///
 
#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::vector;


class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)"
			 << endl;
	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);

	~Point()
	{
		cout << "~Point()" << endl;
	}

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

int main(void)
{
	shared_ptr<int> upi(new int(66));
	cout << "*upi = " << *upi << endl;

	shared_ptr<Point> pt(new Point(1, 2));
	cout << "*pt =" << *pt << endl;
	cout << "pt's use_count = " << pt.use_count() << endl;

	shared_ptr<Point> pt3(new Point(3, 4));
	cout << "*pt3 = " << *pt3 << endl;

	shared_ptr<Point> pt2 = pt;
	cout << "pt's use_count = " << pt.use_count() << endl;
	cout << "pt2's use_count = " << pt2.use_count() << endl;
	pt3 = pt;
	cout << "pt2's use_count = " << pt2.use_count() << endl;
	cout << "pt3's use_count = " << pt3.use_count() << endl;
	cout << endl;

	shared_ptr<Point> pt4(new Point(1, 2));
	cout << "pt4's use_count = " << pt4.use_count() << endl;

	return 0;
}
