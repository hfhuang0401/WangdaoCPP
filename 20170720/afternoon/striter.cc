#include<iostream>
#include<string>


using namespace std;

int main(void)
{
	string str="this is a long sentence";
	cout<<"str.size="<<str.size()<<" str.lenth="<<str.length()<<endl;
	string::iterator iter_big;
	string::iterator iter_end;
	cout<<str<<endl;
	iter_big=str.begin();
	iter_end=str.end();
	str.erase(iter_big+1,iter_end-1);
	cout<<str<<endl;
}
