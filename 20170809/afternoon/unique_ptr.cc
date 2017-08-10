 ///
 /// @file    unique_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-09 14:53:05
 ///
 
#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::unique_ptr;
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

unique_ptr<int> getValue()
{
	unique_ptr<int> upi(new int(88));
	return upi;
}


int main(void)
{
	unique_ptr<int> upi(new int(66));
	cout << "*upi = " << *upi << endl;

	unique_ptr<Point> pt(new Point(1, 2));
	cout << "*pt =" << *pt << endl;

	//unique_ptr<Point> pt2 = pt;//不能执行复制操作
	unique_ptr<Point> pt3(new Point(3, 4));
	cout << "*pt3 = " << *pt3 << endl;
	//pt3 = pt;//不能执行复制操作, unique_ptr是独享型智能指针

	unique_ptr<int> upi2 = getValue();//移动语义, getValue的返回值是一个右值
	cout << "*upi2 = " << *upi2 << endl;

	vector<unique_ptr<int>> vec;
	vec.push_back(std::move(upi2));//要使用移动语义的方式添加元素
								   //添加完之后，upi2对象不再被使用
	cout << *vec[0] << endl;
	//cout << *upi2 << endl;//error
	return 0;
}