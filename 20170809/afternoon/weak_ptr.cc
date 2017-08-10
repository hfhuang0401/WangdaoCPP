 ///
 /// @file    weak_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-09 16:19:04
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;


class X
{
public:
	X(){	cout << "X()" << endl;	} 
	~X(){	cout << "~X()" << endl;	}

	void func()
	{	cout << "X::func()" << endl;	}
};

int main(void)
{
	weak_ptr<X> wp;
	{
		shared_ptr<X> sp(new X);
		cout << "sp 's use_count = " << sp.use_count() << endl;

		wp = sp;

		cout << "sp 's use_count = " << sp.use_count() << endl;

		shared_ptr<X> sp2 = wp.lock();
		if(sp2)
		{
			cout << "提升成功"<< endl;
			sp2->func();
		}
		else
		{
			cout << "提升失败，该对象已被销毁!" << endl;
		}
	}

	shared_ptr<X> sp2 = wp.lock();
	if(sp2)
	{
	cout << "提升成功"<< endl;
	sp2->func();
	}
	else
	{
	cout << "提升失败，该对象已被销毁!" << endl;
	}

	return 0;
}
