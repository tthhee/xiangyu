#include "Priority_Queue.h"

/**
*下虑函数，采用子节点的key value 大于父节点的key value的方式
*/
template<typename Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole)  //下虑函数
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
*将一个已存在的vector数组数据构建成一个堆
*将一半的元素执行下虑操作
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
*用一个已知的vector构建成一个堆
*为有一定余量，array的size 设置成item.size()+10
*利用buildheap形成堆
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
*判断堆结构是否为空
*/
template<typename Comparable>
bool BinaryHeap<Comparable>::isEmpty() const
{
	return currentSize;
}
/**
*查找最小值，由于采用的是子节点大于父节点的方式
*所以最小值为array[1]， 即第一个值
*/
template<typename Comparable>
const Comparable & BinaryHeap<Comparable>::findMin() const
{
	return array[1];
}
/**
*插入一个元素，先将元素插入到最后，然后在利用上虑方式调整，使其满足堆的结构
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
*插入一个右值元素，先将元素插入到最后，然后在利用上虑方式调整，使其满足堆的结构
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
*删除最小元素
*/
template<typename Comparable>
void BinaryHeap<Comparable>::deleteMin()
{
	if (currentSize == 0)
	{
		cout << "Empty Heap!!!" << endl;
		return;
	}
	/********以下两行是调用percolateDown()函数的实现程序**************/
	array[1] = array[currentSize--];
	percolateDown(1);
	/********以上两行是调用percolateDown()函数的实现程序*****************/
	/***************以下是不调用percolateDown()的实现程序***************/
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
	/*************以上是不调用percolateDown()的实现程序*******************/
}
/**
*查找Heap中的元素item
*返回元素的下标
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
*删除Heap中的元素item
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
*使堆为空
*/
template<typename Comparable>
void BinaryHeap<Comparable>::makeEmpty()
{
	currentSize = 0;
}
/**
*PrintHeap()
*以数组的形式输出堆中的元素
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
*返回当前元素个数
*/
template<typename Comparable>
int BinaryHeap<Comparable>::size()
{
	return currentSize;
}
/**
*increaseKey(int p, int n)
*将位置P的key 值增加n, 相当于降低p的优先级
*/
template<typename Comparable>
void BinaryHeap<Comparable>::increaseKey(int p, Comparable n)
{
	array[p] = array[p] + n;
	percolateDown(p);
}
/**
*decreaseKey(int p, int n)
*将位置的key值减小n, 相当于提高P的优先级
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