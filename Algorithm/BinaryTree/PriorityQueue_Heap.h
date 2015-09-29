#ifndef _HEAP_
#define _HEAP_

#include <iostream>
using namespace std;
#define MinPQSize 10
#define MinData   1

template<typename ElementType>
struct  HeapStruct
{
	int capacity;
	int size;
	ElementType *Element;
};
template<typename ElementType>
class Heap
{
private:
	using PriorityQueue = HeapStruct<ElementType>;
	PriorityQueue HeapNode;
//	HeapStruct* head;
public:
	
	PriorityQueue *Initialize(int MaxElements);
};
#endif

template<typename ElementType>
HeapStruct<ElementType> *Heap<ElementType>::Initialize(int MaxElements)
{
	PriorityQueue* H;
	if(MaxElements < MinPQSize)
	{
		cerr<< "Priority queue size is too small" << endl;
		return nullptr;
	}
	H = new HeapStruct();
	if(H == nullptr)
	{
		cerr << "out of space" << end;
		return nullptr;
	}
	H->HeapNode.Element = new ElementType[MaxElements+1];
	if(H->HeapNode.Element == nullptr)
	{
		cerr << "Out of Space!!!" << endl;
	}
	H->HeapNode.Element[0] = MinData;

	return H;

}