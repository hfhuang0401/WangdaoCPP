#include <string.h>
#include <iostream>

using std::cout;
using std::endl;


class Computer
{
public:
	Computer()
	{
		cout<<"Computer()"<<endl;
	}

	Computer & operator=(const Computer & rhs);

	Computer(const char * brand, float fprice);

	~Computer();

	Computer(const Computer & rhs);

	//静态成员函数之中不包含this指针
	static void printTotal()
	{
		//在其内部不能直接访问非静态数据成员和成员函数
		//cout<<this->_brand<<endl;//无法拿到
		//只能访问静态数据成员和成员函数
		cout << "总价：" << _totalPrice << endl;
	}

	static void printcomputer(const Computer & com)
	{
		cout<<"品牌："<<com._brand<<endl;
		cout<<"价格："<<com._fprice<<endl;
	}

	void print();
private:
	char * _brand;
	float _fprice;
	static float _totalPrice;
};

Computer::Computer(const char * brand, float fprice)
: _brand(new char[strlen(brand) + 1]())
, _fprice(fprice)
{
	cout << "Computer(const char*, float)" << endl;
	strcpy(_brand, brand);//深拷贝
	_totalPrice += _fprice ;
}

Computer::~Computer()
{//析构函数的作用：做清理工作
	delete [] _brand;
	cout << "~Computer()" << endl;
}


Computer::Computer(const Computer & rhs)
: _brand(new char[strlen(rhs._brand) + 1]()) //深拷贝
, _fprice(rhs._fprice)
{
	cout << "Computer(const Computer&)" << endl;
	strcpy(_brand, rhs._brand);
}

void Computer::print()
{
	cout << "品牌:" << _brand << endl;
	cout << "价格:" << _fprice << endl;
}


Computer & Computer::operator=(const Computer & rhs)
{
	//1.考虑自复制
	//2.回收左操作数的空间
	//3.再去执行深拷贝
	_fprice = rhs._fprice;
	if(this != &rhs)
	{
		delete [] _brand;//先释放原有空间，再开辟新空间
		_brand = new char[strlen(rhs._brand)+1]();
		strcpy(_brand,rhs._brand);
	}
	return *this;
}

float Computer::_totalPrice = 0.0f;

int main(void)
{
	Computer c1("Lenovo", 5000);
//	c1.printcomputer(c1);
	Computer::printcomputer(c1);//静态成员函数可以直接通过类名进行访问
	c1.printTotal();

	Computer c2("Acer", 6000);
	c2.print();
	c2.printTotal();

	Computer c3("Apple",10000);
	c3.print();
	c3.printTotal();
	
	return 0;
}
