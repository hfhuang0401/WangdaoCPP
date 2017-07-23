#include <iostream>
#include <cstdlib>
 
using std::cout;
using std::endl;

class Queue
{
public:
	Queue(int size = 10)
	{
		_front = 0;
		_back = 0;
		_qu = new int [size+1]();
		_maxSize = size + 1;
	}

	void push(int num);
	void pop();
	int  front();
	int  back();
	bool empty();
	bool full();

private:
	int _front;
	int _back;
	int *_qu;
	int _maxSize;
};

bool Queue::full()
{
	if(((_back+1)%_maxSize)==_front)
	{
		cout<<"ERROR! queue is full"<<endl;
		return true;
	}else
		return false;
}

bool Queue::empty()
{
	if(_front == _back)
	{
		cout<<"ERROR! queue is empty"<<endl;
		return true;
	}else
		return false;
}

void Queue::push(int num)
{
	if(full())
	{
		exit(-1);
	}else
	{
		_qu[_back] = num;
		_back = (_back + 1)% _maxSize;
	}
}

void Queue::pop()
{
	if(empty())
	{
		exit(-1);
	}else
	{
		_front = (_front + 1) % _maxSize;
	}
}

int Queue::front()
{
	if(empty())
	{
		exit(-1);
	}else
		return _qu[_front];
}

int Queue::back()
{
	if(empty())
	{
		exit(-1);
	}else
	{
		if(_back == 0)
			return _qu[_maxSize-1];
		else
			return _qu[_back-1];
	}
}

int main(void)
{
	Queue que(4);
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
