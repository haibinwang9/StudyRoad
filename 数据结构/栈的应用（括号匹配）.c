//ջ��Ӧ�ã�����ƥ�䣩
#include<stdio.h>
#include<stdlib.h>
#define ElemType char
#define OVERFLOW -1   //�ڴ��쳣 
#define ERROR 0  //���� 
#define OK  1    // ��ȷ 
#define STACKINCREMENT 20

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

//�п�
int IsEmpty(SqStack *S) {
	if (S->Stack_len == 0) return OK;
	else return 0;
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

ElemType GetTop(SqStack *S) {
	ElemType *p = S->top;
	return *(p-1);

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



int Correct(char *exp, int max) {
	SqStack S;
	InitStack(&S, 20);
	int i = 0;
	for (i; i < max; i++) {
		switch (*exp)
		{
		case '(':
		case '[':
		case '{': Push(&S, *exp); break;
		case ')':if (GetTop(&S) == '(') Pop(&S); 
				 else {
					 Push(&S, *exp);
				 } break;
		case ']':if (GetTop(&S) == '[') { Pop(&S); }
				 else {
					 Push(&S, *exp);
				 }break;
		case '}':if (GetTop(&S) == '{') { Pop(&S); }
				 else {
					 Push(&S, *exp);
				 }break;
		default:
			break;
		}
		*exp++;
	}
	if (IsEmpty(&S)) {
		printf("ƥ��ɹ���\n");
		return OK;
	}
	else
	{
		printf("ƥ�����\n");
		return ERROR;
	}

}



	int main() {
		char *String1 = "({[{[}]]})";//����1
		Correct(String1, 10);

		char *String2 = "({[{}]})";//����2
		Correct(String2, 8);
		system("pause");
		return 0;

	}
