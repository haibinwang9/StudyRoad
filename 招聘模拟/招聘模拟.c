//应聘模拟

/*已发现的未完善点：一 .当第一志愿未满足时，对其成绩有减五分的操作。这并非其原本成绩。
                  解决方案：输出时判断该应聘者所入取的岗位为其第几志愿。若为第二志愿进行成绩加5操作。
				  二.在输入应聘者的志愿时未判断是否有该工种的招聘。
				  三.对于输入非法数据未进行判断，提示。 
                   .....
*/

 
#include<stdio.h>
#include<stdlib.h>
#include"REC.h"
#define OK 1
#define ERROR 0;
#define QUEUESIZE  80
#define  SIZEADD   10

//利用线性队列便于排序 

//初始化
int InitQueue(Queue *Q) {
	Q->base = (Person *)malloc(QUEUESIZE*sizeof(Person));
	if (!Q->base) exit(1);
	Q->front = Q->rear = 0;//置零
	Q->size = QUEUESIZE;
	return OK;
}

//判空
int IsEmpty(Queue *Q) {
	if (Q->front == Q->rear)return 1;
	else return 0;
}
//进队
int EnQueue(Queue *Q,Person p) {
	if (Q->rear+1==Q->size) Q->base= (Person *)realloc(Q,(QUEUESIZE+SIZEADD) * sizeof(Person));
	Q->base[Q->rear] =p;
	Q->rear++;
	return OK;
}

//获取队列第一个信息
Person GetFirst(Queue *Q) {
	if (IsEmpty(Q))
	{
		printf("空队列！");
		exit(1);
	}
	Person p;
	p = Q->base[0];
	return p;
}
//出队
Person DeQueue(Queue *Q) {
	if (IsEmpty(Q))
	{
		printf("空队列！");
		exit(1);
	}
	Person p;
	p = Q->base[0];
	int i=0;
	for(i;i<Q->rear-1;i++){
		Q->base[i]=Q->base[i+1];
	}
	Q->rear--;
	return p;
}

//队列排序（分数从大到小）
int Sort(Queue *p) {
	int i = 0;
	int j = 0;
	int num = p->rear;
	Person t;
	for ( j; j < num; j++)//冒泡排序 
    for(i;i<num-j;i++)
		if (p->base[i].Score < p->base[i+1].Score)
		{
			t = p->base[i]; p->base[i] = p->base[i+1]; p->base[i+1] = t;
		}
	return OK;
}


//输出

//招聘模拟
int Rec() {
	
	//输入工种有关数据 
	int m=0;
	printf("请输入总工种数：\n");
	scanf("%d",&m);
	int i = 0;
	Works w[m];
	for (i; i < m; i++) {
		printf("请输入第%d个工种所招聘的人数:\n",i+1);
		w[i].Work_ID = i;
		scanf("%d", &w[i].Work_Num);
		}


	Queue Q;//判断队列
	Queue Q1;//落选队列
	Queue Q2[m];  //入选者数组队列 
	InitQueue(&Q);
	InitQueue(&Q1);
    int h=0;
	for(h;h<m;h++){
		InitQueue(&Q2[h]);  //循环初始化数组队列 
	}
	
	//输入应聘者有关数据 
	int n = 0;
	printf("请输入应聘者的总数:\n");
	scanf("%d", &n);
	int j = 0;
	for (  j; j <n; j++)
	{
		Person p;
		printf("请输入第%d应聘者的信息:\n", j + 1);
		p.Person_ID = j;
		printf("请输入该应聘者的成绩:\n");
		scanf("%d", &p.Score);
		printf("请输入该应聘者的第一志愿:\n");
		scanf("%d", &p.First);

		printf("请输入该应聘者的第二志愿:\n");
		scanf("%d", &p.Second);
		p.flag = 0;
		EnQueue(&Q, p);

	}
	
	Sort(&Q);//队列排序（从大到小） 

    //对队列进行操作 
	while (!IsEmpty(&Q)) {
		Person p;
		p = DeQueue(&Q);
		   //判断是否第一志愿未满足 
			if (p.flag == -1){
			   if(w[p.Second].Work_Num)  //该工种招聘剩余数量是否为零 
			       {
			             w[p.Second].Work_Num--;  //工种招聘剩余数量减一 
		  		         EnQueue(&Q2[p.Second],p);   //进入入选者队列 
				  }
		  		else  EnQueue(&Q1,p);    //进入未入选者队列 
				  }
		  		
			else {
				if(w[p.First].Work_Num) {
				w[p.First].Work_Num--;
		    	EnQueue(&Q2[p.First],p);}
				else {
				p.Score = p.Score - 5;
				p.flag = -1;
				EnQueue(&Q, p);
				Sort(&Q);
			         }
				}
		}
     
     
     //输出 
     int o=0;
     for (o;o<m;o++)
     {  
	     printf("\n\n");
     	printf("第%d工种入选者名单:\n",o);
     	int u=0;              //重置u ，若放前一个FOR外面， u值会保存。下个FOR循环无法进入！！ 
		int n=Q2[o].rear;      //保存数据不变 ，若放后一个FOR中Q2[o].rear会改变 ！！！ 
     for(u;u<n;u++){
     	Person p=DeQueue(&Q2[o]);
     	printf("编号：%d,成绩：%d,第一志愿：%d,第二志愿:%d.\n",p.Person_ID,p.Score,p.First,p.Second);
	 }
}

int y=0;
		printf("\n\n");
		printf("未入选者名单:\n", o);
 int  t= Q1.rear;
for(y;y<t;y++){
	   Person p=DeQueue(&Q1);
     	printf("编号：%d,成绩：%d,第一志愿：%d,第二志愿:%d.\n",p.Person_ID,p.Score,p.First,p.Second);
}

}
int main() {
    Rec();  
	return 0;
}


