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
		
	int getX()
	{
		return _ix;
	}

private:
	int _ix;

protected://对派生类进行开放
	int _iy;
};

//实现继承
class Point3D:private Point//采用private进行继承时，除了基类的私有成员不能在派生类内部进行访问
//不写继承方式，默认情况下为private继承
{
public:
	Point3D(int ix = 0,int iy = 0,int iz = 0)
	:Point(ix,iy)
	,_iz(iz)
	{}

	void display()
	{
		//基类的public/protected成员在派生类内部访问权限变成private
		cout<<"("<<getX()	//不管以何种方式进行继承，基类的私有成员都不能在派生类内部进行访问
			<<","<<_iy
			<<","<<_iz
			<<")"<<endl;
	}
private:
	int _iz;
};

int main(void)
{
	Point3D p3d(1,2,3);
	p3d.print();
	p3d.display();
	
	Point pt2(8,8);
//	pt2._iy = 10;//保护类的成员不能在类外访问
}
