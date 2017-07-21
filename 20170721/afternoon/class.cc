#include <iostream>
#include<cstring>
 
using std::cin;
using std::cout;
using std::endl;

struct A
{
	void setA(int a)
	{
		_ia = a;
	}
	void print()
	{
		cout<<"A::_ia = "<<_ia<<endl;
	}
	int _ia;
};//struct的默认访问权限是public

class computer
{
	//class的默认访问权限是private
	private://表现的是封装的特性
		char *m_brand;
		float _fprice;
	public:
		computer();
		computer(const computer & cc);
		computer(const char *brand,float price)
			:m_brand(new char[strlen(brand)+1]())
			,_fprice(price)	
		{
			strcpy(m_brand,brand);//深拷贝
		}
		void print()
		{
			cout << "品牌："<<m_brand<<endl;
			cout<<"价格："<<_fprice<<endl;
		}
		~computer()//析构函数可以显式调用，但不推荐这样使用
		{
			delete [] m_brand;
			cout<<"~computer()"<<endl;
		}
};

computer::computer(const computer & cc)
	:m_brand(new char[strlen(cc.m_brand)+1]())
	 ,_fprice(cc._fprice)
{
	strcpy(m_brand,cc.m_brand);
	cout<<"computer(const computer &)"<<endl;
}

computer p3("HP",6000);//全局对象整个程序结束后调用析构函数

int main(void)
{
	computer c1("Lenovo",5000);//对于栈对象而言，当其生命周期结束时，会自动调用析构函数
	c1.print();
	computer *c2= new computer("Mac",10000);
	c2->print();
	delete c2;//不可少，需要手动释放堆空间，才会执行析构函数
	computer c3 = c1;
	c3.print();
}
