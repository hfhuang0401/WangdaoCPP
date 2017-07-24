#include <iostream> 
#include <string>
#include <new>
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
 
int main(void)
{
	int *arr = new int[3]{1,2,3};
	for(int i = 0;i < 3; i++)
	{
		cout<<"arr["<<i<<"] = "<<arr[i]<<endl;
	}
	string *pstr = new string [10]{"a","an","the",string(3,'x')};
	for(int i = 0;i < 10; i++)
	{
		cout<<"arr["<<i<<"] = "<<pstr[i]<<endl;
	}
	delete [] arr;
	delete [] pstr;
}
