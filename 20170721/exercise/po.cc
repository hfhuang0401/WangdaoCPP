#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;
 
int main(void)
{
	float length = 0.0f,width = 0.0f;
	cout<<"please input length:";
	cin>>length;
	cout<<"please input width:";
	cin>>width;
	float area = length * width;
	cout<< "area is："<<area<<endl;
	return 0;
}
