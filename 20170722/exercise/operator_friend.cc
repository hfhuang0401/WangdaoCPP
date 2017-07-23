#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class Complex
{
	friend Complex & operator + ( Complex & c1 , Complex & c2);
	public:
		Complex(int xx = 0,int yy = 0)
			:_x(xx),_y(yy){}
		void print();
	private:
		int _x;
		int _y;
};

Complex & operator + ( Complex & c1, Complex & c2)
{
	c1._x += c2._x;
	c1._y += c2._y;
	return c1;
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
}
