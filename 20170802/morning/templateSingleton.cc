#include <cstdio>
#include <iostream>
 
using std::cout;
using std::endl;

template <typename T>
class Singleton
{
	class AutoRelease
	{
	public:
		AutoRelease()
		{
			cout<<"AutoRelease()"<<endl;
		}
		~AutoRelease()
		{
			cout<<"~AutoRelease()"<<endl;
			if(_pInstance)
				delete _pInstance;
		}
	};
public:
	static T* getInstance();
private:
	Singleton(){}
	~Singleton(){}
private:
	static T* _pInstance;
	static AutoRelease _auto;
};

#if 0
template <typename T>
T * Singleton<T>::_pInstance = getInstance();//饱汉式
#endif

template <typename T>
T * Singleton<T>::_pInstance = NULL;//饿汉式

template <typename T>
typename Singleton<T>::AutoRelease Singleton<T>::_auto;

template <typename T>
T * Singleton<T>::getInstance()
{
	if(NULL == _pInstance)
	{
		_auto;//该语句不可少，用来由模板生成_auto对象
		_pInstance = new T();
	}
	return _pInstance;
}

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int ix = 0, int iy = 0)" << endl;
	}

	void init(int ix, int iy)
	{
		_ix = ix;
		_iy = iy;
	}

	void print() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}
private:
	int _ix;
	int _iy;
};

int main(void)
{
	Point * p1 = Singleton<Point>::getInstance();//先创建对象
	Point * p2 = Singleton<Point>::getInstance();

	p1->print();
	p1->init(1,2);//再去进行初始化，二段式构造

	p2->print();

	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);

	return 0;
}
