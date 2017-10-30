//ӦƸģ��

/*�ѷ��ֵ�δ���Ƶ㣺һ .����һ־Ըδ����ʱ������ɼ��м���ֵĲ������Ⲣ����ԭ���ɼ���
                  ������������ʱ�жϸ�ӦƸ������ȡ�ĸ�λΪ��ڼ�־Ը����Ϊ�ڶ�־Ը���гɼ���5������
				  ��.������ӦƸ�ߵ�־Ըʱδ�ж��Ƿ��иù��ֵ���Ƹ��
				  ��.��������Ƿ�����δ�����жϣ���ʾ�� 
                   .....
*/

 
#include<stdio.h>
#include<stdlib.h>
#include"REC.h"
#define OK 1
#define ERROR 0;
#define QUEUESIZE  80
#define  SIZEADD   10

//�������Զ��б������� 

//��ʼ��
int InitQueue(Queue *Q) {
	Q->base = (Person *)malloc(QUEUESIZE*sizeof(Person));
	if (!Q->base) exit(1);
	Q->front = Q->rear = 0;//����
	Q->size = QUEUESIZE;
	return OK;
}

//�п�
int IsEmpty(Queue *Q) {
	if (Q->front == Q->rear)return 1;
	else return 0;
}
//����
int EnQueue(Queue *Q,Person p) {
	if (Q->rear+1==Q->size) Q->base= (Person *)realloc(Q,(QUEUESIZE+SIZEADD) * sizeof(Person));
	Q->base[Q->rear] =p;
	Q->rear++;
	return OK;
}

//��ȡ���е�һ����Ϣ
Person GetFirst(Queue *Q) {
	if (IsEmpty(Q))
	{
		printf("�ն��У�");
		exit(1);
	}
	Person p;
	p = Q->base[0];
	return p;
}
//����
Person DeQueue(Queue *Q) {
	if (IsEmpty(Q))
	{
		printf("�ն��У�");
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

//�������򣨷����Ӵ�С��
int Sort(Queue *p) {
	int i = 0;
	int j = 0;
	int num = p->rear;
	Person t;
	for ( j; j < num; j++)//ð������ 
    for(i;i<num-j;i++)
		if (p->base[i].Score < p->base[i+1].Score)
		{
			t = p->base[i]; p->base[i] = p->base[i+1]; p->base[i+1] = t;
		}
	return OK;
}


//���

//��Ƹģ��
int Rec() {
	
	//���빤���й����� 
	int m=0;
	printf("�������ܹ�������\n");
	scanf("%d",&m);
	int i = 0;
	Works w[m];
	for (i; i < m; i++) {
		printf("�������%d����������Ƹ������:\n",i+1);
		w[i].Work_ID = i;
		scanf("%d", &w[i].Work_Num);
		}


	Queue Q;//�ж϶���
	Queue Q1;//��ѡ����
	Queue Q2[m];  //��ѡ��������� 
	InitQueue(&Q);
	InitQueue(&Q1);
    int h=0;
	for(h;h<m;h++){
		InitQueue(&Q2[h]);  //ѭ����ʼ��������� 
	}
	
	//����ӦƸ���й����� 
	int n = 0;
	printf("������ӦƸ�ߵ�����:\n");
	scanf("%d", &n);
	int j = 0;
	for (  j; j <n; j++)
	{
		Person p;
		printf("�������%dӦƸ�ߵ���Ϣ:\n", j + 1);
		p.Person_ID = j;
		printf("�������ӦƸ�ߵĳɼ�:\n");
		scanf("%d", &p.Score);
		printf("�������ӦƸ�ߵĵ�һ־Ը:\n");
		scanf("%d", &p.First);

		printf("�������ӦƸ�ߵĵڶ�־Ը:\n");
		scanf("%d", &p.Second);
		p.flag = 0;
		EnQueue(&Q, p);

	}
	
	Sort(&Q);//�������򣨴Ӵ�С�� 

    //�Զ��н��в��� 
	while (!IsEmpty(&Q)) {
		Person p;
		p = DeQueue(&Q);
		   //�ж��Ƿ��һ־Ըδ���� 
			if (p.flag == -1){
			   if(w[p.Second].Work_Num)  //�ù�����Ƹʣ�������Ƿ�Ϊ�� 
			       {
			             w[p.Second].Work_Num--;  //������Ƹʣ��������һ 
		  		         EnQueue(&Q2[p.Second],p);   //������ѡ�߶��� 
				  }
		  		else  EnQueue(&Q1,p);    //����δ��ѡ�߶��� 
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
     
     
     //��� 
     int o=0;
     for (o;o<m;o++)
     {  
	     printf("\n\n");
     	printf("��%d������ѡ������:\n",o);
     	int u=0;              //����u ������ǰһ��FOR���棬 uֵ�ᱣ�档�¸�FORѭ���޷����룡�� 
		int n=Q2[o].rear;      //�������ݲ��� �����ź�һ��FOR��Q2[o].rear��ı� ������ 
     for(u;u<n;u++){
     	Person p=DeQueue(&Q2[o]);
     	printf("��ţ�%d,�ɼ���%d,��һ־Ը��%d,�ڶ�־Ը:%d.\n",p.Person_ID,p.Score,p.First,p.Second);
	 }
}

int y=0;
		printf("\n\n");
		printf("δ��ѡ������:\n", o);
 int  t= Q1.rear;
for(y;y<t;y++){
	   Person p=DeQueue(&Q1);
     	printf("��ţ�%d,�ɼ���%d,��һ־Ը��%d,�ڶ�־Ը:%d.\n",p.Person_ID,p.Score,p.First,p.Second);
}

}
int main() {
    Rec();  
	return 0;
}


