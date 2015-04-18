#include<stdio.h>
#include<string.h>
#include "Stack.h"
void main()
{
	char buf[50];
	Stack S;
	unsigned int i;
	char temp;
//	buf = getline();
//    scanf_s("%s", buf);
	gets(buf);
	S = CreateStack();
	for( i=0; i<strlen(buf); i++)
	{
		if((buf[i] == '(')||(buf[i]=='[') || (buf[i]=='{'))
		{
			Push(buf[i], S);
		}
		else if((buf[i] == ')')||(buf[i]==']') || (buf[i]=='}'))
		{
			if(IsEmpty(S))
			{
				printf_s("Stack is empty, error balance");
				return;
			}
			else
			{
				temp = Top(S);
				Pop(S);
				switch(buf[i])
				{
				case ')':
				
					if(temp != '(')
					{
						printf_s("error balance ()");
						return;
					}
					break;
				case ']':
					if(temp != '[')
					{
						printf_s("error balance []");
						return;
					}
					break;
				case '}':
					if(temp != '{')
					{
						printf_s("error balance {}");
						return;
					}
					break;
				default:
					break;
				}
			}
		}
	}

	printf_s("balance completely");
	return;
}