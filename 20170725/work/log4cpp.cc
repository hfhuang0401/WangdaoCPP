#include <iostream>
#include <string>
#include <sstream>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/OstreamAppender.hh>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

using namespace log4cpp;

inline string itos(int i)
{
	stringstream ss;
	ss << i;
	return ss.str();
}

#define trans(msg) string(msg).append(" ").append(__FILE__).append("(")\
	.append(itos(__LINE__)).append("):<").append(__func__).append(">").c_str()

#define Error(msg) log->error(trans(msg))
#define Info(msg) log->info(trans(msg))
#define Debug(msg) log->debug(trans(msg))
#define Warn(msg) log->warn(trans(msg))


class Mylog
{
public:
	void warn(const char *msg);
	void error(const char *msg);
	void debug(const char *msg);
	void info(const char *msg);
	static Mylog * getInstance();
	static void destroy();
private:
	Mylog();
	~Mylog();
	PatternLayout *ptnLayout1;
	PatternLayout *ptnLayout2;
	OstreamAppender *pOsAppender;
	RollingFileAppender *rollingFileAppender;
	Category &root;
	static Mylog *_pMylog;
};

Mylog::Mylog()
	:root(Category::getRoot())
{
	ptnLayout1 = new PatternLayout();
	ptnLayout1->setConversionPattern("%d{%Y-%m-%d %H:%M:%S} [%p] :%m%n");
	ptnLayout2 = new PatternLayout();
	ptnLayout2->setConversionPattern("%d{%Y-%m-%d %H:%M:%S} [%p] :%m%n");
	pOsAppender = new OstreamAppender("pOsAppender",&cout);
	pOsAppender->setLayout(ptnLayout1);
	rollingFileAppender = new RollingFileAppender("rollingFileAppender","rollwd.log",1024 * 5,5);
	rollingFileAppender->setLayout(ptnLayout2);
	root.setAppender(pOsAppender);
	root.setAppender(rollingFileAppender);
	root.setPriority(Priority::DEBUG);
	cout<<"Mylog()"<<endl;
}

Mylog::~Mylog()
{
	root.shutdown();
	cout<<"~Mylog()"<<endl;
}

Mylog * Mylog::_pMylog = NULL;

Mylog * Mylog::getInstance()
{
	if(_pMylog == NULL)
	{
		_pMylog = new Mylog();
	}
	return _pMylog;
}

void Mylog::destroy()
{
	if(_pMylog!=NULL)
	{
		delete _pMylog;
		_pMylog = NULL;
		cout<<"space freed..."<<endl;
	}
	cout<<"destoryed..."<<endl;
}

void Mylog::warn(const char *msg)
{
	root.warn(msg);
}

void Mylog::info(const char *msg)
{
	root.info(msg);
}

void Mylog::error(const char *msg)
{
	root.error(msg);
}

void Mylog::debug(const char *msg)
{
	root.debug(msg);
}

int main(void)
{
	Mylog *log = Mylog::getInstance();

	Warn("this is a warn test");
	Info("this is a info test");
	Error("this is a error test");
	Debug("this is a debug test");
	
	Mylog::destroy();
}
