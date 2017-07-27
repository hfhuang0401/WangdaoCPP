#include <pthread.h>
#include <cstdlib>
#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;
 
class Singleton
{
public:
	static Singleton * getInstance()
	{
		pthread_once(&_once,init);
		return _pInstance;
	}

	static void init(void)
	{
		_pInstance = new Singleton;
		atexit(destory);
	}

	static void destory()
	{
		if(_pInstance)
			delete _pInstance;
	}

private:
	Singleton()
	{
		cout<<"Singleton()"<<endl;
	}
	~Singleton()
	{
		cout<<"~Singleton()"<<endl;
	}

private:
	static Singleton * _pInstance; 
	static pthread_once_t _once;
};

Singleton * Singleton::_pInstance = NULL;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main(void)
{
	Singleton::getInstance();
}
