#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
 
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::stringstream;

class Word
{
public:
	Word(string name,int count)
		:_name(name)
		,_count(count)
	{
	}
	string _name;
	int _count;
};

class WordStatistic
{
public:
	void readFile(const string filename);
	void writeFile(const string filename);

private:
	vector<Word> ws;
};

void WordStatistic::readFile(const string filename)
{
	ifstream fin;
	fin.open(filename);
	if(!fin.good())
	{
		cout<<"ifstream open file failed!"<<endl;
		return;
	}
	map<string,size_t> word_count;
	stringstream ss;
	string line;
	string word;
	while(getline(fin,line))
	{
		ss << line;
		while(!ss.eof())
		{
			ss >> word;
			++word_count[word];
		}
		ss.clear();
		ss.str("");
	}
	for(const auto &w : word_count)
	{
		ws.push_back(Word(w.first,w.second));
	}

	fin.close();
}

void WordStatistic::writeFile(const string filename)
{
	ofstream fout;
	fout.open(filename);
	if(!fout.good())
	{
		cout<<"ofstream open file failed"<<endl;
		return;
	}
	vector<Word>::iterator iter;
	for(iter = ws.begin();iter != ws.end();++iter)
	{
		fout << iter->_name<<" "<<iter->_count<<endl;
	}
	
	fout.close();
}

int main(void)
{
	WordStatistic ws;
//	ws.readFile("test.txt");
	ws.readFile("/home/hhf/class_cpp/20170724/work/The_Holy_Bible.txt");
	ws.writeFile("./word_count.txt");
}
