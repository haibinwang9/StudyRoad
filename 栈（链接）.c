#include<stdio.h>
#include<stdlib.h>
#define ElemType char

//结点类型
typedef struct NodeStack{
	ElemType element;
	struct NodeStack *next;
}OutStack,NodeStack;

//栈的链表类型
typedef struct{

	NodeStack *top, *base;//分别表示栈顶，栈底.
	int len; //长度

}LinkStack;


//初始化(带第一个参数)
void InitStack(LinkStack *S,ElemType ms){

	NodeStack *p =(NodeStack *)malloc(sizeof(NodeStack));//申请一个初始化的内存空间结点

	NodeStack *q = (NodeStack *)malloc(sizeof(NodeStack));//申请一个初始化的内存空间结点
	p->element = ms;  //栈底
	p->next = NULL;
	S->base = p;
	q->next = p;
	S->top = q;
	S->len = 1;
}
//入栈
void Push(LinkStack *S, ElemType e) {
	NodeStack *p = (NodeStack*)malloc(sizeof(NodeStack));//申请内存空间结点
	S->top->element = e;
	p->next = S->top;
	S->top = p;
	S->len++;
 }

//出栈
ElemType Pop(LinkStack *S) {
	ElemType e;
	NodeStack *p= S->top->next;
	e = p->element;
	S->top->next= p->next;
	free(p);
	S->len--;
	return e;
}

//输出栈
void OutputStack(LinkStack *S) {
	OutStack *p=S->top->next;
	int i = 1;
	printf("栈开始输出。\n");
	for (i; i < S->len + 1; i++) {
		printf("[%d]=%c\n", i, p->element);
		p = p->next;
	}
	printf("栈输出完成。\n");
}


	int main() {
		LinkStack S;

		InitStack(&S, '1');

		Push(&S, '2');
		Push(&S, '3');
		Push(&S, '4');
		Push(&S, '5');
		OutputStack(&S);

		printf("%c\n", Pop(&S));
		OutputStack(&S);

		system("pause");
		return 0;

	}
