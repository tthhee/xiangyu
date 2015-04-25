#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <memory>
#include <sstream>
using namespace std;
using line_no = vector<string>::size_type;
class QueryResult;
class TextQuery
{
public:
	
	TextQuery(ifstream &infile);
	QueryResult query(const string &word) const;
private:
	//定义输入文件的智能指针
	shared_ptr<vector<string>> file;
	//每个单词到它所在行号的集合的映射
	map<string, shared_ptr<set<line_no>>> wm;
}; 
class QueryResult
{
private:
	string sought;  //查询的单词
	shared_ptr<vector<string>> file;  //指向查询文件的指针
	shared_ptr<set<line_no>> lines;   //指向行号的指针
public:
	QueryResult(string s, shared_ptr<vector<string>> p, shared_ptr<set<line_no>> l):sought(s), file(p), lines(l){}
	friend ostream& print(ostream&, const QueryResult&);


};