//˳�����߰棩   
#include<stdio.h>
#include<stdlib.h>
#define LISTADDSIZE 10//���ӵ���ֵ
#define OK 0
#define ElemType int 
typedef struct LinearList
{
	ElemType *list;
	int size;           //����Ԫ��ֵ�ĳ���
	int MAXSIZE;         //�ܳ���
}List;

//��ʼ��˳���
int InitList(List *L, int ms) {
	if (ms<0) {
		printf("ms��ֵ����С���㣡����������!");
		exit(1);
	}
	L->list = (ElemType *)malloc(ms * sizeof(ElemType));
	L->size = 0;
	L->MAXSIZE = ms;
	return OK;
}

//��˳���ָ��λ�ò���Ԫ��
int InsertList(List *L, int pos, ElemType elem) {
	while (pos >= L->MAXSIZE) {
		ElemType *p = (ElemType *)realloc(L->list, LISTADDSIZE * sizeof(ElemType));
		if (!p)
		{
			printf("���·����ڴ�ʧ�ܣ�");

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


//ɾ��ָ��Ԫ��ֵ��˳����¼
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


//ɾ��ָ��λ�õ�˳����¼
void DeleteList2(List *L, int pos) {
	int  i;
	for (i = 0; i <L->size; i++)
	{
		L->list[i] = L->list[i + 1];

	}
	L->size--;
}

//����ָ��λ�õ�˳���Ԫ��ֵ
int FindList(List *L, int pos) {
	return L->list[pos - 1];
}

//���˳���Ԫ��

int OutputList(List *L) {
	printf("˳���ʼ�����\n");
	int i;
	for (i = 1; i <= L->size; i++)
	{
		printf("L[%d]:%d\n", i, L->list[i - 1]);
	}
	printf("˳��������ϣ�\n");
	return OK;
}

//ɾ��˳����ͷ��ڴ�ռ�
void ClearList(List *L)
{
	if (L->list != NULL)
	{
		free(L->list);
		L->list = 0;
		L->size = L->MAXSIZE = 0;
	}
}

//����ɾ��Ԫ��ֵ��x��y������Ԫ��(����X��Yֵ) 
void  DeleteByXY(List *L, int x, int y) {

	if (y<x) {
		printf("Yֵ��ӦС��Xֵ�����������룡");
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

//�ϲ������������Ա�ͬһԪ��ֵֻ����һ�� 
List* MergeListForOnly(List *L1, List *L2, List *L3) {

	int i = 0;
	while (!(L1->list[i]==NULL && L2->list[i]==NULL)){
		//L1���� 
		if (L1->list[i]==NULL) {
			for (i; i<L2->size; i++) {
				InsertList(L3, i + 1, L2->list[i]);
			}
				return L3;

		}
		//L2���� 
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
	InitList(&L, 2);//��ʼ��
	InitList(&L1, 2);//��ʼ��
	InitList(&L2, 2);//��ʼ��
					 //l
	InsertList(&L, 1, 10);//����Ԫ��
	OutputList(&L);

	InsertList(&L, 2, 9);//����Ԫ��
	OutputList(&L);

	InsertList(&L, 3, 8);//����Ԫ��
	OutputList(&L);

	InsertList(&L, 4, 6);//����Ԫ��
	OutputList(&L);

	InsertList(&L, 5, 5);//����Ԫ��
	OutputList(&L);

	InsertList(&L, 6, 4);//����Ԫ��
	OutputList(&L);

	InsertList(&L, 7, 3);//����Ԫ��
	OutputList(&L);


	//L1

	InsertList(&L1, 1, 9);//����Ԫ��


	InsertList(&L1, 2, 10);//����Ԫ��


	InsertList(&L1, 3, 3);//����Ԫ��


	InsertList(&L1, 4, 1);//����Ԫ��


	MergeListForOnly(&L1, &L, &L2);

	OutputList(&L2);



	//    DeleteByXY(&L,4,6);//����ɾ��Ԫ��ֵ��x��y������Ԫ��(����X��Yֵ) 
	//    OutputList(&L);         
	//
	//
	//	FindList(&L, 8); //����ָ��λ�õ�˳���Ԫ��ֵ
	//	OutputList(&L);
	//
	//	DeleteList1(&L, 8);//ɾ��ָ��Ԫ��ֵ��˳����¼
	//	OutputList(&L);
	//
	//	DeleteList2(&L, 1);//ɾ��ָ��λ�õ�˳����¼
	//	OutputList(&L);
	system("pause");
	return OK;
}
