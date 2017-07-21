#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class point
{
	public:
		point():_ix(0),_iy(0)//真正初始化的过程-->初始化表达式
		{
//			_ix = 0;//赋值语句，并不是初始化的过程
//			_iy = 0;
			cout<<"("<<_ix
				<<","<<_iy
				<<")"<<endl;
		}
		point(int x,int y):_ix(x),_iy(y)
		{
//			_ix = x;
//			_iy = y;
			cout<<"("<<_ix
				<<","<<_iy
				<<")"<<endl;
		}
	private:
		int _ix;
		int _iy;
};

int main(void)
{
	point pt1;//使用默认的构造函数创建对象

	point pt2(3,4);
}
