#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;
 
int main(void)
{
	double d1 = 3.33;

	int ival = static_cast<int>(d1);
	cout<<"d1 = "<<d1<<" "<<"ival = "<<ival<<endl;
	//const_cast/dynamic_cast/reinterpret_cast
}
