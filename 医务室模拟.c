//队列应用（链接）
#include<stdio.h>
#include<stdlib.h>
#include <time.h>  //提取随机数种子（时间数）
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

//初始化
int InitNodeQueue(Queue *L) {
	L->head = (NQueue *)malloc(sizeof(NQueue));
	L->head->next = NULL;
	L->tail = L->head;
	L->len = 0;
	return OK;
}



//判空
int IsEmpty(Queue *L) {
	if (L->head == L->tail) return OK;
	else return 0;
	return OK;
}



//进队
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


//出队
NQueue* DeNodeQueue(Queue *L) {
	if (IsEmpty(L)) { printf("队列为空."); exit(10); }
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



//产生一个随机数
int Rand(int x, int y) {
	//srand((unsigned)time(NULL));//设置从1970年1月1日0点到现在的秒数的值为随机数种子      
	return rand() % (y - x + 1) + x;      //返回一个在	x,y区间的随机数

}

//医务室模拟
int Simulation(int pe) {
	int T1=0;  //医生总等待时间
	int T2=0;  //患者总等待时间
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
		printf("第%d个患者到达时间间隔为:%d,看病时间为:%d\n", i + 1, p->PatTime, p->DocTime);
		if (p->PatTime - dctime < 0)
			T2 += (dctime - p->PatTime);
		else
		{
			T1 +=( p->PatTime - dctime);
		}
			dctime = p->DocTime;
	}
	printf("医生等待的总时间为%d,患者等待的平均时间为%f\n", T1, (float)T2/ (float)pe);
	return 1;
}



int main() {
	//一个程序或者说一个线程只设置一次随机数种子！！！！
	srand((unsigned)time(NULL));//设置从1970年1月1日0点到现在的秒数的值为随机数种子   
	Simulation(10);
	system("pause");
	return 0;
}


