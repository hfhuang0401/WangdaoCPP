#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

int add(int x,int y)
{
	return x + y;
}

int add(int x,int y,int z)
{
	return x + y + z;
}

int main(void)
{
	int a = 3,b = 4,c = 5;
	cout<<"a + b = "<<add(a,b)<<endl;
	cout<<"a + b + c = "<<add(a,b,c)<<endl;
}
