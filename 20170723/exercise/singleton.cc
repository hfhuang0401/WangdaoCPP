#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

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
	CA *p1 = CA::GetInstance(3,4);
	CA *p2 = CA::GetInstance(2,1);
	CA *p3 = CA::GetInstance(6,2);
	cout<<p1<<endl;
	cout<<p2<<endl;
	cout<<p3<<endl;
	p1->disp();
	p2->disp();
	p3->disp();
}
