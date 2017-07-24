#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

//要求：由该类只能生成唯一的对象
//1.该对象不能是栈对象，只能说堆对象

//主要作用：用来替换全局变量
//使用场景：配置文件的读取/词典类的实现/日志系统的输出对象

class CA
{
private:
	static CA *pA;
	int x;
	int y;
	CA(int x = 0,int y = 0)
	{
		this->x = x;
		this->y = y;
		cout<<"构造函数被调用"<<this<<endl;
	}
public:
	static CA* GetInstance(int x =0,int y = 0)
	{
		cout<<"GetInstance func is called..."<<endl;
		if(pA == NULL)
		{
			pA = new CA(x,y);
		}
		return pA;
	}
	void disp() const
	{
		cout<<"("<<this->x<<","<<this->y<<")"<<endl;
	}
};

CA* CA::pA = NULL;//静态成员要在外面初始化

int main(void)
{
//	CA  c1;//禁止该语句运行，让其不能通过编译
//	CA  c2;//需要在类之外调用默认构造函数
	CA *p1 = CA::GetInstance(3,4);
	CA *p2 = CA::GetInstance(2,1);
	CA *p3 = CA::GetInstance(6,2);
	cout<<p1<<endl;
	cout<<p2<<endl;
	cout<<p3<<endl;
	p1->disp();
	p2->disp();
	p3->disp();

	delete p1;//不希望该语句编译通过
}
