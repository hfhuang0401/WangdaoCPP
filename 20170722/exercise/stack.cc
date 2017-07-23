#include <iostream> 
#include<stack> 
using std::cin;
using std::cout;
using std::endl;
using std::stack;
 
int main(void)
{
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	cout<<"top = "<<st.top()<<endl;
	st.pop();
	cout<<"top = "<<st.top()<<endl;
	st.pop();
	cout<<"top = "<<st.top()<<endl;
	st.pop();
	cout<<"top = "<<st.top()<<endl;
}
