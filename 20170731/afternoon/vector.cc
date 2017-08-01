#include <iostream> 
#include <vector>
 
using std::cin;
using std::cout;
using std::endl;
using std::vector;
 
int main(void)
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};

	vector<int>ivec(arr,arr+10);//原生指针也是一种迭代器

	vector<int> numbers = {1,2,3,4,5,6};
//	vector<int> numbers{1,2,3,4,5,6};
//	vector<int>::iterator it;//类似于指针，该迭代器能修改元素的值
	vector<int>::const_iterator it;
	for(it = numbers.begin();it!=numbers.end();++it)
	{
		//++(*it);
		cout<<*it<<endl;
	}

	return 0;
}
