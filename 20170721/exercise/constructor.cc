#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;
 
class point
{
	private:
		int xpos;
		int ypos;
	public:
		point();
		point(int x,int y);
		void print();
};

point::point()
{
	xpos = 0;
	ypos = 0;
}

point::point(int x,int y)
{
	xpos = x;
	ypos = y;
}

void point::print()
{
	cout<<"xpos = "<<xpos<<" ypos = "<<ypos<<endl;
}

int main(void)
{
	point p1;
	p1.print();
	point p2(3,4);
	p2.print();
}
