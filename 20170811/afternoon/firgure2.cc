#include <iostream>
#include <functional>
 
using std::cin;
using std::cout;
using std::endl;
using std::function;
using std::bind;

//基于对象的编程方式
//1.具体类，不再是一个抽象类
//2.其它的图形类也是与Figure无关的类
//3.要调用的成员函数的名字可以进行灵活变动
class Figure
{
public:
	Figure(){}

	//注册回调函数
	void setDisplayCallback(const function<void()> & cb)
	{
		_displayCallback = cb;
	}

	void setAreaCallback(const function<float()> & cb)
	{
		_areaCallback = cb;
	}

	//执行回调函数
	void handleDisplayCallback()
	{
		if(_displayCallback)
			_displayCallback();
	}

	float handleAreaCallback()
	{
		if(_areaCallback)
			return _areaCallback();
		else
			return 0;
	}

private:
	function<void()> _displayCallback;
	function<float()> _areaCallback;
};

class Circle
{
public:
	Circle(float fradius)
	:_fradius(fradius)
	{}

	void show() const
	{
		cout<<"Circle: ";
	}

	float calcArea()
	{
		return PI * _fradius * _fradius;
	}

private:
	static float PI;
	float _fradius;
};

float Circle::PI = 3.14159;

void display(Figure & fig)
{
	fig.handleDisplayCallback();
	cout<<fig.handleAreaCallback()<<endl;
}

int main(void)
{
	Figure fig;
	Circle circle(10);

	fig.setDisplayCallback(bind(&Circle::show,&circle));
	fig.setAreaCallback(bind(&Circle::calcArea,&circle));

	display(fig);
}
