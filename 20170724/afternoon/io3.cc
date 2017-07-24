#include <iostream>
#include <fstream>
#include <string>
#include <vector>
 
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
 
int test0(void)
{
//	ifstream ifs("test.txt");
	ifstream ifs("io1.cc");
	if(!ifs.good())
	{
		cout<<"ifstream open file error! "<<endl;
		return -1;
	}
	
	vector<string> lines;

	string line;
	while(getline(ifs,line))
	{
		lines.push_back(line);
		//cout<<line<<endl;
	}
	
	for(size_t idx = 0;idx!=lines.size();++idx)
	{
		cout<<lines[idx]<<endl;
	}

#if 0
	string word;
	while(ifs >> word)//默认情况下以空格作为分隔符
	{
		cout<<"word = "<<word<<endl;
	}
#endif

#if 0
	cout << "ifs's badbit = "<<ifs.bad()<<endl;
	cout << "ifs's failbit = "<<ifs.fail()<<endl;
	cout << "ifs's eofbit = "<<ifs.eof()<<endl;
	cout << "ifs's goodbit = "<<ifs.good()<<endl;
#endif

	ifs.close();//关闭文件流，必须的
	return 0;
}
int test1()
{
	ifstream ifs("io1.cc");
	if(!ifs.good())
	{
		cout<<"ifsteam open error!"<<endl;
		return -1;
	}

	ofstream ofs("test.txt");
	if(!ofs.good())
	{
		cout<<"ofstream open error!"<<endl;
		ifs.close();
		return -1;
	}
	
	string line;
	while(getline(ifs,line))
	{
		ofs << line <<endl;
	}
	
	ifs.close();
	ofs.close();
	return 0;
}

int main(void)
{
	test1();
}
