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
		if(NULL == _pInstance)
		{
			_pInstance = new Singleton;
			atexit(destory);
		}
		return _pInstance;
	}

	static void destory()
	{
		if(_pInstance)
			delete _pInstance;
		cout<<"freed..."<<endl;
	}

private:
	Singleton(){	cout<<"Singleton()"<<endl;	}
	~Singleton(){	cout<<"~Singleton()"<<endl;	}

private:
	static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = getInstance();//饱汉式，可以保证线程安全

int main(void)
{
	Singleton::getInstance();

	return 0;
}
