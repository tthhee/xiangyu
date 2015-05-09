#include "exercise15-2oop.h"

double Bulk_quote::net_price(size_t n) const
{
	if(n >= quantity)
	{
		return n*(1-discount)*price;
	}
	else
	{
		return n*price;
	}
}

/**
*Quote类的拷贝构造函数
*/
Quote::Quote(const Quote& q)
{
	bookNo = q.bookNo;
	price = q.price;
	cout << "Base_Class Copy Constructor!!!" <<endl;
}
/**
*Quote类的拷贝复制运算符
*/
Quote& Quote::operator=(const Quote& q)
{
	bookNo = q.bookNo;
	price = q.price;
	cout << "Base_Class Copy Assignment Operator!!!" << endl;
	return *this;
	
}
/**
*Disc_Quote类的拷贝构造函数
*/
Disc_quote::Disc_quote(const Disc_quote& d):Quote(d)
{
//	Quote(d);
	quantity = d.quantity;
	discount = d.discount;
	cout << "Disc_quote Copy Constructor!!!" <<endl;
}
Disc_quote& Disc_quote::operator=(const Disc_quote& d)
{
	Quote::operator=(d);
	quantity = d.quantity;
	discount = d.discount;
	cout << "Disc_quote Copy Assignment Operator!!!" << endl;
	return *this;
}
/**
*Bulk_Quote类拷贝构造函数
*/
Bulk_quote::Bulk_quote(const Bulk_quote& b):Disc_quote(b)
{
	//Disc_quote::Disc_quote(b);
	cout << "Bulk_quote Copy Constructor!!!" << endl;
}
Bulk_quote& Bulk_quote::operator=(const Bulk_quote& b)
{
	Disc_quote::operator=(b);
	cout << "Bulk_quote Copy Assignment Operator!!!" <<endl;
	return *this;
}
Quote::~Quote()
{
	cout << "Base_Class Destroy Function!!!" << endl;
}
Disc_quote::~Disc_quote()
{
	cout << "Disc_quote Destroy Function!!!" <<endl;
}
Bulk_quote::~Bulk_quote()
{
	cout << "Bulk_quote Destroy Function!!!" << endl;
}
/**
*PrintTotal()
*打印n个item的总价
*/
double PrintTotal(ostream& os, Quote& item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << "\n";
	os << "#Sold: " << n << " total due: " << ret << "\n";
	return ret;
}
/**
*total_receipt()
*负责将购物篮中的内容逐项打印成清单
*/
double Basket::total_receipt(ostream &os) const
{
	double sum=0.0;   //用于计算总价

	//iter指向ISBN相同的一批元素当中的第一个
	//upper_bound返回一个迭代器，该迭代器指向这批元素的尾后位置
	for(auto iter=items.cbegin(); iter!=items.cend(); iter=items.upper_bound(*iter))
	{
		sum += PrintTotal(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl;
	return sum;
}
int main()
{
//	Disc_quote one;
	Bulk_quote one("xiangyu", 5.5, 10, 0.2);
	Bulk_quote three("liuchang", 10.1, 20, 0.3);
	Basket bsk;
	bsk.add_item(one);
	bsk.add_item(three);
	cout <<"total price: " << bsk.total_receipt(cout) << endl; 
	return 0;
}