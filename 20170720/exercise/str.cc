#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string s1("hello world!");
	string s2;
	string s3(10,'t');
	getline(cin,s2);
	cout<<"s1="<<s1<<endl;
	cout<<"s2="<<s2<<endl;
	cout<<"s3="<<s3<<endl;
}
