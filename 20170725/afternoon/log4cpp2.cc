#include <iostream> 
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>

using std::cin;
using std::cout;
using std::endl;

using namespace log4cpp;
 
int main(void)
{
	PatternLayout * pthLayout = new PatternLayout();
	pthLayout->setConversionPattern("%d: [%p] %c %x: %m%n");
	
	OstreamAppender * pOsAppender = new OstreamAppender("pOsAppender",&cout);
	pOsAppender->setLayout(pthLayout);

	Category & root = Category::getRoot();
	root.addAppender(pOsAppender);
	root.setPriority(Priority::DEBUG);

	root.error("this is an error message");
	root.warn("this is a warn message");

	Category::shutdown();
	
	return 0;
}
