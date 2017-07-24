#include <iostream>
#include <cstring>
#include <cstdlib>
 
using std::cin;
using std::cout;
using std::endl;

//只能生成栈对象
class Student
{
public:
	Student(int id,const char *name)
		:_id(id)
		 ,_name(new char[strlen(name)+1])
	{
		strcpy(_name,name);
		cout<<"Student(int,const char *)"<<endl;
	}
	void print() const
	{
		cout<<"id: "<<_id<<endl;
		cout<<"name: "<<_name<<endl;
	}
	~Student()
	{
		delete [] _name;
		cout<<"~Student()"<<endl;
	}
private:	
	void * operator new(size_t size)
	{
		cout<<" void * operator new(size_t)"<<endl;
		void * ret = malloc(size);
		return ret;
	}
	void operator delete(void * ret)
	{
		cout<<"void operator delete (void *)"<<endl;
		free(ret);
	}

private:
	int _id;
	char *_name;
};

int main(void)
{
	Student stu(101,"Tom");
//	Student *s = new Student(100,"jack");//不能编译通过
//	s->print();
//	delete s;
}
