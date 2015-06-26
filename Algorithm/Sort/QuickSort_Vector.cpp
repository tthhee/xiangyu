#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/**
*交换两个元素的值
*/
// template<typename ElementType>
// void Swapvalue(ElementType &s1, ElementType & s2)
// {
// 	ElementType temp;
// 	temp = s1;
// 	s1 = s2;
// 	s2 = temp;
// }

/**
*当分割后的字数组元素小于等于3个元素时，不适合使用快速排序，此时使用插入排序
*/
template<typename ElementType>
void InsertSort(vector<ElementType> & arr, int left, int right)
{
	ElementType temp;
	int i, j;
	for(i = left+1; i <= right; i++)
	{
		temp = arr[i];
		for(j = i-1; j >= 0; j--)
		{
			if(arr[j] > temp)
			{
				arr[j+1] = arr[j];
			}
			else
				break;
		}

		arr[j+1] = temp;
	}
}

/**
*用于快速排序算法中的取中值算法
*arr是待排序数组
*left是数组第一个元素的下标
*right是数组最后一个元素的下标
*/
template<typename ElementType>
ElementType Median3(vector<ElementType> & array, int left, int right)
{
	int center = (left + right)/2;

	if(array[left] > array[center])
	{
		swap(array[left], array[center]);
	}
	if(array[left] > array[right])
	{
		swap(array[left], array[right]);
	}
	if(array[center] > array[right])
	{
		swap(array[center], array[right]);
	}

	swap(array[center], array[right-1]);
	return array[right-1];

}

/**
*快速排序算法
*arr是带排序数组
*left是数组第一个元素的下标
*right是数组最后一个元素的下标
*/
template<typename ElementType>
void QuickSort(vector<ElementType> & arr, int left, int right)
{
	if(right - left >= 3)
	{
		ElementType pivot;
		pivot = Median3(arr, left, right);
		int i = left;
		int j = right-1;
		while(1)
		{
		while(arr[++i] < pivot){}
		while(arr[--j] > pivot){}

		if(i < j)
		{
			swap(arr[i], arr[j]);
		}
		else
			break;
		}
		
		swap(arr[i], arr[right-1]);
		QuickSort(arr, left, i-1);
		QuickSort(arr, i+1, right);
		
	}
	else
	{
		InsertSort(arr, left, right);
	}

}


int main()
{
	vector<int> array = { 8, 1, 4, 9, 0, 3, 5, 2, 7, 6 };
	vector<int> & arr = array;
	QuickSort<int>(arr, 0, 9);

	for(auto it: array)
	{
		cout << it << " ";
	}
	return 0;
}