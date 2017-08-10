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
private:
	int _ix;
	int _iy;
};

class Point3D:Point
//不写继承方式，默认情况下为private继承
{
public:
	Point3D(int ix = 0,int iy = 0,int iz = 0)
	:Point(ix,iy)
	,_iz(iz)
	{}

	void display() const
	{

	}
private:
	int _iz;
};

int main(void)
{
	Point3D p3d(1,2,3);
	p3d.print();

}
