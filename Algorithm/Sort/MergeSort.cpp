#include <iostream>
#include <vector>
#include <time.h>
#include <windows.h>

using namespace std;

/**
*内部使用函数，用于将两个已排序的数组合并成一个排序数组
*arr是待处理数组， arr被分成两个分别排序的子数组
*temp是另一个临时数组，用于临时存储排序结果
*leftpos是第一个数组，即arr中的前半个数组的第一个元素索引
*rightpos是第二个数组，即arr中的后半个数组的第一个元素索引
*rightend是arr数组的最后一个元素索引
*/
template<typename Comparable>
void merge(vector<Comparable> & arr, vector<Comparable> & temp, int leftpos, int rightpos, int rightend)
{
	int tem_rightpos = rightpos;
	int temp_index = leftpos;
	int numElements = rightend-leftpos+1;
	while(leftpos <= tem_rightpos-1 && rightpos <= rightend)
	{
		if(arr[leftpos] <= arr[rightpos])
		{
			temp[temp_index++] = arr[leftpos];
			leftpos++;
		}
		else
		{
			temp[temp_index++] = arr[rightpos];
			rightpos++;
		}
	}
	while(leftpos <= tem_rightpos-1)
	{
		temp[temp_index++] = arr[leftpos++];
	}
	while(rightpos <= rightend)
	{
		temp[temp_index++] = arr[rightpos++];
	}

	for(int i = 0; i < numElements;i++, --rightend)
	{
		arr[rightend] = temp[rightend];
	}
}

/**
*对一个无序数组采用归并排序的方式进行递归排序
*arr是待排序的数组
*temp是临时数组
*leftbegin 是arr的第一个元素的索引
*rightend 是arr的最后一个元素的索引
*/
template<typename Comparable>
void mergeSort(vector<Comparable> & arr, vector<Comparable> & temp, int leftbegin, int rightend)
{
	if(leftbegin < rightend)
	{
		int center = (rightend + leftbegin)/2;
		mergeSort<Comparable>(arr, temp, leftbegin, center);
		mergeSort<Comparable>(arr, temp, center+1, rightend);
		merge<Comparable>(arr, temp, leftbegin, center+1, rightend);
	}
}

/**
*归并排序算法实现
*
*/
template<typename Comparable>
void MergeSort(vector<Comparable> & arr)
{
	vector<Comparable> tempArray (arr.size());
	mergeSort<Comparable>(arr, tempArray, 0, arr.size()-1);
}

int main()
{
	vector<int> array = {1, 13, 24, 26, 2, 15, 27, 38};
	clock_t start = clock();
	MergeSort<int>(array);
	Sleep(3000);
	clock_t end = clock();

	cout << "the time is " << (end-start) << endl;
	for(auto it = array.begin(); it != array.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}