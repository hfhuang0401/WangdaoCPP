#include <iostream>
#include <sstream>
#include <string>
 
using std::cin;
using std::cout;
using std::endl;
using std::stringstream;
using std::string;

int func()
{
	int ival1 = 512;
	int ival2 = 1024;
	stringstream ss;
	ss<<"this is a long sentence ..."<<endl;
	ss <<"ival1 = "<<ival1<<"  ival2 = "<<ival2<<endl;

	string str = ss.str();
	cout<<str<<endl;

	while(ss>>str)
	{
		cout<<str<<endl;
	}
	return 0;
}

int main(void)
{
	func();
}
