#include <iterator>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>

using std::cin;
using std::map;
using std::set;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ostream;
using std::ifstream;
using std::inserter;
using std::shared_ptr;
using std::istringstream;

class QueryResult;
class TextQuery
{
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream&);
	QueryResult query(const string&)const;
private:
	shared_ptr<vector<string>> file;//输入文件
	map<string,shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is)
:file(new vector<string>)
{
	string text;
	while(getline(is,text))//对文件中每一行
	{
		file->push_back(text);//保存此行文本
		int n = file->size() - 1;//当前行号
		istringstream line(text);//将文本分解为单词
		string word;
		while(line >> word)
		{
			//如果单词不在wm中，以之为下标在wm中添加一项
			auto &lines = wm[word];//lines是一个shared_ptr
			if(!lines)//第一次遇到此单词时，指针为空
				lines.reset(new set<line_no>);//分配一个新的set
			lines->insert(n);//将此行号插入set中,同一行只会执行一次
		}
	}
}

class QueryResult
{
friend ostream & print(ostream &,const QueryResult &);

public:
	using line_no = vector<string>::size_type;
	using ResultIter = set<line_no>::iterator;
	QueryResult(string s,shared_ptr<set<line_no>> p,shared_ptr<vector<string>> f)
	:sought(s)
	,lines(p)
	,file(f)
	{}

	shared_ptr<vector<string>> get_file()const
	{
		return file;
	}

	ResultIter begin()const
	{
		return lines->begin();
	}

	ResultIter end()const
	{
		return lines->end();
	}

private:
	string sought;//查询单词
	shared_ptr <set<line_no>> lines;//出现的行号
	shared_ptr <vector<string>> file;//输入文件
};

QueryResult TextQuery::query(const string &sought) const
{
	//如果未找到sought,将返回一个指向此set的指针
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	//使用find而不是下标运算符来查找单词，避免将单词添加到wm中
	auto loc = wm.find(sought);
	if(loc == wm.end())
		return QueryResult(sought,nodata,file);//未找到
	else
		return QueryResult(sought,loc->second,file);
}

string make_plural(size_t ctr,const string &word, const string &ending)
{
  return (ctr==1) ? word : word+ending;//make_plural(wc, "word ", "s ")当输入中文本中
                                            //word数大于一是在word后加s，为words为word的复数！
}

ostream &print(ostream &os,const QueryResult &qr)
{
	os << qr.sought <<" occurs "<<qr.lines->size() 
	   <<" "<<make_plural(qr.lines->size(),"time","s")<<endl;
	for(auto num : *qr.lines)//对set中每个单词
	{
		os << "<line "<<num + 1<<"> "
		   << *(qr.file->begin() + num)<<endl;
	}

	return os;
}

class Query_base
{
	friend class Query;

protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;

private:
	//eval返回当前Query匹配的QueryResult
	virtual QueryResult eval(const TextQuery &)const = 0;
	//rep是表示查询的一个string
	virtual string rep()const = 0;
};

//管理Query_base继承体系的接口类
class Query
{
//这些运算符需要访问接受shared_ptr的构造函数，而该函数是私有的
friend Query operator ~ (const Query &);
friend Query operator | (const Query &,const Query &);
friend Query operator & (const Query &,const Query &);

public:
	Query(const string &);//构建一个新的WordQuery
	//接口函数：调用对应的Query_base操作
	QueryResult eval(const TextQuery &t) const
	{
		return q->eval(t); 
	}

	string rep() const
	{
		return q->rep();
	}

private:
	Query(shared_ptr<Query_base> query)
	:q(query)
	{}
	shared_ptr<Query_base> q;
};

class WordQuery
:public Query_base
{
	friend class Query;
	
	//具体的类：WordQuery将定义所有继承而来的纯虚函数
	WordQuery(const string &s)
	:query_word(s)
	{}

	string rep() const
	{
		return query_word;
	}
	
	QueryResult eval(const TextQuery & t)const
	{
		return t.query(query_word);
	}

	string query_word;//要查找的单词
};

//Query的构造函数
inline Query::Query(const string &s)
:q(new WordQuery(s))
{}//分配一个WordQuery,令其指针成员指向新分配的对象

class NotQuery
:public Query_base
{
	friend Query operator~(const Query &);
	NotQuery(const Query &q)
	:query(q)
	{}//具体的类：NotQuery将定义所有继承而来的纯虚函数
	string rep() const
	{
		return "~("+query.rep()+")";
	}
	
	QueryResult eval(const TextQuery &)const;

	Query query;
};

