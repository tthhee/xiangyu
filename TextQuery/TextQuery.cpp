#include "TextQuery.h"


TextQuery::TextQuery(ifstream& infile):file(new vector<string>)
{
	string text;
	while(getline(infile, text)) //对文件中的每一行
	{
		file->push_back(text); //保存一行文本
		int n = file->size()-1; //记录行号
		istringstream line(text); //分配一个字符串流
		string word;
		while(line >> word)   //提取一行字符串中的没一个单词
		{
			auto &lines = wm[word];  //lines 的类型为mapped_type是一个shared_ptr，指向set<line_no>
			if(!lines)                //如果word在wm中不存在，则lines是一个空指针
			{
				lines.reset(new set<line_no>);        //如果不存在，为lines分配一个set空间,并用reset使lines指向新分配的set
			}
			lines->insert(n);        //将行号插入到对应word的set中
		}
	}
}
QueryResult TextQuery::query(const string& word) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>); //如果未找到word，就返回这个指针
	auto loc = wm.find(word);
	if(loc == wm.end())
	{
		return QueryResult(word, file, nodata); //未找到
	}
	else
	{
		return QueryResult(word, file, loc->second);
	}

	
}
QueryResult::QueryResult(const QueryResult& s)
{
	sought = s.sought;
	file = make_shared<vector<string>>();
	copy(s.file->begin(), s.file->end(), file->begin());
	lines = make_shared<set<line_no>>();
	copy(s.lines->begin(), s.lines->end(), lines->begin());
}
ostream& print(ostream &os, const QueryResult& qr)
{
	os << qr.sought << " occurs " << qr.lines->size()
	   << "times:" << endl;
	for(auto it : *qr.lines)
	{
		cout << "\t (line " << it+1 << ") ";
		cout << *(qr.file->begin() + it) <<endl;
	}
	return os;
}
void runQueries(ifstream& infile)
{
	//infile 是一个ifstream，指向我们要处理的文件
	TextQuery tq(infile);  //保存文件并建立map
	//与用户交互：提示用户要输入的单词，完成查询并打印结果
	while(true)
	{
		cout << "enter word to look for or 'q' to quit: ";
		string s;
		if(!(cin >> s) || s == "q")
			break;
		else
			print(cout, tq.query(s)) << endl;
	}
}
int main()
{

	ifstream infile("TextQuery.txt");
	runQueries(infile);
	return 0;
}