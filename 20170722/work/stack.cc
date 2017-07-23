#include <iostream>
#include <cstdlib>
 
using std::cin;
using std::cout;
using std::endl;

class Stack
{
public:
	Stack(int size = 10)
	{
		_st = new int [size]();
		_top = 0;
		_maxSize = size;
	}
	
	~Stack()
	{
		if(_st != NULL)
		{
			delete [] _st;
			_st = NULL;
		}
	}

	void push(int num);
	void pop();
	int  top();
	bool empty();
	bool full();
private:
	int *_st;
	int _top;
	int _maxSize;
};

bool Stack::full()
{
	if(_top == _maxSize)
	{
		cout<<"ERROR! Stack is full!"<<endl;
		return true;
	}else
		return false;
}

bool Stack::empty()
{
	if( 0 == _top)
	{
		cout<<"ERROR! Stack is empty"<<endl;
		return true;
	}else
		return false;
}

void Stack::push(int num)
{
	if(full())
	{
		exit(-1);
	}else
	{
		_st[_top++] = num;
	}
}

void Stack::pop()
{
	if(empty())
	{
		exit(-1);
	}else
	{
		_st[_top--] = 0;
	}
}

int Stack::top()
{
	if(empty())
	{
		exit(-1);
	}else
	{
		return _st[_top-1];
	}
}

int main(void)
{
	Stack st(3);
	st.push(10);
	st.push(12);
	st.push(14);
	cout<<"top = "<<st.top()<<endl;
	st.pop();
	cout<<"top = "<<st.top()<<endl;
	st.push(15);
	cout<<"top = "<<st.top()<<endl;
	st.pop();
	cout<<"top = "<<st.top()<<endl;
	st.pop();
	cout<<"top = "<<st.top()<<endl;

}
