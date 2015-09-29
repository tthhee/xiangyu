#include <iostream>

class Numbered
{
public:
	int mysn;
	int a;
	int b;
	static int num;
	Numbered()
	{
		num++;
		mysn = num;
		a = 0;
		b = 0;
	}
	Numbered(const Numbered & s)
	{
		num++;
		mysn = num;
		a = s.a;
		b = s.b;

	}


};
void f(const Numbered& s)
{
	std::cout << s.mysn << std::endl;
}
int Numbered::num = 0;
int main()
{
	Numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);

	return 0;
}
