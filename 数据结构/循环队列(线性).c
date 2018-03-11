 //ѭ�����Զ���
#include<stdio.h>
#include<stdlib.h>
#define QUEUESIZE  100
#define Qelemtype int 
#define OK 1
#define ERROR 0

//���нṹ
typedef struct {
      Qelemtype *base;
	  int front;     //���е�ͷ
	  int rear;      //���е�β

}SqQueue;
//��ʼ��
int InitSqQueue(SqQueue *Q){
   Q->base=(Qelemtype *)malloc(QUEUESIZE*sizeof(Qelemtype));
   if(!Q->base) exit(0);
   Q->front=Q->rear=0;//����
return OK;
}

//������
int EnQueue(SqQueue *Q,Qelemtype e){
     if((Q->rear+1)%QUEUESIZE==Q->front) return ERROR;
	 Q->base[Q->rear]=e;
	 Q->rear=(Q->rear+1)%QUEUESIZE;
return OK;
}

//�пն���
int IsEmpty(SqQueue *Q){
    if(Q->front==Q->rear) return 1;
	else return 0;
}

//������
Qelemtype DeQueue(SqQueue *Q){
	Qelemtype el;
	if(IsEmpty(Q)) return ERROR;
	el=Q->base[Q->front];
    Q->front=(Q->front+1)%QUEUESIZE;
    return el;
}

//��ն���
int ClearQueue(SqQueue *Q){
    Q->front=Q->rear;
	return OK;
}


//���ٶ���
int DestroyQueue(SqQueue *Q){

    free(Q->base);
	Q->base=NULL;
	Q->front=Q->rear=0;
	return OK;
}

int main()
{
     SqQueue Q;
     InitSqQueue(&Q);
	EnQueue(&Q,1);
	EnQueue(&Q,2);
	EnQueue(&Q,3);
	EnQueue(&Q,4);
	EnQueue(&Q,5);
	while(!IsEmpty(&Q))
   printf("%d\n",DeQueue(&Q));
ClearQueue(&Q);
DestroyQueue(&Q);
	return 0;
}


