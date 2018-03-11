//ջ������ģʽ��
#include<stdio.h>
#include<stdlib.h>
#define ElemType char
#define OVERFLOW 0   //�ڴ�Խ�� 
#define OK 1        
#define ERROR -1     //���� 
#define STACKINCREMENT 20    //�����ڴ�ռ������� 

typedef struct {

	ElemType *top, *base;//�ֱ��ʾջ����ջ��.
	int Stack_len;//�Ѵ洢���ݵĳ���
	int Stack_Size; //�����ڴ�ĳ���

}SqStack;


//��ʼ��
int  InitStack(SqStack *S,int length){

	 S->base = (ElemType*)malloc(length*sizeof(ElemType));//�����ڴ�ռ�
	 if (!S->base) exit(OVERFLOW);
	 S->top = S->base;
	 S->Stack_len = 0;
	 S->Stack_Size = length;
	return OK;
}
//��ջ
int Push(SqStack *S, ElemType e) {
	//�ж��Ƿ�ջ��
	if (S->top - S->base >= S->Stack_Size) {
		S->base = (ElemType*)realloc(S->base,
			( STACKINCREMENT+ S->Stack_Size) * sizeof(ElemType));
	}
	if (!S->base) exit(OVERFLOW);
	*S->top++ = e;
	S->Stack_len++;
	return OK;
 }

//��ջ
ElemType Pop(SqStack *S) {
	if (S->top== S->base)
	{
		return ERROR;
	}
	ElemType c;
	 c= *--S->top;
	S->Stack_len--;
	return c;

}

//���ջ
void OutputStack(SqStack *S) {
	ElemType *p= S->top-1;
	int i = 1;
	printf("����ʼ�����\n");
	for (i; i <= S->Stack_len; i++)
	 {
		printf("[%d]=%c\n", i, *p--);
	}
	printf("���������ɡ�\n");
}


	int main() {
		SqStack S;

		InitStack(&S, 20);
		Push(&S, '1');
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
