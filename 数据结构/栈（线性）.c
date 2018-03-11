//栈（线性模式）
#include<stdio.h>
#include<stdlib.h>
#define ElemType char
#define OVERFLOW 0   //内存越界 
#define OK 1        
#define ERROR -1     //错误 
#define STACKINCREMENT 20    //申请内存空间增加量 

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
