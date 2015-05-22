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
QueryResult& QueryResult::operator=(const QueryResult& s)
{
	sought = s.sought;
	auto tempfile = make_shared<vector<string>>();
	copy(s.file->begin(), s.file->end(), tempfile->begin());
	auto templines = make_shared<set<line_no>>();
	copy(s.lines->begin(), s.lines->end(), templines->begin());
	file = tempfile;
	lines = templines;
	return *this;

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

/**
*各个类的eval函数
*/
//OrQuery::eval()
QueryResult OrQuery::eval(const TextQuery& text) const
{
	//通过Query成员lsh和rsh进行虚调用
	//调用eval返回每个运算对象的QueryResult
	auto left = lsh.eval(text),  right = rsh.eval(text);
	//将左侧运算对象的行号拷贝到结果set中
	auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
	//插入右侧运算对象所得的行号
	ret_lines->insert(right.begin(), right.end());
	//返回一个新的QueryResult，它表示lsh,rsh的并集
	return QueryResult(rep(), left.get_file(), ret_lines);
}
//AndQuery::eval()
QueryResult AndQuery::eval(const TextQuery& text) const
{
	//通过Query运算对象的虚调用，以获得运算对象的查询结果set
	auto left=lsh.eval(text), right = rsh.eval(text);
	//保存left和right的交集的set
	auto ret_lines = make_shared<set<line_no>>();
	//将两个范围的交集写入一个目的迭代器中
	//本次调用的目的迭代器向ret添加元素
	set_intersection(left.begin(), left.end(), 
					 right.begin(), right.end(),
					 inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), left.get_file(), ret_lines);
}
//NotQuery::eval()
QueryResult NotQuery::eval(const TextQuery& text) const
{
	//通过Query运算对象对eval进行虚调用
	auto result = query.eval(text);
	//开始时结果set为空
	auto ret_lines = make_shared<set<line_no>>();
	//必须在运算对象出现的所有行中进行迭代
	auto beg = result.begin(), end = result.end();
	//对于输入文件的每一行，如果改行不在result当中，则将其添加到ret_lines中
	auto sz = result.get_file()->size();
	for(size_t n=0; n!=sz; n++)
	{
		//如果还没有处理完result的所有行
		//检查当前行是否存在
		if(beg==end || *beg != n)
		{
			ret_lines->insert(n);
		}
		else if(beg != end)
		{
			beg++;
		}
	}
	return QueryResult(rep(), result.get_file(), ret_lines);
}


int main()
{

	ifstream infile("TextQuery.txt");
	TextQuery tq(infile);
//	runQueries(infile);
	Query q = Query("fiery") & Query("bird") | Query("wind");
	 QueryResult QR = q.eval(tq);
	 print(cout, QR);
	return 0;
}