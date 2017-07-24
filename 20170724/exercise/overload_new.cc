#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
 
using std::cin;
using std::cout;
using std::endl;
using std::size_t;

class Student
{
public:
	int _id;
	char _name[10];

	Student()
	{
		cout<<"Student 构造函数被调用"<<endl;
	}
	~Student()
	{
		cout<<"Student 析构函数被调用"<<endl;
	}
	static void* operator new(size_t nSize);
	static void operator delete(void *pVoid);
};

void* Student::operator new(size_t nSize)
{
	cout<<"new 操作符被调用，size = "<<nSize<<endl;
	//void *pRet = new char[nSize];
	void *pRet = malloc(nSize);
	return pRet;
}

void Student::operator delete(void *pVoid)
{
	cout<<"delete 操作符被调用"<<endl;
	free(pVoid);
}

int main(void)
{
	Student *pstu = new Student;
	pstu->_id = 101;
	strcpy(pstu->_name,"Tony");
	cout<<endl;
	delete pstu;
}
