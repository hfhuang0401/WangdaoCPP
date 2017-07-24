#include <iostream>
#include <vector>
 
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void printVector(const vector<int> & vec)
{
	cout << "vector's size = "<<vec.size()<<endl;
	cout <<"vector's capacity = "<<vec.capacity()<<endl;
}

//vector是一个动态数组,可以动态扩容
//策略：
//1.先根据当前容量capacity扩展空间，开辟出2 x capacity的空间
//2.然后把原来空间中的元素全部复制到新空间去
//3.再在末尾添加新元素
//4.最后回收原来的空间
//int arr[100]
int main(void)
{
	vector<int> num;
	num.reserve(100);//先开辟存放100个元素的空间
	printVector(num);

	num.push_back(1);
	printVector(num);
	num.push_back(2);
	printVector(num);
	num.push_back(3);
	printVector(num);
	num.push_back(4);
	printVector(num);
	num.push_back(5);
	printVector(num);

	for(size_t idx = 0;idx != num.size(); ++idx)
	{
		cout<<"num[idx] = "<<num[idx]<<endl;
	}
}
