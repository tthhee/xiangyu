
#include <malloc.h>
#include<stdlib.h>
#include<stdio.h>
#include "List_Sample.h"
struct Node
{
	ElementType Element;
	Position Next;
};
/**********************************
Describe:
	生成一个链表，需要自行输入元素个数和元素值
************************************/
List CreateList()
{
	ElementType data = 0;
	int num = 0;
	List head;
	List r,s;
	int i;
	head = (List)malloc(sizeof(struct Node));
	head->Element = 0;
	r = head;
	printf_s("enter the number of list's elements: ");
	scanf_s("%d", &num);
//	printf_s("%d" , num);
	for(i = 1; i<=num; i++)
	{
		printf_s("enter data[%d]: ", i);
		scanf_s("%d", &data);
		s = (List)malloc(sizeof(struct Node));
		if(s == NULL)
		{
			printf_s("out of space");
		}
		s->Element = data;
		r->Next = s;
	
		r = s;
	}
	s->Next = NULL;
	printf_s("the List is done\n");
	return head;
}
List InitEmpty()
{
	List L;
	L = malloc(sizeof(struct Node));
	L->Element = 0;
	L->Next = NULL;
	return L;
}
List MakeEmpty(List L)
{
	List temp, temp1;
	temp = L->Next;
	while(temp!=NULL)
	{
		temp1 = temp;
		temp = temp->Next;
		free(temp1);
	}
	L->Next = NULL;
	return L;
}
/*****************************************
Describe:
	判断一个链表是否为空链表， 返回1表示为空链表
******************************************/
int IsEmpty(List L)
{
	return L->Next == NULL;
}
/******************************************
Describe:
	判断位置n的元素是否为链表的最后一个元素 
*******************************************/
int IsLast(Position n, List L)
{
	return n->Next == NULL;
}
/******************************************
Describtion:
	在链表L中查找含有元素x的单元，返回此单元的指针
********************************************/
Position Find(ElementType x, List L)
{
	List temp;
	temp = L->Next;
	while(temp->Next != NULL)
	{
		if(temp->Element == x)
		{
			return temp;
		}
		temp = temp->Next;
	}
	printf_s("no element you want");
	return 0;
}
/*************************************************
Describtion:
	在链表L中查找元素x，并返回包含x元素的单元的前一个单元的指针
***************************************************/
Position FindPrevious(ElementType x, List L)
{
	List temp, pretemp;
	pretemp = L;
	temp = L->Next;
	if(temp == NULL)
	{
		printf_s("this is an empty list");
		return L;
	}
	while(temp->Next != NULL)
	{
		if(temp->Element == x)
		{
			return pretemp;
		}
		pretemp = temp;
		temp = temp->Next;
	}
	printf_s("no element you want");
	return 0;
}
/*******************************************
Describtion:
	在链表L中删除元素x
*********************************************/
void Delete(ElementType x, List L)
{
	List dest, predest;
//	dest = Find(x, L);
	predest = FindPrevious(x, L);
	dest = predest->Next;
	predest->Next = dest->Next;
	free(dest);
}
/***********************************************
insert the x after the Position P in List L
***********************************************/
void Insert(ElementType x, List L, Position p)
{
	List temp;
	temp = (List)malloc(sizeof(struct Node));
	if(temp == NULL)
	{
		printf_s("fatal error out of space");
		return;
	}
	temp->Element = x;
	temp->Next = p->Next;
	p->Next = temp;
}
/******************************************
Describtion:
	删除链表L，注意要释放内存
*******************************************/
void DeleteList(List L)
{
	List temp, P;
	P = L->Next;
	while(P != NULL)
	{
		temp = P->Next;
		free(P);
		P = temp;
	}
}
/***************************************
Describtion:
	打印链表L中的元素值
****************************************/
void PrintList(List L)
{
	List temp;
	if(L->Next == NULL)
	{
		printf_s("List is Empty");
	}
	else
	{
		temp = L->Next;
		while(temp != NULL)
		{
			printf_s(" %d ", temp->Element);
			temp = temp->Next;
		}
		printf("\n");
	}
}
/*************************************************
Describetion:
	打印链表L中的第n个单元的元素
***************************************************/
void PrintList_Element(List L, int n)
{
	int i;
	List temp;
	temp = L;
	for(i=1; i<=n; i++)
	{
		temp = temp->Next;
		if(temp == NULL)
		{
			printf(" %d is out of the length of List ", n);
			return;
		}
	}
	printf(" %d ", temp->Element);
}
/*******************************************
Describetion:
	此程序对应《数据结构与算法分析（第二版）》练习题3.3.2
	打印链表L中那些由链表P所指定的位置上的元素。例如，如果
	p = 1, 3, 4, 6,那么， L中的第1， 第3， 第4， 第6个元素
	被打印出来。
********************************************/
void PrintLots(List L, List P)
{
	List Ptemp;
	Ptemp = P->Next;
	while(Ptemp != NULL)
	{
		PrintList_Element( L, Ptemp->Element );
		Ptemp = Ptemp->Next;
	}
	printf("\n");
}
/*************************************************
Description:
	通过指定链表中的元素值使元素所在的单元与其下一个单元
	进行交换。通过指针实现
*************************************************/
void ExchangeElement_WithNext(ElementType x, List L)
{
	List temp1, temp2, temp3;
	temp1 = FindPrevious(x, L);
	temp2 = Find(x, L);
	temp3 = temp2->Next;
	temp1->Next = temp3;
	temp2->Next = temp3->Next;
	temp3->Next = temp2;
}
/****************************************************
Description:
	通过指定链表单元位置（指针）使其与下一个单元进行交换
	通过指针实现
*****************************************************/
void ExchangePosition_WithNext(Position n, List L)
{
	List temp1, temp2, temp3;
	temp1 = FindPrevious(n->Element, L);
	temp2 = n;
	temp3 = temp2->Next;
	temp1->Next = temp3;
	temp2->Next = temp3->Next;
	temp3->Next = temp2;
}
/**************************************
Description:
	此函数采用冒泡法排序实现链表元素按照从小到大的顺序排序
	注意，在函数中每次扫描找到最小元素值之后将元素值与相应
	单元的元素进行互换。
******************************************/
void Sort(List L)
{
	List min;
	ElementType temp;
	List P, Q;
	Q = L->Next;

	while(Q != NULL)
	{
		P = Q;
		min = P;
		while(P != NULL)
		{
			if(min->Element > P->Element)
			{
				min = P;
			}
			P = P->Next;
		}
		temp = min->Element;
		min->Element = Q->Element;
		Q->Element = temp;
		Q = Q->Next;
	}
}
/*
List Intersect(List L, List P)
{
	List temp1, temp2, temp;
	List head;
	head = L;
	temp1 = L->Next;
	temp2 = P->Next;
	while(temp1 != NULL && temp2 != NULL)
	{
		if(temp1->Element != temp2->Element)
		{
			temp = temp1->Next;
			temp2 = temp2->Next;
			Delete(temp1->Element, L);
		//	if(temp != NULL)
				temp1 = temp;
		}
		else
		{
			temp1 = temp1->Next;
			temp2 = temp2->Next;
		}
		if(temp2 == NULL)
		{
			temp1 = NULL;
		}
	}
	return head;
}
*/
Position First(List L)
{
	if(L->Next==NULL)
	{
		printf("List is empty!");
	}
	return L->Next;
}
Position Header(List L)
{
	return L;
}
void Intersect(List L1, List L2, List Result)
{
//	List Result;
	Position L1Pos, L2Pos, ResultPos;
	L1Pos = First(L1);
	L2Pos = First(L2);
//	Result = MakeEmpty(Result);
	ResultPos = Result;
	while(L1Pos!=NULL && L2Pos!=NULL)
	{
		if(L1Pos->Element > L2Pos->Element)
		{
			L2Pos = L2Pos->Next;
		}
		else if(L1Pos->Element < L2Pos->Element)
		{
			L1Pos = L1Pos->Next;
		}
		else
		{
			Insert(L1Pos->Element,Result, ResultPos);
			ResultPos = ResultPos->Next;
			L1Pos = L1Pos->Next;
			L2Pos = L2Pos->Next;
		}
	}
//	return Result;
}
List Union(List L1, List L2)
{
	//	List Result;
		List temp , temp2;
	List intersect;
	intersect = InitEmpty();
	Intersect(L1, L2, intersect);
//	Result = L1;
//	temp = L2->Next;
	temp2 = intersect->Next;
	while(temp2 != NULL)
	{
		temp = L2->Next;
		while(temp != NULL)
		{
			if(temp->Element == temp2->Element)
			{
				Delete(temp2->Element, L2);
			}
			temp = temp->Next;

		}

//		temp = temp->Next;
		temp2 = temp2->Next;
	}
	temp = L1;
	while(temp->Next != NULL)
	{
		temp = temp->Next;
	}
	temp2 = temp;
	temp = L2->Next;
	while(temp != NULL)
	{
		Insert(temp->Element, L1, temp2);
		temp = temp->Next;
		temp2 = temp2->Next;
	}
	return L1; 
}