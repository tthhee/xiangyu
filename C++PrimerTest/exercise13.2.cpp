#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;
//定义行为像值的类
class HasPtr
{
private:
	string* ps;
	int i;
	
public:
	HasPtr(const string& s = string(), int a = 0): 
		ps(new string(s)), i(a){}
	HasPtr(const HasPtr& s):
		ps(new string(*s.ps)), i(s.i){}
	HasPtr& operator=(const HasPtr& p);
    friend bool lessthan(const HasPtr& s1, const HasPtr& s2);
	friend ostream& operator<<(ostream& os, const HasPtr& P);
	friend void swap(HasPtr& , HasPtr&);
	~HasPtr()
	{
		delete ps;
	}
};
bool lessthan(const HasPtr& s1, const HasPtr& s2)
{
	if(s1.i < s2.i)
	{
		return true;
	}
	else
	{
		return false;
	}
}
ostream& operator<<(ostream& os, const HasPtr& p)
{
	os << *p.ps << " " << p.i;
}
HasPtr& HasPtr::operator=(const HasPtr& p)
{
	i = p.i;
	auto temp = new string(*p.ps);
	delete ps;
	ps = temp;
	return *this;
}

inline void swap(HasPtr& lsh, HasPtr& rsh)
{
	using std::swap;
	swap(lsh.ps, rsh.ps);
	swap(lsh.i, rsh.i);
	cout << "using swap()" << endl;
}
//定义行为像指针的类
class PHasPtr
{
private:
	int i;
	string* ps;
	size_t *use;  //记录有多少个对象共享ps成员
public:
	PHasPtr(const string& s = string()):
		i(0), ps(new string(s)), use(new size_t(1)){}
	PHasPtr(const PHasPtr& p):
		i(p.i), ps(p.ps), use(p.use) {*use++;}
	PHasPtr& operator=(const PHasPtr& s);
	~PHasPtr()
	{
		*use--;
		if(*use == 0)
		{
			delete ps;
			delete use;
		}
	}
};

PHasPtr& PHasPtr::operator=(const PHasPtr& s)
{
	i = s.i;
	if(--*use == 0)
	{
		delete ps;
		delete use;
	}
	*(s,use)++;
	ps = s.ps;
	use = s.use;
	return *this;
}

class TreeNode
{
private:
	string value;
	int count;
	TreeNode *left;
	size_t *leftnum;
	TreeNode *right;
	size_t *rightnum;
public:
	TreeNode():
		value(nullptr), count(0), left(nullptr), right(nullptr),leftnum(new size_t(1)), rightnum(new size_t(1)){}
	TreeNode(const TreeNode& t):
		value(t.value), count(t.count), left(t.left), leftnum(t.leftnum), right(t.right), rightnum(t.rightnum)
		{
			*leftnum++;
			*rightnum++;
		}
	~TreeNode()
	{
		*leftnum--;
		*rightnum--;
		if(*leftnum == 0)
		{
			delete left;
			delete leftnum;
		}
		if(*rightnum == 0)
		{
			delete right;
			delete rightnum;
		}
	}
};
int main()
{
	HasPtr a("xiangyu", 2);
	HasPtr b("liuchang", 1);
	HasPtr c("liuzheng", 3);
	swap(a, b);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	vector<HasPtr> HasVec;
	HasVec.push_back(a);
	HasVec.push_back(b);
	HasVec.push_back(c);
	sort(HasVec.begin(), HasVec.end(), lessthan);
	for(auto it : HasVec)
	{
		cout << it << endl;
	}

	return 0;
}