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
	friend float Line::distance(const Point &,const Point &);
private:
	int _ix;
	int _iy;
};



float Line::distance(const Point &,const Point &)
{

}


int main(void)
{
	Point pt1(1,2);
	Point pt2(3,4);

	cout<<"the distance is "<<distance(pt1,pt2)<<endl;
}
