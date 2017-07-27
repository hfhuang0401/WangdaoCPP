#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

class AnotherPoint;

class Point
{
public:
	Point(int ix = 0,int iy = 0)
	:_ix(ix)
	,_iy(iy)
	{}

	operator int()
	{
		cout<<"operator int()"<<endl;
		return _ix * _iy;
	}

	operator double()
	{
		return static_cast<double>(_ix)/_iy;
	}

	operator AnotherPoint();

	friend ostream & operator << (ostream &os,const Point &rhs);

private:
	int _ix;
	int _iy;
};

ostream & operator << (ostream &os,const Point & rhs)
{
	os<<"("<<rhs._ix
	  <<","<<rhs._iy
	  <<")";
	return os;
}

class AnotherPoint
{
public:
	AnotherPoint(double ix = 0,double iy = 0)
	:_ix(ix)
	,_iy(iy)
	{}

	friend ostream & operator << (ostream &os,const AnotherPoint & rhs);
private:
	double _ix;
	double _iy;
};

ostream & operator << (ostream &os,const AnotherPoint & rhs)
{
	os<<"("<<rhs._ix
	  <<","<<rhs._iy
	  <<")";
	return os;
}

Point::operator AnotherPoint()
{
	return AnotherPoint(_ix,_iy);
}

int main(void)
{
	Point pt(1,2);
	cout<<"pt = "<<pt<<endl;

	int x = pt;
	cout<<"x = "<<x<<endl;

	double y =pt;
	cout<<"y = "<<y<<endl;

	AnotherPoint ap = pt;
	cout<<"ap = "<<ap<<endl;

	return 0;
}
