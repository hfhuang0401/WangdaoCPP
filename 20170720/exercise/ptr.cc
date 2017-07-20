#include<iostream>
using namespace std;

int main(void)
{
	int a =10;
	int b = 5;
	const int *p1 = &a;
	int* const p2 = &a;
	cout<<"before p1="<<*p1<<endl;
	cout<<"before p2="<<*p2<<endl;
	*p2 = 20;
	p1 = &b;
	cout<<"afrer p1="<<*p1<<endl;
	cout<<"after p2="<<*p2<<endl;

}
