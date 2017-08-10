 ///
 /// @file    deleter.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-09 17:02:48
 ///
 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <memory>
#include <string>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;
using std::string;

struct Fpcloser
{
	void operator()(FILE * fp)
	{
		if(fp)
		{
			fclose(fp);
			cout << "fclose(fp)" << endl;
		}
	}
};

void test0()
{
	unique_ptr<FILE, Fpcloser> pFileHandler(fopen("test.txt", "rw+"));
	char buff[1024];
	memset(buff, 0, sizeof(buff));
	fread(buff, 1, 1024, pFileHandler.get());
	cout << buff << endl;
	
	string msg = "wangdao";
	fwrite(msg.c_str(), 1, msg.size(), pFileHandler.get());
}

void test1()
{
	shared_ptr<FILE> sp(fopen("test.txt", "rw+"), Fpcloser());

	char buff[1024];
	memset(buff, 0, sizeof(buff));
	fread(buff, 1, 1024, sp.get());
	cout << buff << endl;
	
	string msg = "wangdao";
	fwrite(msg.c_str(), 1, msg.size(), sp.get());
}

int main(void)
{
	//test0();
	test1();
}
