#include <iostream>

using namespace std;
void ShellSort(int *arr, int length);
int main()
{
	int arr[10] = {4, 2, 65, 23, 17, 25, 64, 24, 90, 33};
	ShellSort(arr, 10);

	for(int i = 0; i < 9; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << arr[9];
	return 0;
}

void ShellSort(int *arr, int length)
{
	int i, j, k;
	for(i = length/2; i > 0; i /=2)
	{
		for(j = i; j < length; j+=i)
		{
			int temp = arr[j];
			for(k = j; k > 0 && arr[k-i]>temp; k-=i)
			{
					arr[k] = arr[k-i];
			}
			arr[k] = temp;
		}
		
	}

}