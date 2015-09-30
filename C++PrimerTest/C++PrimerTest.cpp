#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

struct CModel
{
private:
	int a;
	string str;
public:
	CModel()
	{
		cout << "CModel()" << endl;
		a = 0;
		str = " ";
	}
	CModel(int i, string s):a(i), str(s)
	{
		cout << "CModel(i, s)" << endl; 
	}
	CModel(const CModel& m)
	{
		cout << "CModel(const CModel&)" << endl;
		a = m.a;
		str = m.str;
	}
	void print()
	{
		cout << "a: " << a << endl;
		cout << "str: " << str << endl;
	}
	CModel& operator=(CModel& s)
	{
		a = s.a;
		str = s.str;
		cout << "using operator=" << endl;
	}

	~CModel()
	{
		cout << "using ~CModel()" << endl;
	}
};

void showCModel(CModel& obj)
{
	obj.print();
}
int main()
{
	CModel object(2, "xiangyu");
	CModel object2(3, "liuchang");
//	shared_ptr<CModel> cp = make_shared<CModel>(object);
	vector<CModel> 	Cvec;
	Cvec.push_back(object);
	Cvec.push_back(object2);
	Cvec.push_back(object2);
	Cvec.push_back(object);
	cout << "size: " << Cvec.size() << "maxsize: " << Cvec.max_size() << endl;
	for(auto it : Cvec)
	{
		it.print();
	}

//	showCModel(*cp);
	return 0;
}

