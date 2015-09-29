#include <iostream>
#include <algorithm>
#include <time.h>
#include <windows.h>
using namespace std;
template<typename ElementType>
ElementType Median3(ElementType (&array)[10], int left, int right)
{
	int center = (left + right) / 2;

	if (array[left] > array[center])
	{
		swap(array[left], array[center]);
	}
	if (array[left] > array[right])
	{
		swap(array[left], array[right]);
	}
	if (array[center] > array[right])
	{
		swap(array[center], array[right]);
	}

	swap(array[center], array[right - 1]);

	return array[right - 1];
}

template<typename ElementType>
void InsertSort(ElementType  (&array)[10], int left, int right)
{
	ElementType temp;
	int j;
	for (int i = left + 1; i <= right; i++)
	{
		temp = array[i];
		for ( j = i - 1; j >= 0; j--)
		{
			if (array[j] > array[i])
			{
				array[j + 1] = array[j];
			}
			else
				break;
		}
		array[j+1] = temp;
	}
}

/**
*快速排序算法
*left 是数组array中的最左边元素号
*right 是数组array中的最右边元素号
*/
template<typename ElementType>
void QuickSort(ElementType  (&array)[10], int left, int right)
{
	if (right - left > 3)
	{
		ElementType pivot = Median3(array, left, right);
		int i, j;
		i = left;
		j = right - 1;
		while (1)
		{
			while (array[++i] < pivot){}
			while (array[--j] > pivot){}
			if (i < j)
			{
				swap(array[i], array[j]);
			}
			else
				break;
		}
		swap(array[i], array[right - 1]);
		QuickSort(array, left, i - 1);
		QuickSort(array, i + 1, right);
	}
	else
	{
		InsertSort(array, left, right);
	}
}
int main()
{
	int arr[10] = { 8, 1, 4, 9, 0, 3, 5, 2, 7, 6 };
	int(&array)[10] = arr;
	clock_t start = clock();
	cout << "start time: " << start << endl;
	QuickSort<int>(array, 0, 9);
	Sleep(200);
	clock_t end = clock();
	cout << "the end time: " << end << endl;
	
	cout << "the time of quicksort is " << end - start << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << arr[9];
	return 0;
}