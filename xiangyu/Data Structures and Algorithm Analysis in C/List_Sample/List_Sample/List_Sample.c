
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
	����һ��������Ҫ��������Ԫ�ظ�����Ԫ��ֵ
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
	�ж�һ�������Ƿ�Ϊ������ ����1��ʾΪ������
******************************************/
int IsEmpty(List L)
{
	return L->Next == NULL;
}
/******************************************
Describe:
	�ж�λ��n��Ԫ���Ƿ�Ϊ��������һ��Ԫ�� 
*******************************************/
int IsLast(Position n, List L)
{
	return n->Next == NULL;
}
/******************************************
Describtion:
	������L�в��Һ���Ԫ��x�ĵ�Ԫ�����ش˵�Ԫ��ָ��
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
	������L�в���Ԫ��x�������ذ���xԪ�صĵ�Ԫ��ǰһ����Ԫ��ָ��
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
	������L��ɾ��Ԫ��x
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
	ɾ������L��ע��Ҫ�ͷ��ڴ�
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
	��ӡ����L�е�Ԫ��ֵ
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
	��ӡ����L�еĵ�n����Ԫ��Ԫ��
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
	�˳����Ӧ�����ݽṹ���㷨�������ڶ��棩����ϰ��3.3.2
	��ӡ����L����Щ������P��ָ����λ���ϵ�Ԫ�ء����磬���
	p = 1, 3, 4, 6,��ô�� L�еĵ�1�� ��3�� ��4�� ��6��Ԫ��
	����ӡ������
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
	ͨ��ָ�������е�Ԫ��ֵʹԪ�����ڵĵ�Ԫ������һ����Ԫ
	���н�����ͨ��ָ��ʵ��
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
	ͨ��ָ������Ԫλ�ã�ָ�룩ʹ������һ����Ԫ���н���
	ͨ��ָ��ʵ��
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
	�˺�������ð�ݷ�����ʵ������Ԫ�ذ��մ�С�����˳������
	ע�⣬�ں�����ÿ��ɨ���ҵ���СԪ��ֵ֮��Ԫ��ֵ����Ӧ
	��Ԫ��Ԫ�ؽ��л�����
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
List Intersect(List L1, List L2)
{
	List Result;
	Position L1Pos, L2Pos, ResultPos;
	L1Pos = First(L1);
	L2Pos = First(L2);
	Result =InitEmpty();
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
	return Result;
}
/*************************************************
Description:
	Union()����������L1�� L2Ԫ�صĲ�����(ע�⣺�������������Ԫ�ر����Ǿ�����С���������)
	�������ز��������
	ע�⣺�����е� ResultPos = Result;��Ϊ����Insert()��������Posλ�õĺ�����룬���Զ���һ��������
		  Ҫ�뽫Ԫ�ز��뵽��һ��λ�ã���PosӦΪ�����head.
**************************************************/
List Union(List L1, List L2)
{
	List Result;
	ElementType ResultElement;
	List L1Pos, L2Pos, ResultPos;
	Result = InitEmpty();
	L1Pos = L1->Next;
	L2Pos = L2->Next;
	ResultPos = Result;
	while(L1Pos != NULL && L2Pos != NULL)
	{
		if(L1Pos->Element < L2Pos->Element)
		{
			ResultElement = L1Pos->Element;
			L1Pos = L1Pos->Next;
		}
		else if(L2Pos->Element < L1Pos->Element)
		{
			ResultElement = L2Pos->Element;
			L2Pos = L2Pos->Next;
		}
		else
		{
			ResultElement = L1Pos->Element;
			L1Pos = L1Pos->Next;
			L2Pos = L2Pos->Next;

		}
		Insert(ResultElement, Result, ResultPos);
		ResultPos = ResultPos->Next;
	}
	while(L1Pos != NULL)
	{
		Insert(L1Pos->Element, Result, ResultPos);
		L1Pos = L1Pos->Next;
		ResultPos = ResultPos->Next;
	}
	while(L2Pos != NULL)
	{
		Insert(L2Pos->Element, Result, ResultPos);
		L2Pos = L2Pos->Next;
		ResultPos = ResultPos->Next;
	}
	return Result;	
}

/************************************************
Description:
	����n�ζ���ʽ�����մ����ӵ͵��������������ϵ��
	ϵ���洢��������
*************************************************/
List Polynominal(int n)
{
	List L;
	List LPos;
	int a;
	int i;
	L = InitEmpty();
	LPos = L;
	printf("%d�ζ���ʽ����ϵ��:\n", n);
	for(i=0; i<=n; i++)
	{

		printf("%d����ϵ��: ", i);
		scanf("%d", &a);
		Insert(a,L,LPos);
	}
	return L;
}
/*****************************************
Description:
	δʵ��
*****************************************/
List PolynominalExp(List L, int n, int p)
{
	List Result;
	List LPos, ResultPos;
	int i, j;
	Result = InitEmpty();

}