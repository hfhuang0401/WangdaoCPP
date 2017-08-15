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

//设计模式之工厂模式
//优点:
//	1. 满足单一职责原则
//	2. 满足开闭原则
//	
//适用场景：
//	1.复杂对象的创建
//	2.有多个同类型的对象,提供统一的接口
//
//注意: 如果创建是一个简单对象，完全没有必要去使用工厂模式
class FigureFactory
{
public:
	virtual Figure * create()=0;
};

class CircleFactory
: public FigureFactory
{
public:
	Figure * create()
	{
		//load xml info
		//.....
		//
		int  radius = 5;
		return new Circle(radius);
	}
};

class RectangleFactory
: public FigureFactory
{
public:
	Figure * create()
	{
		//load xml info
		//...
		float length = 3;
		float width = 4;
		return new Rectangle(length, width);
	}
};

class TriangleFactory
: public FigureFactory
{
public:
	Figure * create()
	{
		//load xml info 
		//...
		float fx = 3;
		float fy = 4;
		float fz = 5;
		return new Triangle (fx, fy, fz);
	}
};

int main(void)
{
	unique_ptr<FigureFactory> circleFactory(new CircleFactory());
	unique_ptr<FigureFactory> rectangleFactory(new RectangleFactory());
	unique_ptr<FigureFactory> triangleFactory(new TriangleFactory());

	unique_ptr<Figure> circle(circleFactory->create());
	unique_ptr<Figure> rectangle(rectangleFactory->create());
	unique_ptr<Figure> triangle(triangleFactory->create());

	display(circle.get());//智能指针中get()返回一个原始指针
	display(rectangle.get());
	display(triangle.get());
	return 0;
}
