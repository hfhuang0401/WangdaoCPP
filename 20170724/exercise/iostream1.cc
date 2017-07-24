#include <iostream> 
#include <string>
 
using std::cin;
using std::cout;
using std::endl;
using std::string;

void printCin()
{
 	cout<<"bad = "<<cin.bad()<<endl;
	cout<<"fail = "<<cin.fail()<<endl;
	cout<<"eof = "<<cin.eof()<<endl;
	cout<<"good = "<<cin.good()<<endl;
}
int main(void)
{
	int inum;
	printCin();

	while(cin>>inum)
	{
		cout<<inum<<endl;
	}

	cin.clear();
	printCin();

	string s;
	cin>>s;
	std::cout<<s<<endl;
}
