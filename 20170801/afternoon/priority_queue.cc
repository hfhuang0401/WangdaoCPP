#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
 
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;

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

struct Compare
{
	bool operator()(const Point &lhs,const Point &rhs)
	{
		cout<<"Compare()"<<endl;
		return lhs.distance()<rhs.distance();
	}
};

void test0(void)
{
	int arr[10] = {0,1,3,2,5,6,9,8,7,4};
//	priority_queue<int> pque(arr,arr+10);
//	1.默认情况下，按std::less进行比较，但元素出队时是降序排列
//	2.优先级队列的底层实现用的是堆排序
//	3.每一次比较时，拿堆顶元素与新元素进行比较，当满足比较条件时，就用新元素替换堆顶元素
	priority_queue<int> pque;
	for(int idx=0;idx!=10;++idx)
	{
		pque.push(arr[idx]);
		cout<<"当前队列中优先级最高的是："<<pque.top()<<endl;
	}

	while(!pque.empty())
	{
		cout<<pque.top()<<endl;
		pque.pop();
	}
}

void test1(void)
{
	int arr[10] = {0,1,3,2,5,6,9,8,7,4};
	priority_queue<int,vector<int>,std::greater<int> > pque;
	for(int idx=0;idx!=10;++idx)
	{
		pque.push(arr[idx]);
		cout<<"当前队列中优先级最高的是："<<pque.top()<<endl;
	}

	while(!pque.empty())
	{
		cout<<pque.top()<<endl;
		pque.pop();
	}
}

void test2(void)
{
	priority_queue<Point> pque;
	pque.push(Point(1,2));
	cout<<"当前队列中优先级最高的是："<<pque.top()<<endl;
	pque.push(Point(3,4));
	cout<<"当前队列中优先级最高的是："<<pque.top()<<endl;
	pque.push(Point(5,6));
	cout<<"当前队列中优先级最高的是："<<pque.top()<<endl;
	pque.push(Point(-1,4));
	cout<<"当前队列中优先级最高的是："<<pque.top()<<endl;
	pque.push(Point(0,6));
	cout<<"当前队列中优先级最高的是："<<pque.top()<<endl;

	while(!pque.empty())
	{
		cout<<pque.top()<<endl;
		pque.pop();
	}
}

void test3(void)
{
	priority_queue<Point,vector<Point>,Compare> pque;
	pque.push(Point(1,2));
	cout<<"当前队列中优先级最高的是："<<pque.top()<<endl;
	pque.push(Point(3,4));
	cout<<"当前队列中优先级最高的是："<<pque.top()<<endl;
	pque.push(Point(5,6));
	cout<<"当前队列中优先级最高的是："<<pque.top()<<endl;
	pque.push(Point(-1,4));
	cout<<"当前队列中优先级最高的是："<<pque.top()<<endl;
	pque.push(Point(0,6));
	cout<<"当前队列中优先级最高的是："<<pque.top()<<endl;

	while(!pque.empty())
	{
		cout<<pque.top()<<endl;
		pque.pop();
	}
}
int main()
{
	test3();
	return 0;
}
