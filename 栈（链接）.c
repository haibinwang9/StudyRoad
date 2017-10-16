#include<stdio.h>
#include<stdlib.h>
#define ElemType char

//�������
typedef struct NodeStack{
	ElemType element;
	struct NodeStack *next;
}OutStack,NodeStack;

//ջ����������
typedef struct{

	NodeStack *top, *base;//�ֱ��ʾջ����ջ��.
	int len; //����

}LinkStack;


//��ʼ��(����һ������)
void InitStack(LinkStack *S,ElemType ms){

	NodeStack *p =(NodeStack *)malloc(sizeof(NodeStack));//����һ����ʼ�����ڴ�ռ���

	NodeStack *q = (NodeStack *)malloc(sizeof(NodeStack));//����һ����ʼ�����ڴ�ռ���
	p->element = ms;  //ջ��
	p->next = NULL;
	S->base = p;
	q->next = p;
	S->top = q;
	S->len = 1;
}
//��ջ
void Push(LinkStack *S, ElemType e) {
	NodeStack *p = (NodeStack*)malloc(sizeof(NodeStack));//�����ڴ�ռ���
	S->top->element = e;
	p->next = S->top;
	S->top = p;
	S->len++;
 }

//��ջ
ElemType Pop(LinkStack *S) {
	ElemType e;
	NodeStack *p= S->top->next;
	e = p->element;
	S->top->next= p->next;
	free(p);
	S->len--;
	return e;
}

//���ջ
void OutputStack(LinkStack *S) {
	OutStack *p=S->top->next;
	int i = 1;
	printf("ջ��ʼ�����\n");
	for (i; i < S->len + 1; i++) {
		printf("[%d]=%c\n", i, p->element);
		p = p->next;
	}
	printf("ջ�����ɡ�\n");
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
