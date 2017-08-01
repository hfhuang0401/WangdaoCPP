#include <iostream>
#include <vector>
#include <deque>
#include <list>
 
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;
 
template <typename Container>
void display(const Container & c)
{
	typename Container::const_iterator cit;//typename 不可少
	for(cit = c.begin();cit!=c.end();++cit)
	{
		cout<<*cit<<" ";
	}
	cout<<endl;
}

void test0(void)
{
	vector<int> vecInt{1,2,3,4,5,6};
	display(vecInt);

	vector<int>::iterator it = vecInt.end();
	vecInt.insert(it,7);
	display(vecInt);

	it = vecInt.begin();
	vecInt.insert(it,0);//在vector的头部可以添加元素，但不推荐这样的用法，因为时间复杂度是o(n)
	display(vecInt);
	cout<<endl;

	deque<int> dequeInt(vecInt.begin(),vecInt.end());
	display(dequeInt);

	deque<int>::iterator dit = dequeInt.begin();
	++dit;
	dit = dequeInt.insert(dit,8);//对于deque来说，执行insert方法的时间复杂度与元素的个数正相关o(n)
	display(dequeInt);

	int arr[3] = {10,11,12};
	dequeInt.insert(dit,arr,arr + 3);
	display(dequeInt);
	cout<<"---List---"<<endl;

	list<int> listInt{1,2,3,4,5,6};
	list<int>::iterator lit = listInt.begin();
	++lit;

	listInt.insert(lit,7);//时间复杂度o(1),位置已经指定
	display(listInt);

	vecInt.clear();//对于vector而言，只清空元素，不回收内存
	cout<<"vector's capacity = "<<vecInt.capacity()<<endl;//该方法是vector独有的
	cout<<"vector's size = "<<vecInt.size()<<endl; 
}

int main(void)
{
	test0();
}
