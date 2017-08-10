#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix = 0,int iy = 0)
	:_ix(ix)
	,_iy(iy)
	{}
	
	void print() const
	{
		cout<<"("<<_ix
			<<","<<_iy
			<<")"<<endl;
	}

	int getX()const
	{
		return _ix;
	}

	int getY()const
	{
		return _iy;
	}
private:
	int _ix;
	int _iy;
};

class Point3D:public Point
//不写继承方式，默认情况下为private继承
{
public:
	Point3D(int ix = 0,int iy = 0,int iz = 0)
	:Point(ix,iy)
	,_iz(iz)
	{}

	void display() const
	{
		cout<<"("<<getX()
			<<","<<getY()
			<<","<<_iz
			<<")"<<endl;
	}
private:
	int _iz;
};

int main(void)
{
	Point pt0(5,6);
	pt0.print();

	cout<<"--------"<<endl;

	Point3D p3d(1,2,3);
	p3d.display();

	pt0 = p3d;//Point & operator=(const Point &rhs);
	pt0.print();

//	p3d = pt0;//Point3D & operator=(const Point3D & rhs);

	cout<<"---------"<<endl;
	Point & ref = p3d;
	ref.print();

	cout<<"---------"<<endl;
	Point *p = &p3d;
	p->print();
}
