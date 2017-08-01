#include <iostream>
#include <vector>
#include <deque>
#include <list>
 
using std::cin;
using std::cout;
using std::endl;
using std::endl;
using std::vector;
using std::deque;
using std::list;

//vector、deque都实现了operator[],支持随机访问，说明能在o(1)时间找到元素
//
//list不支持operator[],因为它是链表，不支持随机访问，只支持双向访问

void test0()
{
	deque<int> dequeInt{1,2,3,4,5,6};
	for(size_t idx = 0;idx != dequeInt.size();++idx)
	{	//实现了下标访问运算符
		cout << dequeInt[idx] <<endl;
	}
	cout << endl;

	list<float> listFloat(3,5);
//	cout<<listFloat[0]<<endl;//list不支持下标访问运算符
	
	list<float>::const_iterator lit;//双向访问迭代器
	for(lit = listFloat.begin();lit != listFloat.end();++lit)
	{
		cout<<*lit<<endl;
	}
}

int main(void)
{
	test0();
	return 0;
}
