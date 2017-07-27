#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class Singleton
{
private:
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
	//多线程环境下并不是线程安全的
	static Singleton * getInstance()
	{
		if(NULL == _pInstance)
			_pInstance = new Singleton;
		return _pInstance;
	}
private:
	Singleton(){	cout<<"Singleton()"<<endl;	}
	~Singleton(){	cout<<"~Singleton()"<<endl;	}
private:
	static Singleton * _pInstance;
	static AutoRelease _auto;
};

//懒汉式 \ 饿汉式
//Singleton * Singleton::_pInstance = NULL //懒加载
Singleton * Singleton::_pInstance = getInstance();//饱汉式，可以保证线程安全
Singleton::AutoRelease Singleton::_auto;

int main(void)
{
	Singleton::getInstance();

	return 0;
}
