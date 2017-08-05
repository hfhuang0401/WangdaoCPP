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

//反向迭代器
template <typename Container>
void printElements(const Container & c)
{
	typename Container::const_reverse_iterator it;
	for(it = c.rbegin(); it != c.rend(); ++it)
		cout<<*it<<" ";
	cout<<endl;
}

int main(void)
{
	vector<int> vec{1,2,3};
	vector<int> vec2{4,5,6};
	list<int> listInt;
	
	copy(vec.begin(),vec.end(),back_insert_iterator<list<int> >(listInt));
	printElements(listInt);

	cout<<"---------------------"<<endl;
	copy(vec2.begin(),vec2.end(),front_insert_iterator<list<int> >(listInt));
	printElements(listInt);

	cout<<"---------------------"<<endl;
	copy(vec.begin(),vec.end(),insert_iterator<list<int> >(listInt,++listInt.begin()));
	printElements(listInt);
}
