//����Ӧ�ã����ӣ�
#include<stdio.h>
#include<stdlib.h>
#include <time.h>  //��ȡ��������ӣ�ʱ������
#define Element int 
#define OK 1

typedef struct NodeQueue {
	Element  DocTime,PatTime;
	struct NodeQueue *next;
}NQueue;

typedef struct {
	struct NodeQueue *head, *tail;
	int len;
}Queue;

//��ʼ��
int InitNodeQueue(Queue *L) {
	L->head = (NQueue *)malloc(sizeof(NQueue));
	L->head->next = NULL;
	L->tail = L->head;
	L->len = 0;
	return OK;
}



//�п�
int IsEmpty(Queue *L) {
	if (L->head == L->tail) return OK;
	else return 0;
	return OK;
}



//����
int EnNodeQueue(Queue *L, Element e1,Element e2) {
	NQueue *p = (NQueue *)malloc(sizeof(NQueue));
	if (!p) exit(0);
	p->DocTime = e1;
	p->PatTime = e2;
	p->next = NULL;
	L->tail->next = p;
	L->tail = p;
	L->len++;
	return OK;
}


//����
NQueue* DeNodeQueue(Queue *L) {
	if (IsEmpty(L)) { printf("����Ϊ��."); exit(10); }
	NQueue *p = L->head->next;
	if (p == L->tail) {
		L->head->next = NULL;
		L->tail = L->head;
	}
	else {
		L->head->next = p->next;
	}
	L->len--;
	return p;
}



//����һ�������
int Rand(int x, int y) {
	//srand((unsigned)time(NULL));//���ô�1970��1��1��0�㵽���ڵ�������ֵΪ���������      
	return rand() % (y - x + 1) + x;      //����һ����	x,y����������

}

//ҽ����ģ��
int Simulation(int pe) {
	int T1=0;  //ҽ���ܵȴ�ʱ��
	int T2=0;  //�����ܵȴ�ʱ��
	Queue Q1;
	InitNodeQueue(&Q1);
	int i = 0;
	for (i;i<pe;i++)         
	{
		EnNodeQueue(&Q1, Rand(0, 14), Rand(1, 9));
	}
	i = 0;
	int dctime = 0;
	for (i; i < pe; i++)
	{
		NQueue *p = DeNodeQueue(&Q1);
		printf("��%d�����ߵ���ʱ����Ϊ:%d,����ʱ��Ϊ:%d\n", i + 1, p->PatTime, p->DocTime);
		if (p->PatTime - dctime < 0)
			T2 += (dctime - p->PatTime);
		else
		{
			T1 +=( p->PatTime - dctime);
		}
			dctime = p->DocTime;
	}
	printf("ҽ���ȴ�����ʱ��Ϊ%d,���ߵȴ���ƽ��ʱ��Ϊ%f\n", T1, (float)T2/ (float)pe);
	return 1;
}



int main() {
	//һ���������˵һ���߳�ֻ����һ����������ӣ�������
	srand((unsigned)time(NULL));//���ô�1970��1��1��0�㵽���ڵ�������ֵΪ���������   
	Simulation(10);
	system("pause");
	return 0;
}


