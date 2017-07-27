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

	//类型转换函数：由自定义向其他类型转换
	//1.成员函数形式
	//2.无返回值类型，但是函数体内必须以传值方式返回一个目标类型的变量
	//3.无参数
	//4.能不使用就不要使用

#if 1
	operator int()
	{
		cout<<"operator int()"<<endl;
		return _ix*_iy;
	}	
#endif

#if 0
	operator double()
	{
		return static_cast<double>(_ix)/_iy;
	}
#endif

private:
	int _ix;
	int _iy;
};

int main(void)
{
	Point pt(1,2);
	cout<<"pt = "<<pt<<endl;

	return 0;
}
