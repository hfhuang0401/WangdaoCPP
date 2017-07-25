#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/OstreamAppender.hh>
 
using std::cin;
using std::cout;
using std::endl;

using namespace log4cpp;
 
int main(void)
{
	OstreamAppender *pOsAppender = new OstreamAppender("pOsAppender",&cout);
	pOsAppender->setLayout(new BasicLayout());

	Category & root = Category::getRoot();
	root.addAppender(pOsAppender);
	root.setPriority(Priority::ERROR);

	root.error("this is an error message");
	root.warn("this is a warn message");

	Category::shutdown();

	return 0;
}
