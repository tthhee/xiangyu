#include "List_Sample.h"
#include<stdio.h>

void main()
{
	List L;
	List P, I;

//	ElementType x;
	L = CreateList();
	P = CreateList();
	I = InitEmpty();
//	PrintList(L);
/*	PrintList(L);
	printf("enter the element you want to exchange\n");
	scanf("%d", &x);
	P = Find(x, L);
	ExchangePosition_WithNext(P, L); 
	*/
//	Sort(L);
 //   Intersect(L, P, I);
	I = Union(L, P);
	PrintList(I);
}

