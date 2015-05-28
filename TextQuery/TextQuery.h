#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <memory>
#include <sstream>
#include <algorithm>
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
	QueryResult(const QueryResult& s);
	QueryResult& operator=(const QueryResult&);
	shared_ptr<vector<string>> get_file()
	{
		return file;
	}
	set<line_no>::iterator begin()
	{
		return lines->begin();
	}
	set<line_no>::iterator end()
	{
		return lines->end();
	}
	friend ostream& print(ostream&, const QueryResult&);
};

//这是一个抽象基类，具体的查询类型从中派生，所有成员都是private的
class Query_base
{
	friend class Query;
protected:
	//using line_no = vector<string>::size_type;
	virtual ~Query_base() = default;
private:
	//eval 返回与当前Query匹配的QueryResult ,纯虚函数
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual string rep() const = 0;
};

//这是一个管理Query_base继承体系的接口类 , 在Query_base中被声明为友类
class Query
{
private:
	shared_ptr<Query_base> q;
	Query(shared_ptr<Query_base> query):q(query) {}
private:
	//这些运算符需要访问接收shared_ptr的构造函数，而该函数是私有的
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);
public:
	Query(const string&); //构建一个新的WordQuery
	//接口函数调用对应的Query_base操作
	QueryResult eval(const TextQuery& t) const
	{q->eval(t);}
	string rep() const
	{return q->rep();}
};

ostream& operator<<(ostream& os, const Query &query)
{
	//Query::rep通过它的Query_base指针对rep()进行了虚调用
	return os << query.rep();
}

class WordQuery: public Query_base
{
	friend class Query;   //Query 使用WordQuery类构造函数
private:
	string query_word;    //要查找的单词
	WordQuery(const string &s):query_word(s){}
	//具体的类：WordQuery将定义所有继承而来的纯虚函数
	QueryResult eval(const TextQuery& t) const override
	{
		return t.query(query_word);
	}

	string rep() const  override
	{
		return query_word;
	}

};

//Query类的一个接受实参的构造函数，使用WordQuery类的构造函数定义一个WordQuery对象
inline 	Query::Query(const string& s):q(new WordQuery(s)) {}

class NotQuery: public Query_base
{
	friend Query operator~(const Query &);
	Query query;
	
	NotQuery(const Query &q):query(q){}
	//eval 函数比较复杂在外部定义
	QueryResult eval(const TextQuery &t) const override;
	string rep() const  override
	{
		return "~("+query.rep()+")";
	}


};

inline Query operator~(const Query &operand)
{
	return shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery: public Query_base
{
protected:
	Query lsh, rsh;  //左侧右侧运算符
	string opSym;    //运算符的名字

	BinaryQuery(const Query &l, const Query &r, const string &s):
				lsh(l), rsh(r), opSym(s){}
	string rep() const  override
	{
		return "(" + lsh.rep() + " "
			    + opSym + " " + rsh.rep() + ")"; 
	}
};

class AndQuery: public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query& left, const Query& right):
			BinaryQuery(left, right, "&"){}
	QueryResult eval(const TextQuery&) const override; 
};

inline Query operator&(const Query &left, const Query &right)
{
	return shared_ptr<Query_base>(new AndQuery(left, right));
}

class OrQuery: public BinaryQuery
{
	friend Query operator|(const Query &, const Query&);
	OrQuery(const Query &left, const Query &right):
			BinaryQuery(left, right, "|"){}
	QueryResult eval(const TextQuery&) const override;
};

inline Query operator|(const Query &left, const Query &right)
{
	return shared_ptr<Query_base>(new OrQuery(left, right));
}

