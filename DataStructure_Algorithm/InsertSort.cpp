#include <iostream>

using namespace std;
void InsertSort(int *arr, int length);
int main()
{
	int arr[10] = {4, 2, 65, 23, 17, 25, 64, 24, 90, 33};
	InsertSort(arr, 10);

	for(int i = 0; i < 9; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << arr[9];
	return 0;
}

void InsertSort(int *arr, int length)
{
	int temp;
	int i, j;
	for( i = 1; i < length; i++)
	{
		temp = arr[i];
		for( j = i; j > 0 && arr[j-1] > temp; j--)
		{
			if(arr[j-1] > temp)
			{
				arr[j] = arr[j-1];
			}
		}
		arr[j] = temp;
	}

}