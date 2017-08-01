#include <map>
#include <string>
#include <utility>
#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;

void test0(void)
{
	pair<int,string> t(600036,"招商银行");
	cout<<t.first<<"--->"<<t.second<<endl;
}

void test1()
{
	pair<int,string> t(9,"Asia");
	//1.map里面只能存放关键字不同的元素
	//2.默认情况下，内部元素按关键字以升序方式进行排列
	map<int,string> mapIntStr{
		pair<int,string> (9,"Asia"),
		pair<int,string> (4,"Africa"),
		pair<int,string> (1,"Europe"),
		pair<int,string> (4,"America")
	};

	map<int,string>::const_iterator it;
	for(it = mapIntStr.begin();it!=mapIntStr.end();++it)
	{
		//	cout<<*it<<endl;
		cout<<it->first<<"--->"<<it->second<<endl;
	}
}

void test2()
{
	map<int,string,std::greater<int> > mapIntStr{
		pair<int,string> (9,"Asia"),
		pair<int,string> (4,"Africa"),
		pair<int,string> (1,"Europe"),
		pair<int,string> (4,"America")
	};

	map<int,string>::const_iterator it;
	for(it = mapIntStr.begin();it!=mapIntStr.end();++it)
	{
		cout<<it->first<<"--->"<<it->second<<endl;
	}

	mapIntStr[4] = "Amercia";//修改关键字锁对应的值
							 //重载了下标访问运算符，但并不是随机访问，时间复杂度还是log(N)
	mapIntStr[2] = "Austrilia";//数据即代码的风格
	mapIntStr[3] = "Antarctica";
	cout<<"==============="<<endl;
	for(it = mapIntStr.begin();it!=mapIntStr.end();++it)
	{
		cout<<it->first<<"--->"<<it->second<<endl;
	}

	cout<<"-------------"<<endl;
	cout<<mapIntStr[1]<<endl;
	cout<<mapIntStr[4]<<endl;
}

void test3()
{
	map<string,string > mapIntStr{
		pair<string,string> ("9","Asia"),
		pair<string,string> ("4","Africa"),
		pair<string,string> ("1","Europe"),
		pair<string,string> ("4","America")
	};

	map<string,string>::const_iterator it;
	for(it = mapIntStr.begin();it!=mapIntStr.end();++it)
	{
		cout<<it->first<<"--->"<<it->second<<endl;
	}

	mapIntStr["4"] = "Amercia";//修改关键字锁对应的值
							 //重载了下标访问运算符，但并不是随机访问，时间复杂度还是log(N)
	mapIntStr["2"] = "Austrilia";//数据即代码的风格
	mapIntStr["3"] = "Antarctica";
	cout<<"==============="<<endl;
	for(it = mapIntStr.begin();it!=mapIntStr.end();++it)
	{
		cout<<it->first<<"--->"<<it->second<<endl;
	}

	cout<<"-------------"<<endl;
	cout<<mapIntStr["1"]<<endl;
	cout<<mapIntStr["4"]<<endl;
}


void test4()
{
	map<int,string> mapIntStr{
		pair<int,string> (9,"Asia"),
		pair<int,string> (4,"Africa"),
		pair<int,string> (1,"Europe"),
		pair<int,string> (4,"America")
	};

	map<int,string>::const_iterator it;
	for(it = mapIntStr.begin();it!=mapIntStr.end();++it)
	{
		cout<<it->first<<"--->"<<it->second<<endl;
	}
	
	//第一次添加元素
	pair<int,string> t1(1,"Antarctica");
//	pair<map<int,string>::iterator,bool> ret = mapIntStr.insert(t1);
	auto ret = mapIntStr.insert(t1);//使用auto关键字方便
	if(ret.second)
	{
		cout<<"新元素添加成功"<<endl;
	}else
	{
		cout<<"容器中已有相同关键字的元素，添加失败"<<endl;
	}
	
	//第二次添加元素，make_pair
	ret = mapIntStr.insert(std::make_pair(2,"Antarctica"));
	if(ret.second)
	{
		cout<<"新元素添加成功"<<endl;
	}else
	{
		cout<<"容器中已有相同关键字的元素，添加失败"<<endl;
	}
	cout<<"-------------------"<<endl;
	for(it = mapIntStr.begin();it!=mapIntStr.end();++it)
	{
		cout<<it->first<<"--->"<<it->second<<endl;
	}
}

int main(void)
{
	test4();
	return 0;
}
