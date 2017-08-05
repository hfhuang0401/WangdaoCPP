#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
 
using std::cin;
using std::cout;
using std::endl;
using std::replace;
using std::vector;
using std::string;
using std::ostream_iterator;
 
void test0(void)
{
	vector<int> numbers{1,2,3,4,5,6};

	std::less<int> lt;
	//lt(lhs,rhs);
	
	replace_if(numbers.begin(),numbers.end(),std::bind2nd(lt,3),7);

	std::copy(numbers.begin(),numbers.end(),ostream_iterator<int>(cout," "));
	cout<<endl;

}
//remove-erase惯用法
//在遍历容器的过程中，不建议做删除或添加元素的操作
//因为有可能导致迭代器失效
void test1()
{
	vector<int> numbers{1,2,3,4,5,6,7,8,9,10};
	numbers[3] = numbers[5] = numbers[7] = 99;

	std::copy(numbers.begin(),numbers.end(),ostream_iterator<int>(cout," "));
	cout<<endl;

	numbers.erase(std::remove(numbers.begin(),numbers.end(),99),numbers.end());
	std::copy(numbers.begin(),numbers.end(),ostream_iterator<int>(cout," "));
	cout<<endl;

#if 1
	auto it = std::remove(numbers.begin(),numbers.end(),99);
	std::copy(numbers.begin(),numbers.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
	numbers.erase(it,numbers.end());
#endif
}

void test2()
{
	vector<string> vec;

	vec.push_back("this is A");

	bool flag = true;
	for(auto it = vec.begin();it != vec.end(); ++it)
	{
		cout<<"vec's capacity = "<<vec.capacity()<<endl;
		cout<<*it<<endl;//第二次获取元素时，该迭代器已失效
		if(flag)
		{
			vec.push_back("this is B");//在这里发生了扩容
			flag = false;
		}
	}
}

int main(void)
{
//	test1();
	test2();

	return 0;
}
