#include <iostream> 
#include <functional>
 
using std::cout;
using std::endl;

void f(int n1,int n2,int n3,const int& n4,int n5)
{
	cout<<n1<<" "<<n2<<" "<<n3<<" "<<n4<<" "<<n5<<endl;
}

int g(int n1)
{
	return n1+1;
}

struct Foo
{
	void print_sum(int n1,int n2)
	{
		cout<<n1+n2<<endl;
	}
	int data = 10;
};

int main(void)
{
	//占位符，来记录参数的位置
	using namespace std::placeholders;//_1 , _2 , _3 ...
	
	int n = 7;

	//std::cref是按址传递，其他是按值传递，_2是第二个参数
	auto f1 = std::bind(f,_2,_1,42,std::cref(n),n);
	n =10;
	f1(1,2,1001);// 1->_1 , 2->_2

	cout<<"------------------------"<<endl;
	auto f2 = std::bind(f,_3,std::bind(g,_3),_3,4,5);
	f2(10,11,12);

	Foo foo;
	auto f3 = std::bind(&Foo::print_sum,&foo,95,_1);
	f3(5);
	
	auto f4 = std::bind(&Foo::data,_1);
	cout<<f4(foo)<<endl;
	
	return 0;
}
