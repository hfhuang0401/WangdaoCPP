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
		
	int getX()//protected继承时，除了基类的私有成员在整个集成体系中不能直接在派生类内部访问之外
	{
		return _ix;//其它的非私有成员，都可以在整个继承体系中的派生类内部进行访问;但private继承不行
	}

private:
	int _ix;

protected://对派生类进行开放
	int _iy;
};

class Point3D:protected Point
//采用protected进行继承时，除了基类的private成员不能在派生类内部进行访问之外
//其它的成员都可以在派生类内部进行访问
{
public:
	Point3D(int ix = 0,int iy = 0,int iz = 0)
	:Point(ix,iy)
	,_iz(iz)
	{}

	void display()
	{
		//不管以何种方式进行继承，基类的私有成员都不能在派生类内部进行访问
		cout<<"("<<getX()//基类public成员在派生类内部访问权限变成protected
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
//	p3d.print();//error,print方法在派生类内部是protected
	p3d.display();
	
	Point pt2(8,8);
//	pt2._iy = 10;//保护类的成员不能在类外访问
}
