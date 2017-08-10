#include <cstdio>
#include <iostream> 
#include <string>
 
using std::cin;
using std::cout;
using std::endl;
using std::string;

class SafeFile
{
public:
	SafeFile(const string & filename)
	:_phandler(fopen(filename.c_str(),"w+"))
	{}

	~SafeFile()
	{
		if(_phandler)
		{
			fclose(_phandler);
			cout<<"~SafeFile()"<<endl;
		}
	}

	void write(const string & msg)
	{
		fwrite(msg.c_str(),1,msg.size(),_phandler);
	}

private:
	FILE * _phandler;
};
 
int main(void)
{
	SafeFile sf("test.txt");
	sf.write("hello,world");

	return 0;
}
