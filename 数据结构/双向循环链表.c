//˫��ѭ������
#include<stdio.h>
#include<stdlib.h>
#define ElemType int

//�������
typedef struct DulNode {
	struct DulNode *prior;
	ElemType element;
	struct DulNode *next;
}*Link,*Postion;

//��������
typedef struct {

	Link head, tail;//�ֱ��ʾͷָ�룬βָ��.
	int len; //����

}LinkList;


//��ʼ��(������һ��ֵ��
void InitDulNode(LinkList *L,ElemType ms){
	Link p;
	p= (Link *)malloc(sizeof(Link));
	p->element = ms;
	L->head = p;
	L->tail = p;
	p->next=p;
	p->prior=p;
	L->len = 1;
}

//β����
void InsertDulNodeByEnd(LinkList *L,ElemType item) {
	Link p;
	p = (Link *)malloc(sizeof(Link));
	p->element = item;
	L->tail->next = p;
	p->prior = L->tail;
	L->tail=p;
	p->next = L->head;
	L->len++;
}



//ָ��λ�ò���
int InsertDulNodeByPos(LinkList *L, int item, int pos) {
	Link p;
	p = (Link *)malloc(sizeof(Link));
	p->element = item;
	Postion q;
	q = L->head;
	int i = 1;
	for(i;i<L->len+1;i++)
	{
		if (pos == i) {
			p->next = q;
			p->prior = q->prior;
			q->prior->next = p;
			q->prior = p;
			L->len++;
			printf("�ɹ�������ֵ��");
			return 1;
		}
		q= q->next;
	}
	printf("δ�ҵ�ָ��λ�ã��������СΪ%d.\n", L->len);
	return 0;
	}

	//ָ��λ��ɾ��
	int DeleteDulNodeByPos(LinkList *L, int pos) {
		Postion q;
		q = L->head;
		int i = 1;
		for(i;i<L->len+1;i++)
		{
			if (pos == i) {
				if(L->head==q)  L->head=q->next;  //�ж��Ƿ�Ϊͷָ���� 
				if(L->tail==q)  L->tail=q->prior;  //�ж��Ƿ�Ϊβָ���� 
				q->next->prior = q->prior;
				q->prior->next = q->next;
				free(q);
				L->len--;
				printf("�ɹ�ɾ��ָ��λ����ֵ��");
				return 1;
			}
			q = q->next;
		}
		printf("δ�ҵ�ָ��λ�ã��������СΪ%d\n", L->len);
		return 0;

	}

	//ָ��Ԫ��ɾ��
	int DeleteDulNodeByItem(LinkList *L, int item) {
		Postion q;
		q = L->head;
		int i=1;
		for(i;i<L->len+1;i++)
		{
			if (q->element==item) {
				
				if(L->head==q)  L->head=q->next;  //�ж��Ƿ�Ϊͷָ���� 
				if(L->tail==q)  L->tail=q->prior;  //�ж��Ƿ�Ϊβָ���� 
				q->next->prior = q->prior;
				q->prior->next = q->next;
				free(q);
				L->len--;
				printf("�ɹ�ɾ��ָ����ֵ��\n");
				q = q->next;
			}
			q = q->next;
		}
		return 0;

	}

	//��ѯ
	ElemType SearchDulNode(LinkList *L, int pos) {
		Postion q;
		q = L->head;
		int i = 1;
		for(i;i<L->len+1;i++)
		{
			if (pos == i) {  
				printf("�ɹ��ҵ�ָ��λ����ֵ��");
				return q->element;
			}
			i++;
			q = q->next;
		}
		printf("δ�ҵ�ָ��λ�ã��������СΪ%d\n", L->len);
		return 0;

	}

	//�����ȣ�
	int ListSize(LinkList *L) {
		return L->len;
	}

	void  OutputLinkList(LinkList *L) {
		Postion q;
		q = L->head;
		int i = 1;
		printf("����ʼ�����\n");
		for(i;i<L->len+1;i++)
		{
    
			printf("[%d]=%d.\n",i,q->element);
			q = q->next;
		}
		printf("������������\n");

}


	int main() {

		LinkList L;
		InitDulNode(&L, 1);
		InsertDulNodeByEnd(&L, 2);
		InsertDulNodeByEnd(&L, 3);
		InsertDulNodeByEnd(&L, 4);
		InsertDulNodeByEnd(&L, 5);
		InsertDulNodeByEnd(&L, 6);
		InsertDulNodeByEnd(&L, 7);
		InsertDulNodeByEnd(&L, 8);
		OutputLinkList(&L);

		InsertDulNodeByPos(&L, 8,4);
		OutputLinkList(&L);

		DeleteDulNodeByItem(&L, 8);
		OutputLinkList(&L);

		DeleteDulNodeByPos(&L, 1);
		OutputLinkList(&L);

		return 0;

	}