inline Query operator ~ (const Query & operand)
{
	return shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery
:public Query_base
{
protected:
	BinaryQuery(const Query &l,const Query &r,string s)
	:lhs(l)
	,rhs(r)
	,opSym(s)
	{}//抽象类：BinaryQuery不定义eval

	string rep() const
	{
		return "("+lhs.rep()+" "+opSym+" "+rhs.rep()+")";
	}

	Query lhs,rhs;//左侧和右侧运算对象
	string opSym;//运算符的名字
};

class AndQuery
:public BinaryQuery
{
	friend Query operator & (const Query &,const Query &);

	AndQuery(const Query &left,const Query &right)
	:BinaryQuery(left,right,"&")
	{}

	//具体的类：AndQuery继承了rep并且定义了其他纯虚函数
	QueryResult eval(const TextQuery&) const;
};

inline Query operator & (const Query &lhs,const Query &rhs)
{
	return shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}

class OrQuery
:public BinaryQuery
{
	friend Query operator | (const Query&,const Query&);

	OrQuery(const Query &left,const Query &right)
	:BinaryQuery(left,right,"|")
	{}

	QueryResult eval(const TextQuery&) const;
};

inline Query operator | (const Query &lhs,const Query &rhs)
{
	return shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}

QueryResult OrQuery::eval(const TextQuery &text) const
{
	//通过Query成员lhs和rhs进行虚调用
	//调用eval返回每个运算对象的QueryResult
	auto right = rhs.eval(text),left = lhs.eval(text);

	//将左侧运算对象的行号拷贝到结果set中
	auto ret_lines = std::make_shared<set<line_no>>(left.begin(),left.end());
	
	//插入右侧运算对象所得的行号
	ret_lines->insert(right.begin(),right.end());

	//返回一个新的QueryResult,它表示lhs和rhs的并集
	return QueryResult(rep(),ret_lines,left.get_file());
}

QueryResult AndQuery::eval(const TextQuery &text) const
{
	//通过Query运算对象进行虚调用，以获得运算对象的查询结果set
	auto left = lhs.eval(text),right = rhs.eval(text);

	//保存left和right交集的se;t
	auto ret_lines = std::make_shared<set<line_no>>();
	
	//将两个范围的交集写入一个目的迭代器中
	//本次调用的目的迭代器向ret添加元素
	
	set_intersection(left.begin(),left.end(),right.begin(),right.end(),inserter(*ret_lines,ret_lines->begin()));

	return QueryResult(rep(),ret_lines,left.get_file());
}

//返回运算对象的结果set不存在的行
QueryResult NotQuery::eval(const TextQuery &text) const
{
	//通过Query运算对象对eval进行虚调用
	auto result = query.eval(text);

	//开始时结果set为空
	auto ret_lines = std::make_shared<set<line_no>>();

	//必须在运算对象出现的所有行中进行迭代
	auto beg = result.begin(),end = result.end();

	//对于输入文件的每一行，如果该行不在result当中，则将其添加到ret_lines
	auto sz = result.get_file()->size();

	for(size_t n = 0;n != sz; ++n)
	{
		//如果我们还没有处理完result的所有行
		//检查当前行是否存在
		if(beg==end || *beg != n)
			ret_lines->insert(n);//如果不在result当中，添加这一行
		else if(beg != end)
			++beg;//否则继续获取result的下一行(如果有)
	}

	return QueryResult(rep(),ret_lines,result.get_file());
}

ostream & operator << (ostream & os,const Query & query)
{
	//Quert::rep通过它的Query_base指针对rep()进行了虚调用
	return os <<query.rep();
}

void runQueries(ifstream & infile)
{
	//infile是一个ifstream，指向我们要处理的文件
	TextQuery tq(infile);//保存文件并建立查询map

	while(true)
	{
		cout<<"enter word to look for,or q to quit: ";
		string s;//若遇到文件尾或用户输入了'q'时循环终止
		if(!(cin >> s) || s=="q")
			break;
		print(cout,tq.query(s)) << endl ;
	}
}

#if 0
int main(void)
{
	//ifstream ifs("china_daily.txt");
	//runQueries(ifs);
	Query q = Query("fiery")&Query("bird")|Query("wind");
	cout<<q;

	return 0;
}
#endif

int main(void)
{
	ifstream is("china_daily.txt");
	TextQuery t1(is);
	string word;
//	Query q = Query("link") & Query("will") | Query("people");
	Query o("will");
	Query p("people");
	Query q = Query("will") | Query("people");
	cout << o <<endl;
	cout << p <<endl;
	cout << q << endl;
	cout<<"------------------"<<endl;
	print(cout,o.eval(t1));
	cout<<"##################"<<endl;
	print(cout,p.eval(t1));
	cout<<"##################"<<endl;
	print(cout,q.eval(t1));

	return 0;
}
