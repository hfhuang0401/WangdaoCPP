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
using std::weak_ptr;


class Child;//前向声明

class Parent
{
public:
	Parent()
	{	cout << "Parent()" << endl;	}

	~Parent()
	{	cout << "~Parent()" << endl;	}

	//weak_ptr就是用来解决shared_ptr的循环引用的问题
	weak_ptr<Child> _childPtr;
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
	cout << "parent's use_count = " << parent.use_count() << endl;

	shared_ptr<Child> child(new Child);
	cout << "child's use_count = " << child.use_count() << endl;

	//_childPtr是一个weak_ptr
	parent->_childPtr = child;//进行复制, 引用计数不会加1
	cout << "child's use_count = " << child.use_count() << endl;

	child->_parentPtr = parent;//进行复制，引用计数加1
	cout << "parent's use_count = " << parent.use_count() << endl;

	return 0;
}
