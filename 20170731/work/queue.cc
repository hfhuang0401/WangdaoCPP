#include <cstdlib>
#include <iostream>
#include <string>
 
using std::cin;
using std::cout;
using std::endl;
using std::string;

template <typename T>
class Queue
{
public:
	Queue(int size = 10)
	:_front(0)
	,_back(0)
	,_maxSize(size + 1)
	,_qu(new T[size + 1]())
	{}

	~Queue()
	{
		if(_qu != NULL)
		{
			delete [] _qu;
			_qu = NULL;
		}
	}

	bool full() const;
	bool empty() const;
	void push(T member);
	void pop();
	T & front() const;
	T & back() const;
private:
	int _front;
	int _back;
	int _maxSize;
	T *_qu;
};

template <typename T>
bool Queue<T>::full() const
{
	if(((_back + 1)%_maxSize) == _front)
	{
		cout << "ERROR!queue is full"<<endl;
		return true;
	}else
		return false;
}

template <typename T>
bool Queue<T>::empty() const
{
	if(_front == _back)
	{
		cout<<"ERROR!queue is empty"<<endl;
		return true;
	}else
		return false;
}

template <typename T>
void Queue<T>::push(T member)
{
	if(full())
		exit(-1);
	else
	{
		_qu[_back] = member;
		_back = (_back + 1) % _maxSize;
	}
}

template <typename T>
void Queue<T>::pop()
{
	if(empty())
		exit(-1);
	else
	{
		_front = (_front + 1) % _maxSize;
	}
}

template <typename T>
T & Queue<T>::front() const
{
	if(empty())
		exit(-1);
	else
		return _qu[_front];
}

template <typename T>
T & Queue<T>::back() const
{
	if(empty())
		exit(-1);
	else
		return _qu[(_back -1 + _maxSize) % _maxSize];
}

void test0()
{
	Queue<int> que(4);
	que.push(1);
	que.push(2);
	que.push(3);
	que.push(4);
	cout<<"front = "<<que.front()<<endl;
	cout<<"back = "<<que.back()<<endl;
	que.pop();
	cout<<"pop()"<<endl;
	cout<<"front = "<<que.front()<<endl;
	cout<<"back = "<<que.back()<<endl;
	que.pop();
	cout<<"pop()"<<endl;
	cout<<"front = "<<que.front()<<endl;
	cout<<"back = "<<que.back()<<endl;
	que.push(5);
	cout<<"push()"<<endl;
	cout<<"front = "<<que.front()<<endl;
	cout<<"back = "<<que.back()<<endl;
	que.pop();
	cout<<"pop()"<<endl;
	cout<<"front = "<<que.front()<<endl;
	cout<<"back = "<<que.back()<<endl;
	que.push(6);
	cout<<"push()"<<endl;
	cout<<"front = "<<que.front()<<endl;
	cout<<"back = "<<que.back()<<endl;
	que.push(7);
	cout<<"push()"<<endl;
	cout<<"front = "<<que.front()<<endl;
	cout<<"back = "<<que.back()<<endl;
	que.push(8);
	cout<<"push()"<<endl;
	cout<<"front = "<<que.front()<<endl;
	cout<<"back = "<<que.back()<<endl;
}

void test1()
{
	Queue<string> que(4);
	que.push("hello");
	que.push("world");
	que.push("shenzhen");
	que.push("wangdao");
	cout<<"front = "<<que.front()<<endl;
	cout<<"back = "<<que.back()<<endl;
	que.pop();
	cout<<"pop()"<<endl;
	cout<<"front = "<<que.front()<<endl;
	cout<<"back = "<<que.back()<<endl;
	que.pop();
	cout<<"pop()"<<endl;
	cout<<"front = "<<que.front()<<endl;
	cout<<"back = "<<que.back()<<endl;
	que.push("aaa");
	cout<<"push(aaa)"<<endl;
	cout<<"front = "<<que.front()<<endl;
	cout<<"back = "<<que.back()<<endl;
	que.push("bbb");
	cout<<"push(bbb)"<<endl;
	cout<<"front = "<<que.front()<<endl;
	cout<<"back = "<<que.back()<<endl;
	que.push("ccc");
	cout<<"push(ccc)"<<endl;
	cout<<"front = "<<que.front()<<endl;
	cout<<"back = "<<que.back()<<endl;
}

int main(void)
{
	test1();
	return 0;
}
