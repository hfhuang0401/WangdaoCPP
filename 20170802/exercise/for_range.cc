#include <iostream>
#include <vector>
#include <string>
 
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
 
int main(void)
{
	int x[10] = {1,2,3,4,5,6,7,8,9,10};

	for(int y:x)
	{
		cout<<y<<" ";
	}
	cout<<endl<<"-------------"<<endl;

	for(auto y:x)
	{
		cout<<y<<" ";
	}
	cout<<endl<<"-------------"<<endl;

	for(auto &y:x)
	{
		++y;
	}
	cout<<endl<<"-------------"<<endl;

	for(const auto &y:x)
	{
		cout<<y<<" ";
	}
	cout<<endl;
	cout<<"---integer test over---"<<endl;

	vector<string> v{"hello","hi","where","how"};

	for(const auto &j:v)
	{
		cout<<j<<" ";
	}
	cout<<endl;

	return 0;
}
