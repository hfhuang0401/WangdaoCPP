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
		
		//系统提供的已经能够满足需求
		point & operator = (const point & rhs)
		{
			_ix = rhs._ix;
			_iy = rhs._iy;

			return *this;
		}
		
		//this是一个隐含参数,this代表当前对象本身
		
		void print(/* const point * const this*/) const
		{
		//	_ix = 10;
			cout<<"print::const()"<<endl;
			cout<<"_ix = "<<this->_ix<<" _iy = "<<this->_iy<<endl;
		}

		void print(/*point * const this*/)
		{
		//	this = 0X0001H;//不能让该操作执行
			_ix = 10;
			cout<<"print()"<<endl;
			cout<<"_ix = "<<this->_ix<<" _iy = "<<this->_iy<<endl;
		}
	private:
		int _ix;
		int _iy;
};


int main(void)
{
	int a = 3,b = 4;
	a = b;

	const point pt1 (1,2);
	//const对象只能调用const成员函数，若没有则报错

	point pt2 (3,4);
	//非const对象可以调用const成员函数
	
	//若两个版本的函数同时出现，则各自调用

	pt1.print();
	pt2.print();

	pt2 = pt1;
	pt2.print();
}
