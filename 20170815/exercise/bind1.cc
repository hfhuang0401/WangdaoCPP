#include <iostream> 
#include <functional>

using std::cout;
using std::endl;
 
int Func(int x,int y)
{
	cout <<"x = "<<x
		 <<"y = "<<y
		 <<endl;
	return x+y;
}

class A
{
public:
	int Func(int x,int y)
	{
		cout <<"x = "<<x
			 <<"y = "<<y
			 <<endl;
		return x+y;
	}
};

int main(void)
{
	auto bf1 = std::bind(Func,10,std::placeholders::_1);
	bf1(20);//相当于Func(10,20)

	A a;
	auto bf2 = std::bind(&A::Func,&a,std::placeholders::_1,std::placeholders::_2);
	bf2(10,20);//相当于 a.Func(10,20)

	std::function<int(int)> bf3 = std::bind(&A::Func,&a,std::placeholders::_1,100);
	bf3(10);//相当于 a.Func(10,100)

	return 0;
}
