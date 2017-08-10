#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class A
{
};

class B
:private A
{
public:
	B(int x = 0)
	:_x(x)
	{}

	void print()
	{
		cout<<"x = "<<_x<<endl;
	}

	int _x;
};

int main(void)
{
	B b(3);
	b.print();
}
