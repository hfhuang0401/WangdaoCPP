#include <iostream>
#include <string>
#include <fstream>
#include <map>
 
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::ifstream;
using std::ofstream;

class WordStatistic
{
public:
	void readFile(const string filename);
	void writeFile(const string filename);

private:
	map<string,size_t> word_count;
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
	string word;
	while(fin>>word)
	{
			++word_count[word];
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

	map<string,size_t>::const_iterator it;
	for(it = word_count.begin(); it != word_count.end(); ++it)
	{
		fout<<it->first<<" "<<it->second<<endl;
	}

	fout.close();
}

int main(void)
{
	WordStatistic ws;
	ws.readFile("/home/hhf/class_cpp/20170801/work/The_Holy_Bible.txt");
	ws.writeFile("./word_count.txt");
}
