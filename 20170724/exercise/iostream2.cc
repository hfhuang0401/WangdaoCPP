#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;
 
int main(void)
{
	int ival;
	while(cin>>ival,!cin.eof())
	{
		if(cin.bad())
		{
			cout<<"IO stream corrupted!"<<endl;
			return -1;
		}
		if(cin.fail())
		{
			cout<<"data illegal,try again!"<<endl;
			cin.clear();
			cin.ignore(1024,'\n');
			continue;
		}
		cout<<"ival = "<<ival<<endl;
	}
}
