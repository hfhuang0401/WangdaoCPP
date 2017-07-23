#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class point
{
	public:
		point(int ix = 0,int iy = 0)
			:_ix(ix)
			 ,_iy(iy)
		{
			cout<<"point()"<<endl;
		}
#if 0		
		//系统提供的已经能够满足需求
		point & operator = (const point & rhs)
		{
			_ix = rhs._ix;
			_iy = rhs._iy;

			return *this;
		}
#endif		
		//this是一个隐含参数,this代表当前对象本身
		//
		void print(/*point * const this*/)
		{
		//	this = 0X0001H;//不能让该操作执行
			cout<<"_ix = "<<this->_ix<<" _iy = "<<this->_iy<<endl;
		}
	private:
		const int _ix;
		const int _iy;
};


int main(void)
{
	int a = 3,b = 4;
	a = b;

	point pt1 (1,2);
	point pt2 (3,4);
	pt1.print();
	pt2.print();

//	pt2 = pt1;//如果没有提供赋值运算符函数，系统会自动提供
	pt2.print();
}
