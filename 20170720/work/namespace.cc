#include <iostream>
#include<stdlib.h>

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	int *p1 = new int(1);
	cout<<" *p1= "<<*p1<<endl;
	delete p1;
}
