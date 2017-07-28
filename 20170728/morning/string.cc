#include <cstdio>
#include <iostream> 
#include <string>


using std::cin;
using std::cout;
using std::endl;
using std::string;
 
int main(void)
{
	string s1 = "hello";
	string s2(s1);
	string s3 = s1;
	string s4 = "hello";//并不是复制得来的，是重新创建的对象

	cout <<"s1 = "<<s1<<endl;
	cout <<"s2 = "<<s2<<endl;
	cout <<"s3 = "<<s3<<endl;
	cout <<"s4 = "<<s4<<endl;

	printf("&s1 = %p\n",s1.c_str());
	printf("&s2 = %p\n",s2.c_str());
	printf("&s3 = %p\n",s3.c_str());
	printf("&s4 = %p\n",s4.c_str());

	s1[0] = 'x';
	s4 = s3;
	cout<<"---------------------"<<endl;
	cout <<"s1 = "<<s1<<endl;
	cout <<"s2 = "<<s2<<endl;
	cout <<"s3 = "<<s3<<endl;
	cout <<"s4 = "<<s4<<endl;
	printf("&s1 = %p\n",s1.c_str());
	printf("&s2 = %p\n",s2.c_str());
	printf("&s3 = %p\n",s3.c_str());
	printf("&s4 = %p\n",s4.c_str());
}
