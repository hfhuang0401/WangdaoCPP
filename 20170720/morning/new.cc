#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	int *p1 = (int*)malloc(sizeof(int));//堆空间
	*p1=10;
	free(p1);

	int *p2=new int(1);
	delete p2;

//	int *p3 = (int*)malloc(sizeof(int)*10);

	int *p4 = new int[10];
	for(int i=0;i<10;i++)
		cout<<p4[i]<<",";
	cout<<endl;
}
