#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class Singleton
{
	class AutoFree
	{
	public:
		AutoFree()
		{
			cout<<"AutoFree()"<<endl;
		}
		~AutoFree()
		{
			if(_pInstance)
				delete _pInstance;
			cout<<"~AutoFree()"<<endl;
		}
	};

public:
	static Singleton * getInstance()
	{
		if(NULL == _pInstance)
			_pInstance = new Singleton;
		return _pInstance;
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
	static AutoFree _auto;
};

Singleton * Singleton::_pInstance = Singleton::getInstance();
Singleton::AutoFree Singleton::_auto;

int main(void)
{
	Singleton::getInstance();
}
