#include <iostream> 
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::back_insert_iterator;
using std::front_insert_iterator;
using std::insert_iterator;
using std::vector;
using std::list;
using std::copy;

template <typename Container>
void printElements(const Container & c)
{
//	typename Container::const_iterator it;
	for(auto it = c.begin();it != c.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

#if 0 
template <typename Container>
void printElements(const Container & c)
{
	for(const auto & elem : c)
	{
		cout<<elem<<" ";
	}
	cout<<endl;
}
#endif

//设计模式之适配器
int main(void)
{
	vector<int> vec{1,2,3};
	list<int> listInt;
	
	//back_insert_iterator 适用于vector、list、deque,调用的是push_bcak
	copy(vec.begin(),vec.end(),back_insert_iterator<list<int> >(listInt));
	printElements(listInt);

	//front_insert_iterator 适用于deque、list,调用的是push_front
	cout<<"---------------------"<<endl;
	copy(vec.begin(),vec.end(),front_insert_iterator<list<int> >(listInt));
	printElements(listInt);

	//insert_iterator 调用的是insert方法
	cout<<"---------------------"<<endl;
	copy(vec.begin(),vec.end(),insert_iterator<list<int> >(listInt,++listInt.begin()));
	printElements(listInt);
}
