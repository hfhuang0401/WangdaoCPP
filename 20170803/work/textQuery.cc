#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::set;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::stringstream;

class TextQuery
{
public:
	void readFile(const string filename);
	void query(const string & word);

private:
	vector<string> _lines;
	map<string,set<int> > _word2Line;
	map<string,int> _wordFreq;
};

void TextQuery::readFile(const string filename)
{
	ifstream fin;
	fin.open(filename);
	if(!fin.good())
	{
		cout<<"open file failed!"<<endl;
		return;
	}

	string line;
	string word;
	int lineCount = 0;

	while(getline(fin,line))
	{
		++lineCount;
		_lines.push_back(line);
		stringstream s(line);
		while(s >> word)
		{
			++_wordFreq[word];
			_word2Line[word].insert(lineCount);
		}
	}
}

void TextQuery::query(const string & word)
{
	auto time = _wordFreq.find(word);
	if(time == _wordFreq.end())
		cout<<"cannot find that word!"<<endl;
	else
		cout<<((time->second>1) ? "times:":"time:")<<time->second<<endl;
	for(auto it = _word2Line[word].begin();it != _word2Line[word].end(); ++it)
	{
		cout<<"<line:"<<*it<<"> ";
		cout<<_lines[*it-1]<<endl;
	}
}

int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		cout<<"error args!"<<endl;
		return -1;
	}
	TextQuery ws;
	ws.readFile(argv[1]);
	ws.query(argv[2]);

	return 0;
}
