#include"nestclass.h"

#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;
 
class Line::LineImpl
{
private:
	class Point
	{
	public:
		Point(int ix = 0,int iy = 0)
		:_ix(ix)
		,_iy(iy)
		{}
		void print()const;
	private:
		int _ix;
		int _iy;
	};
public:
	LineImpl(int x1,int y1,int x2,int y2)
	:_p1(x1,y1)
	,_p2(x2,y2)
	{
		cout<<"LineImpl(int,int,int,int)"<<endl;
	}
	void printLine()
	{
		_p1.print();
		cout<<"--->";
		_p2.print();
		cout<<endl;
	}
private:
	Point _p1;
	Point _p2;
};

void Line::LineImpl::Point::print() const
{
	cout<<"("<<_ix
		<<","<<_iy
		<<")";
}

Line::Line(int x1,int y1,int x2,int y2)
:_pImpl(new LineImpl(x1,y1,x2,y2))
{
}

Line::~Line()
{
	delete _pImpl;
}

void Line::printLine()const
{
	_pImpl->printLine();
}

