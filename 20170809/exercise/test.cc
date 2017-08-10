#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class Rational
{
public:
	Rational(int numerator = 0, int denominator = 1)
		: n_(numerator), d_(denominator)
	{
		std::cout << "Constructor Called..." << std::endl;
	}

	~Rational()
	{
		std::cout << "~Destructor Called..." << std::endl;
	}

	Rational(const Rational &rhs)
	{
		n_ = rhs.n_;
		d_ = rhs.d_;
		std::cout << "Copy Constructor Called..." << std::endl;
	}

	int numerator() const {    return n_;   }
	int denominator() const {       return d_;	}

private:
	int n_;
	int d_;
};

const Rational operator *(const Rational &lhs, const Rational &rhs)
{
	std::cout << "...Enter operator *()..." << std::endl;
	Rational tmp(lhs.numerator() * rhs.numerator(),
				 lhs.denominator() * rhs.denominator());
	std::cout << "...Leave operator *()..." << std::endl;

	return tmp;
}

int main(void)
{
	Rational x(1, 5), y(2, 9);
	Rational z = x * y;
	std::cout << "calc result:" << z.numerator()
		<< "/" << z.denominator() << std::endl;

	return 0;
}
