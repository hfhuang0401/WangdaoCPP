#include <iostream> 
#include <sstream>
#include <fstream>
#include <string>


using std::cin;
using std::cout;
using std::endl;
using std::stringstream;
using std::istringstream;
using std::ostringstream;
using std::string;
using std::ifstream;

#if 0
void test0()
{
	int val1 = 512;
	int val2 = 1024;
	stringstream ss;
	ss << "val1= " << val1 << " val2= " << val2;

	string s = ss.str();
	cout << s << endl;

	int inum;

	while(!ss.eof())
	{
		ss >> s >> inum;
		cout << "str: " << s << endl
			<< "num: " << inum << endl;
	}

}
#endif


void test0()
{
	int val1 = 512;
	int val2 = 1024;

	stringstream ss;
//	ss << "val1 = "<< val1 <<" val2 = "<< val2;
	ss << "val1= " << val1 << " val2= " << val2;
	string s = ss.str();
	cout<<s<<endl;

	int inum;

	while(!ss.eof())
	{
		ss >> s >> inum;
		cout<<"str = "<<s <<endl
			<<"num = "<<inum<<endl;
	}
}


#if 0
void readConfig(const string & filename)
{
	ifstream ifs(filename);
	if(!ifs.good())
	{
		cout<<"ifstream open failed"<<endl;
		return;
	}
	string line;
	string key;
	string value;
	while(getline(ifs,line))
	{
		istringstream iss(line);
		iss >>key >>value;
		cout<<key<<"-->"<<value<<endl;
	}
}
#endif

inline string int2str(int number)
{
	ostringstream oss;
	oss<<number;
	return oss.str();
}

void test1()
{
	int val = 1111;
	cout <<int2str(val)<<endl;

	char buff[128] = {0};
	sprintf(buff,"val = %d\n",val);
	cout<<buff;
}

int main(void)
{
	test0();
	//	readConfig("my.conf");
	//	test1();
}
