#include <iostream>
#include<stdlib.h>

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	int *p1 = new int(1);
	cout<<"*p1= "<<*p1<<endl;
	delete p1;

	int *p2 = new int[10];
	for(int idx = 0;idx != 10;++idx)
	{
		p2[idx]=idx;
		cout<<p2[idx]<<",";
	}
	cout<<endl;
	delete [] p2;
}
