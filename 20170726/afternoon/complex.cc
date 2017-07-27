#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class Complex
{
public:
	Complex(double dreal,double dimag)
	:_dreal(dreal)
	 ,_dimag(dimag)
	{
	}
	
	void print() const
	{
		cout<<_dreal <<"+"<<_dimag<<"i"<<endl;
	}
	
//	friend	Complex operator + (const Complex &lhs,const Complex &rhs);
	
	Complex  operator +(const Complex );
private:
	double _dreal;
	double _dimag;
};

#if 0
Complex operator + (const Complex &lhs,const Complex &rhs)
{
	return Complex(lhs._dreal+rhs._dreal,lhs._dimag+rhs._dimag);
}
#endif

#if 0
Complex  Complex::operator +(const Complex rhs)
{
	int dreal;
	int dimag;
	dreal = this->_dreal + rhs._dreal;
	dimag = this->_dimag + rhs._dimag;
	return Complex(dreal,dimag);
}
#endif

Complex  Complex::operator +(const Complex rhs)
{
	return Complex(_dreal+rhs._dreal,_dimag+rhs._dimag);
}
int main(void)
{
	Complex c1(1,2);
	Complex c2(3,-4);

	Complex c3 =c1 + c2;
	c3.print();
	c1.print();
	c2.print();
	return 0;
}
