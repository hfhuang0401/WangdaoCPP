#include <iostream> 
#include <string>
#include <limits>
 
using std::cin;
using std::cout;
using std::endl;
using std::string;

void printCinStatus()
{
	cout<<"cin's badbit = "<<cin.bad()<<endl;
	cout<<"cin's failbit = "<<cin.fail()<<endl;
	cout<<"cin's eofbit = "<<cin.eof()<<endl;
	cout<<"cin's goodbit = "<<cin.good()<<endl;
}

int main(void)
{
	int inum;

	printCinStatus();

	while (cin>>inum)
	{
		cout<<"inum = "<<inum<<endl;
	}
	printCinStatus();

	cout<<endl<<endl;
	cin.clear();//cin对象是有缓冲区的
//	cin.ignore(1024,'\n');//清空缓冲区
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); 
	printCinStatus();

	string s;
	cin>>s;
	cout<<s<<endl;
}
