#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

#if 0

void swap(int x,int y)
{
	int temp = x;
	x = y;
	y = temp;
}

#endif

void swap(int *x ,int * y)
{
	int  temp = *x;
	*x = *y;
	*y = temp;
}

void swap(int &refa,int &refb)
{
	int temp = refa;
	refa = refb;
	refb = temp;
}

int arr[5]={0,1,2,3,4};

int & func(int idx)
{
	return arr[idx];
}

int test()
{
	func(0)=10;
	cout<<"arr[0] = "<<arr[0]<<endl;
}

int main(void)
{
	test();
}
