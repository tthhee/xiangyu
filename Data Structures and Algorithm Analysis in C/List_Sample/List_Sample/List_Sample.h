#ifndef _LIST_SAMPLE_H
#define _LIST_SAMPLE_H

struct Node;
typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List CreateList();
List InitEmpty();
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position n, List L);
Position Find(ElementType x, List L);
Position FindPrevious(ElementType x, List L);
Position First(List L);
Position Header(List L);
void Delete(ElementType x, List L);
void Insert(ElementType x, List L, Position p);
void DeleteList(List L);
void PrintList(List L);
void PrintList_Element(List L, int n);
void PrintLots(List L, List P);
void ExchangeElement_WithNext(ElementType x, List L);
void ExchangePosition_WithNext(Position x, List L);
void Sort(List L);
void Intersect(List L1, List L2, List Result);
List Union(List L1, List L2);

#endif