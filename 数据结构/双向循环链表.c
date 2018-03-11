//双向循环链表
#include<stdio.h>
#include<stdlib.h>
#define ElemType int

//结点类型
typedef struct DulNode {
	struct DulNode *prior;
	ElemType element;
	struct DulNode *next;
}*Link,*Postion;

//链表类型
typedef struct {

	Link head, tail;//分别表示头指针，尾指针.
	int len; //长度

}LinkList;


//初始化(包含第一个值）
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

//尾插入
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



//指定位置插入
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
			printf("成功插入数值。");
			return 1;
		}
		q= q->next;
	}
	printf("未找到指定位置，该链表大小为%d.\n", L->len);
	return 0;
	}

	//指定位置删除
	int DeleteDulNodeByPos(LinkList *L, int pos) {
		Postion q;
		q = L->head;
		int i = 1;
		for(i;i<L->len+1;i++)
		{
			if (pos == i) {
				if(L->head==q)  L->head=q->next;  //判断是否为头指针结点 
				if(L->tail==q)  L->tail=q->prior;  //判断是否为尾指针结点 
				q->next->prior = q->prior;
				q->prior->next = q->next;
				free(q);
				L->len--;
				printf("成功删除指定位置数值。");
				return 1;
			}
			q = q->next;
		}
		printf("未找到指定位置，该链表大小为%d\n", L->len);
		return 0;

	}

	//指定元素删除
	int DeleteDulNodeByItem(LinkList *L, int item) {
		Postion q;
		q = L->head;
		int i=1;
		for(i;i<L->len+1;i++)
		{
			if (q->element==item) {
				
				if(L->head==q)  L->head=q->next;  //判断是否为头指针结点 
				if(L->tail==q)  L->tail=q->prior;  //判断是否为尾指针结点 
				q->next->prior = q->prior;
				q->prior->next = q->next;
				free(q);
				L->len--;
				printf("成功删除指定数值。\n");
				q = q->next;
			}
			q = q->next;
		}
		return 0;

	}

	//查询
	ElemType SearchDulNode(LinkList *L, int pos) {
		Postion q;
		q = L->head;
		int i = 1;
		for(i;i<L->len+1;i++)
		{
			if (pos == i) {  
				printf("成功找到指定位置数值。");
				return q->element;
			}
			i++;
			q = q->next;
		}
		printf("未找到指定位置，该链表大小为%d\n", L->len);
		return 0;

	}

	//链表长度；
	int ListSize(LinkList *L) {
		return L->len;
	}

	void  OutputLinkList(LinkList *L) {
		Postion q;
		q = L->head;
		int i = 1;
		printf("链表开始输出：\n");
		for(i;i<L->len+1;i++)
		{
    
			printf("[%d]=%d.\n",i,q->element);
			q = q->next;
		}
		printf("链表结束输出。\n");

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
