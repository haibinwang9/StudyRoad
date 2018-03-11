//栈的应用（括号匹配）
#include<stdio.h>
#include<stdlib.h>
#define ElemType char
#define OVERFLOW -1   //内存异常 
#define ERROR 0  //错误 
#define OK  1    // 正确 
#define STACKINCREMENT 20

typedef struct {

	ElemType *top, *base;//分别表示栈顶，栈底.
	int Stack_len;//已存储数据的长度
	int Stack_Size; //申请内存的长度

}SqStack;


//初始化
int  InitStack(SqStack *S,int length){

	 S->base = (ElemType*)malloc(length*sizeof(ElemType));//申请内存空间
	 if (!S->base) exit(OVERFLOW);
	 S->top = S->base;
	 S->Stack_len = 0;
	 S->Stack_Size = length;
	return OK;
}

//判空
int IsEmpty(SqStack *S) {
	if (S->Stack_len == 0) return OK;
	else return 0;
}


//入栈
int Push(SqStack *S, ElemType e) {
	//判断是否栈满
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

//出栈
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

//输出栈
void OutputStack(SqStack *S) {
	ElemType *p= S->top-1;
	int i = 1;
	printf("链表开始输出：\n");
	for (i; i <= S->Stack_len; i++)
	 {
		printf("[%d]=%c\n", i, *p--);
	}
	printf("链表输出完成。\n");
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
		printf("匹配成功！\n");
		return OK;
	}
	else
	{
		printf("匹配错误！\n");
		return ERROR;
	}

}



	int main() {
		char *String1 = "({[{[}]]})";//测试1
		Correct(String1, 10);

		char *String2 = "({[{}]})";//测试2
		Correct(String2, 8);
		system("pause");
		return 0;

	}
