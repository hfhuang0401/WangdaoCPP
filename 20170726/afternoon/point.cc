#include <cmath>

#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

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
	
	//友元之普通函数
	friend float distance(const Point &,const Point &);
private:
	int _ix;
	int _iy;
};

float distance(const Point &lhs,const Point &rhs)
{
	return	sqrt((lhs._ix - rhs._ix) * (lhs._ix - rhs._ix)
	+(lhs._iy - rhs._iy) * (lhs._iy - rhs._iy));
}

int main(void)
{
	Point pt1(1,2);
	Point pt2(3,4);

	cout<<"the distance is "<<distance(pt1,pt2)<<endl;
}
