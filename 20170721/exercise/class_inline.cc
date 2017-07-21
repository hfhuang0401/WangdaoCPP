#include <iostream> 
#include <cstring>
 
using std::cin;
using std::cout;
using std::endl;

class computer
{
	private:
		char brand[20];
		float price;
	public:
		void print()
		{
			cout<<"brand is:"<<brand<<endl;
			cout<<"price is:"<<price<<endl;
		}
		void setbrand(char *br)
		{
			strcpy(brand,br);
		}
		void setprice(float pr)
		{
			price = pr;
		}
};

int main(void)
{
	computer com1;
	com1.setprice(5000);
	char brand[]="lenovo";
	com1.setbrand(brand);
	com1.print();
	return 0;
}
