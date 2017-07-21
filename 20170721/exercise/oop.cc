#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class CRectangle
{
	private:
		float length;
		float width;
	public:
		CRectangle(){}
		CRectangle(float l = 0.0f,float w = 0.0f)
		{
			this->length = l;
			this->width = w;
		}
		float area()
		{
			return this->length * this->width;
		}
};
 
int main(void)
{
	CRectangle rect(20.0f,5.0f);
	cout<<"area is："<<rect.area()<<endl;
}
