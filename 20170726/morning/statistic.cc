#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
 
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::stringstream;

typedef struct
{
	string word;
	int num;
}words;

class WordStatistic
{
public:
	void readFile(const string filename);
	void writeFile(const string filename);
private:
	vector<words> wvec;
};

void WordStatistic::readFile(const string filename)
{
	ifstream ifs(filename);
	if(!ifs.good())
	{
		cout<<"istream open file failed!"<<endl;
		return;
	}
	string line;
	while(getline(ifs,line))
	{
		stringstream ss(line);
		string word;
		while(ss>>word)
		{
			size_t idx;
			for(idx = 0;idx != wvec.size(); ++idx)
			{
				if(wvec[idx].word == word)
				{
					++wvec[idx].num;
					break;
				}
			}
			if(idx == wvec.size())
			{
				words wd;
				wd.word = word;
				wd.num = 1;
				wvec.push_back(wd);
			}
		}
	}
	ifs.close();
}

//错误！！find 不能这样用！！！
#if 0
void WordStatistic::readFile(const string filename)
{
	ifstream ifs(filename);
	if(!ifs.good())
	{
		cout<<"istream open file failed!"<<endl;
		return;
	}
	string line;
	while(getline(ifs,line))
	{
		stringstream ss(line);
		string word;
		while(ss>>word)
		{
			vector<words>::iterator witer;
			witer=find(wvec.begin(),wvec.end()-1,word);
			if(witer==wvec.end())
			{
				words wd;
				wd.word = word;
				wd.num = 1;
				wvec.push_back(wd);
			}else
				witer->num++;
		}
	}
	ifs.close();
}
#endif

void WordStatistic::writeFile(const string filename)
{
	ofstream ofs(filename);
	if(!ofs.good())
	{
		cout<<"ofstream open file failed!"<<endl;
		return;
	}
	vector<words>::iterator witer;
	for(witer=wvec.begin();witer!=wvec.end();++witer)
	{
		ofs << witer->word <<" "<<witer->num<<endl;
	}
	ofs.close();
}

int main(void)
{
	WordStatistic wd;
	wd.readFile("The_Holy_Bible.txt");
	wd.writeFile("test.txt");

	return 0;
}
