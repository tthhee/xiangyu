#include "exercise13.5StrVec.h"

void StrVec::push_back(const string& s)
{
	chk_n_alloc();  //确保有足够空间容纳新元素
	alloc.construct(firstfree++, s);  //构造新元素
}

pair<string*, string*> StrVec::alloc_n_copy(const string* s1, const string* s2)
{
	auto data = alloc.allocate(s2-s1);
	return {data, uninitialized_copy(s1, s2, data)};
}

/**
*free()
*首先销毁元素， 然后释放所有内存
*/
void StrVec::free()
{
	if(elements)
	{
		// for(auto p = firstfree; p!=elements;)
		// 	alloc.destroy(--p);
		for_each(elements, firstfree, [this](string& str){alloc.destroy(&str);});
		alloc.deallocate(elements, cap-elements);
	}
}
StrVec::StrVec(const StrVec& str)
{
	auto temp = alloc_n_copy(str.begin(), str.end());
	elements = temp.first;
	firstfree = cap = temp.second;
}

/**
*StrVec(initializer_list<string> strlist)
*使用初始化列表的构造函数
*/
StrVec::StrVec(initializer_list<string> strlist)
{
	auto newcapacity = strlist.size()*2;
	auto data = alloc.allocate(newcapacity);
	auto fisfree = uninitialized_copy(strlist.begin(), strlist.end(), data);
	elements = data;
	firstfree = fisfree;
	cap = elements + newcapacity;
}
StrVec& StrVec::operator=(const StrVec& rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	firstfree = cap = data.second;
	return *this;
}
StrVec::~StrVec()
{
	free();
}
/**
*reallocate()
*
*/
void StrVec::reallocate()
{
	auto newcapacity = size() ? size()*2:1;
	auto newdata = alloc.allocate(newcapacity);

	auto dest = newdata;
	auto elem = elements;
	for(size_t i=0; i<size(); i++)
	{
		alloc.construct(dest++, std::move(*elem++));
	}

	free();
	elements = newdata;
	firstfree = dest;
	cap = elements + newcapacity;
	
}

void StrVec::reserve(size_t n)
{
	size_t old_capacity = capacity();
	if(n > old_capacity)
	{
		auto newcapacity = n;
		auto newdata = alloc.allocate(newcapacity);

		auto dest = newdata;
		auto elem = elements;
		for(size_t i=0; i<size(); i++)
		{
			alloc.construct(dest++, std::move(*elem++));
		}

		free();
		elements = newdata;
		firstfree = dest;
		cap = elements + newcapacity;
	}
}

void StrVec::resize(size_t n)
{
	if(n > capacity())
	{
		
		throw out_of_range("out of range!");
		return;
		
	}

	else if(n>size())
	{
		auto count = n - size();
		uninitialized_fill_n(firstfree, count, "");
	}
}

void StrVec::resize(size_t n, string str)
{
	if(n > capacity())
	{
	
		throw out_of_range("out of range!");
		return;
	}

	else if(n>size())
	{
		auto count = n - size();
		uninitialized_fill_n(firstfree, count, str);
	}
}

int main()
{
	StrVec test{"xianguy", "love", "liuchang"};
	test.push_back("xiangyu");
	 test.push_back("liuchang");
	 cout << "capacity: " << test.capacity() << endl;
	 cout << "size: " << test.size() << endl;
	 for(auto it=test.begin(); it !=test.end(); it++)
	 {
	 	cout << *it << endl;
	 }
	return 0;
}