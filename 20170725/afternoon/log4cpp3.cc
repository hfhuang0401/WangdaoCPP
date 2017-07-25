#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/OstreamAppender.hh>

#include <sstream>
#include <string>
 
using std::cin;
using std::cout;
using std::endl;
using std::ostringstream;
using std::string;

using namespace log4cpp;
int main(void)
{
	PatternLayout * ptnLyout1 = new PatternLayout();
	ptnLyout1->setConversionPattern("%d: [%p] :%m%n");

	PatternLayout * ptnLyout2 = new PatternLayout();
	ptnLyout2->setConversionPattern("%d: [%p] :%m%n");

	FileAppender * fileAppender = new FileAppender("fileAppender","wd.log");
	fileAppender->setLayout(ptnLyout1);

	RollingFileAppender * rollingFileAppender =
		new RollingFileAppender("rollingFileAppender",
				"rollwd.log",5 * 1024,3);
	rollingFileAppender->setLayout(ptnLyout2);

	Category & root = Category::getRoot().getInstance("Root");
	root.addAppender(fileAppender);
	root.addAppender(rollingFileAppender);
	root.setPriority(Priority::DEBUG);

	for(size_t idx = 0;idx != 100; ++idx)
	{
		string errormsg;
		ostringstream oss;
		oss << idx <<":Root Error Message";
		root.error(oss.str());
	}
	Category::shutdown();
	return 0;
}
