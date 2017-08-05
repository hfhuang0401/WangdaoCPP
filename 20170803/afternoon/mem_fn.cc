#include <iostream> 
#include <functional>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::for_each;
using std::remove_if;

class Number
{
public:
	Number(int value = 0)
	:_value(value)
	{}

	void display()const
	{
		cout<<_value<<" ";
	}

	bool isEven()const
	{
		return !(_value % 2);
	}

	bool isPrime()const
	{
		if(_value == 1)
		{
			cout<<"value = 1"<<endl;
			return true;
		}

		for(int idx = 2;idx <= _value/2; ++idx)
		{
			if(!(_value % idx))
				return false;
		}
		return true;
	}

private:
	int _value;
};

int main(void)
{
	vector<Number> numbers;
	for(int idx = 1;idx != 14; ++idx)
	{
		numbers.push_back(Number(idx));
	}

	for_each(numbers.begin(),numbers.end(),std::mem_fn(&Number::display));
	cout<<endl;

	numbers.erase(remove_if(numbers.begin(),numbers.end(),std::mem_fn(&Number::isPrime)),numbers.end());

	for_each(numbers.begin(),numbers.end(),std::mem_fn(&Number::display));
	cout<<endl;
}
