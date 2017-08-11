#include <iostream>
#include <cmath>
 
using std::cin;
using std::cout;
using std::endl;

//能够满足面向对象设计原则之开闭原则(对扩展开放，对修改关闭)
//
//1.通过继承和虚函数的方式实现多态
class Figure
{
public:
	virtual void display()const = 0;
	virtual float area()=0;
};

class Rectangle
:public Figure
{
public:
	Rectangle(float flength,float fwidth)
	:_flength(flength)
	,_fwidth(fwidth)
	{}

	virtual void display() const
	{
		cout<<"Rectangle: ";
	}

	virtual float area()
	{
		return _flength * _fwidth;
	}

private:
	float _flength;
	float _fwidth;
};

class Circle
:public Figure
{
public:
	Circle(float fradius)
	:_fradius(fradius)
	{}

	virtual void display() const
	{
		cout<<"Circle: ";
	}

	virtual float area()
	{
		return PI * _fradius *_fradius;
	}

private:
	float _fradius;
	static float PI;
};

class Triangle
:public Figure
{
public:
	Triangle(float fa,float fb,float fc)
	:_fa(fa)
	,_fb(fb)
	,_fc(fc)
	{}

	virtual void display() const
	{
		cout<<"Triangle: ";
	}
	
	virtual float area()
	{
		float p = (_fa + _fb + _fc)/2;
		return sqrt(p *(p - _fa) * (p - _fb) * (p - _fc));
	}

private:
	float _fa;
	float _fb;
	float _fc;
};

float Circle::PI = 3.14159;

void display(Figure & fig)
{
	fig.display();
	cout<<fig.area()<<endl;
}

int main(void)
{
	Circle circle(5);
	Rectangle rectangle(3,4);
	Triangle triangle(3,4,5);

	display(circle);
	display(rectangle);
	display(triangle);

	return 0;
}
