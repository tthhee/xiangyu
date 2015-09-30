#include <iostream>
#include <string>
#include <set>

using namespace std;
class Folder;
class Message
{
	friend class Folder;
private:
	string contents;  //实际文本消息
	set<Folder*> folders; //包含本Message的Foulder
	//拷贝构造函数、拷贝赋值运算符和析构函数所使用的工具函数
	//将本Message添加到指定的Folder中
	void add_to_Folders(const Message&);
	//从folders中的每个Folder中删除Message
	void remove_from_Folders();
public:
	//folders被隐式初始化为空集合
	Message(const string& str = ""):
		contents(str) {}                 //默认构造函数
	Message(const Message& );           //拷贝构造函数
	Message& operator=(const Message&);  //拷贝复制运算符
	~Message();    //析构函数
	//从给定Folder集合中添加/删除本Message
	void save(Folder&);
	void remove(Folder&);
};
void swap(Message& , Message&);
class Folder
{
	friend class Message;
private:
	set<Message*> Msg;

public:
	Folder(const Folder& );
	Folder& operator=(const Folder&);
	~Folder();
	void addMsg(const Message*);   //向此Folder中添加Message
	void remMsg(const Message*);
};