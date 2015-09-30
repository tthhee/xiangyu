#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename Comparable>
void print(const vector<Comparable> & arr)
{
	auto it = arr.begin();
	for(; it != arr.end()-1; it++)
	{
		cout << *it << ", ";
	}
	cout << *(it++) << endl;
}
/**
*下虑函数，应用于(max)堆， 
*a 是操作的数组， i是下虑的位置， n 是二叉堆的size
*/
template<typename Comparable>
void perDown(vector<Comparable> & a, int i, int n)
{
	int child;
	int cnt;
	Comparable temp;
	temp = a[i];
	for(cnt=i; 2*cnt+1 < n; cnt = child)
	{
		child = cnt*2+1;
		if(child != n-1 && a[child] < a[child+1])
		{
			child++;
		}
		if(a[child] > temp)
		{
			a[cnt] = a[child];			
		}
		else
			break;
	}
	a[cnt] = temp; 
}

template<typename Comparable>
void HeapSort(vector<Comparable> & array)
{
	//build heap
	for(int i=array.size()/2-1; i>=0; i--)
	{
		perDown(array, i, array.size());
	}
	//sort
	for(int j = array.size()-1; j>0 ; j--)
	{

		std::swap(array[0], array[j]);
		perDown(array, 0, j);
	}

}



int main()
{
	vector<int> str = {31, 41, 59, 26, 53, 58, 97};
	HeapSort(str);
	print(str);
	return 0;
}
