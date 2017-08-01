#include <string.h>
#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

template <typename T>
T add(T x,T y);

//模板特化 --> 把模板的参数固定下来
template <>
char* add(char *px,char *py)
{
	char * ptmp = new char[strlen(px) + strlen(py) + 1]();
	strcpy(ptmp,px);
	strcat(ptmp,py);
	return ptmp;
}

//模板偏特化 --> 把部分模板参数固定下来


//函数模板与函数模板之间也可以进行重载
template <typename T>
T add(T x,T y,T z)
{
	return x + y + z;
}


int main(void)
{
	int ia = 1,ib = 2;
	double da = 3.3,db = 4.4;

	cout<<"ia + ib ="<<add(ia,ib)<<endl;//隐式实例化
	cout<<"da + db ="<<add<double>(da,db)<<endl;//显式实例化

	char str1[128] = "Hello,world";
	char str2[] = "shenzhen,wangdao";

	cout<<add(str1,str2)<<endl;

	return 0;
}

//函数模板的实现
template <typename T>
T add(T x,T y)
{
	return x + y;
}
