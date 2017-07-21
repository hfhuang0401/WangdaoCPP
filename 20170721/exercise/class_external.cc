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
		void print();
		void setbrand(char *br);
		void setprice(float pr);
};

void computer::print()
{
			cout<<"brand is:"<<brand<<endl;
			cout<<"price is:"<<price<<endl;
}
void computer::setbrand(char *br)
{
	strcpy(brand,br);
}
void computer::setprice(float pr)
{
	price = pr;
}

int main(void)
{
	computer com2;
	com2.setprice(6999);
	char brand[] = "Acer";
	com2.setbrand(brand);
	com2.print();
	computer *pcom =new computer;
	char pbrand[] = "Apple";
	pcom->setbrand(pbrand);
	pcom->setprice(8999);
	pcom->print();
	delete pcom;
	pcom = NULL;
}
