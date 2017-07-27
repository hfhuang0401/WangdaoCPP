#include <cmath>

#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class Point;//类的前向声明,声明的是一个不完全的类

class Line
{
public:
	float distance(const Point &,const Point &);
};

class Point
{
public:
	Point(int ix=0,int iy=0)
	:_ix(ix)
	 ,_iy(iy)
	{}

	void print() const
	{
		cout<<"("<<_ix
			<<","<<_iy
			<<")"<<endl;
	}
	
	//友元之成员函数
	friend class Line;//友元关系是单向的，不能传递，不可继承
//	friend Line;
private:
	int _ix;
	int _iy;
};



float Line::distance(const Point &pt1,const Point &pt2)
{
	cout<<pt1._ix<<pt2._iy<<endl;
	return 1.2;
}


int main(void)
{
	Point pt1(1,2);
	Point pt2(3,4);

}
