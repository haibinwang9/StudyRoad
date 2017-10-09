//������
#include<stdio.h>
#include<stdlib.h>
#define ElemType int
typedef struct list {
	ElemType data;   //���� 
	struct list *next;  //ָ���¸���� 
}LIST;

//��ʼ������
void InitList(LIST *L, ElemType ms) {
	L->data = ms;
	L->next = NULL;
}

//������ָ��λ�ò���Ԫ��
void InsertListByItem(LIST *L, int item, int re) {
	LIST *p = L;
	LIST *in = (LIST*)malloc(sizeof(LIST));//����һ���µĽ�㣡�� 
	in->data = item;
	int i = 1;
	while (p->next)
	{
		if (re == i)//Ԫ��λ��ƥ�� 
		{
			in->next = p->next;
			p->next = in;
		}
		p = p->next;
		i++;
	}
}

//����������ָ��λ�ò���Ԫ��
void InsertListInEnd(LIST *L, int item) {
	LIST *p = L;
	LIST *in = (LIST*)malloc(sizeof(LIST));//����һ���µĽ�㣡�� 
	in->data = item;
	while (!(p->next == NULL))//��Ϊ����㣬�����¸���� 
	{
		p = p->next;
	}
	in->next = p->next;
	p->next = in;
	return;
}

//ɾ��ָ��Ԫ��ֵ�������¼
int DeleteListByItem(LIST *L, int item) {
	LIST *p = L;
	while (p->next)
	{
		if (item == p->next->data)//Ԫ��ֵƥ�� 
		{

			p->next = p->next->next;//������Ҫɾ���Ľ�� 
		}
		else p = p->next;//�¸���� 
	}
	return 0;
}

//ɾ��ָ��λ�õ�Ԫ�� 
int DeleteListByPos(LIST *L, int pos) {
	int i = 1;
	LIST *p = L;
	while (p->next)
	{
		if (pos == i)//Ԫ��ֵƥ�� 
		{

			p->next = p->next->next;//������Ҫɾ���Ľ�� 
			return 0;
		}	
			p = p->next;//�¸���� 
			i++;
	}
	return 1;
}





//���������е�Ԫ��
int FindList(LIST *L, int item) {
	LIST *p = L;
	int i = 1;
	while (p->next)
	{
		if (item == p->next->data)//Ԫ��ֵƥ�� 
		{
			return i;        //����Ԫ��λ�� 
		}
		p = p->next;    //�¸���� 
		i++;
	}
	printf("No Find!");
	return 0;
}


//�������Ԫ��
int OutputList(LIST *L) {
	LIST *p = L;
	int i = 1;
	printf("begining:\n");
	while (p->next)
	{
		printf("LSIT[%d]=%d.\n", i, p->next->data);
		p = p->next;
		i++;
	}
	printf("end:\n");
	return 0;
}


//һ��������A��Ϊ ���Ϊż��ΪB��������ΪA���� 
int SeparateList(LIST *A, LIST *B) {
	int i = 1;
	LIST *a = A;
	while (a->next) {
		//�Ƿ�Ϊż��λ��
		if (!(i % 2)) {
			ElemType data=0;
			data = a->next->data;//������Ҫɾ�������ݣ�
			a->next= a->next->next;//ɾ���Ľ��
			InsertListInEnd(B, data);//�����ݱ��浽B������
		}
		else
		{
			a = a->next;//�¹���㣻
		}
		i++;
	}
	return 0;

}


//��ת������(����1��
int ReverseList_Method1(LIST *L) {
	LIST *p=L;
	LIST *head=L;//����ͷ���
	LIST flag1;//����ԭ�����ǰ����ַ
	LIST flag2;//����ԭ����ĺ�����ַ

	   //���׽��Ĳ���
		flag1.next=p->next;   //�����һ�����ĵ�ַ
		p=p->next;            //ָ���һ����㣨ǰ����
		flag2.next = p->next; //����ڶ������������ĵ�ַ
		p->next = NULL;		  // �Ե�һ������nextָ��NULL������Ϊ�����β��
		p = flag2.next;		  //���ڶ������ĵ�ַ��p


	//	���м���Ĳ���
	while (p->next)   //�ж��Ƿ񵽴�ԭ�����β���
	{
		flag2.next= p->next;  //��������ĵ�ַ
		p->next= flag1.next;  //��ǰ���ĵ�ַ����ý���next
		flag1.next = p;       //����ý��ĵ�ַ
		p  = flag2.next;	  //��pָ��������ĺ����ƶ��Ǹ����������ĵ�ַ����p
    
	}
    //	��β���Ĳ���
	p->next = flag1.next;   //��ǰ���ĵ�ַ����ԭ�����β����next
	head->next = p;         //��ͷ���ָ��ԭ�����β���
	return 0;
}

//��ת������(����2��,����һ���µ������������ò��뷽�����в���
int ReverseList_Method2(LIST *L, LIST *N) {
	LIST *p = L;
	while (p->next)
	{
		ElemType item = p->next->data;
		InsertListByItem(N, item, 1);
		p = p->next;
	}
	return 0;
}



int main() {

	LIST L;
	LIST B;

	InitList(&L, 0);//��ʼ��
	InitList(&B, 0);//��ʼ��

	InsertListInEnd(&L, 10);//����������ָ��λ�ò���Ԫ��
	OutputList(&L);

	InsertListInEnd(&L, 9);//����������ָ��λ�ò���Ԫ��
	OutputList(&L);

	InsertListInEnd(&L, 8);//����������ָ��λ�ò���Ԫ��
	OutputList(&L);

	InsertListInEnd(&L, 7);//����������ָ��λ�ò���Ԫ��
	OutputList(&L);

	InsertListInEnd(&L, 6);//����������ָ��λ�ò���Ԫ��
	OutputList(&L);

	InsertListInEnd(&L, 5);//����������ָ��λ�ò���Ԫ��
	OutputList(&L);

	InsertListByItem(&L, 10, 2);//������ָ��λ�ò���Ԫ��
	OutputList(&L);

	printf("�����е�%d��Ϊ5\n", FindList(&L, 5));//���������е�Ԫ��

	SeparateList(&L, &B);
	OutputList(&L);
	OutputList(&B);

	ReverseList_Method1(&L);
	OutputList(&L);

	//	DeleteListByItem(&L, 10);//ɾ��ָ��Ԫ��ֵ�������¼
	//	OutputList(&L);
	system("pause");

	return 0;
}

