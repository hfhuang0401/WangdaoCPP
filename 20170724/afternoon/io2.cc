#include <iostream> 
#include <limits>
 
using std::cin;
using std::cout;
using std::endl;
 
int main(void)
{
	int ival;
	
	//ctrl + d 结束输入
	while(cin >> ival,!cin.eof())
	{
		if(cin.bad())
		{
			cout<<"io corrupted!"<<endl;
			return -1;
		}
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cout<<"please input an interger num"<<endl;
			continue;
		}
		cout<<"ival = "<<ival<<endl;
	}
}
