#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

//模板参数的形式有两种：
//1.类型参数，使用typename/class
//2.非类型参数，整型数据，代表的是常量
//
//函数模板可以设置默认参数，C++11新特性
template <typename T,int number = 10>
T func(T value)
{
	return value * number;
}

int add(int a,int b);
int add(int x,int y);

int main(void)
{
	cout<<func<int>(2)<<endl;
}
