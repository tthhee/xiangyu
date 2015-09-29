#ifndef _PRIORITY_QUEUE_
#define _PRIORITY_QUEUE_

#include <iostream>
#include <vector>
using namespace std;
template<typename Comparable>
class BinaryHeap
{
public:
	explicit BinaryHeap(int capacity = 100);  //Ä¬ÈÏÈÝÁ¿100
	explicit BinaryHeap(const vector<Comparable> & item);

	bool isEmpty() const;
	const Comparable & findMin() const;
	int findItem(const Comparable & item);

	void insert(const Comparable & x);
	void insert(Comparable && x);
	void deleteMin();
	void deleteElement(const Comparable & item);
	void makeEmpty();
	void PrintHeap();
	int size();
	void decreaseKey(int p, Comparable n);
	void increaseKey(int p, Comparable n);

private:
	int currentSize; //number of element in heap
	vector<Comparable> array;
	void buildHeap();
	void percolateDown(int hole);
};
#endif