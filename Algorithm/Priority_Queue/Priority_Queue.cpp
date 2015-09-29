#include "Priority_Queue.h"

/**
*���Ǻ����������ӽڵ��key value ���ڸ��ڵ��key value�ķ�ʽ
*/
template<typename Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole)  //���Ǻ���
{
	int child;
	Comparable temp = std::move(array[hole]);
	for (; 2 * hole <= currentSize; hole = child)
	{
		child = 2 * hole;
		if (child != currentSize && array[child] > array[child + 1])
		{
			child++;
		}
		if (array[child] < temp)
			array[hole] = std::move(array[child]);
		else
			break;
	}
	array[hole] = std::move(temp);
}
/**
*��һ���Ѵ��ڵ�vector�������ݹ�����һ����
*��һ���Ԫ��ִ�����ǲ���
*/
template<typename Comparable>
void BinaryHeap<Comparable>::buildHeap()
{
	for (int i = currentSize / 2; i > 0; i--)
		percolateDown(i);
}
template<typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(int capacity)
{
	array.resize(capacity);
	currentSize = 0;
}
/**
*��һ����֪��vector������һ����
*Ϊ��һ��������array��size ���ó�item.size()+10
*����buildheap�γɶ�
*/
template<typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(const vector<Comparable> & item)
:array(item.size() + 10), currentSize(item.size())
{
	for (int i = 0; i < item.size(); i++)
	{
		array[i + 1] = item[i];
	}
	buildHeap();
}
/**
*�ж϶ѽṹ�Ƿ�Ϊ��
*/
template<typename Comparable>
bool BinaryHeap<Comparable>::isEmpty() const
{
	return currentSize;
}
/**
*������Сֵ�����ڲ��õ����ӽڵ���ڸ��ڵ�ķ�ʽ
*������СֵΪarray[1]�� ����һ��ֵ
*/
template<typename Comparable>
const Comparable & BinaryHeap<Comparable>::findMin() const
{
	return array[1];
}
/**
*����һ��Ԫ�أ��Ƚ�Ԫ�ز��뵽���Ȼ�����������Ƿ�ʽ������ʹ������ѵĽṹ
*/
template<typename Comparable>
void BinaryHeap<Comparable>::insert(const Comparable & x)
{
	currentSize++;
	int cnt = currentSize;
	array.push_back(x);
	for (; cnt > 1; cnt = cnt / 2)
	{
		if (array[cnt / 2] > x)
		{
			array[cnt] = array[cnt / 2];
		}
		else
			break;
	}
	array[cnt] = x;
}
/**
*����һ����ֵԪ�أ��Ƚ�Ԫ�ز��뵽���Ȼ�����������Ƿ�ʽ������ʹ������ѵĽṹ
*/
template<typename Comparable>
void BinaryHeap<Comparable>::insert(Comparable && x)
{
	if (currentSize == array.size() - 1)
	{
		array.resize(array.size() * 2);
	}
	currentSize++;
	int cnt = currentSize;
	array.push_back(std::move(x));
	for (; cnt > 1; cnt = cnt / 2)
	{
		if (array[cnt / 2] > x)
		{
			array[cnt] = std::move(array[cnt / 2]);
		}
		else
			break;
	}
	array[cnt] = std::move(x);
}
/**
*ɾ����СԪ��
*/
template<typename Comparable>
void BinaryHeap<Comparable>::deleteMin()
{
	if (currentSize == 0)
	{
		cout << "Empty Heap!!!" << endl;
		return;
	}
	/********���������ǵ���percolateDown()������ʵ�ֳ���**************/
	array[1] = array[currentSize--];
	percolateDown(1);
	/********���������ǵ���percolateDown()������ʵ�ֳ���*****************/
	/***************�����ǲ�����percolateDown()��ʵ�ֳ���***************/
/*	int cnt = 1;
	int child;
	for (; cnt * 2 <= currentSize; cnt = child)
	{
		child = cnt*2;
		if (array[child + 1] < array[child])
		{
			child++;
		//	array[cnt] = array[child];
		}
		if (array[child] > array[currentSize])
		{
			break;
		}
		else
		{
			array[cnt] = array[child];
		}
	}
	array[cnt] = array[currentSize];
	currentSize--;
	*/
	/*************�����ǲ�����percolateDown()��ʵ�ֳ���*******************/
}
/**
*����Heap�е�Ԫ��item
*����Ԫ�ص��±�
*/
template<typename Comparable>
int BinaryHeap<Comparable>::findItem(const Comparable & item)
{
	int i;
	for (i = 1; i <= currentSize; i++)
	{
		if (item == array[i])
		{
			return i;
		}
	}
	cout << "cannot find item " << item << endl;
}
/**
*ɾ��Heap�е�Ԫ��item
*/
template<typename Comparable>
void BinaryHeap<Comparable>::deleteElement(const Comparable & item)
{
	int cnt;
	cnt = findItem(item);
	int child;
	for (; cnt * 2 < currentSize; cnt = child)
	{
		child = cnt * 2;
		if (array[child + 1] < array[child])
		{
			child++;
			//	array[cnt] = array[child];
		}
		if (array[child] > array[currentSize])
		{
			break;
		}
		else
		{
			array[cnt] = array[child];
		}
	}
	array[cnt] = array[currentSize];
	currentSize--;
}
/**
*MakeEmpty()
*ʹ��Ϊ��
*/
template<typename Comparable>
void BinaryHeap<Comparable>::makeEmpty()
{
	currentSize = 0;
}
/**
*PrintHeap()
*���������ʽ������е�Ԫ��
*/
template<typename Comparable>
void BinaryHeap<Comparable>::PrintHeap()
{
	if (currentSize == 0)
	{
		cout << "Empty Heap!!!" << endl;
		return;
	}
	for (int i = 1; i < currentSize; i++)
	{
		cout << array[i] << ", ";
	}
	cout << array[currentSize] << endl;
}
/**
*size()
*���ص�ǰԪ�ظ���
*/
template<typename Comparable>
int BinaryHeap<Comparable>::size()
{
	return currentSize;
}
/**
*increaseKey(int p, int n)
*��λ��P��key ֵ����n, �൱�ڽ���p�����ȼ�
*/
template<typename Comparable>
void BinaryHeap<Comparable>::increaseKey(int p, Comparable n)
{
	array[p] = array[p] + n;
	percolateDown(p);
}
/**
*decreaseKey(int p, int n)
*��λ�õ�keyֵ��Сn, �൱�����P�����ȼ�
*/
template<typename Comparable>
void BinaryHeap<Comparable>::decreaseKey(int p, Comparable n)
{
	Comparable temp = array[p] + n;
	int cnt = p;
	for (; cnt > 1; cnt = cnt/2)
	{
		if (array[cnt] < array[cnt / 2])
		{
			array[cnt] = array[cnt / 2];
		}
		else
			break;
	}
	array[cnt] = temp;
}
int main()
{
	vector<int> str = { 24, 31, 19, 68, 21, 16, 65, 26, 32, 13 };
	BinaryHeap<int> binHeap(str);
	cout << "size: " << binHeap.size() <<endl;
	binHeap.PrintHeap();
	binHeap.insert(15);
	binHeap.insert(23);
	binHeap.PrintHeap();
	binHeap.deleteMin();
	binHeap.PrintHeap();
	binHeap.deleteElement(16);
	binHeap.PrintHeap();
	return 0;
}