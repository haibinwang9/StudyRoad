//顺序表（提高版）   
#include<stdio.h>
#include<stdlib.h>
#define LISTADDSIZE 10//增加的数值
#define OK 0
#define ElemType int 
typedef struct LinearList
{
	ElemType *list;
	int size;           //已有元素值的长度
	int MAXSIZE;         //总长度
}List;

//初始化顺序表
int InitList(List *L, int ms) {
	if (ms<0) {
		printf("ms数值不能小于零！请重新输入!");
		exit(1);
	}
	L->list = (ElemType *)malloc(ms * sizeof(ElemType));
	L->size = 0;
	L->MAXSIZE = ms;
	return OK;
}

//向顺序表指定位置插入元素
int InsertList(List *L, int pos, ElemType elem) {
	while (pos >= L->MAXSIZE) {
		ElemType *p = (ElemType *)realloc(L->list, LISTADDSIZE * sizeof(ElemType));
		if (!p)
		{
			printf("重新分配内存失败！");

		}
		L->list = p;
		L->MAXSIZE += LISTADDSIZE;

	}
	int i;
	for (i = L->size - 1; i >= pos - 1; i--)
	{
		L->list[i] = L->list[i - 1];
	}
	L->list[pos - 1] = elem;
	L->size++;
	return OK;
}


//删除指定元素值的顺序表记录
void DeleteList1(List *L, int elem) {
	int i;
	for (i = 0; i <L->size; i++)
	{
		if (L->list[i] == elem)
		{
			int j;
			for (j = i; j <= L->size - i; j++) {
				L->list[j] = L->list[j + 1];


			}
			L->size--;
		}
	}

}


//删除指定位置的顺序表记录
void DeleteList2(List *L, int pos) {
	int  i;
	for (i = 0; i <L->size; i++)
	{
		L->list[i] = L->list[i + 1];

	}
	L->size--;
}

//查找指定位置的顺序表元素值
int FindList(List *L, int pos) {
	return L->list[pos - 1];
}

//输出顺序表元素

int OutputList(List *L) {
	printf("顺序表开始输出！\n");
	int i;
	for (i = 1; i <= L->size; i++)
	{
		printf("L[%d]:%d\n", i, L->list[i - 1]);
	}
	printf("顺序表输出完毕！\n");
	return OK;
}

//删除顺序表，释放内存空间
void ClearList(List *L)
{
	if (L->list != NULL)
	{
		free(L->list);
		L->list = 0;
		L->size = L->MAXSIZE = 0;
	}
}

//批量删除元素值在x到y的所有元素(包含X，Y值) 
void  DeleteByXY(List *L, int x, int y) {

	if (y<x) {
		printf("Y值不应小于X值，请重新输入！");
	}

	int i = 0, j = 0;
	for (i; i<L->size; i++) {
		if (!(L->list[i] <= y&&L->list[i] >= x)) {
			L->list[j] = L->list[i];
			j++;
		}

	}
	L->size = L->size - (i - j);
}

//合并两个有序线性表，同一元素值只出现一次 
List* MergeListForOnly(List *L1, List *L2, List *L3) {

	int i = 0;
	while (!(L1->list[i]==NULL && L2->list[i]==NULL)){
		//L1较少 
		if (L1->list[i]==NULL) {
			for (i; i<L2->size; i++) {
				InsertList(L3, i + 1, L2->list[i]);
			}
				return L3;

		}
		//L2较少 
		if (L2->list[i]==NULL) {
			
			for (i; i< L1->size; i++) {
				InsertList(L3, i + 1, L1->list[i]);
			}
				return L3;
		}


		if (L1->list[i] == L2->list[i]) {
			InsertList(L3, i + 1, L1->list[i]);
		}
		else
		{
			InsertList(L3, i + 1, L1->list[i]<L2->list[i] ? L1->list[i] : L2->list[i]);
		}
		i++;
	}
	return L3;

}



int main()
{
	List L;
	List L1;
	List L2;
	InitList(&L, 2);//初始化
	InitList(&L1, 2);//初始化
	InitList(&L2, 2);//初始化
					 //l
	InsertList(&L, 1, 10);//插入元素
	OutputList(&L);

	InsertList(&L, 2, 9);//插入元素
	OutputList(&L);

	InsertList(&L, 3, 8);//插入元素
	OutputList(&L);

	InsertList(&L, 4, 6);//插入元素
	OutputList(&L);

	InsertList(&L, 5, 5);//插入元素
	OutputList(&L);

	InsertList(&L, 6, 4);//插入元素
	OutputList(&L);

	InsertList(&L, 7, 3);//插入元素
	OutputList(&L);


	//L1

	InsertList(&L1, 1, 9);//插入元素


	InsertList(&L1, 2, 10);//插入元素


	InsertList(&L1, 3, 3);//插入元素


	InsertList(&L1, 4, 1);//插入元素


	MergeListForOnly(&L1, &L, &L2);

	OutputList(&L2);



	//    DeleteByXY(&L,4,6);//批量删除元素值在x到y的所有元素(包含X，Y值) 
	//    OutputList(&L);         
	//
	//
	//	FindList(&L, 8); //查找指定位置的顺序表元素值
	//	OutputList(&L);
	//
	//	DeleteList1(&L, 8);//删除指定元素值的顺序表记录
	//	OutputList(&L);
	//
	//	DeleteList2(&L, 1);//删除指定位置的顺序表记录
	//	OutputList(&L);
	system("pause");
	return OK;
}
