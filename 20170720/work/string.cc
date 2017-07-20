#include <iostream> 
#include<string>
#include<cstring>
#include<cstdio>
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
 
int main(void)
{
	string s1 = "hello";
	string s2 = ",world";
	string s3 = s1 + s2 +",Shenzhen";
	cout<<"s1 = "<< s1 <<endl;
	cout<<"s2 = "<< s2 <<endl;
	cout<<"s3 = "<< s3 <<endl;
	cout<<"s3.sizie() = "<<s3.size()<<endl;
	cout<<"s3.length() = "<<s3.length()<<endl;

	for(size_t idx = 0;idx != s3.size();++idx)
	{
		cout<<s3[idx]<<" ";
	}
	cout<<endl;
	
	string s4 = s3.substr(12,8);
	cout<<"s4 = "<<s4<<endl;

	const char* p1 = s4.c_str();
	const char* p2 = s4.data();
	printf("p1 = %s\n",p1);
	printf("p2 = %s\n",p2);
}
