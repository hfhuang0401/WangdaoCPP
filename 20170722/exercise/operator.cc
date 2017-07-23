#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class Complex
{
	public:
		Complex(int xx = 0,int yy = 0)
			:_x(xx),_y(yy){}
		Complex & operator + ( Complex);
		void print();
	private:
		int _x;
		int _y;
};

Complex & Complex::operator + ( Complex rhs)
{
	this->_x += rhs._x;
	this->_y += rhs._y;
	return *this;
}

void Complex::print()
{
	cout<<"x = "<<_x<<" y = "<<_y<<endl;
}

int main(void)
{
	Complex c1(1,2);
	Complex c2(3,4);
	Complex c3 = c1 + c2;
	c3.print();
	c2.print();
	c1.print();
}
