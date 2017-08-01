#include <cmath>
#include <iostream> 
#include <set>
 
using std::cin;
using std::cout;
using std::endl;
using std::set;

#if 0
void test0(void)
{
	int arr[] = {2,1,3,5,4,6,3,5,6};
	//set内部不能存放相同的关键字，内部元素是唯一的
	//默认情况下采用升序方式进行排列
	set<int,std::greater<int> > setInt(arr,arr+9);

	set<int>::const_iterator it;
	for(it = setInt.begin();it != setInt.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	//cout<<setInt[0]<<endl;//不支持下标访问运算符，只支持双向迭代器
}
#endif

class Point
{
public:
	Point(int ix=0,int iy =0)
	:_ix(ix)
	,_iy(iy)
	{}
	friend std::ostream & operator <<(std::ostream &os,const Point &rhs);
	friend bool operator <(const Point &lhs,const Point &rhs);
	friend bool operator >(const Point &lhs,const Point &rhs);
	friend bool operator == (const Point &lhs,const Point &rhs);

	float distance()const
	{
		return sqrt(_ix*_ix+_iy*_iy);
	}

private:
	int _ix;
	int _iy;
};

std::ostream & operator <<(std::ostream &os,const Point &rhs)
{
	os<<"("<<rhs._ix
	  <<","<<rhs._iy
	  <<")";
	return os;
}

#if 0
bool operator <(const Point &lhs,const Point &rhs)
{
	return (lhs.distance()<rhs.distance());
}
#endif

bool operator <(const Point &lhs,const Point &rhs)
{
	if(lhs.distance()<rhs.distance())
		return true;
	else if(lhs.distance()==rhs.distance())
	{
		if(lhs._ix<rhs._ix)
			return true;
		else
			return false;
	}else
		return false;
}

bool operator >(const Point &lhs,const Point &rhs)
{
	return (lhs.distance()>rhs.distance());
}

#if 0
//只要内容相同，就认为这两个对象相等
bool operator == (const Point &lhs,const Point &rhs)
{
	cout<<"operator == is  called"<<endl;
	if (lhs.distance()==rhs.distance())
	{
		if(lhs._ix==rhs._ix && lhs._iy==rhs._iy)
			return true;
		else
			return false;
	}else
		return false;
}
#endif

struct Compare
{
	bool operator()(const Point &lhs,const Point &rhs)
	{
		cout<<"Compare()"<<endl;
		return lhs.distance()<rhs.distance();
	}
};

void test2()
{
	//如何判断两个元素相等
	//
	//1.比较时使用 std::less<Point>,就是一个 < 符号
	//2.等价 !(e1 < e2) && !(e2 < e1)
	set<Point> points{
//	set<Point,std::greater<Point> > points{
		Point(-1,2),
		Point(3,4),
		Point(0,-1),
		Point(1,2),
		Point(5,9),
		Point(1,2)
	};

	set<Point>::iterator it;
	for(it = points.begin(); it != points.end(); ++ it)
	{
		//*it = 7//set之中的元素都是只读的,不能进行修改
		cout<<*it<<endl;
	}
}

void test3()
{
	set<Point,Compare> points{
		Point(-1,2),
		Point(3,4),
		Point(0,-1),
		Point(1,2),
		Point(5,9),
		Point(1,2)
	};

	set<Point>::iterator it;
	for(it = points.begin(); it != points.end(); ++ it)
	{
		cout<<*it<<endl;
	}
}

int main(void)
{
	test3();
}
