#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <memory>
using namespace std;

class Quote
{
private:
	string bookNo;    //书籍的ISBN编号

protected:
	double price = 0.0;   //代表普通状态下不打折的价格
public:
	Quote() = default;
	Quote(const string isbn, double pri):
		bookNo(isbn), price(pri) {}
	//拷贝构造函数
	Quote(const Quote& d);
	//拷贝复制运算符
	Quote& operator=(const Quote&);

	//该虚函数返回当前对象的一份动态分配的拷贝
	virtual Quote* clone() const & {return new Quote(*this);}
	virtual Quote* clone() && {return new Quote(std::move(*this));}
	//返回给定数量的书籍的销售总额
	//派生类负责改写并使用不同的折扣算法
	virtual double net_price(size_t n) const    
	{
		return n*price;
	}

	string isbn() const         
	{
		return bookNo;
	}
	virtual ~Quote();   //对析构函数进行动态绑定
};


// class Bulk_quote: public Disc_quote
// {
// private:
// 	size_t min_qty = 0;   //获得折扣的最小购买数量
// 	double discount = 0.0;  //折扣
// public:
// 	Bulk_quote() = default;
// 	Bulk_quote(const string isbn, double pri, size_t min_num, double disc):
// 		Quote(isbn, pri), min_qty(min_num), discount(disc) {}

// 	//重写此函数以覆盖基类中的此函数
// 	double net_price(size_t n) const override;
// 	~Bulk_quote(){}
// };

class Disc_quote:public Quote
{
//	using Quote::Quote;
protected:
	size_t quantity = 0;
	double discount = 0.0;
public:
	Disc_quote() = default;
	Disc_quote(const string isbn, double pri, size_t qty, double disc):
		Quote(isbn, pri), quantity(qty), discount(disc){}
	//拷贝构造函数
	Disc_quote(const Disc_quote&);
	//拷贝复制运算符
	Disc_quote& operator=(const Disc_quote&);

	double net_price(size_t n) const = 0; //纯虚函数，函数定义必须放在外面
	~Disc_quote();
};

class Bulk_quote: public Disc_quote
{
//	using Disc_quote::Disc_quote;
public:
	Bulk_quote() =default;
	Bulk_quote(const string isbn, double pri, size_t min_num, double disc):
		Disc_quote(isbn, pri, min_num, disc) {}
	//拷贝构造函数
	Bulk_quote(const Bulk_quote&);
	Bulk_quote& operator=(const Bulk_quote&);

	Bulk_quote* clone() const & {return new Bulk_quote(*this);}
	Bulk_quote* clone() && {return new Bulk_quote(std::move(*this));}
	//重写此函数以覆盖基类中的此函数
	double net_price(size_t n) const override;
	~Bulk_quote();
};

class Basket
{
private:

	//排序规则，用于multiset中的排序规则
	static bool compare(const shared_ptr<Quote> &lsh, const shared_ptr<Quote> &rsh)
	{
		return (lsh->isbn() < rsh->isbn());
	}
	multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
public:
	//Basket类使用合成的默认构造函数和拷贝控制成员

	// void add_item(const shared_ptr<Quote> &sale)
	// {
	// 	items.insert(sale);
	// }
	void add_item(const Quote& sale) //拷贝给定对象
	{
		items.insert(shared_ptr<Quote> (sale.clone()));
	}
	void add_item(Quote&& sale)
	{
		items.insert(shared_ptr<Quote> (sale.clone()));
	}
	//打印每本书的总价和购物篮中的所有书的总价
	double total_receipt(ostream &os) const;

};