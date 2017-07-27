#include<pthread.h>
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
		cout<<"getInstance()"<<endl;
		if(_pInstance==NULL)
			cout<<"first is NULL"<<endl;
		else
			cout<<"first is not NULL"<<endl;
		pthread_once(&_once,init);
		if(_pInstance==NULL)
			cout<<"and then is NULL"<<endl;
		else
			cout<<"and then is not NULL"<<endl;
		cout<<"getInstance() func over..."<<endl;
		return _pInstance;
	}

	static void init()
	{
		cout<<"init()"<<endl;
		_pInstance = new Singleton;
		atexit(destory);
		cout<<"init() func over..."<<endl;
	}
	
	static void destory()
	{
		if(_pInstance)
			delete _pInstance;
		cout<<"destory()"<<endl;
	}

private:
	Singleton(){	cout<<"Singleton()"<<endl;	}
	~Singleton(){	cout<<"~Singleton()"<<endl;	}

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
