#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class point
{
	public:
		//构造函数是能够进行重载的
		point()
		{//默认构造函数
			_ix = 0;
			_iy = 0;
			cout<<"("<<_ix
				<<","<<_iy
				<<")"<<endl;
		}
		//在类内部只要显式定义了一个有参构造函数，系统就不会再提供默认构造函数
		//如果希望调用默认构造函数创建对象，必须显式定义默认构造函数
//		point(int x = 0,int y = 0) 
		point(int x,int y)
		{
			_ix = x;
			_iy = y;
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
