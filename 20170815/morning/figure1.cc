#include <math.h>
#include <iostream>
#include <functional>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;

//能够满足面向对象设计原则之开闭原则
//
//1.通过继承和虚函数的方式实现多态
class Figure
{
public:
	virtual void display() const=0;
	virtual float area()=0;
};


class Rectangle
: public Figure
{
public:
	Rectangle(float flength, float fwidth)
	: _flength(flength)
	, _fwidth(fwidth)
	{}

	virtual void display() const
	{	cout << "rectangle:";}
	virtual float area()
	{
		return _flength * _fwidth;
	}
private:
	float _flength;
	float _fwidth;
};

class Circle
: public Figure
{
public:
	Circle(float fradius)
	: _fradius(fradius)
	{}

	virtual void display() const
	{	cout << "circle:";}

	virtual float area()
	{
		return PI * _fradius * _fradius;
	}
private:
	float _fradius;
	static float PI; 
};

float Circle::PI = 3.14159;


class Triangle 
: public Figure
{
public:
	Triangle(float fa, float fb, float fc)
	: _fa(fa)
	, _fb(fb)
	, _fc(fc)
	{}

	virtual void display() const
	{	cout << "triangle:";}

	virtual float area()
	{
		float p = (_fa + _fb + _fc) / 2;
		return sqrt(p * (p - _fa) * (p - _fb) * (p - _fc));//海伦公式
	}
private:
	float _fa;
	float _fb;
	float _fc;
};

void display(Figure * fig)
{
	fig->display();
	cout << fig->area() << endl;
}

//静态工厂方法
// 优点: 创建图形对象时是比较统一的
// 缺点: 1. 不满足单一职责原则: 可以创建多种图形的
//	     2. 不满足开放闭合原则: 如果要创建新的图形，就必须修改FigureFactory类
class FigureFactory
{
public:
	static Figure * createCircle()
	{
		//load xml info
		//.....
		//
		int  radius = 5;
		return new Circle(radius);
	}

	static Figure * createRectangle()
	{
		//load xml info
		//...
		float length = 3;
		float width = 4;
		return new Rectangle(length, width);
	}

	static Figure * createTriangle()
	{
		//load xml info 
		//...
		float fx = 3;
		float fy = 4;
		float fz = 5;
		return new Triangle (fx, fy, fz);
	}

#if 0
	static Figure * createDiamond()
	{
		//load xml info
		//...
	}
#endif

};

int main(void)
{
	unique_ptr<Figure> circle(FigureFactory::createCircle());
	unique_ptr<Figure> rectangle(FigureFactory::createRectangle());
	unique_ptr<Figure> triangle(FigureFactory::createTriangle());

	display(circle.get());
	display(rectangle.get());
	display(triangle.get());
	return 0;
}
