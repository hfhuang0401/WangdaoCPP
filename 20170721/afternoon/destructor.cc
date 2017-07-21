#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class point
{
	public:
		point()
		{//默认构造函数
			_ix = 0;
			_iy = 0;
			cout<<"("<<_ix
				<<","<<_iy
				<<")"<<endl;
		}
		point(int x,int y)
		{
			_ix = x;
			_iy = y;
			cout<<"("<<_ix
				<<","<<_iy
				<<")"<<endl;
		}
		~point()
		{//如果没有显式提供析构函数，系统都会提供一个默认的析构函数
			cout<<"destructor("<<_ix<<","<<_iy<<")"<<endl;
		}
	private:
		int _ix;
		int _iy;
};

int main(void)
{
	point pt1;
	point pt2(3,4);
}
