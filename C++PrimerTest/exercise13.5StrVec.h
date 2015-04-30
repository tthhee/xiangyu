#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>

using namespace std;
//allocator<string> alloc; 
class StrVec
{
private:
	string* elements;  //指向分配内存中的首元素
	string* firstfree; //指向最后一个实际元素之后的位置
	string* cap;	   //指向分配的内存末尾之后的位置
	allocator<string> alloc;   //分配元素
	void chk_n_alloc()
	{
		if(size() == capacity()) 
			reallocate();
	}
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();
	void reallocate();
public:
	StrVec():
		elements(nullptr), firstfree(nullptr), cap(nullptr) {}
	StrVec(initializer_list<string> strlist);
	StrVec(const StrVec&);  //拷贝构造函数
	StrVec& operator=(const StrVec&); //赋值构造函数
	~StrVec();
	void push_back(const string&);
	size_t size()
	{return (firstfree - elements);}
	size_t capacity()
	{return (cap - elements);}
	string* begin() const
	{
		return elements;
	}
	string* end() const
	{
		return firstfree;
	}
	void reserve(size_t n);
	void resize(size_t n);
	void resize(size_t n, string str);


};