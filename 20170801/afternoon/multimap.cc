#include <iostream>
#include <map>
#include <string>
#include <utility>
 
using std::cin;
using std::cout;
using std::endl;
using std::multimap;
using std::string;
using std::pair;
 
void test1()
{
	pair<int,string> t(9,"Asia");
	//1.multimap里面可以存放关键字相同的元素
	//2.默认情况下，内部元素按关键字以升序方式进行排列
	multimap<int,string> multimapIntStr{
		pair<int,string> (9,"Asia"),
		pair<int,string> (4,"Africa"),
		pair<int,string> (1,"Europe"),
		pair<int,string> (4,"America")
	};

	multimap<int,string>::const_iterator it;
	for(it = multimapIntStr.begin();it!=multimapIntStr.end();++it)
	{
		//	cout<<*it<<endl;
		cout<<it->first<<"--->"<<it->second<<endl;
	}
}
int main(void)
{
	test1();
}
