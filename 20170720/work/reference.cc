#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;
 
int main(void)
{
	int a = 10;
	int & ref = a;
	cout<<"a = "<<a<<endl;
	cout<<"ref = "<<ref<<endl;

	ref = 11;
	int b =20;
	ref = b;

	cout<<"a = "<< a <<endl;
	cout<<"ref = "<< b <<endl;
}
