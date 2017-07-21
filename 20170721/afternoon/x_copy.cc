#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;


class X
{
	public:
		//初始化列表中数据成员被初始化的顺序并不是由初始化列表中的顺序决定，而是由其在类中被声明时的顺序决定的
//		X(int a):_iy(a),_ix(_iy)
		X(int a):_ix(a),_iy(_ix)
		{
			cout<<"constructor()"<<endl;
		}
		void print()
		{
			cout<<"_ix = "<<_ix<<" _iy = "<<_iy<<endl;
		}
	private:
		int _ix;
		int _iy;
};
int main(void)
{
	X x(3);
	x.print();
}
