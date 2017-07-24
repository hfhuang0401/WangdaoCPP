#include <iostream>
#include <fstream>
#include <string>
#include <vector>
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

int func()
{
	ifstream ifs("file.txt");
	if(!ifs.good())
	{
		cout<<"open file error!"<<endl;
		return -1;
	}
	vector<string> svec;
	string line;
	while(getline(ifs,line))
	{
		svec.push_back(line);
	}

	vector<string>::iterator iter =svec.begin();
	for(;iter != svec.end();++iter)
	{
		cout<<*iter<<endl;
	}
	ifs.close();
	return 0;
}

int main(void)
{
	ifstream ifs("file.txt");
	if(!ifs.good())
	{
		cout<<"open file error!"<<endl;
		return -1;
	}

	ofstream ofs("test.txt");
	string line;
	while(getline(ifs,line))
	{
		ofs << line <<endl;
	}
	return 0;
}
