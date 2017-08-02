#include <iostream>
#include <vector>
#include<algorithm>
#include <iterator>
 
using std::cin;
using std::cout;
using std::endl;
using std::copy;
using std::vector;
using std::ostream_iterator;
 
int main(void)
{
	cout<<"sizeof(cout)"<<sizeof(cout)<<endl;

//	ostream_iterator<int> osi(cout,"\n");
	ostream_iterator<int> osi(cout);

	vector<int> numbers{1,2,3,4,5,6};

	copy(numbers.begin(),numbers.end(),osi);
	
	cout<<endl;
	return 0;
}
