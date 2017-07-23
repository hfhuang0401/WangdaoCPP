#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class Point
{
public:
//	Point(int ix = 0,int iy = 0)
	Point(int ix,int iy)
	{
		static int iCount = 0;
		iCount ++;
		cout<<iCount<<"<构造函数被调用>"<<endl;
		_x = ix;
		_y = iy;
	}
private:
	int _x;
	int _y;
};

int main(void)
{
	Point pt1[2];

	Point pt2[2] = {Point(1,2),Point(3,4)};

	Point pt3[] = {Point(1,2),Point(3,4)};

	Point pt4[5] = {Point(1,2),Point(3,4)};
}
