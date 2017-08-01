#include <iostream>
#include <string>
 
using std::cin;
using std::cout;
using std::endl;
using std::string;

template <typename T,int kSize = 10>
class Stack
{
public:
	Stack()
	:_top(-1)
	,_arr(new T[kSize]())
	{}
	~Stack();

	bool empty() const;
	bool full() const;
	void push(const T &value);
	void pop();
	T top();
private:
	int _top;
	T *_arr;
};

template <typename T,int kSize>
Stack<T,kSize>::~Stack()
{
	delete [] _arr;
}

template <typename T,int kSize>
bool Stack<T,kSize>::empty() const
{
	return _top == -1;
}

template <typename T,int kSize>
bool Stack<T,kSize>::full() const
{
	return _top == kSize - 1;
}

template <typename T,int kSize>
void Stack<T,kSize>::push(const T &value)
{
	if(!full())
	{
		_arr[++_top] = value;
	}else
	{
		cout<<"stack is full!"<<endl;
	}
}

template <typename T,int kSize>
void Stack<T,kSize>::pop()
{
	if(!empty())
	{
		--_top;
	}else
	{
		cout<<"stack is empty"<<endl;
	}
}

template <typename T,int kSize>
T Stack<T,kSize>::top()
{
	return _arr[_top];
}

int test0(void)
{
	Stack<int> istack;

	cout<<"此时栈是否为空?"<<istack.empty()<<endl;
	istack.push(1);
	cout<<"此时栈是否为空?"<<istack.empty()<<endl;

	for(int idx = 2;idx != 12; ++idx)
	{
		istack.push(idx);
	}

	cout<<"此时栈是否已满?"<<istack.full()<<endl;

	while(!istack.empty())
	{
		cout<<istack.top()<<" ";
		istack.pop();
	}

	cout<<"此时栈是否为空?"<<istack.empty()<<endl;
	return 0;
}

int main(void)
{
	Stack<string> istack;

	cout<<"此时栈是否为空?"<<istack.empty()<<endl;
	istack.push("AAAAAA");
	cout<<"此时栈是否为空?"<<istack.empty()<<endl;

	for(int idx = 1;idx != 11; ++idx)
	{
		string elem(6,'A' + idx);
		istack.push(elem);
	}

	cout<<"此时栈是否已满?"<<istack.full()<<endl;

	while(!istack.empty())
	{
		cout<<istack.top()<<" ";
		istack.pop();
	}

	cout<<"此时栈是否为空?"<<istack.empty()<<endl;
}
