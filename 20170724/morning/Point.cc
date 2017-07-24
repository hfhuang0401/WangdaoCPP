#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class Point
{
public:
//	explicit //使用explicit禁止隐式转换
	Point(int ix = 0,int iy = 0)
	:_ix(ix)
	,_iy(iy)
	{
		cout<<"Point(int ix = 0 , int iy = 0)"<<endl;
	}
	void print()
	{
		cout<<"("<<_ix<<","<<_iy<<")"<<endl;
	}
private:
	int _ix;
	int _iy;
};

int main(void)
{
	Point p1 = 1;
	p1.print();
}
