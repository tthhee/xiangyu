#include <iostream>
#include <string>
#include <memory>

using namespace std;
//定义行为像值的类
class HasPtr
{
private:
	int i;
	string* ps;
public:
	HasPtr(const string& s = string()): 
		ps(new string(s)), i(0){}
	HasPtr(HasPtr& s):
		ps(new string(*s.ps)), i(s.i){}
	HasPtr& operator=(const HasPtr& p);
	~HasPtr()
	{
		delete ps;
	}
};

HasPtr& HasPtr::operator=(const HasPtr& p)
{
	i = p.i;
	auto temp = new string(*p.ps);
	delete ps;
	ps = temp;
	return *this;
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
	return 0;
}