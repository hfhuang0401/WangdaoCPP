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
		char m_brand[20];//下划线代表类里的成员,m表示member
		float _fprice;
	public:
		void print()
		{
			cout << "品牌："<<m_brand<<endl;
			cout<<"价格："<<_fprice<<endl;
		}
		void setBrand(const char* brand)
		{
			strcpy(m_brand,brand);
		}
		void setPrice(float price)
		{
			_fprice = price;
		}
};//超出大括号的范围，就称为类之外



int main(void)
{
	computer c1;
//	c1.price = 5000;//不可以在类外访问私有成员
	c1.setPrice(5000);
	c1.setBrand("Lenovo");
	c1.print();

	A a;
	a.setA(10);
	a.print();
	a._ia= 20;
	a.print();
}
