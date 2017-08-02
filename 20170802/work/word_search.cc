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

class WordSearch
{
public:
	void readFile(const string filename)
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
			_lineVec.push_back(line);
			stringstream s(line);
			while(s >> word)
			{
				++_wordCount[word];
				_wordLine[word].insert(lineCount);
			}
		}
	}

	void findWord(string word)
	{
		auto time = _wordCount.find(word);
		if(time == _wordCount.end())
			cout<<"cannot find that word!"<<endl;
		else
			cout<<((time->second>1) ? "times:":"time:")<<time->second<<endl;
		set<int>::const_iterator it;
		for(it = _wordLine[word].begin();it != _wordLine[word].end(); ++it)
		{
			cout<<"<line:"<<*it<<"> ";
			cout<<_lineVec[*it-1]<<endl;
		}
	}

private:
	vector<string> _lineVec;
	map<string,int> _wordCount;
	map<string,set<int> > _wordLine;
};
 
int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		cout<<"error args!"<<endl;
		return -1;
	}
	WordSearch ws;
	ws.readFile(argv[1]);
	ws.findWord(argv[2]);
	
	return 0;
}
