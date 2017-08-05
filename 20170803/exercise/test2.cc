#include <iostream>
#include <vector>
#include <algorithm>
 
using std::cin;
using std::cout;
using std::endl;
using std::vector;
 
void display(int & value)
{
	++value;
	cout<<value<<" ";
}

//lambda表达式 -->匿名函数
//[](){
	//...
//}

int main(void)
{
	vector<int> numbers {1,2,3,4,5,6};
	for_each(numbers.begin(),numbers.end(),[](int & value){
			value++;
			});
	for_each(numbers.begin(),numbers.end(),[](int & value){
			cout<<value<<" ";
			});
	cout<<endl;
}
