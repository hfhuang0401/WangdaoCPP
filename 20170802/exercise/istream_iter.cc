#include <iostream>
#include <iterator>
#include <vector>
#include <string>
 
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::vector;
using std::string;
 
int main(void)
{
	istream_iterator<string> in_iter(cin),eof;
	vector<string> vec(in_iter,eof);
	
	cout<<"-------------------------"<<endl;
	for(const auto &it : vec)
		cout<<it<<" ";
	cout<<endl;
}
