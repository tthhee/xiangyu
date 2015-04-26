#include <iostream>
#include <string>

using namespace std;

static int num = 0;
class Employee{
	string name;
	int sn;
	Employee()
	{
		name = " ";
		sn = ++num;
	}
	Employee(string name)
	{
		sn = ++num;
		this.name = name;
	}

	Employee(const Employee& s)
	{
		sn = ++num;
		name = s.name;
	}
};