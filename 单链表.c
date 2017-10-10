//单链表
#include<stdio.h>
#include<stdlib.h>
#define ElemType int
typedef struct list {
	ElemType data;   //数据 
	struct list *next;  //指向下个结点 
}LIST;

//初始化链表
void InitList(LIST *L, ElemType ms) {
	L->data = ms;
	L->next = NULL;
}

//向链表指定位置插入元素
void InsertListByItem(LIST *L, int item, int re) {
	LIST *p = L;
	LIST *in = (LIST*)malloc(sizeof(LIST));//申请一个新的结点！！ 
	in->data = item;
	int i = 1;
	while (p->next)
	{
		if (re == i)//元素位置匹配 
		{
			in->next = p->next;
			p->next = in;
		}
		p = p->next;
		i++;
	}
}

//向有序链表指定位置插入元素
void InsertListInEnd(LIST *L, int item) {
	LIST *p = L;
	LIST *in = (LIST*)malloc(sizeof(LIST));//申请一个新的结点！！ 
	in->data = item;
	while (!(p->next == NULL))//不为最后结点，跳到下个结点 
	{
		p = p->next;
	}
	in->next = p->next;
	p->next = in;
	return;
}

//删除指定元素值的链表记录
int DeleteListByItem(LIST *L, int item) {
	LIST *p = L;
	while (p->next)
	{
		if (item == p->next->data)//元素值匹配 
		{

			p->next = p->next->next;//跳过需要删除的结点 
		}
		else p = p->next;//下个结点 
	}
	return 0;
}

//删除指定位置的元素 
int DeleteListByPos(LIST *L, int pos) {
	int i = 1;
	LIST *p = L;
	while (p->next)
	{
		if (pos == i)//元素值匹配 
		{

			p->next = p->next->next;//跳过需要删除的结点 
			return 0;
		}	
			p = p->next;//下个结点 
			i++;
	}
	return 1;
}





//查找链表中的元素
int FindList(LIST *L, int item) {
	LIST *p = L;
	int i = 1;
	while (p->next)
	{
		if (item == p->next->data)//元素值匹配 
		{
			return i;        //返回元素位置 
		}
		p = p->next;    //下个结点 
		i++;
	}
	printf("No Find!");
	return 0;
}


//输出链表元素
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


//一个单链表A分为 序号为偶数为B链表，奇数为A链表。 
int SeparateList(LIST *A, LIST *B) {
	int i = 1;
	LIST *a = A;
	while (a->next) {
		//是否为偶数位数
		if (!(i % 2)) {
			ElemType data=0;
			data = a->next->data;//保存需要删除的数据；
			a->next= a->next->next;//删除的结点
			InsertListInEnd(B, data);//将数据保存到B链表中
		}
		else
		{
			a = a->next;//下过结点；
		}
		i++;
	}
	return 0;

}


//逆转单链表(方法1）
int ReverseList_Method1(LIST *L) {
	LIST *p=L;
	LIST *head=L;//保存头结点
	LIST flag1;//储存结点的前驱地址
	LIST flag2;//储存结点的后驱地址

	   //对首结点的操作
		flag1.next=p->next;   //保存第一个结点的地址
		p=p->next;            //指向第一个结点（前驱）
		flag2.next = p->next; //保存第二个（后驱）的地址
		p->next = NULL;		  // 对第一个结点的next指向NULL，即变为链表的尾端
		p = flag2.next;		  //将第二个结点的地址给p


	//	对中间结点的操作
	while (p->next)   //判断是否到达原链表的尾结点
	{
		flag2.next= p->next;  //保存后驱的地址
		p->next= flag1.next;  //将前驱的地址赋予该结点的next
		flag1.next = p;       //保存该结点的地址
		p  = flag2.next;	  //将p指针向链表的后面移动那个，即后驱的地址赋予p
    
	}
    //	对尾结点的操作
	p->next = flag1.next;   //将前驱的地址赋予原链表的尾结点的next
	head->next = p;         //将头结点指向原链表的尾结点
	return 0;
}

//逆转单链表(方法2）,创建一个新的链表，并且运用插入方法进行操作
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

	InitList(&L, 0);//初始化
	InitList(&B, 0);//初始化

	InsertListInEnd(&L, 10);//向有序链表指定位置插入元素
	OutputList(&L);

	InsertListInEnd(&L, 9);//向有序链表指定位置插入元素
	OutputList(&L);

	InsertListInEnd(&L, 8);//向有序链表指定位置插入元素
	OutputList(&L);

	InsertListInEnd(&L, 7);//向有序链表指定位置插入元素
	OutputList(&L);

	InsertListInEnd(&L, 6);//向有序链表指定位置插入元素
	OutputList(&L);

	InsertListInEnd(&L, 5);//向有序链表指定位置插入元素
	OutputList(&L);

	InsertListByItem(&L, 10, 2);//向链表指定位置插入元素
	OutputList(&L);

	printf("链表中第%d个为5\n", FindList(&L, 5));//查找链表中的元素

	SeparateList(&L, &B);
	OutputList(&L);
	OutputList(&B);

	ReverseList_Method1(&L);
	OutputList(&L);

	//	DeleteListByItem(&L, 10);//删除指定元素值的链表记录
	//	OutputList(&L);
	system("pause");

	return 0;
}

