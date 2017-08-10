 ///
 /// @file    circleReference.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-09 15:51:44
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;


class Child;//前向声明

class Parent
{
public:
	Parent()
	{	cout << "Parent()" << endl;	}

	~Parent()
	{	cout << "~Parent()" << endl;	}

	shared_ptr<Child> _childPtr;
};

class Child
{
public:
	Child()
	{	cout << "Child()" << endl;	}

	~Child()
	{	cout << "~Child()" << endl;	}

	shared_ptr<Parent> _parentPtr;
};

int main(void)
{
	shared_ptr<Parent> parent(new Parent);

	shared_ptr<Child> child(new Child);

	parent->_childPtr = child;//进行复制, 引用计数加1

	child->_parentPtr = parent;//进行复制，引用计数加1

	return 0;
}
