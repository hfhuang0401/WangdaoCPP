#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix = 0,int iy = 0)
	{
		cout<<"<构造函数被调用>"<<endl;
		_x = ix;
		_y = iy;
	}

	~Point()
	{
		cout<<"析构函数被调用"<<endl;
	}

	void print()
	{
		cout<<"x: "<<_x<<" y: "<<_y<<endl;
	}

	void set(int xp,int yp)
	{
		_x = xp;
		_y = yp;
	}

private:
	int _x;
	int _y;
};

int main(void)
{
	Point *p = new Point(4,5);
	p->print();
	delete p;
	p = NULL;

	Point *pp =new Point[3];
	delete [] pp;

	Point *ppp = new Point[2];
	ppp[0].print();
	ppp[1].set(4,5);
	ppp[1].print();
	delete [] ppp;
	ppp = NULL;
}
