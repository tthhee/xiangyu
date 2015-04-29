#include "exercise13.4Message_Folder.h"

/*DOWN*********************Message 类成员*************************************************/
void Message::save(Folder& f)
{
	folders.insert(&f);
	f.addMsg(this);
}
void Message::remove(Folder& f)
{
	folders.erase(&f);
	f.remMsg(this);
}
//将本Message添加到指向m的Folder中
void Message::add_to_Folders(const Message& m)
{
	for(auto it : m.folders)
	{
		it->addMsg(this);
	}
}
void Message::remove_from_Folders()
{
	for(auto it : folders)
	{
		it->remMsg(this);
	}
}
Message::Message(const Message& m)
{
	contents = m.contents;   //拷贝内容文本
	folders = m.folders;     //拷贝folders
	add_to_Folders(m);       //将本消息加到所有包含m的目录中
}
Message::~Message()
{
	remove_from_Folders();
}
Message& Message::operator=(const Message& m)
{
	remove_from_Folders();
	contents = m.contents;
	folders = m.folders;
	add_to_Folders(m);
	return *this;
}
/*UP*********************************Message 类成员*************************************************/
/*DOWN******************************Folder 类成员*************************************************/
Folder::Folder(const Folder& f):Msg(f.Msg)
{
	for(auto it : Msg)
	{
		*it.folders.insert(this);
	}
}
Folder::~Folder()
{
	for(auto it : Msg)
	{
		*it.folders.erase(this);
	}
}
Folder& Folder::operator=(const Folder& f)
{
	for(auto it : Msg)
	{
		*it.folders.erase(this);
	}
	Msg = f.Msg;
	for(auto it : Msg)
	{
		*it.folders.insert(&f);
	}

}
void Folder::addMsg(Message* s)
{
	Msg.insert(s);
}
void Folder::remMsg(Message* s)
{
	Msg.erase(s);
}
/*UP********************************Folder 类成员*************************************************/
void swap(Message& m1, Message& m2)
{
	using std::swap;
	swap(m1.contents, m2.contents);   //交换文本内容
	//将m1从其目录中删除
	for(auto it : m1.folders)         
	{
		it->remMsg(&m1);
	}
	//将m2从其目录中删除
	for(auto it : m2.folders)
	{
		it->remMsg(&m2);
	}
	m1.add_to_Folders(m2);
	m2.add_to_Folders(m1);
	swap(m1.folders, m2.folders);
}
int main()
{
	return 0;
}
