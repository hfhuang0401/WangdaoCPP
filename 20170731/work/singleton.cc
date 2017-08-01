#include <pthread.h>
#include <cstdlib>
#include <iostream> 
 
using std::cout;
using std::endl;

template <typename T>
class Singleton;

class X
{
public:
	void disp()
	{
		cout<<"a = "<<_a<<endl;
	}
private:
	X(int a = 0)
	:_a(a)
	{
		cout<<"X()"<<endl;
	}
	~X()
	{
		cout<<"~X()"<<endl;
	}
private:
	int _a;

	//将模板类设为友元类，访问私有的构造函数
	friend class Singleton<X>;
};

class Student
{
public:
	void print()
	{
		cout<<"student->print()"<<endl;
	}
private:
	Student()
	{
		cout<<"Student()"<<endl;
	}
	~Student()
	{
		cout<<"~Student()"<<endl;
	}

	//将模板类设为友元类，访问私有的构造函数
	friend class Singleton<Student>;
};

template <typename T>
class Singleton
{
public:
	static T* getInstance()
	{
		pthread_once(&_once,init);
		return _cName;
	}

	static void init(void)
	{
		_cName = new T();
		atexit(destory);
	}

	static void destory()
	{
		if(_cName)
			delete _cName;
	}

private:
	static T *_cName;
	static pthread_once_t _once;
};

template <typename T>
T * Singleton<T>::_cName = NULL;

template <typename T>
pthread_once_t Singleton<T>::_once = PTHREAD_ONCE_INIT;

int main(void)
{
	//构造函数私有化
	//X x;
	//Student *s = new Student;

	X *x1 = Singleton<X>::getInstance();
	x1->disp();
	X *x2 = Singleton<X>::getInstance();
	x2->disp();

	Student *s1 = Singleton<Student>::getInstance();
	s1->print();
	Student *s2 = Singleton<Student>::getInstance();
	s2->print();
}
