#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <iterator>

using namespace std;

int main()
{
	deque<int> v{istream_iterator<int>(cin), istream_iterator<int>()};
	v.push_back(11);
	for(auto it : v)
	{
		cout << it << " ";
	}
	cout << endl;
}

