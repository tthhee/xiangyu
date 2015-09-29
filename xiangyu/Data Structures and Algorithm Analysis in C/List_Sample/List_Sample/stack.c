#include "stdlib.h"
#include "stdio.h"
#include "Stack.h"

struct StackNode
{
	char Element;
	PtrToNode Next;
};

int StackIsEmpty(Stack S)
{
	return S->Next == NULL;
}
Stack CreateStack(void)
{
	Stack S;
	S = malloc(sizeof(struct StackNode));
	if(S == NULL)
	{
		printf_s("Out of space");
	}
	S->Next = NULL;
	return S;
}
void MakeEmptyStack(Stack S)
{
	if(S == NULL)
	{
		printf_s("must use Createstack first");
	}
	else
	{
		while(!IsEmpty(S))
		{
			Pop(S);
		}
	}
}
void Pop(Stack S)
{
	PtrToNode FirstCell;
	if(IsEmpty(S))
	{
		printf_s("Empty stack");
	}
	else
	{
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		free(FirstCell);
	}
}
void Push(char x, Stack S)
{
	PtrToNode TmpCell;
	TmpCell = malloc(sizeof(struct StackNode));
	if(TmpCell == NULL)
	{
		printf_s("out of space");
	}
	else
	{
		TmpCell->Element = x;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}

char Top(Stack S)
{
	if(S->Next == NULL)
	{
		printf_s("stack is empty");
		return 0;
	}
	else
	{
		return S->Next->Element;
	}
}