#include <iostream>
#include<fstream>
 
using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ios;

int func1()
{
	ofstream ofs("test.txt",ios::app);
	if(!ofs)
	{
		cout<<"ofstream error!"<<endl;
		return -1;
	}
	cout<<ofs.tellp()<<endl;
	ofs <<"that's new"<<endl;
	
	ofs.close();
	return 0;
}

int func2()
{
	func1();

	ifstream ifs("test.txt",ios::ate);//打开文件后立即定位到文件末尾
	if(!ifs)
	{
		cout<<"ifstream error"<<endl;
		return -1;
	}
	cout<<ifs.tellg()<<endl;

	ifs.close();
	return 0;
}

int main(void)
{
	fstream outfile("f.dat",ios::out|ios::in);
	if(!outfile)
	{
		cout<<"fstream error"<<endl;
		return -1;
	}
	
	int ival;
	for(int idx = 0;idx != 10; ++idx)
	{
		cin>>ival;
		outfile<<ival<<' ';
	}
	cout<<outfile.tellp()<<endl;

	outfile.seekg(0,ios::beg);

	for(int idx = 0;idx != 10; ++idx)
	{
		outfile >> ival;
		cout<<ival<<' ';
	}
	outfile.close();
	return 0;
}
