#include<iostream>

using std::cin;
using std::cout;
using std::endl;

namespace A
{
	void displayA();
}

namespace B
{
	int num=5;
	void displayB()
	{
		cout<<"displayB()"<<endl;
		A::displayA();
	}
}

namespace A
{
	void displayA()
	{
		cout<<"B::num = "<<B::num<<endl;
	}
}

void func()
{
	using A::displayA;
	using B::displayB;
	displayB();
}

int main(void)
{
//	A::displayA();
//	B::displayB();
	func();
}
