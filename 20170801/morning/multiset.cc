#include <cmath>
#include <iostream> 
#include <set>
 
using std::cin;
using std::cout;
using std::endl;
using std::multiset;

#if 1
void test0(void)
{
	int arr[] = {2,1,3,5,4,6,3,5,6};
	//multiset内部不能存放相同的关键字，内部元素是唯一的
	//默认情况下采用升序方式进行排列
	multiset<int,std::greater<int> > multisetInt(arr,arr+9);

	multiset<int>::const_iterator it;
	for(it = multisetInt.begin();it != multisetInt.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	//cout<<multisetInt[0]<<endl;//不支持下标访问运算符，只支持双向迭代器
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

bool operator <(const Point &lhs,const Point &rhs)
{
	return (lhs.distance()<rhs.distance());
}

bool operator >(const Point &lhs,const Point &rhs)
{
	return (lhs.distance()>rhs.distance());
}

void test2()
{
	//如何判断两个元素相等
	multiset<Point,std::greater<Point> > points{
		Point(1,2),
		Point(3,4),
		Point(0,-1),
		Point(-1,2),
		Point(5,9),
		Point(1,2)
	};

	multiset<Point>::iterator it;
	for(it = points.begin(); it != points.end(); ++ it)
	{
		//*it = 7//multiset之中的元素都是只读的,不能进行修改
		cout<<*it<<endl;
	}
}

int main(void)
{
	test2();
}
