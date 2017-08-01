#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

		  //模板参数推导
//函数模板  --->  模板函数
//				  实例化
//	  模板  --->  代码生成器
template <typename T>
T add(T x,T y);

//函数模板与函数模板之间也可以进行重载
template <typename T>
T add(T x,T y,T z)
{
	return x + y + z;
}

#if 0
//模板函数：根据实参传递时的类型自动推导
int add(int x,int y)
{
	return x + y;
}
#endif

//函数模板与普通函数是可以进行重载的
//重载时，会优先执行普通函数
double add(double a,double b)
{
	cout<<"double add(double x,double y)"<<endl;
	return a + b;
}


int main(void)
{
	int ia = 1,ib = 2,ic = 3;
	double da = 3.3,db = 4.4;
	char ca = 'A',cb = 1;

	cout<<"ia + ib ="<<add(ia,ib)<<endl;//隐式实例化
	cout<<"da + db ="<<add<double>(da,db)<<endl;//显式实例化
	cout<<"ca + cb ="<<add(ca,cb)<<endl;
	cout<<"ia + da ="<<add(ia,da)<<endl;

	cout<<"ia + ib + ic"<<add(ia,ib,ic)<<endl;

	return 0;
}

//函数模板的实现
template <typename T>
T add(T x,T y)
{
	return x + y;
}
