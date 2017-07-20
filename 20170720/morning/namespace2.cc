#include<iostream>

using std::cin;
using std::cout;
using std::endl;

namespace B
{
	int num=5;
}

namespace A
{
	void displayA()
	{
		cout<<"B::num = "<<B::num<<endl;
	}
}

namespace B
{
	void displayB()
	{
		cout<<"displayB()"<<endl;
		A::displayA();
	}
}


int main(void)
{
	A::displayA();
	B::displayB();
}
