#include <iostream> 
#include <iterator>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;
 
int main(void)
{
	vector<int> numbers;

	istream_iterator<int> isi(cin);

	cout<<"this is a test"<<endl;

//	copy(isi,istream_iterator<int>(),numbers.begin());//vector没有空间，所以会出错

	copy(isi,istream_iterator<int>(),std::back_inserter(numbers));

	for(auto & elem : numbers)
	{
		cout<<elem<<" ";
	}
	cout<<endl;

#if 0
	ostream iterator<int> osi(cout,"\n");
	copy(numbers.begin(),numbers.end(),osi);
#endif

	return 0;
}
