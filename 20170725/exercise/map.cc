#include <iostream>
#include <vector>
#include <map>
#include <set>
 
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::set;
using std::multiset;
 
int main(void)
{
	vector<int> ivec;
	for(vector<int>::size_type i = 0; i!=10; ++i)
	{
		ivec.push_back(i);
		ivec.push_back(i);
	}
	set<int> iset(ivec.cbegin(),ivec.cend());
	multiset<int> miset(ivec.cbegin(),ivec.cend());

	cout<<"vector.size = "<<ivec.size()<<endl;
	cout<<"set.size = "<<iset.size()<<endl;
	cout<<"multiset.size = "<<miset.size()<<endl;
}
