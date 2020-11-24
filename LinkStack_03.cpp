/*链栈的操作*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define OK 1
#define ERROR -1
#define OVERFLOW 0

typedef struct LStack
{
	char data;
	struct LStack *next;
}LStack, *LinkStack;

typedef struct{
	LinkStack front;
	LinkStack rear;
}LinkQueue;
 
int InitStack_L(LinkQueue &S)
{
	S.front=S.rear=(LinkStack)malloc(sizeof(LStack));
	 if(!S.front)
	 	return ERROR;
	S.front->next=NULL; 
	return OK;
	//*S = (LinkStack)malloc(sizeof(LStack));
	//if(!(*S))
		//return ERROR;
	//(*S)->next = NULL;
		//return OK;
}

int Push_L(LinkQueue &S,char e)
{
	LinkStack p;

	p = (LinkStack)malloc(sizeof(LStack));
	if(!p)
		return ERROR;
	p->data = e;
	p->next = NULL;
	S.rear->next=p; 
	S.rear= p;
		return OK;
}

int Pop_L(LinkQueue S,char *e)
{
	LinkStack p;
	p = S.front->next;
	*e = p->data;
	S.front->next = p->next;
	free(p);
		return OK;
}

int StackTraverse_L(LinkQueue S,int(*visit)(LinkStack))
{
	LinkStack p;
	p = S.front->next;
	while(p)
	{
		visit(p);
		p = p->next;
	}
	printf("\n");

	return OK;
}

int visit(LinkStack p)
{
	printf("%c",p->data);
		return OK;
}


main()
{
	LinkQueue S;
	char e;
	int i,n;

	InitStack_L(S);//初始化栈。建立只含一个头结点的栈

	printf("Input the length of the LinkQueue: ");
		scanf("%d",&n);//输入栈的长度
	for(i=1; i<=n; i++)
	{
		printf("Input the %dth push data into the stack: ",i);
		fflush(stdin);         //Pay more attention!!!
		scanf("%c",&e);
		Push_L(S,e);           //第i个元素入栈
	}
	printf("Traverse the LinkQueue: ");
	StackTraverse_L(S,visit);  //遍历栈
	printf("Pop out the top data:");
	Pop_L(S,&e);               //弹出栈顶元素至变量e
	printf("%c\n",e);
	printf("Traverse the LinkQueue again: ");
	StackTraverse_L(S,visit);
	return 0;
}
