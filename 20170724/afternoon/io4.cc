#include <iostream>
#include <fstream>
 
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::ios;

void test0()
{
	//app 对输出流起作用
//	ofstream ofs("test.txt",ios::ate);//对输出流无效
	ofstream ofs("test.txt",ios::app);
	if(!ofs.good())
	{
		cout<<"ofstream open error !"<<endl;
		return;
	}

	cout<<ofs.tellp()<<endl;
	ofs << "that's new"<<endl;
}

void test1()
{
	//ate 对输入流起作用
	ifstream ifs("test.txt",ios::ate);
	if(!ifs.good())
	{
		cout<<"ifstream open error !"<<endl;
		return;
	}

	cout<<ifs.tellg()<<endl;//tellg-->输入流定位
}

void test2()
{
	//对文件输入输出流而言，也要求文件存在
	fstream fs("f.dat");
	if(!fs.good())
	{
		cout<<"fstream open error!"<<endl;
		return;
	}

	int inum;

	for(size_t idx =0;idx!=10;++idx)
	{
		cin>>inum;
		fs << inum <<" ";
	}
	
//	fs.seekp(0,ios::beg);//偏移到文件开始的位置
	fs.seekg(0,ios::beg);//偏移到文件开始的位置
	for(size_t idx = 0;idx!=10;++idx)
	{
		fs >> inum;
		cout<<inum<<" ";
	}
	cout<<endl;

	fs.close();
}

int main(void)
{
//	test0();
//	test1();
	test2();
}
