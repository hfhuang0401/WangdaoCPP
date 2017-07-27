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
			atexit(destory);//需放在大括号里，仅在初始化时注册1次
		}
		return _pInstance;
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
};

Singleton * Singleton::_pInstance = Singleton::getInstance();

int main(void)
{
	Singleton::getInstance();
}
